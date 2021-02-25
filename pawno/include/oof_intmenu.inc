/*
Interior Menu by Sky

Credits:
Garsino (for positions and interior names)
Sky for improving this script and making it a include (using ALS Hook now)

Version 1.0

* Changelod
Version 1.0: Released
Version 1.1: Fixed a bug with HideMenu function and added hideprice param (use 1 to hide price)

Commands: /aint

Using this include in OOF Gamemode
*/
#define D_INTERIORMENU		501

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	// Speed test
	//new speedtest = GetTickCount();
	if(dialogid == D_INTERIORMENU)
	{
		if(response)
		{
   			if(listitem == 0) // 24/7
   			{
			ShowPlayerDialog(playerid, D_INTERIORMENU+1, DIALOG_STYLE_LIST, "24/7's", "24/7 Interior 1 \n24/7 Interior 2 \n24/7 Interior 3 \n24/7 Interior 4 \n24/7 Interior 5 \n24/7 Interior 6 \nBack", "Select", "Cancel");
			}
			if(listitem == 1) // Airports
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU+2, DIALOG_STYLE_LIST, "Airport Interiors", "Francis Ticket Sales Airport \nFrancis Baggage Claim Airport \nAndromada Cargo Hold \nShamal Cabin \nLS Airport Baggage Claim \nInterernational Airport \nAbandoned AC Tower \nBack", "Select", "Cancel");
			}
			if(listitem == 2) // Ammunations
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU+3, DIALOG_STYLE_LIST, "Ammunation Interiors", "Ammunation 1 \nAmmunation 2 \nAmmunation 3 \nAmmunation 4 \nAmmunation 5 \nBooth Ammunation \nRange Ammunation \nBack", "Select", "Cancel");
   			}
			if(listitem == 3) // Houses
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU+4, DIALOG_STYLE_LIST, "Houses", "B Dup's Apartment\nB Dup's Crack Palace \nOG Loc's House \nRyder's house \nSweet's house \nMadd Dogg's Mansion \nBig Smoke's Crack Palace \nBack", "Select", "Cancel");
   			}
			if(listitem == 4) // Houses 2
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU+5, DIALOG_STYLE_LIST, "Houses 2", "Johnson House \nAngel Pine Trailer \nSafe House \nSafe House 2 \nSafe House 3 \nSafe House 4 \nVerdant Bluffs Safehouse \nWillowfield Safehouse \nThe Camel's Toe Safehouse \nBack", "Select", "Cancel");
   			}
			if(listitem == 5) // Missions
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU+6, DIALOG_STYLE_LIST, "Missions", "Atrium \nBurning Desire Building \nColonel Furhberger \nWelcome Pump \nWu Zi Mu's Apartement \nJizzy's \nDillimore Gas Station \nJefferson Motel \nLiberty City \nSherman Dam \nBack", "Select", "Cancel");
   			}
			if(listitem == 6) // Missions 2
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU+7, DIALOG_STYLE_LIST, "Stadiums", "RC War Arena \nRacing Stadium \nRacing Stadium 2 \nBloodbowl Stadium \nKickstart Stadium \nBack", "Select", "Cancel");
   			}
			if(listitem == 7) // Casino Interiors
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU+8, DIALOG_STYLE_LIST, "Casino Interiors", "Caligulas Casino \n4 Dragons Casino \nRedsands Casino \n4 Dragons Managerial Suite \nInside Track Betting \nCaligulas Roof \nRosenberg's Caligulas Office \n4 Dragons Janitors Office \nBack", "Select", "Cancel");
			}
			if(listitem == 8) // Shops
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU+9, DIALOG_STYLE_LIST, "Shop Interiors", "Tattoo \nBurger Shot \nWell Stacked Pizza \nCluckin' Bell \nRusty Donut's \nZero's RC Shop \nSex Shop \nBack", "Select", "Cancel");
			}
			if(listitem == 9) // Garages
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU+10, DIALOG_STYLE_LIST, "Mod Shops/Garages","Loco Low Co. \nWheel Arch Angels \nTransfender \nDoherty Garage \nBack", "Select", "Cancel");
   			}
			if(listitem == 10) // Girl Friends
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU+11, DIALOG_STYLE_LIST, "CJ's Girlfriends Interiors","Denises Bedroom \nHelena's Barn \nBarbara's Love Nest \nKatie's Lovenest \nMichelle's Love Nest \nMillie's Bedroom \nBack", "Select", "Cancel");
   			}
			if(listitem == 11) // Clothing & Barber Store
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU+12, DIALOG_STYLE_LIST, "Clothing & Barber Store","Barber Shop \nPro-Laps \nVictim \nSubUrban \nReece's Barber Shop \nZip \nDidier Sachs \nBinco \nBarber Shop 2 \nWardrobe \nBack", "Select", "Cancel");
   			}
   			if(listitem == 12) // Resturants & Clubs
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU+13, DIALOG_STYLE_LIST, "Resturants & Clubs","Brothel \nBrothel 2 \nThe Big Spread Ranch \nDinner \nWorld Of Coq \nThe Pig Pen \nClub \nJay's Diner \nSecret Valley Diner \nFanny Batter's Whore House \nBack", "Select", "Cancel");
   			}
   			if(listitem == 13) // No Specific Group
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU+14, DIALOG_STYLE_LIST, "No Specific Category","Blastin' Fools Records \nWarehouse \nWarehouse 2 \nBudget Inn Motel Room \nLil' Probe Inn \nCrack Den \nMeat Factory \nBike School \nDriving School \nBack", "Select", "Cancel");
   			}
   			if(listitem == 14) // Burglary Houses
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU+15, DIALOG_STYLE_LIST, "Burglary Houses","Burglary House 1 \nBurglary House 2 \nBurglary House 3 \nBurglary House 4 \nBurglary House 5 \nBurglary House 6 \nBurglary House 7 \nBurglary House 8 \nBurglary House 9 \nBurglary House 10 \nBack", "Select", "Cancel");
   			}
			if(listitem == 15) // Burglary Houses 2
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU+16, DIALOG_STYLE_LIST, "Burglary Houses 2","Burglary House 11 \nBurglary House 12 \nBurglary House 13 \nBurglary House 14 \nBurglary House 15 \nBurglary House 16 \nBack", "Select", "Cancel");
   			}
   			if(listitem == 16) // Gyms
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU+17, DIALOG_STYLE_LIST, "Gyms","Los Santos Gym \nSan Fierro Gym \nLas Venturas Gym \nBack", "Select", "Cancel");
   			}
   			if(listitem == 17) // Departements
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU+18, DIALOG_STYLE_LIST, "Departments","SF Police Department \nLS Police Department \nLV Police Department \nPlanning Department\nBack", "Select", "Cancel");
   			}
   			if(listitem == 18) // Back
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU, DIALOG_STYLE_LIST, "Interior Categories","24/7's\nAirports\nAmmunations\nHouses\nHouses 2\nMissions\nStadiums\nCasinos\nShops\nGarages\nGirlfriends\nClothing/Barber Store\nResturants/Clubs\nNo Category\nBurglary\nBurglary 2\nGym\nDepartment\nBack", "Select", "Cancel");
   			}
		}
		return 1;
	}
//===================================24/7's===================================//
	if(dialogid == D_INTERIORMENU+1) // 24/7's
	{
		if(response)
		{
			if(listitem == 0) // 24/7 1
			{
		   	SetPlayerPos(playerid,-25.884499,-185.868988,1003.549988);
		    SetPlayerInterior(playerid,17);
			}
			if(listitem == 1) // 24/7 2
			{
		   	SetPlayerPos(playerid,-6.091180,-29.271898,1003.549988);
		    SetPlayerInterior(playerid,10);
			}
			if(listitem == 2) //  24/7 3
			{
		   	SetPlayerPos(playerid,-30.946699,-89.609596,1003.549988);
			SetPlayerInterior(playerid,18);
			}
			if(listitem == 3) //  24/7 4
			{
		   	SetPlayerPos(playerid,-25.132599,-139.066986,1003.549988);
		    SetPlayerInterior(playerid,16);
			}
			if(listitem == 4) //  24/7 5
			{
		   	SetPlayerPos(playerid,-27.312300,-29.277599,1003.549988);
		    SetPlayerInterior(playerid,4);
			}
			if(listitem == 5) // 24/7 6
			{
		   	SetPlayerPos(playerid,-26.691599,-55.714897,1003.549988);
		    SetPlayerInterior(playerid,6);
			}
			if(listitem == 6) // Back
  			{
			ShowPlayerDialog(playerid, D_INTERIORMENU, DIALOG_STYLE_LIST, "Interior Categories","24/7's\nAirports\nAmmunations\nHouses\nHouses 2\nMissions\nStadiums\nCasinos\nShops\nGarages\nGirlfriends\nClothing/Barber Store\nResturants/Clubs\nNo Category\nBurglary\nBurglary 2\nGym\nDepartment\nBack", "Select", "Cancel");
			}
		}
		return 1;
	}
//==================================Airports==================================//
	if(dialogid == D_INTERIORMENU+2) // Airport Interiors
	{
		if(response)
		{
			if(listitem == 0) // Francis Ticket Sales Airport
			{
		   	SetPlayerPos(playerid,-1827.147338,7.207418,1061.143554);
		    SetPlayerInterior(playerid,14);
			}
			if(listitem == 1) // Francis Baggage Claim Airport
			{
		   	SetPlayerPos(playerid,-1855.568725,41.263156,1061.143554);
		    SetPlayerInterior(playerid,14);
			}
			if(listitem == 2) // Andromada Cargo Hold
			{
		   	SetPlayerPos(playerid,315.856170,1024.496459,1949.797363);
		    SetPlayerInterior(playerid,9);
			}
			if(listitem == 3) // Shamal Cabin
			{
		   	SetPlayerPos(playerid,2.384830,33.103397,1199.849976);
		    SetPlayerInterior(playerid,1);
			}
			if(listitem == 4) // LS Airport Baggage Claim
			{
		   	SetPlayerPos(playerid,-1870.80,59.81,1056.25);
		    SetPlayerInterior(playerid,14);
			}
			if(listitem == 5) // Interernational Airport
			{
		   	SetPlayerPos(playerid,-1830.81,16.83,1061.14);
		    SetPlayerInterior(playerid,14);
			}
			if(listitem == 6) // Abounded AC Tower
			{
		   	SetPlayerPos(playerid, 419.8936, 2537.1155, 10);
		    SetPlayerInterior(playerid, 10);
			}
			if(listitem == 7) // Back
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU, DIALOG_STYLE_LIST, "Interior Categories","24/7's\nAirports\nAmmunations\nHouses\nHouses 2\nMissions\nStadiums\nCasinos\nShops\nGarages\nGirlfriends\nClothing/Barber Store\nResturants/Clubs\nNo Category\nBurglary\nBurglary 2\nGym\nDepartment\nBack", "Select", "Cancel");
			}
		}
		return 1;
	}
//=================================Ammunation=================================//
	if(dialogid == D_INTERIORMENU+3) // Ammunations
	{
		if(response)
		{
			if(listitem == 0) // Ammunation 1
			{
		   	SetPlayerPos(playerid,286.148987,-40.644398,1001.569946);
		    SetPlayerInterior(playerid,1);
			}
			if(listitem == 1) // Ammunation 2
			{
		   	SetPlayerPos(playerid,286.800995,-82.547600,1001.539978);
		    SetPlayerInterior(playerid,4);
			}
			if(listitem == 2) // Ammunation 3
			{
		   	SetPlayerPos(playerid,296.919983,-108.071999,1001.569946);
		    SetPlayerInterior(playerid,6);
			}
			if(listitem == 3) // Ammunation 4
			{
		   	SetPlayerPos(playerid,314.820984,-141.431992,999.661987);
		    SetPlayerInterior(playerid,7);
			}
			if(listitem == 4) // Ammunation 5
			{
		   	SetPlayerPos(playerid,316.524994,-167.706985,999.661987);
		    SetPlayerInterior(playerid,6);
			}
			if(listitem == 5) // Booth Ammunation
			{
		   	SetPlayerPos(playerid,302.292877,-143.139099,1004.062500);
		    SetPlayerInterior(playerid,7);
			}
			if(listitem == 6) // Range Ammunation
			{
		   	SetPlayerPos(playerid,280.795104,-135.203353,1004.062500);
		    SetPlayerInterior(playerid,7);
			}
			if(listitem == 7) // Back
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU, DIALOG_STYLE_LIST, "Interior Categories","24/7's\nAirports\nAmmunations\nHouses\nHouses 2\nMissions\nStadiums\nCasinos\nShops\nGarages\nGirlfriends\nClothing/Barber Store\nResturants/Clubs\nNo Category\nBurglary\nBurglary 2\nGym\nDepartment\nBack", "Select", "Cancel");
			}
		}
		return 1;
	}
//===================================Houses===================================//
	if(dialogid == D_INTERIORMENU+4) // Houses
	{
		if(response)
		{
			if(listitem == 0) // B Dup's Apartment
			{
		   	SetPlayerPos(playerid,1527.0468, -12.0236, 1002.0971);
		    SetPlayerInterior(playerid,3);
			}
			if(listitem == 1) // B Dup's Crack Palace
			{
		   	SetPlayerPos(playerid,1523.5098, -47.8211, 1002.2699);
		    SetPlayerInterior(playerid,2);
			}
			if(listitem == 2) // OG Loc's House
			{
		   	SetPlayerPos(playerid,512.9291, -11.6929, 1001.5653);
		    SetPlayerInterior(playerid,3);
			}
			if(listitem == 3) // Ryder's
			{
		   	SetPlayerPos(playerid,2447.8704, -1704.4509, 1013.5078);
		    SetPlayerInterior(playerid,2);
			}
			if(listitem == 4) // Sweet's
			{
		   	SetPlayerPos(playerid,2527.0176, -1679.2076, 1015.4986);
		    SetPlayerInterior(playerid,1);
			}
			if(listitem == 5) // Madd Dogg's Mansion
			{
		   	SetPlayerPos(playerid,1267.8407, -776.9587, 1091.9063);
		    SetPlayerInterior(playerid,5);
			}
			if(listitem == 6) // Big Smoke's Crack Palace
			{
		   	SetPlayerPos(playerid,2536.5322, -1294.8425, 1044.125);
		    SetPlayerInterior(playerid,2);
			}
			if(listitem == 7) // Back
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU, DIALOG_STYLE_LIST, "Interior Categories","24/7's\nAirports\nAmmunations\nHouses\nHouses 2\nMissions\nStadiums\nCasinos\nShops\nGarages\nGirlfriends\nClothing/Barber Store\nResturants/Clubs\nNo Category\nBurglary\nBurglary 2\nGym\nDepartment\nBack", "Select", "Cancel");
			}
		}
		return 1;
	}
//===================================Safe Houses===================================//
	if(dialogid == D_INTERIORMENU+5) // Houses
	{
		if(response)
		{
			if(listitem == 0) // CJ's House
			{
		   	SetPlayerPos(playerid,2496.0549, -1695.1749, 1014.7422);
		    SetPlayerInterior(playerid,3);
			}
			if(listitem == 1) // Angel Pine trailer
			{
		   	SetPlayerPos(playerid,1.1853, -3.2387, 999.4284);
		    SetPlayerInterior(playerid,2);
			}
			if(listitem == 2) // Safe House
			{
		   	SetPlayerPos(playerid,2233.6919, -1112.8107, 1050.8828);
		    SetPlayerInterior(playerid,5);
			}
			if(listitem == 3) // Safe House 2
			{
		   	SetPlayerPos(playerid,2194.7900, -1204.3500, 1049.0234);
		    SetPlayerInterior(playerid,6);
			}
			if(listitem == 4) // Safe House 3
			{
		   	SetPlayerPos(playerid,2319.1272, -1023.9562, 1050.2109);
		    SetPlayerInterior(playerid,9);
			}
			if(listitem == 5) // Safe House 4
			{
		   	SetPlayerPos(playerid,2262.4797,-1138.5591,1050.6328);
		    SetPlayerInterior(playerid,10);
			}
			if(listitem == 6) // Verdant Bluff safehouse
			{
		   	SetPlayerPos(playerid,2365.1089, -1133.0795, 1050.875);
		    SetPlayerInterior(playerid,8);
			}
			if(listitem == 7) // Willowfield Safehouse
			{
		   	SetPlayerPos(playerid,2282.9099, -1138.2900, 1050.8984);
		    SetPlayerInterior(playerid,11);
			}
			if(listitem == 8) // The Camel's Toe Safehouse
			{
		   	SetPlayerPos(playerid,2216.1282, -1076.3052, 1050.4844);
		    SetPlayerInterior(playerid,1);
			}
			if(listitem == 9) // Back
			{
   			ShowPlayerDialog(playerid, D_INTERIORMENU, DIALOG_STYLE_LIST, "Interior Categories","24/7's\nAirports\nAmmunations\nHouses\nHouses 2\nMissions\nStadiums\nCasinos\nShops\nGarages\nGirlfriends\nClothing/Barber Store\nResturants/Clubs\nNo Category\nBurglary\nBurglary 2\nGym\nDepartment\nBack", "Select", "Cancel");
			}
		}
		return 1;
	}
//==================================Missions==================================//
	if(dialogid == D_INTERIORMENU+6) // Missions
	{
		if(response)
		{
			if(listitem == 0) // Atrium
			{
		   	SetPlayerPos(playerid,1726.18,-1641.00,20.23);
		    SetPlayerInterior(playerid,18);
			}

			if(listitem == 1) // Burning Desire
			{
		   	SetPlayerPos(playerid,2338.32,-1180.61,1027.98);
		    SetPlayerInterior(playerid,5);
			}
			if(listitem == 2) // Colonel Furhberger
			{
		   	SetPlayerPos(playerid,2807.63,-1170.15,1025.57);
		    SetPlayerInterior(playerid,8);
			}
			if(listitem == 3) // Welcome Pump(Dillimore)
			{
		   	SetPlayerPos(playerid,681.66,-453.32,-25.61);
		    SetPlayerInterior(playerid,1);
			}
			if(listitem == 4) // Woozies Apartment
			{
		   	SetPlayerPos(playerid,-2158.72,641.29,1052.38);
		    SetPlayerInterior(playerid,1);
			}
			if(listitem == 5) // Jizzy's
			{
		   	SetPlayerPos(playerid,-2637.69,1404.24,906.46);
		    SetPlayerInterior(playerid,3);
			}
			if(listitem == 6) // Dillimore Gas Station
			{
		   	SetPlayerPos(playerid,664.19,-570.73,16.34);
		    SetPlayerInterior(playerid,0);
			}
			if(listitem == 7) // Jefferson Motel
			{
		   	SetPlayerPos(playerid,2220.26,-1148.01,1025.80);
		    SetPlayerInterior(playerid,15);
			}
			if(listitem == 8) // Liberty City
			{
		   	SetPlayerPos(playerid,-750.80,491.00,1371.70);
		    SetPlayerInterior(playerid,1);
			}
			if(listitem == 9) // Sherman Dam
			{
		   	SetPlayerPos(playerid,-944.2402, 1886.1536, 5.0051);
		    SetPlayerInterior(playerid,17);
			}
			if(listitem == 10) // Back
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU, DIALOG_STYLE_LIST, "Interior Categories","24/7's\nAirports\nAmmunations\nHouses\nHouses 2\nMissions\nStadiums\nCasinos\nShops\nGarages\nGirlfriends\nClothing/Barber Store\nResturants/Clubs\nNo Category\nBurglary\nBurglary 2\nGym\nDepartment\nBack", "Select", "Cancel");
			}
		}
		return 1;
	}
//=================================Missions 2=================================//
	if(dialogid == D_INTERIORMENU+7) //
	{
		if(response)
		{

			if(listitem == 0) // RC War Arena
			{
		   	SetPlayerPos(playerid,-1079.99,1061.58,1343.04);
		    SetPlayerInterior(playerid,10);
			}
			if(listitem == 1) // Racing Stadium
			{
		   	SetPlayerPos(playerid,-1395.958,-208.197,1051.170);
		    SetPlayerInterior(playerid,7);
			}
			if(listitem == 2) // Racing Stadium 2
			{
		   	SetPlayerPos(playerid,-1424.9319,-664.5869,1059.8585);
		    SetPlayerInterior(playerid,4);
			}
			if(listitem == 3) // Bloodbowl Stadium
			{
		   	SetPlayerPos(playerid,-1394.20,987.62,1023.96);
		    SetPlayerInterior(playerid,15);
			}
			if(listitem == 4) // Kickstart Stadium
			{
		   	SetPlayerPos(playerid,-1410.72,1591.16,1052.53);
		    SetPlayerInterior(playerid,14);
			}
			if(listitem == 5) // Back
			{
            ShowPlayerDialog(playerid, D_INTERIORMENU, DIALOG_STYLE_LIST, "Interior Categories","24/7's\nAirports\nAmmunations\nHouses\nHouses 2\nMissions\nStadiums\nCasinos\nShops\nGarages\nGirlfriends\nClothing/Barber Store\nResturants/Clubs\nNo Category\nBurglary\nBurglary 2\nGym\nDepartment\nBack", "Select", "Cancel");
			}
		}
		return 1;
	}
//===============================Casino Interiors================================//
	if(dialogid == D_INTERIORMENU+8) // Casino Interiors
	{
		if(response)
		{
			if(listitem == 0) // Caligulas
			{
		   	SetPlayerPos(playerid,2233.8032,1712.2303,1011.7632);
		    SetPlayerInterior(playerid,1);
			}
			if(listitem == 1) // 4 Dragons Casino
			{
		   	SetPlayerPos(playerid,2016.2699,1017.7790,996.8750);
		    SetPlayerInterior(playerid,10);
			}
			if(listitem == 2) // Redsands Casino
			{
			SetPlayerPos(playerid,1132.9063,-9.7726,1000.6797);
		    SetPlayerInterior(playerid,12);
			}
			if(listitem == 3) // 4 Dragons' Managerial Suite NOT SOLID
			{
		   	SetPlayerPos(playerid,2003.1178, 1015.1948, 33.008);
		    SetPlayerInterior(playerid,11);
			}
			if(listitem == 4) // Inside Track betting
			{
		   	SetPlayerPos(playerid,830.6016, 5.9404, 1004.1797);
		    SetPlayerInterior(playerid,3);
			}
			if(listitem == 5) // Caligulas Roof
			{
		   	SetPlayerPos(playerid,2268.5156, 1647.7682, 1084.2344);
		    SetPlayerInterior(playerid,1);
			}
			if(listitem == 6) // Rosenberg's Caligulas Office NOT SOLID FLOOR
			{
		   	SetPlayerPos(playerid,2182.2017, 1628.5848, 1043.8723);
		    SetPlayerInterior(playerid,2);
			}
			if(listitem == 7) // 4 Dragons Janitor's Office
			{
		   	SetPlayerPos(playerid,1893.0731, 1017.8958, 31.8828);
		    SetPlayerInterior(playerid,10);
			}
			if(listitem == 8) // Back
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU, DIALOG_STYLE_LIST, "Interior Categories","24/7's\nAirports\nAmmunations\nHouses\nHouses 2\nMissions\nStadiums\nCasinos\nShops\nGarages\nGirlfriends\nClothing/Barber Store\nResturants/Clubs\nNo Category\nBurglary\nBurglary 2\nGym\nDepartment\nBack", "Select", "Cancel");
			}
		}
		return 1;
	}
//===============================Shop Interiors================================//
	if(dialogid == D_INTERIORMENU+9) // Shop Interiors
	{
		if(response)
		{
			if(listitem == 0) // Tattoo
			{
		   	SetPlayerPos(playerid,-203.0764,-24.1658,1002.2734);
		    SetPlayerInterior(playerid,16);
			}
			if(listitem == 1) // Burger Shot
			{
		   	SetPlayerPos(playerid,365.4099,-73.6167,1001.5078);
		    SetPlayerInterior(playerid,10);
			}
			if(listitem == 2) // Well Stacked Pizza
			{
		   	SetPlayerPos(playerid,372.3520,-131.6510,1001.4922);
		    SetPlayerInterior(playerid,5);
			}
			if(listitem == 3) // Cluckin Bell
			{
		   	SetPlayerPos(playerid,365.7158,-9.8873,1001.8516);
		    SetPlayerInterior(playerid,9);
			}
			if(listitem == 4) // Rusty Donut's
			{
		   	SetPlayerPos(playerid,378.026,-190.5155,1000.6328);
		    SetPlayerInterior(playerid,17);
			}
			if(listitem == 5) // Zero's
			{
		   	SetPlayerPos(playerid,-2240.1028, 136.973, 1035.4141);
		    SetPlayerInterior(playerid,6);
			}
			if(listitem == 6) // Sex Shop
			{
		   	SetPlayerPos(playerid,-100.2674, -22.9376, 1000.7188);
		    SetPlayerInterior(playerid,3);
			}
			if(listitem == 7) // Back
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU, DIALOG_STYLE_LIST, "Interior Categories","24/7's\nAirports\nAmmunations\nHouses\nHouses 2\nMissions\nStadiums\nCasinos\nShops\nGarages\nGirlfriends\nClothing/Barber Store\nResturants/Clubs\nNo Category\nBurglary\nBurglary 2\nGym\nDepartment\nBack", "Select", "Cancel");
			}
		}
		return 1;
	}
//===================================MOD SHOPS/GARAGES==================================//
	if(dialogid == D_INTERIORMENU+10) //
	{
		if(response)
		{
			if(listitem == 0) // Loco Low Co.
			{
		   	SetPlayerPos(playerid,616.7820,-74.8151,997.6350);
		    SetPlayerInterior(playerid,2);
			}
			if(listitem == 1) // Wheel Arch Angels
			{
		   	SetPlayerPos(playerid,615.2851,-124.2390,997.6350);
		    SetPlayerInterior(playerid,3);
			}
			if(listitem == 2) // Transfender
			{
		   	SetPlayerPos(playerid,617.5380,-1.9900,1000.6829);
		    SetPlayerInterior(playerid,1);
			}
			if(listitem == 3) // Doherty Garage
			{
		   	SetPlayerPos(playerid,-2041.2334, 178.3969, 28.8465);
		    SetPlayerInterior(playerid,1);
			}
			if(listitem == 4) // Back
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU, DIALOG_STYLE_LIST, "Interior Categories","24/7's\nAirports\nAmmunations\nHouses\nHouses 2\nMissions\nStadiums\nCasinos\nShops\nGarages\nGirlfriends\nClothing/Barber Store\nResturants/Clubs\nNo Category\nBurglary\nBurglary 2\nGym\nDepartment\nBack", "Select", "Cancel");
			}
		}
		return 1;
	}
//===================================Girlfriend Interiors==================================//
	if(dialogid == D_INTERIORMENU+11) //
	{
		if(response)
		{
			if(listitem == 0) // Denise's Bedroom
			{
		   	SetPlayerPos(playerid,245.2307, 304.7632, 999.1484);
		    SetPlayerInterior(playerid,1);
			}
			if(listitem == 1) // Helena's Barn
			{
		   	SetPlayerPos(playerid,290.623, 309.0622, 999.1484);
		    SetPlayerInterior(playerid,3);
			}
			if(listitem == 2) // Barbaras Love Nest
			{
		   	SetPlayerPos(playerid,322.5014, 303.6906, 999.1484);
		    SetPlayerInterior(playerid,5);
			}
			if(listitem == 3) // Katie's Lovenest
			{
		   	SetPlayerPos(playerid,269.6405, 305.9512, 999.1484);
		    SetPlayerInterior(playerid,2);
			}
			if(listitem == 4) // Michelle's Love Nest
			{
		   	SetPlayerPos(playerid,306.1966, 307.819, 1003.3047);
		    SetPlayerInterior(playerid,4);
			}
			if(listitem == 5) // Millie's Bedroom
			{
		   	SetPlayerPos(playerid,344.9984, 307.1824, 999.1557);
		    SetPlayerInterior(playerid,6);
			}
			if(listitem == 6) // Back
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU, DIALOG_STYLE_LIST, "Interior Categories","24/7's\nAirports\nAmmunations\nHouses\nHouses 2\nMissions\nStadiums\nCasinos\nShops\nGarages\nGirlfriends\nClothing/Barber Store\nResturants/Clubs\nNo Category\nBurglary\nBurglary 2\nGym\nDepartment\nBack", "Select", "Cancel");
			}
		}
		return 1;
	}
//===================================CLOTHING/BARBER SHOP==================================//
	if(dialogid == D_INTERIORMENU+12) //
	{
		if(response)
		{
			if(listitem == 0) // Barber Shop
			{
		   	SetPlayerPos(playerid,418.4666, -80.4595, 1001.8047);
		    SetPlayerInterior(playerid,3);
			}
			if(listitem == 1) // Pro Laps
			{
		   	SetPlayerPos(playerid,206.4627, -137.7076, 1003.0938);
		    SetPlayerInterior(playerid,3);
			}
			if(listitem == 2) // Victim
			{
		   	SetPlayerPos(playerid,225.0306, -9.1838, 1002.218);
		    SetPlayerInterior(playerid,5);
			}
			if(listitem == 3) // Suburban
			{
		   	SetPlayerPos(playerid,204.1174, -46.8047, 1001.8047);
		    SetPlayerInterior(playerid,1);
			}
			if(listitem == 4) // Reece's Barber Shop
			{
		   	SetPlayerPos(playerid,414.2987, -18.8044, 1001.8047);
		    SetPlayerInterior(playerid,2);
			}
			if(listitem == 5) // Zip
			{
		   	SetPlayerPos(playerid,161.4048, -94.2416, 1001.8047);
		    SetPlayerInterior(playerid,18);
			}
			if(listitem == 6) // Didier Sachs
			{
		   	SetPlayerPos(playerid,204.1658, -165.7678, 1000.5234);
		    SetPlayerInterior(playerid,14);
			}
			if(listitem == 7) // Binco
			{
		   	SetPlayerPos(playerid,207.5219, -109.7448, 1005.1328);
		    SetPlayerInterior(playerid,15);
			}
			if(listitem == 8) // Barber Shop 2
			{
		   	SetPlayerPos(playerid,411.9707, -51.9217, 1001.8984);
		    SetPlayerInterior(playerid,12);
			}
			if(listitem == 9) // Wardrobe
			{
		   	SetPlayerPos(playerid,256.9047, -41.6537, 1002.0234);
		    SetPlayerInterior(playerid,14);
			}
			if(listitem == 10) // Back
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU, DIALOG_STYLE_LIST, "Interior Categories","24/7's\nAirports\nAmmunations\nHouses\nHouses 2\nMissions\nStadiums\nCasinos\nShops\nGarages\nGirlfriends\nClothing/Barber Store\nResturants/Clubs\nNo Category\nBurglary\nBurglary 2\nGym\nDepartment\nBack", "Select", "Cancel");
			}
		}
		return 1;
	}
//===================================RESTURANTS/CLUBS==================================//
	if(dialogid == D_INTERIORMENU+13) //
	{
		if(response)
		{
			if(listitem == 0) // Brotel
			{
		   	SetPlayerPos(playerid,974.0177, -9.5937, 1001.1484);
		    SetPlayerInterior(playerid,3);
			}
			if(listitem == 1) // Brotel 2
			{
		   	SetPlayerPos(playerid,961.9308, -51.9071, 1001.1172);
		    SetPlayerInterior(playerid,3);
			}
			if(listitem == 2) // Big Spread Ranch
			{
		   	SetPlayerPos(playerid,1212.0762,-28.5799,1000.9531);
		    SetPlayerInterior(playerid,3);
			}
			if(listitem == 3) // Dinner
			{
		   	SetPlayerPos(playerid,454.9853, -107.2548, 999.4376);
		    SetPlayerInterior(playerid,5);
			}
			if(listitem == 4) // World Of Coq
			{
		   	SetPlayerPos(playerid,445.6003, -6.9823, 1000.7344);
		    SetPlayerInterior(playerid,1);
			}
			if(listitem == 5) // The Pig Pen
			{
		   	SetPlayerPos(playerid,1204.9326,-8.1650,1000.9219);
		    SetPlayerInterior(playerid,2);
			}
			if(listitem == 6) // Dance Club
			{
		   	SetPlayerPos(playerid,490.2701,-18.4260,1000.6797);
		    SetPlayerInterior(playerid,17);
			}
			if(listitem == 7) // Jay's Dinner
			{
		   	SetPlayerPos(playerid,449.0172, -88.9894, 999.5547);
		    SetPlayerInterior(playerid,4);
			}
			if(listitem == 8) // Secret Valley Dinner
			{
		   	SetPlayerPos(playerid,442.1295, -52.4782, 999.7167);
		    SetPlayerInterior(playerid,6);
			}
			if(listitem == 9) // Fanny Batter's Whore House
			{
		   	SetPlayerPos(playerid,748.4623, 1438.2378, 1102.9531);
		    SetPlayerInterior(playerid,6);
			}
			if(listitem == 10) // Back
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU, DIALOG_STYLE_LIST, "Interior Categories","24/7's\nAirports\nAmmunations\nHouses\nHouses 2\nMissions\nStadiums\nCasinos\nShops\nGarages\nGirlfriends\nClothing/Barber Store\nResturants/Clubs\nNo Category\nBurglary\nBurglary 2\nGym\nDepartment\nBack", "Select", "Cancel");
			}
		}
		return 1;
	}
//===================================No Specific Group==================================//
	if(dialogid == D_INTERIORMENU+14) //
	{
		if(response)
		{
			if(listitem == 0) // Blastin' Fools Records
			{
		   	SetPlayerPos(playerid,1037.8276, 0.397, 1001.2845);
		    SetPlayerInterior(playerid,3);
			}
			if(listitem == 1) // Warehouse
			{
		   	SetPlayerPos(playerid,1290.4106, 1.9512, 1001.0201);
		    SetPlayerInterior(playerid,18);
			}
			if(listitem == 2) // Warehouse 2
			{
		   	SetPlayerPos(playerid,1411.4434,-2.7966,1000.9238);
		    SetPlayerInterior(playerid,1);
			}
			if(listitem == 3) // Budget Inn Motel Room
			{
		   	SetPlayerPos(playerid,446.3247, 509.9662, 1001.4195);
		    SetPlayerInterior(playerid,12);
			}
			if(listitem == 4) // Lil' Probe Inn
			{
		   	SetPlayerPos(playerid,-227.5703, 1401.5544, 27.7656);
		    SetPlayerInterior(playerid,18);
			}
			if(listitem == 5) //Crack Den
			{
		   	SetPlayerPos(playerid,318.5645, 1118.2079, 1083.8828);
		    SetPlayerInterior(playerid,5);
			}
			if(listitem == 6) // Meat Factory
			{
		   	SetPlayerPos(playerid,963.0586, 2159.7563, 1011.0303);
		    SetPlayerInterior(playerid,1);
			}
			if(listitem == 7) // Bike School
			{
		   	SetPlayerPos(playerid,1494.8589, 1306.48, 1093.2953);
		    SetPlayerInterior(playerid,3);
			}
			if(listitem == 8) // Driving School
			{
		   	SetPlayerPos(playerid,-2031.1196, -115.8287, 1035.1719);
		    SetPlayerInterior(playerid,3);
			}
			if(listitem == 9) // Back
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU, DIALOG_STYLE_LIST, "Interior Categories","24/7's\nAirports\nAmmunations\nHouses\nHouses 2\nMissions\nStadiums\nCasinos\nShops\nGarages\nGirlfriends\nClothing/Barber Store\nResturants/Clubs\nNo Category\nBurglary\nBurglary 2\nGym\nDepartment\nBack", "Select", "Cancel");
			}
		}
		return 1;
	}
/*==============================Burglary Houses================================*/
	if(dialogid == D_INTERIORMENU+15) //
	{
		if(response)
		{
			if(listitem == 0) // Burglary House #1
			{
		   	SetPlayerPos(playerid,234.6087, 1187.8195, 1080.2578);
		    SetPlayerInterior(playerid,3);
			}
			if(listitem == 1) // Burglary House #2
			{
		   	SetPlayerPos(playerid,225.5707, 1240.0643, 1082.1406);
		    SetPlayerInterior(playerid,2);
			}
			if(listitem == 2) // Burglary House #3
			{
		   	SetPlayerPos(playerid,224.288, 1289.1907, 1082.1406);
		    SetPlayerInterior(playerid,1);
			}
			if(listitem == 3) // Burglary House #4
			{
		   	SetPlayerPos(playerid,239.2819, 1114.1991, 1080.9922);
		    SetPlayerInterior(playerid,5);
			}
			if(listitem == 4) // Burglary House #5
			{
		   	SetPlayerPos(playerid,295.1391, 1473.3719, 1080.2578);
		    SetPlayerInterior(playerid,15);
			}
			if(listitem == 5) // Burglary House #6
			{
		   	SetPlayerPos(playerid,261.1165, 1287.2197, 1080.2578);
		    SetPlayerInterior(playerid,4);
			}
			if(listitem == 6) // Burglary House #7
			{
			SetPlayerPos(playerid,24.3769, 1341.1829, 1084.375);
		    SetPlayerInterior(playerid,10);
			}
			if(listitem == 7) // Burglary House #8
			{
		   	SetPlayerPos(playerid,-262.1759, 1456.6158, 1084.3672);
		    SetPlayerInterior(playerid,4);
			}
			if(listitem == 8) // Burglary House #9
			{
		   	SetPlayerPos(playerid,22.861, 1404.9165, 1084.4297);
		    SetPlayerInterior(playerid,5);
			}
			if(listitem == 9) // Burglary House #10
			{
		   	SetPlayerPos(playerid,140.3679, 1367.8837, 1083.8621);
		    SetPlayerInterior(playerid,5);
			}
			if(listitem == 10) // Back
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU, DIALOG_STYLE_LIST, "Interior Categories","24/7's\nAirports\nAmmunations\nHouses\nHouses 2\nMissions\nStadiums\nCasinos\nShops\nGarages\nGirlfriends\nClothing/Barber Store\nResturants/Clubs\nNo Category\nBurglary\nBurglary 2\nGym\nDepartment\nBack", "Select", "Cancel");
			}
		}
		return 1;
	}
//===============================Burglary Houses 2================================//
	if(dialogid == D_INTERIORMENU+16) //
	{
		if(response)
		{
			if(listitem == 0) // Burglary House #11
			{
		   	SetPlayerPos(playerid,234.2826, 1065.229, 1084.2101);
		    SetPlayerInterior(playerid,6);
			}
			if(listitem == 1) // Burglary House #12
			{
		   	SetPlayerPos(playerid,-68.5145, 1353.8485, 1080.2109);
		    SetPlayerInterior(playerid,6);
			}
			if(listitem == 2) // Burglary House #13
			{
		   	SetPlayerPos(playerid,-285.2511, 1471.197, 1084.375);
		    SetPlayerInterior(playerid,15);
			}
			if(listitem == 3) // Burglary House #14
			{
		   	SetPlayerPos(playerid,-42.5267, 1408.23, 1084.4297);
		    SetPlayerInterior(playerid,8);
			}
			if(listitem == 4) // Burglary House #15
			{
		   	SetPlayerPos(playerid,84.9244, 1324.2983, 1083.8594);
		    SetPlayerInterior(playerid,9);
			}
			if(listitem == 5) // Burglary House #16
			{
		   	SetPlayerPos(playerid,260.7421, 1238.2261, 1084.2578);
		    SetPlayerInterior(playerid,9);
			}
			if(listitem == 6) // Back
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU, DIALOG_STYLE_LIST, "Interior Categories","24/7's\nAirports\nAmmunations\nHouses\nHouses 2\nMissions\nStadiums\nCasinos\nShops\nGarages\nGirlfriends\nClothing/Barber Store\nResturants/Clubs\nNo Category\nBurglary\nBurglary 2\nGym\nDepartment\nBack", "Select", "Cancel");
			}
		}
		return 1;
	}
//===============================Gyms================================//
	if(dialogid == D_INTERIORMENU+17) //
	{
		if(response)
		{
			if(listitem == 0) // LS Gym
			{
		   	SetPlayerPos(playerid,234.2826, 1065.229, 1084.2101);
		    SetPlayerInterior(playerid,6);
			}
			if(listitem == 1) // SF Gym
			{
		   	SetPlayerPos(playerid,771.8632,-40.5659,1000.6865);
		    SetPlayerInterior(playerid,6);
			}
			if(listitem == 2) // LV Gym
			{
		   	SetPlayerPos(playerid,774.0681,-71.8559,1000.6484);
		    SetPlayerInterior(playerid,7);
			}
			if(listitem == 3) // Back
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU, DIALOG_STYLE_LIST, "Interior Categories","24/7's\nAirports\nAmmunations\nHouses\nHouses 2\nMissions\nStadiums\nCasinos\nShops\nGarages\nGirlfriends\nClothing/Barber Store\nResturants/Clubs\nNo Category\nBurglary\nBurglary 2\nGym\nDepartment\nBack", "Select", "Cancel");
			}
		}
		return 1;
	}
//===============================Departments================================//
	if(dialogid == D_INTERIORMENU+18) //
	{
		if(response)
		{
			if(listitem == 0) // SFPD
			{
		   	SetPlayerPos(playerid,246.40,110.84,1003.22);
		    SetPlayerInterior(playerid,10);
			}
			if(listitem == 1) // LSPD
			{
		   	SetPlayerPos(playerid,246.6695, 65.8039, 1003.6406);
		    SetPlayerInterior(playerid,6);
			}
			if(listitem == 2) // LVPD
			{
		   	SetPlayerPos(playerid,288.4723, 170.0647, 1007.1794);
		    SetPlayerInterior(playerid,3);
			}
			if(listitem == 3) // Planning Department(CITY HALL)
			{
		   	SetPlayerPos(playerid,386.5259, 173.6381, 1008.3828);
		    SetPlayerInterior(playerid,3);
			}
			if(listitem == 4) // Back
			{
			ShowPlayerDialog(playerid, D_INTERIORMENU, DIALOG_STYLE_LIST, "Interior Categories","24/7's\nAirports\nAmmunations\nHouses\nHouses 2\nMissions\nStadiums\nCasinos\nShops\nGarages\nGirlfriends\nClothing/Barber Store\nResturants/Clubs\nNo Category\nBurglary\nBurglary 2\nGym\nDepartment\nBack", "Select", "Cancel");
			}
		}
		return 1;
	}
	// Speed test
	//printf("INT_OnDialogResponse executed in  %i ms", (GetTickCount() - speedtest));
	#if defined INT_OnDialogResponse
		return INT_OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1; // return 0 here if it doesn't work
	#endif
}
#if defined _ALS_OnDialogResponse
	#undef OnDialogResponse
#else
	#define _ALS_OnDialogResponse
#endif

#define OnDialogResponse INT_OnDialogResponse
#if defined INT_OnDialogResponse
	forward INT_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif
