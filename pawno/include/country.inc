/*	Player country lookup by Emmet
	Edited by Maximus

	Functions:
	forward GetPlayerCountry(playerid, country[], size = sizeof(country));
	forward GetPlayerRegion(playerid, region[], size = sizeof(region));
	forward GetPlayerCity(playerid, city[], size = sizeof(city));
	forward GetPlayerISP(playerid, isp[], size = sizeof(isp));
	forward GetPlayerOrganization(playerid, org[], size = sizeof(org));

Changelog:
Version 1.1
	Added Two New Functions:
	GetPlayerISP(playerid, isp[], size = sizeof(isp));
	GetPlayerOrganization(playerid, org[], size = sizeof(org));
	Updated api website to ip-api.com
*/

#include <a_http>

#if !defined MAX_COUNTRY_NAME
	#define MAX_COUNTRY_NAME    (32)
#endif

#if !defined MAX_ISP_NAME
	#define MAX_ISP_NAME		(50)
#endif

#if !defined MAX_ASN_LENGTH
	#define MAX_ASN_LENGTH		(33)
#endif

#if !defined MAX_LAT_LON_LENGTH
	#define MAX_LAT_LON_LENGTH		(12)
#endif

#if !defined MAX_PROXY_LENGTH
	#define MAX_PROXY_LENGTH		(8)
#endif

//forward OnLookupComplete(playerid, country[], region[], city[], isp[], org[]);

enum e_LookupData {
	// Packed string containing the name of the country.
	e_LookupCountry[MAX_COUNTRY_NAME + 1 char],
	
	// Packed string containing the name of the region.
	e_LookupRegion[MAX_COUNTRY_NAME + 1 char],

	// Packed string containing the name of the city.
	e_LookupCity[MAX_COUNTRY_NAME + 1 char],

	e_LookupISP[MAX_ISP_NAME + 1 char],
	e_LookupOrg[MAX_ISP_NAME + 1 char],
	e_LookupASN[MAX_ASN_LENGTH + 1 char],
	e_LookupLat[MAX_LAT_LON_LENGTH + 1 char],
	e_LookupLon[MAX_LAT_LON_LENGTH + 1 char],
	e_LookupProxy[MAX_PROXY_LENGTH + 1 char]
};

static
	g_asLookupData[MAX_PLAYERS][e_LookupData]
;

public OnPlayerConnect(playerid)
{
	new string[64];

	strpack(g_asLookupData[playerid][e_LookupCountry], "Unknown", MAX_COUNTRY_NAME char);
	strpack(g_asLookupData[playerid][e_LookupRegion], "Unknown", MAX_COUNTRY_NAME char);
	strpack(g_asLookupData[playerid][e_LookupCity], "Unknown", MAX_COUNTRY_NAME char);
	strpack(g_asLookupData[playerid][e_LookupISP], "Unknown", MAX_ISP_NAME char);
	strpack(g_asLookupData[playerid][e_LookupOrg], "Unknown", MAX_ISP_NAME char);
	strpack(g_asLookupData[playerid][e_LookupASN], "Unknown", MAX_ASN_LENGTH char);
	strpack(g_asLookupData[playerid][e_LookupLat], "Unknown", MAX_LAT_LON_LENGTH char);
	strpack(g_asLookupData[playerid][e_LookupLon], "Unknown", MAX_LAT_LON_LENGTH char);
	strpack(g_asLookupData[playerid][e_LookupProxy], "Unknown", MAX_PROXY_LENGTH char);

	GetPlayerIp(playerid, string, sizeof(string));

	if (!IsPlayerNPC(playerid) && strcmp(string, "127.0.0.1") != 0)
	{
		// Insert the domain at the beginning of the IP.
		strins(string, "ip-api.com/json/", 0);
		strcat(string, "?fields=134873");
		//strins(string, "www.realip.info/api/p/geoip.php?ip=", 0);
		
		// Send the lookup request.
		HTTP(playerid, HTTP_GET, string, "", "HTTP_OnLookupResponse");
	}
	#if defined CL_OnPlayerConnect
		return CL_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}

forward HTTP_OnLookupResponse(index, response, data[]);
public HTTP_OnLookupResponse(index, response, data[])
{
	new
		pos = -1;

	if (!IsPlayerConnected(index))
	{
		return 0;
	}
	else if (response == 200)
	{
		if (strfind(data, "Reserved", true) != -1 || strlen(data) < 15)
		{
			return 0;
		}
		else
		{
			new
				country[MAX_COUNTRY_NAME],
				region[MAX_COUNTRY_NAME],
				city[MAX_COUNTRY_NAME],
				isp[MAX_ISP_NAME],
				org[MAX_ISP_NAME],
				asn[MAX_ASN_LENGTH],
				lat[MAX_LAT_LON_LENGTH],
				lon[MAX_LAT_LON_LENGTH],
				proxy[MAX_PROXY_LENGTH]
			;

			if ((pos = strfind(data, "\"country\":")) != -1)
			{
				pos = pos + 11;

				strmid(country, data, pos, strfind(data, "\"", true, pos), MAX_COUNTRY_NAME);
			}
			if ((pos = strfind(data, "\"regionName\":")) != -1)
			{
				pos = pos + 14;

				strmid(region, data, pos, strfind(data, "\"", true, pos), MAX_COUNTRY_NAME);

			}
			if ((pos = strfind(data, "\"city\":")) != -1)
			{
				pos = pos + 8;

				strmid(city, data, pos, strfind(data, "\"", true, pos), MAX_COUNTRY_NAME);
			}
			if ((pos = strfind(data, "\"isp\":")) != -1)
			{
				pos = pos + 7;

				strmid(isp, data, pos, strfind(data, "\"", true, pos), MAX_ISP_NAME);
			}
			if ((pos = strfind(data, "\"org\":")) != -1)
			{
				pos = pos + 7;

				strmid(org, data, pos, strfind(data, "\"", true, pos), MAX_ISP_NAME);
			}
			if ((pos = strfind(data, "\"as\":")) != -1)
			{
				pos = pos + 6;

				strmid(asn, data, pos, strfind(data, "\"", true, pos), MAX_ASN_LENGTH);
			}
			if ((pos = strfind(data, "\"lat\":")) != -1)
			{
				pos = pos + 7;

				strmid(lat, data, pos, strfind(data, "\"", true, pos), MAX_LAT_LON_LENGTH);
			}
			if ((pos = strfind(data, "\"lon\":")) != -1)
			{
				pos = pos + 7;

				strmid(lon, data, pos, strfind(data, "\"", true, pos), MAX_LAT_LON_LENGTH);
			}
			if ((pos = strfind(data, "\"proxy\":")) != -1)
			{
				pos = pos + 9;

				strmid(proxy, data, pos, strfind(data, "\"", true, pos), MAX_PROXY_LENGTH);
			}

			if (pos != -1)
			{
				// Call our callback, which is called when a lookup has completed.
				//if(isnull(region)) region = "Unknown";
				//CallLocalFunction("OnLookupComplete", "dsssss", index, country, region, city, isp, org);

				// Pack the data for later use.
				strpack(g_asLookupData[index][e_LookupCountry], country, MAX_COUNTRY_NAME char);
				strpack(g_asLookupData[index][e_LookupRegion], region, MAX_COUNTRY_NAME char);
				strpack(g_asLookupData[index][e_LookupCity], city, MAX_COUNTRY_NAME char);
				strpack(g_asLookupData[index][e_LookupISP], isp, MAX_ISP_NAME char);
				strpack(g_asLookupData[index][e_LookupOrg], org, MAX_ISP_NAME char);
				strpack(g_asLookupData[index][e_LookupASN], asn, MAX_ASN_LENGTH char);
				strpack(g_asLookupData[index][e_LookupLat], lat, MAX_LAT_LON_LENGTH char);
				strpack(g_asLookupData[index][e_LookupLon], lon, MAX_LAT_LON_LENGTH char);
				strpack(g_asLookupData[index][e_LookupProxy], proxy, MAX_PROXY_LENGTH char);
			}
		}
	}
	return 0;
}

stock GetPlayerCountry(playerid, country[], size = sizeof(country))
{
	if (IsPlayerConnected(playerid))
		return strunpack(country, g_asLookupData[playerid][e_LookupCountry], size);

	else
		strunpack(country, !"Unknown", size);

	return 0;
}

stock GetPlayerRegion(playerid, region[], size = sizeof(region))
{
	if (IsPlayerConnected(playerid))
		return strunpack(region, g_asLookupData[playerid][e_LookupRegion], size);

	else
		strunpack(region, !"Unknown", size);
		
	return 0;
}

stock GetPlayerCity(playerid, city[], size = sizeof(city))
{
	if (IsPlayerConnected(playerid))
		return strunpack(city, g_asLookupData[playerid][e_LookupCity], size);

	else
		strunpack(city, !"Unknown", size);
		
	return 0;
}

stock GetPlayerISP(playerid, isp[], size = sizeof(isp))
{
	if (IsPlayerConnected(playerid))
		return strunpack(isp, g_asLookupData[playerid][e_LookupISP], size);

	else
		strunpack(isp, !"Unknown", size);

	return 0;
}

stock GetPlayerOrganization(playerid, org[], size = sizeof(org))
{
	if (IsPlayerConnected(playerid))
		return strunpack(org, g_asLookupData[playerid][e_LookupISP], size);

	else
		strunpack(org, !"Unknown", size);

	return 0;
}

stock GetPlayerASN(playerid, asn[], size = sizeof(asn))
{
	if (IsPlayerConnected(playerid))
		return strunpack(asn, g_asLookupData[playerid][e_LookupASN], size);

	else
		strunpack(asn, !"Unknown", size);

	return 0;
}

stock GetPlayerLatitude(playerid, lat[], size = sizeof(lat))
{
	if (IsPlayerConnected(playerid))
		return strunpack(lat, g_asLookupData[playerid][e_LookupLat], size);

	else
		strunpack(lat, !"Unknown", size);

	return 0;
}

stock GetPlayerLongitude(playerid, lon[], size = sizeof(lon))
{
	if (IsPlayerConnected(playerid))
		return strunpack(lon, g_asLookupData[playerid][e_LookupLon], size);

	else
		strunpack(lon, !"Unknown", size);

	return 0;
}

stock GetPlayerProxy(playerid, proxy[], size = sizeof(proxy))
{
	if (IsPlayerConnected(playerid))
		return strunpack(proxy, g_asLookupData[playerid][e_LookupProxy], size);

	else
		strunpack(proxy, !"Unknown", size);

	return 0;
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect CL_OnPlayerConnect

#if defined CL_OnPlayerConnect
	forward CL_OnPlayerConnect(playerid);
#endif