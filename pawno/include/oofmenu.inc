/*
	Textdraw system by Maximus (Sky).
	Version: 2.0
	Credits: Maximus and SA-MP Team

* Changelog
Version 1.0: Released
Version 1.1: Fixed a bug with HideMenu function and added hideprice param (use 1 to hide price)
Version 1.5: Added Player Info Menu (Per Player Textdraws for dynamic info)
Version 2.0: Added "ShowPlayerInfoMenu" and "HidePlayerInfoMenu". Edited "ShowPlayerInfo"

Global Textdraws with menu
Per Player Textdraws with menu
Information Textdraws
Per Player Information Textdraws
Global textdraws (half done)

Using in OOF Gamemode
*/

#define MAX_ROWS				20
#define MAX_TD_MENUS 			10
#define INVALID_TEXTDRAW_ID		(-1)
//#define IMENU_OFF				0

// Global Menu
new Text:TD_Menu[MAX_PLAYERS] = Text:INVALID_TEXT_DRAW;
new Text:TD_MenuH[MAX_PLAYERS] = Text:INVALID_TEXT_DRAW;
new Text:TD_MenuT[MAX_PLAYERS] = Text:INVALID_TEXT_DRAW;
new Text:TD_MenuU[MAX_PLAYERS] = Text:INVALID_TEXT_DRAW;
new Text:TD_MenuPrice[MAX_PLAYERS] = Text:INVALID_TEXT_DRAW;

// Global Info Menu
new Text:InfoMenu[MAX_PLAYERS] = {Text:INVALID_TEXT_DRAW, ...};
new Text:InfoMenuH[MAX_PLAYERS] = {Text:INVALID_TEXT_DRAW, ...};
new Text:InfoMenuT[MAX_PLAYERS] = {Text:INVALID_TEXT_DRAW, ...};
new Text:InfoMenuU[MAX_PLAYERS] = {Text:INVALID_TEXT_DRAW, ...};

// Per Player Info
new PlayerText:PlayerInfo[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...};
new PlayerText:PlayerInfoH[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...};
new PlayerText:PlayerInfoT[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...};
new PlayerText:PlayerInfoU[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...};

// Per Player Info (Menu Selection)
new PlayerText:PlayerInfoMenu[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...};
new PlayerText:PlayerInfoMenuH[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...};
new PlayerText:PlayerInfoMenuT[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...};
new PlayerText:PlayerInfoMenuU[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...};

// Per Player Menu
new PlayerText:PlayerMenu[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...};
new PlayerText:PlayerMenuH[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...};
new PlayerText:PlayerMenuT[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...};
new PlayerText:PlayerMenuU[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...};
new PlayerText:PlayerMenu_Price[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...};

new Text:g_TextdrawBox[MAX_PLAYERS] = Text:INVALID_TEXT_DRAW;
new Text:g_TextdrawH[MAX_PLAYERS] = Text:INVALID_TEXT_DRAW;
new Text:g_TextdrawI[MAX_PLAYERS] = Text:INVALID_TEXT_DRAW;

new Menu_ID[MAX_PLAYERS];
new InfoMenu_ID[MAX_PLAYERS];
new PlayerInfo_ID[MAX_PLAYERS];
new PlayerInfoMenu_ID[MAX_PLAYERS];
new PlayerMenu_ID[MAX_PLAYERS];
new g_Textdraw_ID[MAX_PLAYERS] = INVALID_TEXTDRAW_ID;

/*new current_menu[MAX_PLAYERS];
new Text:textdraw_name[MAX_TDMENUS];
new Text:textdraw_nameH;
new Text:textdraw_nameT[MAX_TDMENUS];
new Text:textdraw_nameU;

new const options_array[][] =
{
	"item1", "item2", "item3"
};*/

/*stock Create_Menu(menuid, header[], const Options_TD[][], len = sizeof(Options_TD))
{
	textdraw_name[menuid] = TextDrawCreate(133.0, 133.0, "~n~~n~~n~~n~~n~~n~~n~Press ~y~LMB ~w~To Close This Box~n~");
	TextDrawAlignment(textdraw_name[menuid], 2);
	TextDrawBackgroundColor(textdraw_name[menuid], 255);
	TextDrawFont(textdraw_name[menuid], 1);
	TextDrawLetterSize(textdraw_name[menuid], 0.320000, 1.000000);
	TextDrawColor(textdraw_name[menuid], -1);
	TextDrawSetOutline(textdraw_name[menuid], 1);
	TextDrawSetProportional(textdraw_name[menuid], 1);
	TextDrawUseBox(textdraw_name[menuid], 1);
	TextDrawBoxColor(textdraw_name[menuid], 119);
	TextDrawTextSize(textdraw_name[menuid], 0.000000, 256.000000);

	textdraw_nameH = TextDrawCreate(133.000000, 138.000000, header);
	TextDrawAlignment(textdraw_nameH, 2);
	TextDrawBackgroundColor(textdraw_nameH, 255);
	TextDrawFont(textdraw_nameH, 3);
	TextDrawLetterSize(textdraw_nameH, 0.460000, 1.200000);
	TextDrawColor(textdraw_nameH, -1);
	TextDrawSetOutline(textdraw_nameH, 1);
	TextDrawSetProportional(textdraw_nameH, 1);

	textdraw_nameT[menuid] = TextDrawCreate(7.000000, 167.000000, "_");
	TextDrawBackgroundColor(textdraw_nameT[menuid], 255);
	TextDrawFont(textdraw_nameT[menuid], 1);
	TextDrawLetterSize(textdraw_nameT[menuid], 0.280000, 0.900000);
	TextDrawColor(textdraw_nameT[menuid], -1);
	TextDrawSetOutline(textdraw_nameT[menuid], 1);
	TextDrawSetProportional(textdraw_nameT[menuid], 1);

	for(new i; i < len; i++)
	{
		TextDrawSetString(textdraw_nameT[menuid], Options_TD[i]);
	}

	textdraw_nameU = TextDrawCreate(268.000000, 156.000000, "_");
	TextDrawBackgroundColor(textdraw_nameU, 255);
	TextDrawFont(textdraw_nameU, 1);
	TextDrawLetterSize(textdraw_nameU, 0.500000, -0.500000);
	TextDrawColor(textdraw_nameU, -1);
	TextDrawSetOutline(textdraw_nameU, 0);
	TextDrawSetProportional(textdraw_nameU, 1);
	TextDrawSetShadow(textdraw_nameU, 1);
	TextDrawUseBox(textdraw_nameU, 1);
	TextDrawBoxColor(textdraw_nameU, -16777080);
	TextDrawTextSize(textdraw_nameU, 0.000000, 0.000000);
	return 1;
}

Show_MenuTD(playerid, menuid)
{
	TextDrawShowForPlayer(playerid, textdraw_name[menuid]);
	TextDrawShowForPlayer(playerid, textdraw_nameH);
	TextDrawShowForPlayer(playerid, textdraw_nameT[menuid]);
	TextDrawShowForPlayer(playerid, textdraw_nameU);
	current_menu[playerid] = menuid;
}*/

public OnPlayerConnect(playerid)
{
	Menu_ID[playerid] = 0; // 0 = MENU_OFF
	InfoMenu_ID[playerid] = 0;
	PlayerInfo_ID[playerid] = 0;
	PlayerInfoMenu_ID[playerid] = 0;
	PlayerMenu_ID[playerid] = 0;
	g_Textdraw_ID[playerid] = INVALID_TEXTDRAW_ID;

	#if defined Menu_OnPlayerConnect
		return Menu_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect Menu_OnPlayerConnect
#if defined Menu_OnPlayerConnect
	forward Menu_OnPlayerConnect(playerid);
#endif

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	switch(IsPlayerInAnyVehicle(playerid))
	{
		case 0:
		{
			if((newkeys & KEY_CROUCH) && (newkeys & KEY_SPRINT) || (newkeys & KEY_FIRE) && (newkeys & KEY_SPRINT) || (newkeys == KEY_FIRE) || (newkeys == KEY_CROUCH))
			{
				if(InfoMenu_ID[playerid] > 0)
				{
					HideInfoMenu(playerid);
					InfoMenu_ID[playerid] = 0;
				}

				if(PlayerInfo_ID[playerid] > 0)
				{
					HidePlayerInfo(playerid);
					PlayerInfo_ID[playerid] = 0;
				}

				if(PlayerInfoMenu_ID[playerid] > 0)
				{
					HidePlayerInfoMenu(playerid);
					SendClientMessage(playerid, COLOR_RED, "Selection Cancelled.");
					PlayerInfoMenu_ID[playerid] = 0;
				}
			}
		}
		case 1:
		{
			if((newkeys & KEY_FIRE) && (newkeys & KEY_HANDBRAKE) || (newkeys & KEY_FIRE) && (newkeys & KEY_SPRINT) || (newkeys & KEY_JUMP) && (newkeys & KEY_SPRINT) || (newkeys == KEY_FIRE) || (newkeys == KEY_JUMP))
			{
				if(InfoMenu_ID[playerid] > 0)
				{
					HideInfoMenu(playerid);
					InfoMenu_ID[playerid] = 0;
				}

				if(PlayerInfo_ID[playerid] > 0)
				{
					HidePlayerInfo(playerid);
					PlayerInfo_ID[playerid] = 0;
				}

				if(PlayerInfoMenu_ID[playerid] > 0)
				{
					HidePlayerInfoMenu(playerid);
					SendClientMessage(playerid, COLOR_RED, "Selection Cancelled.");
					PlayerInfoMenu_ID[playerid] = 0;
				}
			}
		}
	}

	if(PRESSED(KEY_NO))
	{
		if(InfoMenu_ID[playerid] > 0)
		{
			HideInfoMenu(playerid);
			//if(InfoMenu_ID[playerid] > 1) SendClientMessage(playerid, COLOR_RED, "Selection Cancelled.");
			InfoMenu_ID[playerid] = 0;
		}

		if(PlayerInfo_ID[playerid] > 0)
		{
			HidePlayerInfo(playerid);
			PlayerInfo_ID[playerid] = 0;
		}

		if(PlayerInfoMenu_ID[playerid] > 0)
		{
			HidePlayerInfoMenu(playerid);
			SendClientMessage(playerid, COLOR_RED, "Selection Cancelled.");
			PlayerInfoMenu_ID[playerid] = 0;
		}
	}

	#if defined Menu_OnPlayerKeyStateChange
		return Menu_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerKeyStateChange
	#undef OnPlayerKeyStateChange
#else
	#define _ALS_OnPlayerKeyStateChange
#endif

#define OnPlayerKeyStateChange Menu_OnPlayerKeyStateChange
#if defined Menu_OnPlayerKeyStateChange
	forward Menu_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif

stock ShowInfoMenu(playerid, menuid, rows, header[], content[]) // Global Info Textdraw with playerid parameter
{
	if(rows == 1)
	{
		TextDrawSetString(InfoMenu[playerid], "~n~~n~~n~~n~~n~~n~Press ~y~~k~~CONVERSATION_NO~ ~w~To Close This Box~n~");
	}
	else
	{
		new str[64];
		for(new i; i < rows; i++)
		{
			format(str, sizeof(str), "%s~n~", str);
		}

		new result_str[185];
		result_str = "~n~~n~~n~~n~~n~Press ~y~~k~~CONVERSATION_NO~ ~w~To Close This Box~n~";
		strins(result_str, str, 0);

		TextDrawSetString(InfoMenu[playerid], result_str);
	}

	TextDrawSetString(InfoMenuH[playerid], header);
	TextDrawSetString(InfoMenuT[playerid], content);

	TextDrawShowForPlayer(playerid, InfoMenu[playerid]);
	TextDrawShowForPlayer(playerid, InfoMenuH[playerid]);
	TextDrawShowForPlayer(playerid, InfoMenuT[playerid]);
	TextDrawShowForPlayer(playerid, InfoMenuU[playerid]);
	InfoMenu_ID[playerid] = menuid;
}

stock HideInfoMenu(playerid) // Hide Global Info Menu TD
{
	TextDrawHideForPlayer(playerid, InfoMenu[playerid]);
	TextDrawHideForPlayer(playerid, InfoMenuH[playerid]);
	TextDrawHideForPlayer(playerid, InfoMenuT[playerid]);
	TextDrawHideForPlayer(playerid, InfoMenuU[playerid]);
}

stock ShowPlayerInfo(playerid, menuid, rows, header[], content[]) // Per Player Info Textdraw (for dynamic textdraws)
{
	if(rows == 1)
	{
		PlayerTextDrawSetString(playerid, PlayerInfo[playerid], "~n~~n~~n~~n~~n~~n~Press ~y~~k~~CONVERSATION_NO~ ~w~To Close This Box~n~");
	}
	else
	{
		new str[64];
		for(new i; i < rows; i++)
		{
			format(str, sizeof(str), "%s~n~", str);
		}

		new result_str[185];
		result_str = "~n~~n~~n~~n~~n~Press ~y~~k~~CONVERSATION_NO~ ~w~To Close This Box~n~";
		strins(result_str, str, 0);

		PlayerTextDrawSetString(playerid, PlayerInfo[playerid], result_str);
	}

	PlayerTextDrawSetString(playerid, PlayerInfoH[playerid], header);
	PlayerTextDrawSetString(playerid, PlayerInfoT[playerid], content);

	PlayerTextDrawShow(playerid, PlayerInfo[playerid]);
	PlayerTextDrawShow(playerid, PlayerInfoH[playerid]);
	PlayerTextDrawShow(playerid, PlayerInfoT[playerid]);
	PlayerTextDrawShow(playerid, PlayerInfoU[playerid]);
	PlayerInfo_ID[playerid] = menuid;
}

stock HidePlayerInfo(playerid) // Hide Per Player Info Menu TD
{
	PlayerTextDrawHide(playerid, PlayerInfo[playerid]);
	PlayerTextDrawHide(playerid, PlayerInfoH[playerid]);
	PlayerTextDrawHide(playerid, PlayerInfoT[playerid]);
	PlayerTextDrawHide(playerid, PlayerInfoU[playerid]);
}

stock ShowPlayerInfoMenu(playerid, menuid, rows, header[], content[]) // Per Player Info Textdraw (for dynamic textdraws)
{
	if(rows == 1)
	{
		if(menuid > 1) PlayerTextDrawSetString(playerid, PlayerInfoMenu[playerid], "~n~~n~~n~~n~~n~~n~Press ~y~F6 ~w~(~y~T~w~) And Enter An Amount~n~Press ~y~~k~~CONVERSATION_NO~ ~w~To Close This Box~n~");
		else PlayerTextDrawSetString(playerid, PlayerInfoMenu[playerid], "~n~~n~~n~~n~~n~~n~Press ~y~~k~~CONVERSATION_NO~ ~w~To Close This Box~n~");
	}
	else
	{
		new str[64];
		for(new i; i < rows; i++)
		{
			format(str, sizeof(str), "%s~n~", str);
		}

		new result_str[185];
		if(menuid > 1) result_str = "~n~~n~~n~~n~~n~Press ~y~F6 ~w~(~y~T~w~) And Enter An Amount~n~Press ~y~~k~~CONVERSATION_NO~ ~w~To Close This Box~n~";
		else result_str = "~n~~n~~n~~n~~n~Press ~y~~k~~CONVERSATION_NO~ ~w~To Close This Box~n~";
		strins(result_str, str, 0);

		PlayerTextDrawSetString(playerid, PlayerInfoMenu[playerid], result_str);
	}

	PlayerTextDrawSetString(playerid, PlayerInfoMenuH[playerid], header);
	PlayerTextDrawSetString(playerid, PlayerInfoMenuT[playerid], content);

	PlayerTextDrawShow(playerid, PlayerInfoMenu[playerid]);
	PlayerTextDrawShow(playerid, PlayerInfoMenuH[playerid]);
	PlayerTextDrawShow(playerid, PlayerInfoMenuT[playerid]);
	PlayerTextDrawShow(playerid, PlayerInfoMenuU[playerid]);
	PlayerInfoMenu_ID[playerid] = menuid;
}

stock HidePlayerInfoMenu(playerid) // Hide Per Player Info Menu TD
{
	PlayerTextDrawHide(playerid, PlayerInfoMenu[playerid]);
	PlayerTextDrawHide(playerid, PlayerInfoMenuH[playerid]);
	PlayerTextDrawHide(playerid, PlayerInfoMenuT[playerid]);
	PlayerTextDrawHide(playerid, PlayerInfoMenuU[playerid]);
}

stock ShowMenu(playerid, menuid, rows, header[], content[]) // Global Textdraw with playerid parameter
{
	if(rows == 1)
	{
		if(menuid > 1) TextDrawSetString(TD_Menu[playerid], "~n~~n~~n~~n~~n~~n~Press ~y~F6 ~w~(~y~T~w~) And Select A Number~n~Press ~y~~k~~CONVERSATION_NO~ ~w~To Close This Box~n~");
		else TextDrawSetString(TD_Menu[playerid], "~n~~n~~n~~n~~n~~n~Press ~y~~k~~CONVERSATION_NO~ ~w~To Close This Box~n~");
	}
	else
	{
		new str[64];
		for(new i; i < rows; i++)
		{
			format(str, sizeof(str), "%s~n~", str);
		}
		//printf("[debug] Show menu str %s  rows %d", str, rows);
		new result_str[185];
		if(menuid > 1) result_str = "~n~~n~~n~~n~~n~Press ~y~F6 ~w~(~y~T~w~) And Select A Number~n~Press ~y~~k~~CONVERSATION_NO~ ~w~To Close This Box~n~";
		else result_str = "~n~~n~~n~~n~~n~Press ~y~~k~~CONVERSATION_NO~ ~w~To Close This Box~n~";
		strins(result_str, str, 0);

		//printf("[debug] Show menu result_str %s  rows %d", result_str, rows);

		TextDrawSetString(TD_Menu[playerid], result_str);
	}

	TextDrawSetString(TD_MenuH[playerid], header);
	TextDrawSetString(TD_MenuT[playerid], content);

	TextDrawShowForPlayer(playerid, TD_Menu[playerid]);
	TextDrawShowForPlayer(playerid, TD_MenuH[playerid]);
	TextDrawShowForPlayer(playerid, TD_MenuT[playerid]);
	TextDrawShowForPlayer(playerid, TD_MenuU[playerid]);
	Menu_ID[playerid] = menuid;
}

stock ShowMenu_Price(playerid, content[]) // Global Price TD
{
	TextDrawSetString(TD_MenuPrice[playerid], content);
	TextDrawShowForPlayer(playerid, TD_MenuPrice[playerid]);
}

stock HideMenu(playerid, hideprice = 0) // Hide Global TD
{
	TextDrawHideForPlayer(playerid, TD_Menu[playerid]);
	TextDrawHideForPlayer(playerid, TD_MenuH[playerid]);
	TextDrawHideForPlayer(playerid, TD_MenuT[playerid]);
	TextDrawHideForPlayer(playerid, TD_MenuU[playerid]);
	if(hideprice == 1) TextDrawHideForPlayer(playerid, TD_MenuPrice[playerid]);
}

stock ShowPlayerMenu(playerid, menuid, rows, header[], content[]) // Per Player Textdraw (for dynamic textdraws)
{
	if(rows == 1)
	{
		if(menuid == 50) PlayerTextDrawSetString(playerid, PlayerMenu[playerid], "~n~~n~~n~~n~~n~~n~Press ~y~~k~~CONVERSATION_NO~ ~w~To Close This Box~n~");
		else PlayerTextDrawSetString(playerid, PlayerMenu[playerid], "~n~~n~~n~~n~~n~~n~Press ~y~F6 ~w~(~y~T~w~) And Select A Number~n~Press ~y~~k~~CONVERSATION_NO~ ~w~To Close This Box~n~");
		//PlayerTextDrawSetString(playerid, PlayerMenu[playerid], "~n~~n~~n~~n~~n~~n~Press ~y~~k~~CONVERSATION_NO~ ~w~To Close This Box~n~");
	}
	else
	{
		new str[64];
		for(new i; i < rows; i++)
		{
			format(str, sizeof(str), "%s~n~", str);
		}
		//printf("[debug] Show menu str %s  rows %d", str, rows);

		new result_str[185];
		if(menuid == 50) result_str = "~n~~n~~n~~n~~n~Press ~y~~k~~CONVERSATION_NO~ ~w~To Close This Box~n~";
		else result_str = "~n~~n~~n~~n~~n~Press ~y~F6 ~w~(~y~T~w~) And Select A Number~n~Press ~y~~k~~CONVERSATION_NO~ ~w~To Close This Box~n~";
		strins(result_str, str, 0);

		//printf("[debug] func: Show_Player_Menu() result_str %s  rows %d", result_str, rows);

		PlayerTextDrawSetString(playerid, PlayerMenu[playerid], result_str);
	}

	PlayerTextDrawSetString(playerid, PlayerMenuH[playerid], header);
	PlayerTextDrawSetString(playerid, PlayerMenuT[playerid], content);

	PlayerTextDrawShow(playerid, PlayerMenu[playerid]);
	PlayerTextDrawShow(playerid, PlayerMenuH[playerid]);
	PlayerTextDrawShow(playerid, PlayerMenuT[playerid]);
	PlayerTextDrawShow(playerid, PlayerMenuU[playerid]);
	PlayerMenu_ID[playerid] = menuid;
}

stock ShowPlayerMenu_Price(playerid, content[]) // Per Player Price TD
{
	PlayerTextDrawSetString(playerid, PlayerMenu_Price[playerid], content);
	PlayerTextDrawShow(playerid, PlayerMenu_Price[playerid]);
}

stock HidePlayerMenu(playerid, hideprice = 0) // Hide Per Player TD
{
	PlayerTextDrawHide(playerid, PlayerMenu[playerid]);
	PlayerTextDrawHide(playerid, PlayerMenuH[playerid]);
	PlayerTextDrawHide(playerid, PlayerMenuT[playerid]);
	PlayerTextDrawHide(playerid, PlayerMenuU[playerid]);
	if(hideprice == 1) PlayerTextDrawHide(playerid, PlayerMenu_Price[playerid]);
}

stock CreateGlobalBox(playerid, Float:posX = 0.00, Float:posY = 0.00, Float:boxsizex = 0.000000, Float:boxsizey = 369.363281)
{
	g_TextdrawBox[playerid] = TextDrawCreate(posX, posY, "_");
	TextDrawLetterSize(g_TextdrawBox[playerid], 0.000000, 18.362688);
	TextDrawTextSize(g_TextdrawBox[playerid], boxsizex, boxsizey);
	TextDrawAlignment(g_TextdrawBox[playerid], 2);
	TextDrawColor(g_TextdrawBox[playerid], -1);
	TextDrawUseBox(g_TextdrawBox[playerid], 1);
	TextDrawBoxColor(g_TextdrawBox[playerid], 119);
	TextDrawSetShadow(g_TextdrawBox[playerid], 0);
	TextDrawSetOutline(g_TextdrawBox[playerid], 0);
	TextDrawBackgroundColor(g_TextdrawBox[playerid], 255);
	TextDrawFont(g_TextdrawBox[playerid], 1);
	TextDrawSetProportional(g_TextdrawBox[playerid], 1);
}

stock CreateGlobalTD(playerid, textdraw_id, Float:hx, Float:hy, Float:ix, Float:iy)
{
	if(g_Textdraw_ID[playerid] >= 0) {
		TextDrawDestroy(g_TextdrawH[playerid]);
		TextDrawDestroy(g_TextdrawI[playerid]);
	}
	g_TextdrawH[playerid] = TextDrawCreate(hx, hy, "_");
	TextDrawLetterSize(g_TextdrawH[playerid], 0.589999, 2.000000);
	TextDrawAlignment(g_TextdrawH[playerid], 2);
	TextDrawColor(g_TextdrawH[playerid], -1);
	TextDrawSetShadow(g_TextdrawH[playerid], 0);
	TextDrawSetOutline(g_TextdrawH[playerid], 1);
	TextDrawBackgroundColor(g_TextdrawH[playerid], 255);
	TextDrawFont(g_TextdrawH[playerid], 3);
	TextDrawSetProportional(g_TextdrawH[playerid], 1);

	g_TextdrawI[playerid] = TextDrawCreate(ix, iy, "_");
	TextDrawLetterSize(g_TextdrawI[playerid], 0.298500, 1.180000);
	TextDrawAlignment(g_TextdrawI[playerid], 2);
	TextDrawColor(g_TextdrawI[playerid], -1);
	TextDrawSetShadow(g_TextdrawI[playerid], 0);
	TextDrawSetOutline(g_TextdrawI[playerid], 1);
	TextDrawBackgroundColor(g_TextdrawI[playerid], 255);
	TextDrawFont(g_TextdrawI[playerid], 1);
	TextDrawSetProportional(g_TextdrawI[playerid], 1);
	g_Textdraw_ID[playerid] = textdraw_id;
}

stock ShowGlobalTD(playerid, textdraw_id, header[], info[], usebox = 0)
{
	TextDrawSetString(g_TextdrawH[playerid], header);
	TextDrawSetString(g_TextdrawI[playerid], info);

	if(usebox == 1) {
		//TextDrawUseBox(g_Textdraw, 1);
		TextDrawShowForPlayer(playerid, g_TextdrawBox[playerid]);
	}
	TextDrawShowForPlayer(playerid, g_TextdrawH[playerid]);
	TextDrawShowForPlayer(playerid, g_TextdrawI[playerid]);
	g_Textdraw_ID[playerid] = textdraw_id;
	//TextDrawShowForPlayer(playerid, g_TextdrawU);
}

stock ChangeTextDrawPosition(textdraw_id, Float:posx, Float:posy, text[])
{
	TextDrawDestroy(textdraw_id);
	textdraw_id = TextDrawCreate(posx, posy, text);
}

/*Create_TDMenu(td_name, rows, header[], content[]) // Global textdraw with menu
{
	new Text:td_name;

	switch(rows)
	{
		case 1:
		{
			td_name = TextDrawCreate(133.000000, 133.000000, "~n~~n~~n~~n~Press ~y~F6 ~w~(~y~T~w~) And Select A Number~n~Press ~y~LMB ~w~To Close This Box~n~");
			TextDrawAlignment(td_name, 2);
			TextDrawBackgroundColor(td_name, 255);
			TextDrawFont(td_name, 1);
			TextDrawLetterSize(td_name, 0.320000, 1.000000);
			TextDrawColor(td_name, -1);
			TextDrawSetOutline(td_name, 1);
			TextDrawSetProportional(td_name, 1);
			TextDrawUseBox(td_name, 1);
			TextDrawBoxColor(td_name, 119);
			TextDrawTextSize(td_name, 0.000000, 256.000000);
		}
		case 2:
		{
			td_name = TextDrawCreate(133.000000, 133.000000, "~n~~n~~n~~n~~n~Press ~y~F6 ~w~(~y~T~w~) And Select A Number~n~Press ~y~LMB ~w~To Close This Box~n~");
		}*/
		/*default:
		{
			print("Maximum rows in a textdraw is 20.");
		}*/
	//}
	/*TextDrawAlignment(td_name, 2);
	TextDrawBackgroundColor(td_name, 255);
	TextDrawFont(td_name, 1);
	TextDrawLetterSize(td_name, 0.320000, 1.000000);
	TextDrawColor(td_name, -1);
	TextDrawSetOutline(td_name, 1);
	TextDrawSetProportional(td_name, 1);
	TextDrawUseBox(td_name, 1);
	TextDrawBoxColor(td_name, 119);
	TextDrawTextSize(td_name, 0.000000, 256.000000);

	textdraw_nameH = TextDrawCreate(133.000000, 138.000000, header);
	TextDrawAlignment(textdraw_nameH, 2);
	TextDrawBackgroundColor(textdraw_nameH, 255);
	TextDrawFont(textdraw_nameH, 3);
	TextDrawLetterSize(textdraw_nameH, 0.460000, 1.200000);
	TextDrawColor(textdraw_nameH, -1);
	TextDrawSetOutline(textdraw_nameH, 1);
	TextDrawSetProportional(textdraw_nameH, 1);

	textdraw_nameT = TextDrawCreate(7.000000, 167.000000, content[]);
	TextDrawBackgroundColor(textdraw_nameT, 255);
	TextDrawFont(textdraw_nameT, 1);
	TextDrawLetterSize(textdraw_nameT, 0.280000, 0.900000);
	TextDrawColor(textdraw_nameT, -1);
	TextDrawSetOutline(textdraw_nameT, 1);
	TextDrawSetProportional(textdraw_nameT, 1);

	textdraw_nameU = TextDrawCreate(268.000000, 156.000000, "_");
	TextDrawBackgroundColor(textdraw_nameU, 255);
	TextDrawFont(textdraw_nameU, 1);
	TextDrawLetterSize(textdraw_nameU, 0.500000, -0.500000);
	TextDrawColor(textdraw_nameU, -1);
	TextDrawSetOutline(textdraw_nameU, 0);
	TextDrawSetProportional(textdraw_nameU, 1);
	TextDrawSetShadow(textdraw_nameU, 1);
	TextDrawUseBox(textdraw_nameU, 1);
	TextDrawBoxColor(textdraw_nameU, -16777080);
	TextDrawTextSize(textdraw_nameU, 0.000000, 0.000000);
}*/
