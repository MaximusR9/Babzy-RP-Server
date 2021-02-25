/*


		.oooooo.     .oooooo.   oooooooooooo
	   d8P'  `Y8b   d8P'  `Y8b  `888'     `8
	  888      888 888      888  888
	  888      888 888      888  888oooo8
	  888      888 888      888  888    "
	  `88b    d88' `88b    d88'  888
	   `Y8bood8P'   `Y8bood8P'  o888o


	  Functions
*/

//////////////////////////////////
// Macros
//////////////////////////////////
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

//------------  Interiors  ------------------------
#define DEFAULT_INTERIOR	0
#define VICE_STADIUM		16

//---------------  SHOP Defines for IsPlayerInShop var  ----------------
#define SHOP_NONE			-1
#define SHOP_DRBAR			0
#define SHOP_PCBANK			1
#define SHOP_SFGYM			2
#define SHOP_BSSHOP			3
#define SHOP_FCBANK			4
#define SHOP_FCSHOP			5
#define SHOP_FC24			6
#define SHOP_PC24B			7
#define SHOP_PC24 			8
#define SHOP_VM				9
#define SHOP_OOFVILLA		10
#define SHOP_OOFMANSION		11
#define SHOP_APAMMU			12
#define SHOP_LVBANK			13
#define SHOP_LSCH			14
#define SHOP_SFCH			15
#define SHOP_LVCH			16
#define SHOP_LSAMMU			17
#define SHOP_SFAMMU			18
#define SHOP_LVAMMU			19
#define SHOP_LSPD			20

//---------  Virtual Worlds  ---------  Usefull for House system
#define DEFAULT_WORLD		0
#define DRBAR_WORLD			50
#define BSSHOP_WORLD		51
#define APAMMU_WORLD		52
#define SFGYM_WORLD			53
#define PCBANK_WORLD		54
#define FCBANK_WORLD		55
#define PC24BOB_WORLD		56
#define PC24_WORLD			57
#define VMEADOWS_WORLD		58
#define FCSHOP_WORLD		59
#define FC24_WORLD			60
#define BC24_WORLD			61
#define BBVILLA_WORLD		62
#define LVBANK_WORLD		63
#define OOFMANSION_WORLD	64
#define LSCH_WORLD			65
#define SFCH_WORLD			66
#define LVCH_WORLD			67
#define LSAMMU_WORLD		68
#define SFAMMU_WORLD		69
#define LVAMMU_WORLD		70
#define LSPD_WORLD			71

#define TDMS_WORLD			100
#define JDM_WORLD			101
#define CS_WORLD			102
#define CS2_WORLD			103
#define DEAGLE_WORLD 		104
#define DEAGLE2_WORLD		105
#define DERBY_WORLD			106
#define DMS_WORLD			107
#define GDM_WORLD			108
#define MINIGUN_WORLD		109
#define ONEPUNCH_WORLD		110
#define ROCKET_WORLD		111
#define SNIPER_WORLD		112
#define FDUEL_WORLD			2500
#define DUEL_WORLD 			4000 // Duel virtual world will start at 4000 (increase on /daccept)
#define CBUG_WORLD			6000
#define JAIL_WORLD			7161
#define ADMIN_WORLD			50104
#define OEDITOR_WORLD		70000

//----------  Defines for Shops pickup  --------------
#define DRBAR_ENTER			0
#define DRBAR_EXIT			1
#define SFGYM_ENTER			2
#define SFGYM_EXIT			3
#define PCBANK_ENTER		4
#define PCBANK_EXIT			5
#define FCBANK_ENTER		6
#define FCBANK_EXIT			7
#define FCSHOP_ENTER		8
#define FCSHOP_EXIT			9
#define FC24_ENTER			10
#define FC24_EXIT			11
#define BSSHOP_ENTER		12
#define BSSHOP_EXIT			13
#define APAMMU_ENTER		14
#define APAMMU_EXIT			15
#define PC24_ENTER			16
#define PC24_EXIT			17
#define PC24B_ENTER			18
#define PC24B_EXIT			19
#define VM_ENTER			20
#define VM_EXIT				21
#define BBVILLA_ENTER		22
#define BBVILLA_EXIT		23
#define LVBANK_ENTER		24
#define LVBANK_EXIT			25
#define OOFMANSION_A_ENTER	26
#define OOFMANSION_A_EXIT	27
#define OOFMANSION_B_ENTER	28
#define OOFMANSION_B_EXIT	29
#define LSCH_ENTER			30
#define LSCH_EXIT			31
#define SFCH_ENTER			32
#define SFCH_EXIT			33
#define LVCH_ENTER			34
#define LVCH_EXIT			35
#define LSAMMU_ENTER		36
#define LSAMMU_EXIT			37
#define SFAMMU_ENTER		38
#define SFAMMU_EXIT			39
#define LVAMMU_ENTER		40
#define LVAMMU_EXIT			41
#define LSPD_ENTER			42
#define LSPD_EXIT			43


//==============================================================================
//  Var
//==============================================================================
// Class Names - By Sky (concept/idea from cb cnr)
new SkinNames[][312] = {//TotaL 311 skins , 55 normal peds skins
"Carl Johnson", "Pothead", "Maccer", "Andre",// 0,1,2,3
"Skinny Guy", "Fat Guy", "Emmet", "Street Thug",// 4,5,6,7
"Janitor", "Business Woman", "Old Grandma", "Blackjack Dealer",// 8,9,10,11
"Gold Digger", "Gangsta Girl", "Old Man", "Mr. Whittaker",//12,13,14,15
"Airport Worker", "Buisness Man", "Beach Guy" ,"DJ Rapper", "Rich Guy", "Gangsta",// 16-21
"Street Thug", "Skater", "Gangsta", "Gangsta", "Backpacker", "Construction Worker",// 22-27
"Drug Dealer", "Drug Dealer", "Drug Dealer", "Cowboy Grandma", "Fisherman", "Kidnapper", "Cowboy",// 28-34
"Gardener", "Golfer", "Golfer", "Happy Grandma", "Happy Grandma", "Jewel Thief",// 35-40
"Drug Dealer", "Jethro", "Gambler", "Offender", "Beach Guy", "Loan Shark", "Gangster",// 41-47
"Immigrant", "Snakehead", "Mechanic", "Mountain Biker", "Mountain Biker", "Grandma", "Grandma",// 48-54
"Gold Digger", "Gangsta Girl", "Business Man", "Store Clerk", "Man Whore", "Street Racer", "Pilot",// 55-61
"Colonel Fuhrberger", "Crack Whore", "Crack Whore", "Gangsta Girl", "Gangster", "Bouncer", "Priest", // 62-68
"Social Worker", "Scientist", "Police Pilot", "Pothead", "Vigilante",// 69-73
"INVALID SKIN", "Prostitute", "Contract Killer", "Bad Lady", "Hobo", "Hobo",// 75-79 skin id 74 is invalid remove it
"Boxer", "Boxer", "Black Elvis", "White Elvis", "Blue Elvis", "Private Escort", "Ryder Gangsta", "Stripper",// 80-87
"Happy Grandma", "Cranky Grandma", "Slut", "Rich Woman", "Skater", "Jewel Thief",// 88-93
"Retired Old Man", "Mentally ill)", "Sports Buff", "Lifeguard", "Man Whore", "Skater",// 94-99
"Biker", "Pusher", "Gang Member", "Gang Member", "Gang Member", "Gang Member", "Gang Member",// 100-106
"Gang Member", "Gang Member", "Gang Member", "Gang Member", "Mafia Boss", "Contract Killer",// 107-112
"Drug Lord", "Gang Member", "Gang Member", "Gang Member", "Traid Hitmen", "Triad Hitmen", // 113-118
"Sindacco", "Triad Hitmen", "Vigilante", "Vigilante", "Pusher", "Bouncer", "Bank Robber", "Traid Mafia",// 119-126
"Contract Killer", "Farmer", "Farm Old Lady", "Old Lady", "Farmer Girl", "Old Hippy", "Trucker",// 127-133
"Hobo", "Mentally ill", "Pothead", "Mentally ill", "Beach Girl", "Beach Girl", "Beach Girl",// 134-140
"Contract killer", "Pothead", "Gangsta", "Hospital Worker", "Bikini Girl", "Beach Guy",// 141-146
"Buisnessman", "BuisnessWoman", "Big Smoke Armored", "Jewel Thief", "Fat Girl", "Prostitute",// 147-152
"Engineer", "Beach Guy", "Food Delivery", "Barber", "Hillbilly", "Farmer", "Yokel",// 153-159
"Yokel", "Redneck", "Mentally ill", "Secret Service", "Secret Service", "C.I.A agent", "C.I.A Agent",// 160-166
"Food Delivery", "Food Vendor", "Pusher", "Street Racer", "Blackjack Dealer", "Blackjack Dealer",// 167-172
"Gangster", "Gangster", "Gangster", "Gangsta", "White Rapper", "Stripper", "Gun Nut",// 173-179
"Street Racer", "Punk Addict", "Car Salesman", "Crack Head", "Pusher", "Jewel Thief",// 180-185
"Arms Importer", "Buisness Man", "Street Racer", "Casino Worker", "Barbara", "Gangsta Girl",// 186-191
"Vigilante", "Gangsta Girl", "Blackjack Dealer", "Gangsta Girl", "Crazy Grandma", "Redneck Grandma",// 192-197
"Redneck Girl", "Crazy Yokel", "Crazy Yokel", "Farmer Girl", "Trucker", "Karate Teacher",// 198-203
"Karate Teacher", "Food Delivery", "Bouncer", "Fat Stripper", "Su Xi Mu", "Food Delivery",// 204-209
"Store Clerk", "Staff Member",// 210-211
"Mentally ill", "Gambler", "Private Escort", "Jewel Thief", "Contract Killer", "Staff Member",// 212-217
"Grandma", "Rich Woman", "Pothead", "Store Clerk", "Store Clerk", "Contract Killer", "News Reporter",// 218-224
"Store Clerk", "Gangsta Girl", "Buisness Man", "Business Man", "Business Man", // 225-229
"Pothead Hobo", "Grandma", "Crazy Grandma", "Gold Digger", "Taxi Driver", "Old Man", "Crazy Old Man",// 230-236
"Prostitute", "Crack Whore", "Hobo", "The D.A", "Fat Gangster", "Fat Gangster", "Fat Stripper",// 237-243
"Stripper", "Fat Girl", "Stripper", "Biker", "Biker", "Pimp", "Street Racer", "Beach Lady",// 244-251
"Man Whore", "Bus Driver", "Biker", "Limo Driver", "Prostitue", "Stripper", "fat Guy", "Fat Guy",// 252-259
"Construction Worker", "Trucker", "Car Salesman", "Jewel Thief", "Clown",// 260-264
"Officer Tenpenny", "Officer Pulaski", "Officer Hernandez", "Dwayne", "Big Smoke",// 265-269
"Sweet Johnson", "Ryder Wilson", "Mafia Boss", "Drug Importer", "Paramedic", "Paramedic",// 270-275
"Paramedic", "Firefighter", "Firefighter", "Firefighter", "Police Officer",// 276-280
"Police Officer", "Police Officer", "County Sheriff", "Police Special Unit",// 281-284
"S.W.A.T Team", "F.B.I Agent", "Police Technician", "Country Sheriff", "Zero",// 285-289
"Ken Rosenberg", "Kent Paul", "Cesar Vialpando", "OG LOC", "Wu Zi Mu (Woozie)",// 290-294
"Toreno", "Jizzy", "Madd Dogg", "Catalina", "Claude Speed",// 295-300
"Police Officer", "Police Officer", "Police Officer", "Off Duty Cop", "Off Duty Cop", "Off Duty Cop",// 300-305
"Police Officer", "Police Officer", "Paramedic", "County Sheriff", // 306,307,308,309
"Police Officer", "Police Officer" // 310, 311
};
//-----------------------------------------------------------------------------<
// Vehicle Names - Betamaster
new VehicleNames[212][] = {
{"Landstalker"},{"Bravura"},{"Buffalo"},{"Linerunner"},{"Perrenial"},{"Sentinel"},{"Dumper"},
{"Firetruck"},{"Trashmaster"},{"Stretch"},{"Manana"},{"Infernus"},{"Voodoo"},{"Pony"},{"Mule"},
{"Cheetah"},{"Ambulance"},{"Leviathan"},{"Moonbeam"},{"Esperanto"},{"Taxi"},{"Washington"},
{"Bobcat"},{"Mr Whoopee"},{"BF Injection"},{"Hunter"},{"Premier"},{"Enforcer"},{"Securicar"},
{"Banshee"},{"Predator"},{"Bus"},{"Rhino"},{"Barracks"},{"Hotknife"},{"Trailer 1"},{"Previon"},
{"Coach"},{"Cabbie"},{"Stallion"},{"Rumpo"},{"RC Bandit"},{"Romero"},{"Packer"},{"Monster"},
{"Admiral"},{"Squalo"},{"Seasparrow"},{"Pizzaboy"},{"Tram"},{"Trailer 2"},{"Turismo"},
{"Speeder"},{"Reefer"},{"Tropic"},{"Flatbed"},{"Yankee"},{"Caddy"},{"Solair"},{"Berkley's RC Van"},
{"Skimmer"},{"PCJ-600"},{"Faggio"},{"Freeway"},{"RC Baron"},{"RC Raider"},{"Glendale"},{"Oceanic"},
{"Sanchez"},{"Sparrow"},{"Patriot"},{"Quad"},{"Coastguard"},{"Dinghy"},{"Hermes"},{"Sabre"},
{"Rustler"},{"ZR-350"},{"Walton"},{"Regina"},{"Comet"},{"BMX"},{"Burrito"},{"Camper"},{"Marquis"},
{"Baggage"},{"Dozer"},{"Maverick"},{"News Chopper"},{"Rancher"},{"FBI Rancher"},{"Virgo"},{"Greenwood"},
{"Jetmax"},{"Hotring"},{"Sandking"},{"Blista Compact"},{"Police Maverick"},{"Boxville"},{"Benson"},
{"Mesa"},{"RC Goblin"},{"Hotring Racer A"},{"Hotring Racer B"},{"Bloodring Banger"},{"Rancher"},
{"Super GT"},{"Elegant"},{"Journey"},{"Bike"},{"Mountain Bike"},{"Beagle"},{"Cropdust"},{"Stunt"},
{"Tanker"}, {"Roadtrain"},{"Nebula"},{"Majestic"},{"Buccaneer"},{"Shamal"},{"Hydra"},{"FCR-900"},
{"NRG-500"},{"HPV1000"},{"Cement Truck"},{"Tow Truck"},{"Fortune"},{"Cadrona"},{"FBI Truck"},
{"Willard"},{"Forklift"},{"Tractor"},{"Combine"},{"Feltzer"},{"Remington"},{"Slamvan"},
{"Blade"},{"Freight"},{"Streak"},{"Vortex"},{"Vincent"},{"Bullet"},{"Clover"},{"Sadler"},
{"Firetruck LA"},{"Hustler"},{"Intruder"},{"Primo"},{"Cargobob"},{"Tampa"},{"Sunrise"},{"Merit"},
{"Utility"},{"Nevada"},{"Yosemite"},{"Windsor"},{"Monster A"},{"Monster B"},{"Uranus"},{"Jester"},
{"Sultan"},{"Stratum"},{"Elegy"},{"Raindance"},{"RC Tiger"},{"Flash"},{"Tahoma"},{"Savanna"},
{"Bandito"},{"Freight Flat"},{"Streak Carriage"},{"Kart"},{"Mower"},{"Duneride"},{"Sweeper"},
{"Broadway"},{"Tornado"},{"AT-400"},{"DFT-30"},{"Huntley"},{"Stafford"},{"BF-400"},{"Newsvan"},
{"Tug"},{"Trailer 3"},{"Emperor"},{"Wayfarer"},{"Euros"},{"Hotdog"},{"Club"},{"Freight Carriage"},
{"Trailer 3"},{"Andromada"},{"Dodo"},{"RC Cam"},{"Launch"},{"Police Car (LSPD)"},{"Police Car (SFPD)"},
{"Police Car (LVPD)"},{"Police Ranger"},{"Picador"},{"S.W.A.T. Van"},{"Alpha"},{"Phoenix"},{"Glendale"},
{"Sadler"},{"Luggage Trailer A"},{"Luggage Trailer B"},{"Stair Trailer"},{"Boxville"},{"Farm Plow"},
{"Utility Trailer"}
};
//-----------------------------------------------------------------------------<
// Weapon Names
new const WeaponNames[48][32] = {
	{"Unarmed (Fist)"}, // 0
	{"Brass Knuckles"}, // 1
	{"Golf Club"}, // 2
	{"Night Stick"}, // 3
	{"Knife"}, // 4
	{"Baseball Bat"}, // 5
	{"Shovel"}, // 6
	{"Pool Cue"}, // 7
	{"Katana"}, // 8
	{"Chainsaw"}, // 9
	{"Purple Dildo"}, // 10
	{"Big White Vibrator"}, // 11
	{"Medium White Vibrator"}, // 12
	{"Small White Vibrator"}, // 13
	{"Flowers"}, // 14
	{"Cane"}, // 15
	{"Grenade"}, // 16
	{"Teargas"}, // 17
	{"Molotov"}, // 18
	{"Vehicle Gun"}, // 19
	{"Vehicle Gun"}, // 20
	{" "}, // 21
	{"Colt 45"}, // 22
	{"Colt 45 (Silenced)"}, // 23
	{"Desert Eagle"}, // 24
	{"Normal Shotgun"}, // 25
	{"Sawnoff Shotgun"}, // 26
	{"Combat Shotgun"}, // 27
	{"Micro Uzi (Mac 10)"}, // 28
	{"MP5"}, // 29
	{"AK47"}, // 30
	{"M4"}, // 31
	{"Tec9"}, // 32
	{"Country Rifle"}, // 33
	{"Sniper Rifle"}, // 34
	{"Rocket Launcher"}, // 35
	{"Heat-Seeking Rocket Launcher"}, // 36
	{"Flamethrower"}, // 37
	{"Minigun"}, // 38
	{"Satchel Charge"}, // 39
	{"Detonator"}, // 40
	{"Spray Can"}, // 41
	{"Fire Extinguisher"}, // 42
	{"Camera"}, // 43
	{"Night Vision Goggles"}, // 44
	{"Infrared Vision Goggles"}, // 45
	{"Parachute"}, // 46
	{"Fake Pistol"} // 47
};

// Weapon Data
enum E_WEAPON_DATA
{
	e_WeaponId,
	Float:e_WeaponDamage
}

new const s_WeaponInfo[][E_WEAPON_DATA] = {
	{0, 0.0},
	{1, 0.0},
	{2, 0.0},
	{3, 0.0},
	{4, 0.0},
	{5, 0.0},
	{6, 0.0},
	{7, 0.0},
	{8, 0.0},
	{9, 0.0},
	{10, 0.0},
	{11, 0.0},
	{12, 0.0},
	{13, 0.0},
	{14, 0.0},
	{15, 0.0},
	{16, 0.0},
	{17, 0.0},
	{18, 0.0},
	{19, 0.0},
	{20, 0.0},
	{21, 0.0},
	{22, 8.2500000000000000000},
	{23, 13.200000762939453125},
	{24, 46.200000762939453125},
	{25, 3.3},
	{26, 3.3},
	{27, 4.95},
	{28, 6.6000003814697265625},
	{29, 8.2500000000000000000},
	{30, 9.90000057220458984375},
	{31, 9.90000057220458984375},
	{32, 6.6000003814697265625},
	{33, 24.7500019073486328125},
	{34, 41.2500000000000000000}
};

//=======================================================================================
//  Stocks
//=======================================================================================
// Admin Stocks
//==============================  Hooks  ========================================

//-----------------------------------------------------------------------------<
//  Use VectorSize to calculate distance much better than floatsqroot, vectorsize is also faster.
stock Float:GetDistanceBetweenPointsI(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2)
{
    return VectorSize(x1-x2, y1-y2, z1-z2);
}

stock Float:GetDistanceBetweenPlayersI(pl1, pl2)
{
      new Float:pos[6];
      if(!IsPlayerConnected(pl1) || !IsPlayerConnected(pl2)) return -1.0;
      GetPlayerPos(pl1, pos[0], pos[1], pos[2]);
      GetPlayerPos(pl2, pos[3], pos[4], pos[5]);
      return VectorSize(pos[0]-pos[3],pos[1] - pos[4], pos[2]-pos[5]);
}

// ---- slower way of calculating distance --------
stock Float:GetDistanceBetweenPlayers(p1,p2)
{
    new Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2;
    if(!IsPlayerConnected(p1) || !IsPlayerConnected(p2))
    {
        return -1.00;
    }
    GetPlayerPos(p1,x1,y1,z1);
    GetPlayerPos(p2,x2,y2,z2);
    return floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));
}

stock Float:GetDistanceBetweenPoints(Float:rx1,Float:ry1,Float:rz1,Float:rx2,Float:ry2,Float:rz2)
{
	return floatadd(floatadd(floatsqroot(floatpower(floatsub(rx1,rx2),2)),floatsqroot(floatpower(floatsub(ry1,ry2),2))),floatsqroot(floatpower(floatsub(rz1,rz2),2)));
}

stock GetDistance( Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2 )
{
    return floatround( floatsqroot( ( ( x1 - x2 ) * ( x1 - x2 ) ) + ( ( y1 - y2 ) * ( y1 - y2 ) ) + ( ( z1 - z2 ) * ( z1 - z2 ) ) ) ) );
}

GetName(playerid)
{
    new szUsername[MAX_PLAYER_NAME + 1];
    GetPlayerName(playerid, szUsername, sizeof(szUsername));
    return szUsername;
}

stock IsPlayerSpawned(playerid)
{
	new statex = GetPlayerState(playerid);
	if(statex != PLAYER_STATE_NONE && statex != PLAYER_STATE_WASTED && statex != PLAYER_STATE_SPAWNED) return true;
	return false;
}

/*TeleportPlayer(playerid, Float:X, Float:Y, Float:Z, Float:A, interiorid, worldid) // By Sky
{
	SetPlayerPos(playerid, Float:X, Float:Y, Float:Z);
	SetPlayerFacingAngle(playerid, Float:A);
	SetPlayerInterior(playerid, interiorid);
	SetPlayerVirtualWorld(playerid, worldid);
	SetCameraBehindPlayer(playerid);
}*/

SendClientMessageToAllEx(exception, color, const message[]) // Send client message to all except - By Eagle
{
	//for(new i = 0; i < MAX_PLAYERS; i++)
	for(new i = 0, j = GetPlayerPoolSize(); i <= j; i++)
	{
		if(IsPlayerConnected(i))
		{
			if(i != exception)
			{
				SendClientMessage(i, color, message);
			}
		}
	}
}

// Usage SCMToAllInArea(DM_DEAGLE, -1, "Test");
stock SCMToAllInArea(area, color, const message[])
{
	for(new i = 0, j = GetPlayerPoolSize(); i <= j; i++)
	{
		if(!IsPlayerConnected(i)) continue;
		switch(area)
		{
			//case DM_DEAGLE: if(g_InDM{i} == DM_DEAGLE) SendClientMessage(i, color, message);
		}
	}
}

stock closestdeadguy(playerid) // By cessil
{
	new Float:ix,Float:iy,Float:iz;
	new id = -1;
	for(new i=0;i<MAX_PLAYERS;i++)
	{
		if(IsPlayerConnected(i))
		{
			if(!IsPlayerSpawned(i))
			{
				GetPlayerPos(i,ix,iy,iz);
				if(IsPlayerInRangeOfPoint(playerid,3.0,ix,iy,iz)) id = i;
			}
		}
	}
	return id;
}

stock SendToJail(playerid, jail) // By Me (Eagle)
{
	switch(jail)
	{
	    case 0:// case 0 = jail 0 is for LS Jail, Use LS Jail for Bans
	    {
	        SetPlayerPos(playerid, 264.8282,77.5187,1001.0391);
			SetPlayerFacingAngle(playerid, 269.4966);
			SetPlayerInterior(playerid, 6);
	    }
	    case 1:// case 1 is for SF Jail, Use SF Jail for Kicks
	    {
	        new randSF = random(4);
	        switch(randSF)
	        {
	            case 0:{ SetPlayerPos(playerid, 215.5656,110.3724,999.0156); SetPlayerFacingAngle(playerid, 0.3046); }
	            case 1:{ SetPlayerPos(playerid, 219.4608,109.9365,999.0156); SetPlayerFacingAngle(playerid, 359.4897); }
	            case 2:{ SetPlayerPos(playerid, 223.5364,110.5552,999.0156); SetPlayerFacingAngle(playerid, 0.7430); }
	            case 3:{ SetPlayerPos(playerid, 228.6532,110.4232,999.0156); SetPlayerFacingAngle(playerid, 1.9963); }
			}
			SetPlayerInterior(playerid, 10);
	    }
	    case 2:// case 1 is for LV Jail, Use LV Jail for Account Disables
	    {
	        switch(random(3))
	        {
	            case 0:{ SetPlayerPos(playerid, 215.5656,110.3724,999.0156); SetPlayerFacingAngle(playerid, 0.3046); }
	            case 1:{ SetPlayerPos(playerid, 219.4608,109.9365,999.0156); SetPlayerFacingAngle(playerid, 359.4897); }
	            case 2:{ SetPlayerPos(playerid, 223.5364,110.5552,999.0156); SetPlayerFacingAngle(playerid, 0.7430); }
	            case 3:{ SetPlayerPos(playerid, 228.6532,110.4232,999.0156); SetPlayerFacingAngle(playerid, 1.9963); }
			}
			SetPlayerInterior(playerid, 10);
	    }
	}
	SetPlayerVirtualWorld(playerid, JAIL_WORLD);
	SetCameraBehindPlayer(playerid);
	return 1;
}

stock GetVehicleSpeed(vehicleid)
{
    new
        Float: X,
        Float: Y,
        Float: Z
    ;

    if(GetVehicleVelocity(vehicleid, X, Y, Z))
        return floatround(floatsqroot((X * X) + (Y * Y) + (Z * Z)) * 190);

    return 0;
}

stock GetVehicleSpeedMPH(vehicleid)
{
	new Float:x, Float:y, Float:z;
	
	if(GetVehicleVelocity(vehicleid, x, y, z))
		return floatround(floatsqroot(X * X + Y * Y + Z * Z) * 180 / 1.609344);
		
	return 0;
}

stock Float:GetVehicleSpeedRC(vehicleid, UseMPH) //(RealCop228) not sure who made this
{
	new Float:speed_x,Float:speed_y,Float:speed_z,Float:temp_speed;
	GetVehicleVelocity(vehicleid,speed_x,speed_y,speed_z);
	if(UseMPH == 0) temp_speed = floatsqroot(((speed_x*speed_x)+(speed_y*speed_y))+(speed_z*speed_z))*136.666667;
	else temp_speed = floatsqroot(((speed_x*speed_x)+(speed_y*speed_y))+(speed_z*speed_z))*85.4166672;
	floatround(temp_speed,floatround_round);
	return temp_speed;
}

stock DeleteWeaponsOnSlot(playerid, weapon1, weapon2, type = 1)
{
	new query[128];
	switch(type)
	{
		case 1:
		{
			mysql_format(MySQL, query, sizeof(query), "DELETE FROM `player_weapons` WHERE `ID` = %d AND `weaponid` = %d AND %d", pInfo[playerid][ID], weapon1, weapon2);
			mysql_tquery(MySQL, query, "", "");
		}
		case 2:
		{
			mysql_format(MySQL, query, sizeof(query), "DELETE FROM `player_weapons` WHERE `ID` = %d AND `weaponid` = %d", pInfo[playerid][ID], weapon1);
			mysql_tquery(MySQL, query, "", "");
		}
	}
}

stock IsValidSkin(skinid)
{
    return (0 <= skinid <= 311) && skinid != 74;
}

stock IsInValidSkin(skinid) // By Eagle (Me)
{
    switch(skinid)
	{
		//case 0,3,4,5,6,65,86,92,96,99,149,208,217,269..271,289..297,299: return true;
		case 0,74,92,99,211,217,270,292..294,297..299: return true;
	}
    return false;
}

stock GetSkinGender(skinid)
{
	switch(skinid)
	{
		case 0..8, 14..30, 32..38, 42..52, 57..62, 66..68, 70..74, 78..84, 86, 94..128, 132..137, 142..144, 146, 147, 149, 153..156, 158..168, 170, 171, 173..177, 179..189, 200, 202..204, 206..210, 212, 213, 217, 220.223, 227..230, 234..236, 239..242, 247..250, 252..255, 258..262, 264..297, 299: return 0;
		default: return 1;
	}
	return 1;
}

stock IsValidAdminCar(vehicleid) // By Sky
{
	switch(vehicleid)
	{
		case 411,415,429,451,494,502,503,504,541,603: return false;
	}
	return true;
}

stock IsPlayerInWater(playerid)
{
	new anim = GetPlayerAnimationIndex(playerid);
 	if(((anim >=  1538) && (anim <= 1542)) || (anim == 1544) || (anim == 1250) || (anim == 1062)) return true;
  	return false;
}

stock IsPlayerInInvalidNosVehicle(playerid)//Credits to Donya
{
    new vehicleid = GetPlayerVehicleID(playerid);
    #define MAX_INVALID_NOS_VEHICLES 52
    new InvalidNosVehicles[MAX_INVALID_NOS_VEHICLES] =
    {
        581,523,462,521,463,522,461,448,468,586,417,425,469,487,512,520,563,593,
        509,481,510,472,473,493,520,595,484,430,453,432,476,497,513,533,577,
        452,446,447,454,590,569,537,538,570,449,519,460,488,511,519,548,592
    };
    if(IsPlayerInAnyVehicle(playerid))
    {
        for(new i = 0; i < MAX_INVALID_NOS_VEHICLES; i++)
        {
            if(GetVehicleModel(vehicleid) == InvalidNosVehicles[i]) return true;
        }
    }
    return false;
}

GetVehicleModelIDFromName(vname[]) // from fsdebug filterscript
{
	for(new i = 0; i < 211; i++)
	{
		if(strfind(VehicleNames[i], vname, true) != -1) return i + 400;
	}
	return -1;
}

stock GetWeaponModelIDFromName(wname[])
{
	for(new i = 0; i < 48; i++) {
		if (i == 19 || i == 20 || i == 21) continue;
		if (strfind(WeaponNames[i], wname, true) != -1) {
			return i;
		}
	}
	return -1;
}

SSCANF:vehicles(string[])
{
	// if the string is numeric, check for valid vehicle modelid
	if ('0' <= string[0] <= '9')
	{
		new ret = strval(string);
		if (400 <= ret <= 611)
		{
			return ret;
		}
	}
	// or if the vehicle name or match is entered, check for the nearest vehicle name
	else
	{
		for(new i = 0; i < 211; i++)
		{
			if (strfind(VehicleNames[i], string, true) != -1)
			{
				return i + 400;
			}
		}
	}
	return -1;
}

//---------------------------------------------
// GetNumberOfPlayersOnThisIP
// Returns the number of players connecting from the
// provided IP address
stock GetNumberOfPlayersOnThisIP(test_ip[])
{
	new against_ip[16];
	new ip_count = 0;
	for(new x = 0; x < MAX_PLAYERS; x++) {
		if(IsPlayerConnected(x)) {
		    GetPlayerIp(x, against_ip, 16);
		    if(!strcmp(against_ip, test_ip)) ip_count++;
		}
	}
	return ip_count;
}

stock GetPlayersOnline()
{
	new count;
	for(new x = 0; x < MAX_PLAYERS; x++)
	{
		if(IsPlayerConnected(x))
		{
			if(!IsPlayerNPC(x))
			{
				count++;
			}
		}
	}
	return count;
}

stock ReturnWeaponName(weaponid)
{
	new name[sizeof(WeaponNames[])];

	if(weaponid < 0 || weaponid >= sizeof(WeaponNames))
	{
		format(name, sizeof(name), "Weapon %d", weaponid);
	}
	else
	{
		format(name, sizeof(name), "%s", WeaponNames[weaponid]);
	}
	return name;
}

stock RemovePlayerWeapon(playerid, ...)
{
    new iArgs = numargs();
    while(--iArgs)
	{
		SetPlayerAmmo(playerid, getarg(iArgs), 0);
    }
}

stock minrand(min, max) //By Alex "Y_Less" Cole
{
    return random(max - min) + min;
}

Convert_Time(seconds) // Convert Seconds to Minutes and Seconds - By Maximus
{
	new minutes = floatround(seconds / 60, floatround_floor);
	new remainder = seconds % 60;

	new string[7];
	switch(minutes)
	{
		case 0..9:
		{
			switch(remainder)
			{
				case 0..9: format(string, sizeof(string), "0%d:0%d", minutes, remainder);
				default: format(string, sizeof(string), "0%d:%d", minutes, remainder);
			}
		}
		default:
		{
			switch(remainder)
			{
				case 0..9: format(string, sizeof(string), "%d:0%d", minutes, remainder);
				default: format(string, sizeof(string), "%d:%d", minutes, remainder);
			}
		}
	}
	return string;
}

stock timestamp() //By Y-Less
{
	new h,m,s,d,n,y;
	gettime(h, m, s);
	getdate(y, n, d);
	return maketime(h, m, s, d, n, y);
}

stock maketime(hour, minute, second, day, month, year) //By Y-Less
{
	static days_of_month[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	static lMinute,	lHour,lDay,lMonth, lYear, lMinuteS, lHourS, lDayS, lMonthS, lYearS;
	if (year != lYear)
	{
		lYearS = 0;
		for (new j = 1970; j < year; j++)
		{
			lYearS += 31536000;
			if ((!(j % 4) && (j % 100)) || !(j % 400)) lYearS += 86400;
		}
		lYear = year;
	}
	if (month != lMonth)
	{
		lMonthS = 0;
		month--;
		for (new i = 0; i < month; i++)
		{
			lMonthS += days_of_month[i] * 86400;
			if ((i == 1) && ((!(year % 4) && (year % 100)) || !(year % 400))) lMonthS += 86400;
		}
		lMonth = month;
	}
	if (day != lDay)
	{
		lDayS = day * 86400;
		lDay = day;
	}
	if (hour != lHour)
	{
		lHourS = hour * 3600;
		lHour = hour;
	}
	if (minute != lMinute)
	{
		lMinuteS = minute * 60;
		lMinute = minute;
	}
	return lYearS + lMonthS + lDayS + lHourS + lMinuteS + second;
}

stock SecondsToTime(value)
{
	new processedstring[64];
	if(value >= 19327352831)
	{
		processedstring = "NULL (int+INFINITY)";
		return processedstring;
	}

	if(value < 60)
	{
	    if(value < 2)
        	format(processedstring,sizeof(processedstring),"%d Second",value);
        else
        	format(processedstring,sizeof(processedstring),"%d Seconds",value);
	}
    else if(value < 60 * 60)
    {
       	if(value / 60 < 2)
       	{
       		format(processedstring,sizeof(processedstring),"1 Minute");
			if(value - ((value / 60) * 60) > 0)
				format(processedstring,sizeof(processedstring),"1 Minute, %d Seconds",value - ((value / 60) * 60));

		}
		else
		{
	    	if(value - ((value / 60) * 60) > 0)
				format(processedstring,sizeof(processedstring),"%d Minutes, %d Seconds",value / 60, value - ((value / 60) * 60));
			else
   				format(processedstring,sizeof(processedstring),"%d Minutes", value / 60);
		}
	}
    else if(value < 60 * 60 * 24)
    {
        if(value / (60 * 60) < 2)
        {
        	format(processedstring,sizeof(processedstring),"%d Hour",value / (60 * 60));
			if(((value / 60) - 60) > 0)
                format(processedstring,sizeof(processedstring),"%s, %d Minutes",processedstring, ((value / 60) - 60));
			if(value - ((value / 60) * 60) > 0)
			    format(processedstring,sizeof(processedstring),"%s, %d Seconds",processedstring, value - ((value / 60) * 60));
		}
		else
		{
        	format(processedstring,sizeof(processedstring),"%d Hours",value / (60 * 60));
            if(((value / 60) - 60 * (value / (60 * 60))) > 0)
                format(processedstring,sizeof(processedstring),"%s, %d Minutes",processedstring, ((value / 60) - 60 * (value / (60 * 60))) );
			if(value - ((value / 60) * 60) > 0)
			    format(processedstring,sizeof(processedstring),"%s, %d Seconds",processedstring, value - ((value / 60) * 60));
		}
	}
	else if(value < 60 * 60 * 24 * 30)
    {
        if(value / (60 * 60 * 24) < 2)
        {
            format(processedstring,sizeof(processedstring),"1 Day");
            if(value / (60 * 60) - (24*(value / (60 * 60 * 24))) > 0)
        		format(processedstring,sizeof(processedstring),"%s, %d Hours",processedstring, value / (60 * 60) - (24*(value / (60 * 60 * 24))) );
			if( ((value / 60) - 60 * (value / (60 * 60))) > 0)
                format(processedstring,sizeof(processedstring),"%s, %d Minutes",processedstring, (value / 60) - (60*(value / (60 * 60))));
			if(value - ((value / 60) * 60) > 0)
			    format(processedstring,sizeof(processedstring),"%s, %d Seconds",processedstring, value - ((value / 60) * 60));
		}
		else
		{
		    format(processedstring,sizeof(processedstring),"%d Days",value / (60 * 60 * 24));
		    if(value / (60 * 60) - (24*(value / (60 * 60 * 24))) > 0)
        		format(processedstring,sizeof(processedstring),"%s, %d Hours",processedstring, value / (60 * 60) - (24*(value / (60 * 60 * 24))));
			if( ((value / 60) - 60 * (value / (60 * 60))) > 0)
                format(processedstring,sizeof(processedstring),"%s, %d Minutes",processedstring, ((value / 60) - 60 * (value / (60 * 60))) );
			if(value - ((value / 60) * 60) > 0)
			    format(processedstring,sizeof(processedstring),"%s, %d Seconds",processedstring, value - ((value / 60) * 60));
		}
	}
	else if(value < 60 * 60 * 24 * 30 * 12)
    {
        if(value / (60 * 60 * 24) < 2)
        {
            format(processedstring,sizeof(processedstring),"1 Month");
            if(value / (60 * 60 * 24) - (30*(value / (60 * 60 * 24 * 30))) > 0)
          	 	format(processedstring,sizeof(processedstring),"%s, %d Days",processedstring, value / (60 * 60 * 24) - (30*(value / (60 * 60 * 24 * 30))));
            if(value / (60 * 60) - (24*(value / (60 * 60 * 24))) > 0)
        		format(processedstring,sizeof(processedstring),"%s, %d Hours",processedstring, value / (60 * 60) - (24*(value / (60 * 60 * 24))) );
			if( ((value / 60) - 60 * (value / (60 * 60))) > 0)
                format(processedstring,sizeof(processedstring),"%s, %d Minutes",processedstring, (value / 60) - (60*(value / (60 * 60))));
			if(value - ((value / 60) * 60) > 0)
			    format(processedstring,sizeof(processedstring),"%s, %d Seconds",processedstring, value - ((value / 60) * 60));
		}
		else
		{
		    format(processedstring,sizeof(processedstring),"%d Months",value / (60 * 60 * 24 * 30));
		    if(value / (60 * 60 * 24) - (30*(value / (60 * 60 * 24 * 30))) > 0)
          	 	format(processedstring,sizeof(processedstring),"%s, %d Days",processedstring, value / (60 * 60 * 24) - (30*(value / (60 * 60 * 24 * 30))));
		    if(value / (60 * 60) - (24*(value / (60 * 60 * 24))) > 0)
        		format(processedstring,sizeof(processedstring),"%s, %d Hours",processedstring, value / (60 * 60) - (24*(value / (60 * 60 * 24))));
			if( ((value / 60) - 60 * (value / (60 * 60))) > 0)
                format(processedstring,sizeof(processedstring),"%s, %d Minutes",processedstring, ((value / 60) - 60 * (value / (60 * 60))) );
			if(value - ((value / 60) * 60) > 0)
			    format(processedstring,sizeof(processedstring),"%s, %d Seconds",processedstring, value - ((value / 60) * 60));
		}
	}
	else
    {
        if(value / (60 * 60 * 24 * 30 * 12) < 2)
        {
            format(processedstring,sizeof(processedstring),"1 Year");
            if(value / (60 * 60 * 24 * 30) - (12*(value / (60 * 60 * 24 * 30 * 12))) > 0)
          	 	format(processedstring,sizeof(processedstring),"%s, %d Months",processedstring, value / (60 * 60 * 24 * 30) - (12*(value / (60 * 60 * 24 * 30 * 12))));
            if(value / (60 * 60 * 24) - (30*(value / (60 * 60 * 24 * 30))) > 0)
          	 	format(processedstring,sizeof(processedstring),"%s, %d Days",processedstring, value / (60 * 60 * 24) - (30*(value / (60 * 60 * 24 * 30))));
            if(value / (60 * 60) - (24*(value / (60 * 60 * 24))) > 0)
        		format(processedstring,sizeof(processedstring),"%s, %d Hours",processedstring, value / (60 * 60) - (24*(value / (60 * 60 * 24))) );
			if( ((value / 60) - 60 * (value / (60 * 60))) > 0)
                format(processedstring,sizeof(processedstring),"%s, %d Minutes",processedstring, (value / 60) - (60*(value / (60 * 60))));
			if(value - ((value / 60) * 60) > 0)
			    format(processedstring,sizeof(processedstring),"%s, %d Seconds",processedstring, value - ((value / 60) * 60));
		}
		else
		{
		    format(processedstring,sizeof(processedstring),"%d Years",value / (60 * 60 * 24 * 30 * 12));
            if(value / (60 * 60 * 24 * 30) - (12*(value / (60 * 60 * 24 * 30 * 12))) > 0)
          	 	format(processedstring,sizeof(processedstring),"%s, %d Months",processedstring, value / (60 * 60 * 24 * 30) - (12*(value / (60 * 60 * 24 * 30 * 12))));
		    if(value / (60 * 60 * 24) - (30*(value / (60 * 60 * 24 * 30))) > 0)
          	 	format(processedstring,sizeof(processedstring),"%s, %d Days",processedstring, value / (60 * 60 * 24) - (30*(value / (60 * 60 * 24 * 30))));
		    if(value / (60 * 60) - (24*(value / (60 * 60 * 24))) > 0)
        		format(processedstring,sizeof(processedstring),"%s, %d Hours",processedstring, value / (60 * 60) - (24*(value / (60 * 60 * 24))));
			if( ((value / 60) - 60 * (value / (60 * 60))) > 0)
                format(processedstring,sizeof(processedstring),"%s, %d Minutes",processedstring, ((value / 60) - 60 * (value / (60 * 60))) );
			if(value - ((value / 60) * 60) > 0)
			    format(processedstring,sizeof(processedstring),"%s, %d Seconds",processedstring, value - ((value / 60) * 60));
		}
	}
	return processedstring;
}

stock IsMonth31(month)
{
 	switch (month)
	{
	    case 1: return 1;
	    case 3: return 1;
	    case 5: return 1;
	    case 7: return 1;
	    case 8: return 1;
	    case 10: return 1;
	    case 12: return 1;
	    default: return 0;
	}
	return 0;
}

stock IsMonth29(year)
{
 	new y = 2000;
 	for(new i = 4; i < 3000; i += 4) if ((y+i) == year) return 1;
 	return 0;
}

stock ConvertTime(&cts, &ctm=-1,&cth=-1,&ctd=-1,&ctw=-1,&ctmo=-1,&cty=-1)
{
    #define PLUR(%0,%1,%2) (%0),((%0) == 1)?((#%1)):((#%2))

    #define CTM_cty 31536000
    #define CTM_ctmo 2628000
    #define CTM_ctw 604800
    #define CTM_ctd 86400
    #define CTM_cth 3600
    #define CTM_ctm 60

    #define CT(%0) %0 = cts / CTM_%0; cts %= CTM_%0

    new strii[128];

    if(cty != -1 && (cts/CTM_cty))
    {
        CT(cty); CT(ctmo); CT(ctw); CT(ctd); CT(cth); CT(ctm);
        format(strii, sizeof(strii), "%d %s, %d %s, %d %s, %d %s, %d %s, %d %s, and %d %s",PLUR(cty,"year","years"),PLUR(ctmo,"month","months"),PLUR(ctw,"week","weeks"),PLUR(ctd,"day","days"),PLUR(cth,"hour","hours"),PLUR(ctm,"minute","minutes"),PLUR(cts,"second","seconds"));
        return strii;
    }
    if(ctmo != -1 && (cts/CTM_ctmo))
    {
        cty = 0; CT(ctmo); CT(ctw); CT(ctd); CT(cth); CT(ctm);
        format(strii, sizeof(strii), "%d %s, %d %s, %d %s, %d %s, %d %s, and %d %s",PLUR(ctmo,"month","months"),PLUR(ctw,"week","weeks"),PLUR(ctd,"day","days"),PLUR(cth,"hour","hours"),PLUR(ctm,"minute","minutes"),PLUR(cts,"second","seconds"));
        return strii;
    }
    if(ctw != -1 && (cts/CTM_ctw))
    {
        cty = 0; ctmo = 0; CT(ctw); CT(ctd); CT(cth); CT(ctm);
        format(strii, sizeof(strii), "%d %s, %d %s, %d %s, %d %s, and %d %s",PLUR(ctw,"week","weeks"),PLUR(ctd,"day","days"),PLUR(cth,"hour","hours"),PLUR(ctm,"minute","minutes"),PLUR(cts,"second","seconds"));
        return strii;
    }
    if(ctd != -1 && (cts/CTM_ctd))
    {
        cty = 0; ctmo = 0; ctw = 0; CT(ctd); CT(cth); CT(ctm);
        format(strii, sizeof(strii), "%d %s, %d %s, %d %s, and %d %s",PLUR(ctd,"day","days"),PLUR(cth,"hour","hours"),PLUR(ctm,"minute","minutes"),PLUR(cts,"second","seconds"));
        return strii;
    }
    if(cth != -1 && (cts/CTM_cth))
    {
        cty = 0; ctmo = 0; ctw = 0; ctd = 0; CT(cth); CT(ctm);
        format(strii, sizeof(strii), "%d %s, %d %s, and %d %s",PLUR(cth,"hour","hours"),PLUR(ctm,"minute","minutes"),PLUR(cts,"second","seconds"));
        return strii;
    }
    if(ctm != -1 && (cts/CTM_ctm))
    {
        cty = 0; ctmo = 0; ctw = 0; ctd = 0; cth = 0; CT(ctm);
        format(strii, sizeof(strii), "%d %s, and %d %s",PLUR(ctm,"minute","minutes"),PLUR(cts,"second","seconds"));
        return strii;
    }
    cty = 0; ctmo = 0; ctw = 0; ctd = 0; cth = 0; ctm = 0;
    format(strii, sizeof(strii), "%d %s", PLUR(cts,"second","seconds"));
    return strii;
}

stock ChatLog(playerid, text[])
{
	new File:iFile = fopen("OOFAdmin/Logs/ChatLog.txt", io_append);
	new logData[200];
	new fyear, fmonth, fday, fhour, fminute, fsecond;

	getdate(fyear, fmonth, fday);
	gettime(fhour, fminute, fsecond);

	format(logData, sizeof(logData), "[%02d/%02d/%04d | %02d:%02d:%02d] %s:  %s\r\n", fday, fmonth, fyear, fhour, fminute, fsecond, GetName(playerid), text);
	if(iFile) {
		fwrite(iFile, logData);
		fclose(iFile);
	}
	else print("[warning] Failed to write to file: \"OOFAdmin/Logs/ChatLog.txt\"");
	return 1;
}

stock SaveIn(filename[], text[]) //Credits to Luxirion - Recover from OOF DM
{
	new File:iFile;
	new filepath[40];
	new szLog[256];
	new year, month, day;
	new hour, minute, second;

	getdate(year, month, day);
	gettime(hour, minute, second);
	format(filepath, sizeof(filepath), "OOFAdmin/Logs/%s", filename);
	iFile = fopen(filepath, io_append);
	format(szLog, sizeof(szLog),"[%02d/%02d/%02d | %02d:%02d:%02d] %s", day, month, year, hour, minute, second, text);
	if(iFile)
	{
		fwrite(iFile, szLog);
		fwrite(iFile, "\r\n");
		fclose(iFile);
	}
	else printf("[warning] Failed to write to file: %s", filename);
	return 1;
}

stock SetPlayerFacePlayer(playerid, giveplayerid) 
{
    new Float:pX,
        Float:pY,
        Float:pZ,
        Float:gX,
        Float:gY,
        Float:gZ;

    if(GetPlayerPos(playerid, pX, pY, pZ) && GetPlayerPos(giveplayerid, gX, gY, gZ)) {
        SetPlayerFacingAngle(playerid, (pX = -atan2((gX - pX), (gY - pY))));
        return SetPlayerFacingAngle(giveplayerid, (pX + 180.0));
    }
    return false;
}

/*stock Float: GetZAngleBetweenPoints(Float: x1, Float: y1, Float: x2, Float: y2) {
    return -atan2(x2 - x1, y2 - y1);
}*/


// for fishing system. new FishWeight = frandom(20, 5, 1) +1; or new Float:FishWeight
// format(string, sizeof(string), "%.1f", frandom(50.0, 1.0, 2));
// Test (Alpha)
/*Float:frandom(Float:max, Float:min = 0.0, dp = 4) // dp is decimal places (1 = 5.5 and 4 = 5.5555)
{
	new
		// Get the multiplication for storing fractional parts.
		Float:mul = floatpower(10.0, dp),
		// Get the max and min as integers, with extra dp.
		imin = floatround(min * mul),
		imax = floatround(max * mul);
	// Get a random int between two bounds and convert it to a float.
	return float(random(imax - imin) + imin) / mul;
}*/

//-----------------------------------------------------------------------------<

// Copyright © 'Rengar'