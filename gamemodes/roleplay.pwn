/*
    Roleplay Server
    By Maximus
*/

#include <a_samp>
// Change MAX_PLAYERS to the amount of players (slots)
#undef MAX_PLAYERS
#define MAX_PLAYERS			51 // 51

#if !defined gpci
native gpci(playerid, serial[], len);
#endif

//////////////////////////////////
// Config
//////////////////////////////////
#define MAX_CONNECTIONS_FROM_IP     5 // Max 5 players can be on server from a single ip
#define VERSION         		"1.0"
#define SERVER_IP				"none"
#define WEBSITE					"none"
#define RCON_PASS				"None"
#define ENABLE_DEBUG			true		// Enable / Disable Debugging

public OnGameModeInit()
{
	print("Initializing 'Main'");
	OnGameModeInitEx();

	#if defined Main_OnGameModeInit
		return Main_OnGameModeInit();
	#else
		return 1;
	#endif
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif

#define OnGameModeInit Main_OnGameModeInit
#if defined Main_OnGameModeInit
	forward Main_OnGameModeInit();
#endif

//////////////////////////////////
// Includes
//////////////////////////////////
#include <a_mysql>
#include <bcrypt>
//#include <foreach>
#include <sscanf2>
#include <izcmd>
#include <streamer>
//#include <country>
//#include <a_zones>
//#include <OPA>
//#include <mSelection>
//#include <strlib>
//#include <oof_func>
//#include <antiadvertising>
//#include <oof_intmenu>
#include <easyDialog>
//#include <fly>
#include <distance>

// Default Values
#define DEFAULT_WORLD		0
#define DEFAULT_INTERIOR	0

//---------------  Limits of stuff  -----------
#define MAX_LOGIN_TIME			180
#define MAX_MODLOGIN_ATTEMPTS	3
#define MAX_LOGIN_ATTEMPTS		3
#define MAX_GAME_TEXTS			3
#define MAX_TJL_MESSAGES		4
#define MAX_VEHICLE_NAME		20
#define MAX_LOCATION_NAME		50			// Max location name (houses name can be 48 characters)
#define MAX_SALOC_NAME			25			// Max san andreas location name (bayside, blueberry etc)
#define MAX_SKINS				312
#define MAX_SHOP_STAFF			50
#define MAX_SHOPS				44
#define MAX_MAP_ICONS			13

// MySQL
#if ENABLE_DEBUG == true
#define MYSQL_HOST			"localhost"
#define MYSQL_DATABASE		"roleplay"
#define MYSQL_USER			"root"
#define MYSQL_PASSWORD      ""
#endif

#if ENABLE_DEBUG == false
#define MYSQL_HOST 			"127.0.0.1"
#define MYSQL_DATABASE 		"roleplay"
#define MYSQL_USER 			""
#define MYSQL_PASSWORD 		""
#endif

//      Admin Ranks
#define ADMIN_LEVEL1     "Admin"
#define ADMIN_LEVEL2     "Senior Admin"
#define ADMIN_LEVEL3     "Head Admin"
#define ADMIN_LEVEL4     "Developer"

#define ResetMoneyBar ResetPlayerMoney
#define UpdateMoneyBar GivePlayerMoney

// Model selection menu
//new skinlist = mS_INVALID_LISTID;
#define ADMIN_SKIN_MENU			1
#define ADMIN_SKIN_SELECTION	2

//---------- CMD Spam Wait Timers --------------
#define NUM_CMDSPAM			28 // Number of array/number of spam defines +1
#define NUM_LOOP_CMDSPAM	27 // This should 1 less than NUM_CMDSPAM

#define ALLCMDS 		0
#define Report			1
#define AnimSpam		2
#define FlashSpam		3
#define FoffSpam		4
#define RaSpam			5
#define SlapSpam		6
#define FartSpam		7
#define CrySpam			8
#define CHANGE_WEAPON	9
#define HouseBuyVisit	10
#define KnockSpam		11
#define BreakIn			12
#define Ra_MSG 			13
#define GOTO 			14
#define RipSpam			15
#define PASSWORD_CHANGE		16
#define KEY_YES_SPAM		17
#define RobSpam				18
#define TPSPAM				19
#define PEESPAM				20
#define ARMOUR_SPAM			21
#define LEAVE_SPAM			22
#define FIX_SPAM			23
#define KISS_SPAM			24
#define PSLAP_SPAM			25
#define KEY_MISSION_SPAM	26
#define DISCORD_REPORT		27

//--------------------------------------------------------------------
//  Macros
//--------------------------------------------------------------------
#define FLOAT_INFINITY      (Float:0x7F800000)
// By Sky (Maximus)
#define S_GetPlayerSkin(%0) pInfo[%0][Skin]

#define GetPlayerHours(%0) pInfo[%0][Hour]

#define GetItemPrice(%0) g_Item[%0][e_price]
#define GetWeaponPrice(%0) g_Weapon[%0][e_price]

#define GetPokemonName(%0) pokeInfo[%0][poName]
#define GetPokemonPrice(%0) pokeInfo[%0][poPrice]

#define IsPlayerInJail(%0) aJailTime[playerid] > 0

//#define SendGameText(%0, %1) if(pSet[%0][GameMessage] == 1) GameTextPlayer(%0, %1);
	//else if(pSet[%0][GameMessage] == 2) GameTextForPlayer(%0, %1, 3000, 3);
#define GetVehicleName(%0) VehicleNames[%0-400]
#define GetClothName(%0) ClothesInfo[%0][mName]
#define GetWeaponName_(%0) WeaponNames[%0]
#define GetWeaponDamage(%0) s_WeaponInfo[%0][e_WeaponDamage]

//=======================  Keys (OnPlayerKeySateChange)  =======================
#define KEY_AIM (128)

// HOLDING(keys)
#define HOLDING(%0) \
	((newkeys & (%0)) == (%0))

// PRESSED (keys)
#define PRESSED(%0) (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

// PRESSING(keyVariable, keys)
#define PRESSING(%0,%1) \
	(%0 & (%1))

// RELEASED(keys)
#define RELEASED(%0) \
	(((newkeys & (%0)) != (%0)) && ((oldkeys & (%0)) == (%0)))
//-----------------------------------------------------------------------------<

#define strcpy(%0,%1,%2) strcat((%0[0] = '\0', %0), %1, %2) // Slice

// Spawn Point Las Venturas (The High Roller)
#define DEFAULT_SPAWN_X 		1958.3783
#define DEFAULT_SPAWN_Y 		1343.1572
#define DEFAULT_SPAWN_Z 		15.3746
#define DEFAULT_SPAWN_A 		270.1425

enum E_PLAYER_DATA
{
	ID,
	Name[MAX_PLAYER_NAME],
	Password[BCRYPT_HASH_LENGTH],
	IP,
	Admin,
	VIP,
	Banned,
	Hours,
	Minutes,
	Seconds,
	Skin,
	Score,
	Money,
	bankMoney,
	Float: X,
	Float: Y,
	Float: Z,
	Float: Angle,
	Interior,
	Spawned,
	Cache: Cache_ID
};
new Player[MAX_PLAYERS][E_PLAYER_DATA];

new Float:matLocations[][] = {
	{2196.0667,-2663.2827,13.5469}, // Ocean docks
	{-1895.5040,-1671.6693,23.0156},
	{2833.1238,892.6077,10.7578,6.0423},
	{-58.3614,-223.7440,5.4297},
	{-1029.0605,-710.2379,32.0078},
	{-1874.1077,1417.8599,7.1763},
	{591.3609,869.9827,-42.4973},
	{-1481.7745,145.2400,18.7734}
};

/*enum ServerData
{
	CheatersKilled
};
new sInfo[ServerData];*/

new bool:IsPlayerRegistered[MAX_PLAYERS char];
new bool:IsPlayerLoggedIn[MAX_PLAYERS char];
//new bool:OnClassSelection[MAX_PLAYERS char];
new bool:AllowSpawn[MAX_PLAYERS char];

new wrongLogin[MAX_PLAYERS];

//=============================  Anti Cheat  ===============================
new Cash[MAX_PLAYERS];

#define BCRYPT_COST 12

//MySQL connection handle
new MySQL: MySQL;

// MySQL race check
new MySQLRaceCheck[MAX_PLAYERS];

//========= Timers =============
// Admin
/*new SpecTimer[MAX_PLAYERS];
new FineTimer[MAX_PLAYERS];
new WarnTimer[MAX_PLAYERS];

new ConnectTimer[MAX_PLAYERS];
new KickTimer[MAX_PLAYERS];
new DrugsTimer[MAX_PLAYERS];
new BeanTimer[MAX_PLAYERS];
new GameTextTimer[MAX_PLAYERS];
new GDTimer[MAX_PLAYERS];
new VisitTimer[MAX_PLAYERS];
new ChallengeTimer[MAX_PLAYERS];
new DuelInviteTimer[MAX_PLAYERS];*/
new loginTimer[MAX_PLAYERS];

#include "utils/colors.pwn"
#include "utils/functions.pwn"

main()
{
	print(" ");
	print("---------------------------------------");
	print(" Roleplay Gamemode v"VERSION" Loaded.");
	print("---------------------------------------");
	print(" ");
}

OnGameModeInitEx()
{
	new result = GetTickCount();  // <-- This is for Duration
	print("--------------------------------------------------------");
	print("|  Roleplay Gamemode Version "VERSION" - (c) 2020  |");
	print("|  By Maximus (Eagle_Eye)                              |");
	print("--------------------------------------------------------");

	SetGameModeText("Roleplay");
	ShowPlayerMarkers(1);
	EnableStuntBonusForAll(0);
	DisableInteriorEnterExits();
	AntiDeAMX();

	//SSCANF_Option(MATCH_NAME_PARTIAL, 1);

	new MySQLOpt: option_id = mysql_init_options();
	mysql_set_option(option_id, AUTO_RECONNECT, true); // it automatically reconnects when loosing connection to mysql server
	#if ENABLE_DEBUG == false
    mysql_log();
    #endif

    #if ENABLE_DEBUG == true
    mysql_log(ALL);
    #endif

	MySQL = mysql_connect(MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD, MYSQL_DATABASE, option_id); // AUTO_RECONNECT is enabled for this connection handle only
	if (MySQL == MYSQL_INVALID_HANDLE || mysql_errno(MySQL) != 0)
	{
		print("MySQL connection failed. Server is shutting down.");
		SendRconCommand("exit");
		return 1;
	}
	print("MySQL connection is successful.");

	// Create table if not exists
	//SetupPlayerTable();

	for(new skinid = 1; skinid < 264; skinid++)
	{
	    switch(skinid)
	    {
	    	case 1,2,14,16,18,20,21,23,24,82..84,102,103,104,105..110,114,115,116,117,118,167,189,221,240,250,7, 9..13, 15, 17, 19, 22, 25..41, 43..64, 66..70, 72, 75..81, 85, 87..101, 111..113, 120, 123..148, 150..162, 168..188, 190, 191, 193..207, 209, 210, 212..216, 218..220, 222..239, 241..249, 251..263,3..6,8,42,65,273:
	    	{
	    	    AddPlayerClass(skinid, 0.0,0.0,0.0, 0.0, 0,0,0,0,0,0);
			}
	    }
	}

	for (new i = 0; i < sizeof(matLocations); i++)
	{
		CreateDynamicPickup(1239, 1, matLocations[i][0], matLocations[i][1], matLocations[i][2], DEFAULT_WORLD, DEFAULT_INTERIOR, -1, 100);
		Create3DTextLabel("Press {D6D631}Y {FFFFFF}To Pickup {0077FF}Box of Materials", -1, matLocations[i][0], matLocations[i][1], matLocations[i][2]+0.5, 10.0, DEFAULT_WORLD);
	}
	printf("OOF GM Loaded In:  %i ms", (GetTickCount() - result));
	return 1;
}

public OnGameModeExit()
{
	// save all player data before closing connection
	for (new i = 0, j = GetPlayerPoolSize(); i <= j; i++) // GetPlayerPoolSize function was added in 0.3.7 version and gets the highest playerid currently in use on the server
	{
		if (IsPlayerConnected(i))
		{
			// reason is set to 1 for normal 'Quit'
			OnPlayerDisconnect(i, 1);
		}
	}

	mysql_close(MySQL);
	return 1;
}

public OnPlayerConnect(playerid)
{
	MySQLRaceCheck[playerid]++;

	Player[playerid][Spawned] = 0;

	// reset player data
	static const empty_player[E_PLAYER_DATA];
	Player[playerid] = empty_player;

	GetPlayerName(playerid, Player[playerid][Name], MAX_PLAYER_NAME);
	GetPlayerIp(playerid, Player[playerid][IP], 16);

	// send a query to recieve all the stored player data from the table
	new query[103];
	mysql_format(MySQL, query, sizeof query, "SELECT * FROM `users` WHERE `username` = '%e' LIMIT 1", Player[playerid][Name]);
	mysql_tquery(MySQL, query, "OnPlayerDataLoaded", "dd", playerid, MySQLRaceCheck[playerid]);
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	if(IsPlayerNPC(playerid))
	{
		return 1;
	}

	// Default SA-MP Class Selection
	SetPlayerPos(playerid, 1958.3783, 1343.1572, 15.3746);
	SetPlayerCameraPos(playerid, 1958.3783, 1343.1572, 15.3746);
	SetPlayerCameraLookAt(playerid, 1958.3783, 1343.1572, 15.3746);

	if(Player[playerid][Skin] > 0) SetPlayerSkin(playerid, Player[playerid][Skin]);
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	MySQLRaceCheck[playerid]++;

	Player[playerid][Spawned] = 0;
	//FirstSpawn[playerid] = 0;
	//FirstSpawnAfterRegister[playerid] = 0;

	UpdatePlayerData(playerid, reason);

	// if the player was kicked (either wrong password or taking too long) during the login part, remove the data from the memory
	if (cache_is_valid(Player[playerid][Cache_ID]))
	{
		cache_delete(Player[playerid][Cache_ID]);
		Player[playerid][Cache_ID] = MYSQL_INVALID_CACHE;
	}

	// if the player was kicked before the time expires (30 seconds), kill the timer
	if (loginTimer[playerid])
	{
		KillTimer(loginTimer[playerid]);
		loginTimer[playerid] = 0;
	}

	// Sets "IsPlayerLoggedIn" to false when the player disconnects, it prevents from saving the player data twice when "gmx" is used
	IsPlayerLoggedIn{playerid} = false;

	for (new i = 0; i < MAX_PLAYER_ATTACHED_OBJECTS; i++)
    {
        if (IsPlayerAttachedObjectSlotUsed(playerid, i)) RemovePlayerAttachedObject(playerid, i);
    }
	return 1;
}

public OnPlayerSpawn(playerid)
{
	// spawn the player to their last saved position
	SetPlayerInterior(playerid, Player[playerid][Interior]);
	SetPlayerPos(playerid, Player[playerid][X], Player[playerid][Y], Player[playerid][Z]);
	SetPlayerFacingAngle(playerid, Player[playerid][Angle]);
	SetCameraBehindPlayer(playerid);

	Player[playerid][Spawned] = 1;
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	Player[playerid][Spawned] = 0;
	//UpdatePlayerDeaths(playerid);
	//UpdatePlayerKills(killerid);
	return 1;
}

forward OnPlayerDataLoaded(playerid, race_check);
public OnPlayerDataLoaded(playerid, race_check)
{
	if (race_check != MySQLRaceCheck[playerid]) return Kick(playerid);

	new string[115];
	if(cache_num_rows() > 0)
	{
		// we store the password and the salt so we can compare the password the player inputs
		// and save the rest so we won't have to execute another query later
		cache_get_value(0, "password", Player[playerid][Password], BCRYPT_HASH_LENGTH);
		cache_get_value_int(0, "skin", Player[playerid][Skin]);

		// saves the active cache in the memory and returns an cache-id to access it for later use
		Player[playerid][Cache_ID] = cache_save();

		// Set the player skin to his saved skin
		SetPlayerSkin(playerid, Player[playerid][Skin]);

		IsPlayerRegistered{playerid} = true;

		SendClientMessage(playerid, COLOR_WHITE, "This Name Is {FF0000}Already Registered{FFFFFF}.");
		format(string, sizeof string, "This account (%s) is registered. Please login by entering your password in the field below:", Player[playerid][Name]);
		//ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Login", string, "Login", "Abort");
		Dialog_Show(playerid, LoginMenu, DIALOG_STYLE_PASSWORD, "Account Login", string, "Login", "Abort");
		
		// from now on, the player has 30 seconds to login
		loginTimer[playerid] = SetTimerEx("OnLoginTimeout", MAX_LOGIN_TIME * 1000, false, "d", playerid);
	}
	else
	{
		format(string, sizeof string, "Welcome %s, you can register by entering your password in the field below:", Player[playerid][Name]);
		//ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, "Registration", string, "Register", "Abort");
		Dialog_Show(playerid, "RegisterMenu", DIALOG_STYLE_PASSWORD, "Account Registration", string, "Register", "Abort");
		IsPlayerRegistered{playerid} = false;
	}
	return 1;
}

Dialog:LoginMenu(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		bcrypt_check(inputtext, Player[playerid][Password], "OnPasswordChecked", "d", playerid);
	}
	else return Kick(playerid);
	return 1;
}

forward OnPasswordChecked(playerid);
public OnPasswordChecked(playerid)
{
	new bool:match = bcrypt_is_equal();
	if (match)
	{
		SendClientMessage(playerid, COLOR_GREEN, "You have been successfully logged in.");
		
		// sets the specified cache as the active cache so we can retrieve the rest player data
		cache_set_active(Player[playerid][Cache_ID]);

		cache_get_value_int(0, "id", Player[playerid][ID]);
		//printf("%d", Player[playerid][ID]);

		//cache_get_value_int(0, "kills", Player[playerid][Kills]);
		//cache_get_value_int(0, "deaths", Player[playerid][Deaths]);

		cache_get_value_int(0, "admin", Player[playerid][Admin]);
		cache_get_value_int(0, "vip", Player[playerid][VIP]);
		cache_get_value_int(0, "banned", Player[playerid][Banned]);
		cache_get_value_int(0, "hours", Player[playerid][Hours]);
		cache_get_value_int(0, "minutes", Player[playerid][Minutes]);
		cache_get_value_int(0, "seconds", Player[playerid][Seconds]);
		cache_get_value_int(0, "score", Player[playerid][Score]);
		cache_get_value_int(0, "money", Player[playerid][Money]);
		cache_get_value_int(0, "bank_money", Player[playerid][bankMoney]);
		cache_get_value_float(0, "x", Player[playerid][X]);
		cache_get_value_float(0, "y", Player[playerid][Y]);
		cache_get_value_float(0, "z", Player[playerid][Z]);
		cache_get_value_float(0, "angle", Player[playerid][Angle]);
		//printf("angle %f", Player[playerid][Angle]);
		cache_get_value_int(0, "interior", Player[playerid][Interior]);

		SetPlayerScore(playerid, Player[playerid][Score]);
		SetPlayerCash(playerid, Player[playerid][Money]);

		//new query[103];
		//mysql_format(MySQL, query, sizeof query, "SELECT * FROM `users` WHERE `username` = '%e' LIMIT 1", Player[playerid][Name]);
		//mysql_tquery(MySQL, query, "OnPlayerDataLoaded", "dd", playerid, MySQLRaceCheck[playerid]);
		
		// remove the active cache from memory and unsets the active cache as well
		cache_delete(Player[playerid][Cache_ID]);
		Player[playerid][Cache_ID] = MYSQL_INVALID_CACHE;

		KillTimer(loginTimer[playerid]);
		loginTimer[playerid] = 0;

		IsPlayerRegistered{playerid} = true;
		IsPlayerLoggedIn{playerid} = true;

		// spawn the player to their last saved position after login
		SetSpawnInfo(playerid, NO_TEAM, Player[playerid][Skin], Player[playerid][X], Player[playerid][Y], Player[playerid][Z], Player[playerid][Angle], 0, 0, 0, 0, 0, 0);
		SpawnPlayer(playerid);
	}
	else
	{
		new string[141];
		wrongLogin[playerid]++;
		if (wrongLogin[playerid] >= MAX_LOGIN_ATTEMPTS)
		{
			format(string, sizeof string, "*KICK: %s (%d) has been kicked - (incorrect password)");
			SendClientMessageToAll(COLOR_PINK, string);
			DelayedKick(playerid);
		}
		else
		{
			format(string, sizeof string, "This account (%s) is registered. Please login by entering your password in the field below:\n\n{FF0000}Wrong Password!", Player[playerid][Name]);
			Dialog_Show(playerid, LoginMenu, DIALOG_STYLE_INPUT, "Account Login", string, "Login", "Abort");
		}
	}
	return 1;
}

Dialog:RegisterMenu(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		new string[64];
		if (strlen(inputtext) < 6)
		{
			format(string, sizeof string, "Welcome %s, you can register by entering your password in the field below:\n\nMinimum: {FF0000}6 {FFFFFF}characters", Player[playerid][Name]);
			Dialog_Show(playerid, "RegisterMenu", DIALOG_STYLE_PASSWORD, "Account Registration", string, "Register", "Abort");
			return 1;
		}
		bcrypt_hash(inputtext, BCRYPT_COST, "OnPasswordHashed", "d", playerid);
	}
	else return Kick(playerid);
	return 1;
}

forward OnPasswordHashed(playerid);
public OnPasswordHashed(playerid)
{
	bcrypt_get_hash(Player[playerid][Password]);
	printf("%s asd %s", Player[playerid][Password]);

	new query[172];
	mysql_format(MySQL, query, sizeof(query), "INSERT into users (username, password, ip)\
	VALUES ('%e', '%s', '%s')", Player[playerid][Name], Player[playerid][Password], Player[playerid][IP]);
	mysql_tquery(MySQL, query, "OnPlayerRegister", "d", playerid);
	SendClientMessage(playerid, COLOR_GREEN, "Registering your account please wait.....");
	return 1;
}

forward OnPlayerRegister(playerid);
public OnPlayerRegister(playerid)
{
	// retrieves the ID generated for an AUTO_INCREMENT column by the sent query
	Player[playerid][ID] = cache_insert_id();
	IsPlayerRegistered{playerid} = true;
	IsPlayerLoggedIn{playerid} = true;
	SetPlayerScore(playerid, 0);
	GivePlayerCash(playerid, 500);
	//FirstSpawnAfterRegister[playerid] = 1;
	AllowSpawn{playerid} = true;

	SendClientMessage(playerid, COLOR_GREEN, "Account successfully registered, you have been automatically logged in.");

	Player[playerid][X] = DEFAULT_SPAWN_X;
	Player[playerid][Y] = DEFAULT_SPAWN_Y;
	Player[playerid][Z] = DEFAULT_SPAWN_Z;
	Player[playerid][Angle] = DEFAULT_SPAWN_A;

	SetSpawnInfo(playerid, NO_TEAM, 1, Player[playerid][X], Player[playerid][Y], Player[playerid][Z], Player[playerid][Angle], 0, 0, 0, 0, 0, 0);
	SpawnPlayer(playerid);
	return 1;
}

forward OnLoginTimeout(playerid);
public OnLoginTimeout(playerid)
{
	if(IsPlayerLoggedIn{playerid} == false)
	{
		loginTimer[playerid] = 0;

		new sKick[68];
		format(sKick, sizeof(sKick), "*KICK: %s (%d)  (PAUSE KICK)  Login Timeout.", Player[playerid][Name], playerid);
		SendClientMessageToAll(COLOR_PINK, sKick);
		
		GameTextForPlayer(playerid, "~r~Login Timeout", 5000, 3);

		DelayedKick(playerid);
	}
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if (PRESSED(KEY_YES))
	{
		for (new i = 0; i < sizeof(matLocations); i++)
		{
			if (IsPlayerInRangeOfPoint(playerid, 5.0, matLocations[i][0], matLocations[i][1], matLocations[i][2]))
			{
				if (Player[playerid][Spawned] == 0) return 1;

				SetPlayerAttachedObject(playerid, 0, 1271, 1, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.727, 0.736, 0.926);
				//EditAttachedObject(playerid, 0);
				ApplyAnimation(playerid, "CARRY", "liftup", 4.0, 0, 0, 0, 0, 0);
				//SetPlayerAttachedObject(playerid, index, modelid, bone, Float:fOffsetX = 0.0, Float:fOffsetY = 0.0, Float:fOffsetZ = 0.0, Float:fRotX = 0.0, Float:fRotY = 0.0, Float:fRotZ = 0.0, Float:fScaleX = 1.0, Float:fScaleY = 1.0, Float:fScaleZ = 1.0, materialcolor1 = 0, materialcolor2 = 0)
				SendClientMessage(playerid, COLOR_ORANGE, "*Picks up a box of materials");
				SendClientMessage(playerid, COLOR_RED, "((Press \"Y\" to load the materials into the truck))");
			}
		}

		new vehicle = GetClosestVehicleToPlayer(playerid);
		printf("%d, %s", vehicle, vehicle);
		//if (IsPlayerNearVehicle)
	}
	return 1;
}

public OnPlayerEditAttachedObject(playerid, response, index, modelid, boneid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fScaleX, Float:fScaleY, Float:fScaleZ)
{
	//printf("%d, %d, %d, %f, %f, %f, %f, %f, %f, %f, %f, %f", index, modelid, boneid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, fScaleX, fScaleY, fScaleZ);
	return 1;
}

public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
	SetPlayerPosFindZ(playerid, fX, fY, fZ);
	return 1;
}

forward _KickPlayerDelayed(playerid);
public _KickPlayerDelayed(playerid)
{
	Kick(playerid);
	return 1;
}

DelayedKick(playerid, time = 500)
{
	SetTimerEx("_KickPlayerDelayed", time, false, "d", playerid);
	return 1;
}

UpdatePlayerData(playerid, reason)
{
	if (IsPlayerLoggedIn{playerid} == false) return 0;

	// if the client crashed, it's not possible to get the player's position in OnPlayerDisconnect callback
	// so we will use the last saved position (in case of a player who registered and crashed/kicked, the position will be the default spawn point)
	if (reason == 1)
	{
		GetPlayerPos(playerid, Player[playerid][X], Player[playerid][Y], Player[playerid][Z]);
		GetPlayerFacingAngle(playerid, Player[playerid][Angle]);
	}

	new query[205];
	mysql_format(MySQL, query, sizeof query, "UPDATE users SET hours = %d, minutes = %d, seconds = %d, x = %f, y = %f, z = %f, angle = %f,\
	interior = %d WHERE id = %d LIMIT 1",\
	Player[playerid][Hours], Player[playerid][Minutes], Player[playerid][Seconds], Player[playerid][X], Player[playerid][Y], Player[playerid][Z],\
	Player[playerid][Angle], GetPlayerInterior(playerid), Player[playerid][ID]);
	mysql_tquery(MySQL, query);
	return 1;
}
//sUPDATE `players` SET hours = %d, minutes = %d, seconds = %d, x = %f, y = %f, z = %f, angle = %f,interior = %d WHERE id = %d LIMIT 1

SetupPlayerTable()
{
	mysql_tquery(MySQL, "CREATE TABLE IF NOT EXISTS `users` (\
	`id` int(11) NOT NULL AUTO_INCREMENT,\
	`username` varchar(24) NOT NULL,\
	`password` varchar(61) NOT NULL,\
	`ip` varchar(16) NOT NULL DEFAULT '0.0.0.0',\
	`register_date` datetime NOT NULL DEFAULT current_timestamp(),\
	`last_online` datetime NOT NULL DEFAULT current_timestamp(),\
	`admin` tinyint(4) NOT NULL DEFAULT 0,\
	`vip` tinyint(4) NOT NULL DEFAULT 0,\
	`banned` tinyint(4) NOT NULL DEFAULT 0,\
	`hours` int(11) NOT NULL DEFAULT 0,\
	`minutes` int(11) NOT NULL DEFAULT 0,\
	`seconds` int(11) NOT NULL DEFAULT 0,\
	`skin` smallint(6) NOT NULL DEFAULT 1,\
	`score` int(11) NOT NULL DEFAULT 0,\
	`money` int(11) NOT NULL DEFAULT 0,\
	`bank_money` int(11) NOT NULL DEFAULT 0,\
	`x` float NOT NULL,\
	`y` float NOT NULL,\
	`z` float NOT NULL,\
	`angle` float NOT NULL,\
	`interior` tinyint(4) NOT NULL DEFAULT 0,\
	PRIMARY KEY (`id`),\
	UNIQUE KEY `username` (`username`))");
	return 1;
}

// Commands

// Vehicle Commands
CMD:svehicle(playerid, params[])
{
	//if(Player[playerid][Admin] < 1) return 0;
	if(IsPlayerLoggedIn{playerid} == false) return SendClientMessage(playerid, COLOR_RED, "You Must Be Logged In To Use This Command.");
	if(!IsPlayerSpawned(playerid)) return SendClientMessage(playerid, COLOR_RED, "You Cannot Use This Command While Dead.");
	//if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "You Already Have A Vehicle.");
	new vname[32], color1, color2, siren;
	if(sscanf(params, "s[32]I(-1)I(-1)I(0)", vname, color1, color2, siren)) return SendClientMessage(playerid, COLOR_RED, "Usage: /svehicle (vehicle name / id)");
	//if(Iter_Count(Vehicle) == MAX_VEHICLES) return SendClientMessage(playerid, COLOR_RED, "Reached Vehicle Limit. Cannot Create More Vehicles.");

	new vehid = GetVehicleModelIDFromName(vname);
	if(vehid == -1)
	{
		vehid = strval(vname);
		if(vehid < 400 || vehid > 611) return SendClientMessage(playerid, COLOR_RED, "Invalid Vehicle ID.");
	}

	new Float:x, Float:y, Float:z, vehicleid;
	GetPlayerPos(playerid, x, y, z);
	vehicleid = CreateVehicle(vehid, x+1.0, y, z, 0.0, color1, color2, 180, siren);
	
	SetVehicleVirtualWorld(vehicleid, GetPlayerVirtualWorld(playerid));
	LinkVehicleToInterior(vehicleid, GetPlayerInterior(playerid));

	// Send message to online admins
	//new string[81];
	//format(string, sizeof(string), "*ADMIN: %s (%d) has spawned %s [id %d]", GetName(playerid), playerid, GetVehicleName(vehid), vehicleid);
	//AdminAction(playerid, STEALTH_OLIVE, string);

	new szVeh[77];
	format(szVeh, sizeof(szVeh), "You Have Spawned A Vehicle (For Non Admins) %s - ID %d", VehicleNames[vehid-400], vehid);
	SendClientMessage(playerid, BOB, szVeh);

	//new szLog[101];
	//format(szLog, sizeof(szLog), "%s (%d) has spawned a server (non admin) vehicle: %s  id %d", GetName(playerid), playerid, VehicleNames[vehid-400], vehid);
	//SaveIn("AdminCMDLog.txt", szLog);
	return 1;
}
CMD:sveh(playerid, params[]) return cmd_svehicle(playerid, params);
CMD:car(playerid, params[]) return cmd_svehicle(playerid, params);

CMD:vcolorlist(playerid, params[])
{
	//if(pInfo[playerid][Admin] == 0 && pInfo[playerid][sHelper] == 0) return 0;
	if(!IsPlayerSpawned(playerid)) return SendClientMessage(playerid, COLOR_RED, "You Cannot Use This Command While Dead.");
	if(!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "You Can Only Use This Command While Inside Of A Vehicle.");
	
	static color_list[3072];
	color_list[0] = EOS;

	for(new colorid; colorid != sizeof gVehicleColors; colorid++)
	{
		format(color_list, sizeof color_list, "%s{%06x}%03d%s", color_list, gVehicleColors[colorid] >>> 8, colorid, !((colorid + 1) % 16) ? ("\n") : (" "));
	}

	//ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Color List", color_list, "Close", "");
	Dialog_Show(playerid, "", DIALOG_STYLE_MSGBOX, "Color List", color_list, "Close", "");
	return 1;
}
CMD:vclist(playerid, params[]) return cmd_vcolorlist(playerid, params);

CMD:atestpos(playerid, params[])
{
	new Float:x, Float:y, Float:z, Float:a;
	if(sscanf(params, "p<,>fffF(0)", x, y, z, a)) return SendClientMessage(playerid, COLOR_RED, "USAGE: /tp x, y, z, a (Default Angle: 0.0)");

	SetPlayerPos(playerid, x, y, z);
	SetPlayerFacingAngle(playerid, a);
	new str[128];
	format(str, sizeof(str), "%f X,  %f Y,  %f Z,  A %f", x, y, z, a);
	SendClientMessage(playerid, COLOR_GREEN, str);
	return 1;
}
CMD:tp(playerid, params[]) return cmd_atestpos(playerid, params);

//===============  Anti Cheat Functions  =================
//-----  Server Side Money  --------------
stock GivePlayerCash(playerid, money)
{
    Cash[playerid] += money;
    ResetMoneyBar(playerid);//Resets the money in the original moneybar, Do not remove!
    UpdateMoneyBar(playerid,Cash[playerid]);//Sets the money in the moneybar to the serverside cash, Do not remove!
    return Cash[playerid];
}

stock SetPlayerCash(playerid, money)
{
    Cash[playerid] = money;
    ResetMoneyBar(playerid);//Resets the money in the original moneybar, Do not remove!
    UpdateMoneyBar(playerid,Cash[playerid]);//Sets the money in the moneybar to the serverside cash, Do not remove!
    return Cash[playerid];
}

stock ResetPlayerCash(playerid)
{
    Cash[playerid] = 0;
    ResetMoneyBar(playerid);//Resets the money in the original moneybar, Do not remove!
    UpdateMoneyBar(playerid,Cash[playerid]);//Sets the money in the moneybar to the serverside cash, Do not remove!
    return Cash[playerid];
}

stock GetPlayerCash(playerid)
{
    return Cash[playerid];
}

AntiDeAMX()
{
    new a[][] = {
        "Unarmed (Fist)",
        "Brass K"
    };
    #pragma unused a
}