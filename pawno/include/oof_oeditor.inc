/*
	Object Editor by Maximus (Sky)
	Version: 1.5
	Using in gamemode: OoF
	Credits: Maximus, Incognito (streamer) and SA-MP Team

	* Changelog
	Version 1.0: Initial Release
	Version 1.1: Changed MAX_ADMIN_OBJECTS to 500 and fixed a few bugs.
	Version 1.5: Added Object Slot system (10 slots).
	Version 2.0:
		* Added MAX_OBJECT_SLOTS in ObjectInfo enum because object slot system was not working correctly.
		* Changed MAX_OBJECT_SLOTS to 3.

*/

#define ENABLE_OBJ true 			// enable / disable admin object creation
#define MAX_ADMIN_OBJECTS	500
#define MAX_OBJECT_SLOTS	5
#define MAX_SLOTTEXT_LENGTH	25		// Max length of object slot name
#define MAX_TEXT_LENGTH		128		// Max object material text "128"
#define MAX_CAR_OBJECTS		25

//**  Objects System
#if ENABLE_OBJ == true
enum ObjectInfo
{
	oID,
	oModel,
	Text3D:oTextID,
	Float:oX,
	Float:oY,
	Float:oZ,
	Float:oRX,
	Float:oRY,
	Float:oRZ,
	oMIndex,
	oText[128],
	oMSize,
	oFontFace[64],
	oFontSize,
	oFontBold,
	oFontColor,
	oBackColor,
	oAlignment,
	oTXDname,
	oMColor,
	oAttachedVehicle,
	oSlot
};
new ObjectData[MAX_ADMIN_OBJECTS][ObjectInfo];
#endif

new CurrObject[MAX_PLAYERS] = { -1, ... };
new AttachedObj[MAX_VEHICLES][MAX_CAR_OBJECTS];
new ObjectSlot[MAX_PLAYERS] = { -1, ... };
new ObjectSlotName[MAX_OBJECT_SLOTS][MAX_SLOTTEXT_LENGTH];

// Get the material index of a player object
#define GetObjectMaterialIndex(%0) ObjectData[%0][oMIndex];

#define GetObjectSlot(%0) ObjectSlot[%0]

#if ENABLE_OBJ == true
new Iterator:Objects[MAX_OBJECT_SLOTS]<MAX_ADMIN_OBJECTS>;
#endif

////////////////////////////////////////////////////////////////
//// Object System Callbacks
////////////////////////////////////////////////////////////////
public OnPlayerEditDynamicObject(playerid, objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
	if(ObjectData[CurrObject[playerid]][oAttachedVehicle] > -1)
	{
		if(response == EDIT_RESPONSE_FINAL)
		{
			new Float:tmpx, Float:tmpy, Float:tmpz, Float:tmpa;
			new Float:finalx, Float:finaly;
			new Float:vx, Float:vy, Float:vz, Float:vr;
			GetVehiclePos(ObjectData[CurrObject[playerid]][oAttachedVehicle], vx, vy, vz);
			GetVehicleZAngle(ObjectData[CurrObject[playerid]][oAttachedVehicle], vr);
			tmpx = x - vx;
			tmpy = y - vy;
			tmpz = z - vz;
			tmpa = rz - vr;
			finalx = tmpx*floatcos(vr, degrees)+tmpy*floatsin(vr, degrees);
			finaly = -tmpx*floatsin(vr, degrees)+tmpy*floatcos(vr, degrees);
			printf("[debug] object id %d itr %d, veh id %d", CurrObject[playerid], ObjectData[CurrObject[playerid]][oID], ObjectData[CurrObject[playerid]][oAttachedVehicle]);
			AttachDynamicObjectToVehicle(ObjectData[CurrObject[playerid]][oID], ObjectData[CurrObject[playerid]][oAttachedVehicle], finalx, finaly, tmpz, rx, ry, tmpa);
			OEH_SetObjectPos(CurrObject[playerid], finalx, finaly, tmpz, rx, ry, tmpa);
			SendClientMessage(playerid, COLOR_LGREEN, "Attached Object position saved.");
			//return 1;
		}
		/*else if(response == EDIT_RESPONSE_UPDATE)
		{
			new Float:tmpx, Float:tmpy, Float:tmpz;
			new Float:vx, Float:vy, Float:vz;
			GetVehiclePos(ObjectData[objectid][oAttachedVehicle], vx, vy, vz);
			tmpx = x - vx;
			tmpx = y - vy;
			tmpx = z - vz;
			AttachDynamicObjectToVehicle(ObjectData[CurrObject[playerid]][oID], ObjectData[objectid][oAttachedVehicle], tmpx, tmpy, tmpz, rx, ry, rz);
		}*/
		else if(response == EDIT_RESPONSE_CANCEL)
		{
			OEH_DestroyDynamicObject(ObjectSlot[playerid], CurrObject[playerid]);
			SendClientMessage(playerid, COLOR_PINK2, "Attached Object destroyed.");
			//return 1;
		}
	}
	else {
		//new string[64];
		//format(string, sizeof(string), "%f called", x);
		//SendClientMessage(playerid, -1, string);
		
		// Player finished editing an object
		if(response == EDIT_RESPONSE_FINAL)
		{
			OEH_SetObjectPos(CurrObject[playerid], x, y, z, rx, ry, rz);
			SendClientMessage(playerid, COLOR_LGREEN, "Object position saved.");
		}
		/*else if(response == EDIT_RESPONSE_UPDATE)
		{
			// Update object position (not sure if it syncs to other players)
			//if(!IsValidDynamicObject(ObjectData[CurrObject[playerid]][oID])) return 1;
			SetDynamicObjectPos(ObjectData[CurrObject[playerid]][oID], x, y, z);
			SetDynamicObjectRot(ObjectData[CurrObject[playerid]][oID], rx, ry, rz);
		}*/
		else if(response == EDIT_RESPONSE_CANCEL)
		{
			// Player cancelled editing object, put object pos to old pos
			SetDynamicObjectPos(ObjectData[CurrObject[playerid]][oID], ObjectData[CurrObject[playerid]][oX], ObjectData[CurrObject[playerid]][oY], ObjectData[CurrObject[playerid]][oZ]);
			SetDynamicObjectRot(ObjectData[CurrObject[playerid]][oID], ObjectData[CurrObject[playerid]][oRX], ObjectData[CurrObject[playerid]][oRY], ObjectData[CurrObject[playerid]][oRZ]);
		}
	}

	#if defined OEH_OnPlayerEditDynamicObject
		return OEH_OnPlayerEditDynamicObject(playerid, objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerEditDynamicObject
	#undef OnPlayerEditDynamicObject
#else
	#define _ALS_OnPlayerEditDynamicObject
#endif

#define OnPlayerEditDynamicObject OEH_OnPlayerEditDynamicObject
#if defined OEH_OnPlayerEditDynamicObject
	forward OEH_OnPlayerEditDynamicObject(playerid, objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz);
#endif

public OnPlayerSelectDynamicObject(playerid, objectid, modelid, Float:x, Float:y, Float:z)
{
	/*new index, slot;
	// Find edit object
	for(new s = 0; s < MAX_OBJECT_SLOTS; s++)
	{
		foreach(new i : Objects[s])
		{
			//Object found
			if(ObjectData[i][oID] == objectid)
			{
				slot = s;
				index = i;
				printf("[debug] objectid: %d, oID %d, index %d, slot %d", objectid, ObjectData[index][oID], index, slot);
				break;
			}
		}
	}*/

	printf("objectid: %d", objectid);
	new index;
	new slot = GetPlayerVirtualWorld(playerid) - OEDITOR_WORLD;

	if(slot < 0 || slot > MAX_OBJECT_SLOTS)
	{
		printf("stunt world: %d", slot);
		SendClientMessage(playerid, COLOR_RED, "You are not in a stunt world. Type /ostart to switch to a stunt world.");
		return 1;
	}

	//new tslot;
	for(new s = 0; s < MAX_OBJECT_SLOTS; s++)
	{
		// Find edit object
		foreach(new i : Objects[s])
		{
			// Object found
			if(ObjectData[i][oID] == objectid)
			{
				index = i;
				printf("index %d i %d slot %d", index, i ,s);
				break;
			}
		}
		/*if(Iter_Contains(Objects[s], ObjectData[index][oID]))
		{
			printf("inside iter contains:  s %d objectid %d", s, objectid);
			tslot = s;
		}
		else {
			new string[70];
			format(string, sizeof(string), "This object is in slot '%d'. Change your slot to select this object.", s);
			SendClientMessage(playerid, COLOR_RED, string);
			return 1;
		}*/
	}

	if(slot != ObjectData[index][oSlot])
	{
		new string[70];
		format(string, sizeof(string), "This object is in slot '%d'. Change your slot to select this object.", ObjectData[index][oSlot]);
		SendClientMessage(playerid, COLOR_RED, string);
		return 1;
	}

	// Find edit object
	/*foreach(new i : Objects[tslot])
	{
		// Object found
		if(ObjectData[i][oID] == objectid)
		{
			index = i;
			break;
		}
	}*/

	//if(ObjectSlot[playerid] != slot) {
	/*if(ObjectData[index][oSlot] != slot) {
		new string[70];
		format(string, sizeof(string), "This object is in slot '%d'. Change your slot to select this object.", slot+1);
		SendClientMessage(playerid, COLOR_RED, string);
		return 1;
	}*/

	//if(ObjectSlot[playerid] != ObjectData[index][oSlot])

	/*for(new slot = 0; slot < MAX_OBJECT_SLOTS; slot++) {
	if(!Iter_Contains(Objects[slot], index))
	{
		printf("[debug] object select: slot %d, objectid %d, index %d", ObjectSlot[playerid], ObjectData[index][oID], index);
		SendClientMessage(playerid, COLOR_RED, "Invalid object slot.");
		return 1;
	}
	}*/

	/*for(new slot = 0; slot < MAX_OBJECT_SLOTS; slot++) {
		printf("[debug] object select: slot %d, objectid %d", slot, ObjectData[index][oID]);
		if(!Iter_Contains(Objects[slot], ObjectData[index][oID]))
		{
			printf("[debug] object select 2: slot %d, objectid %d", slot, ObjectData[index][oID]);
			SendClientMessage(playerid, COLOR_RED, "Invalid object slot.");
			return 1;
		}
	}*/

	CurrObject[playerid] = index;
	printf("[debug] OnPlayerSelectDynamicObject: CurrObject[playerid] '%d', ObjectData[CurrObject[playerid]][oID] '%d'", CurrObject[playerid], ObjectData[CurrObject[playerid]][oID]);
	//EditDynamicObject(playerid, ObjectData[CurrObject[playerid]][oID]);
	
	new string[55];
	format(string, sizeof(string), "Object selected. You are now editing object id: %d", index);
	SendClientMessage(playerid, COLOR_LGREEN, string);
	if(index == -1) SendClientMessage(playerid, COLOR_RED, "WARNING: Object ID '-1' is invalid.");

	// Cancel Object Selection
	CancelEdit(playerid);
	
	#if defined _OnPlayerSelectDynamicObject
		return _OnPlayerSelectDynamicObject(playerid, objectid, modelid, Float:x, Float:y, Float:z);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerSelect\
	DynamicObject
	#undef OnPlayerSelectDynamicObject
#else
	#define _ALS_OnPlayerSelectDynamicObject
#endif

#define OnPlayerSelectDynamicObject _OnPlayerSelectDynamicObject
#if defined _OnPlayerSelectDynamicObject
	forward _OnPlayerSelectDynamicObject(playerid, objectid, modelid, Float:x, Float:y, Float:z);
#endif

////////////////////////////////////////////////////////////////
//// Object System Stocks
////////////////////////////////////////////////////////////////

// CreateDynamicObject_I = CreateDynamicObject and add Iterator
stock OEH_CreateDynamicObject(slot, modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, index = -1)
{
	if(index == -1) index = Iter_Free(Objects[slot]);

	if(index != -1)
	{
		// Add iterator
		Iter_Add(Objects[slot], index);

		// Create object
		ObjectData[index][oID] = CreateDynamicObject(modelid, x, y, z, rx, ry, rz, -1, -1, -1, 300.0);
		Streamer_SetFloatData(STREAMER_TYPE_OBJECT, ObjectData[index][oID], E_STREAMER_DRAW_DISTANCE, 300.0);

		// Update the streamer
		foreach(new i : Player)
		{
			if(IsPlayerInRangeOfPoint(i, 200.0, x, y, z)) Streamer_Update(i);
		}

		printf("oid: %d, slot %d, index %d", ObjectData[index][oID], slot, index);

		ObjectData[index][oModel] = modelid;
		ObjectData[index][oX] = x;
		ObjectData[index][oY] = y;
		ObjectData[index][oZ] = z;
		ObjectData[index][oRX] = rx;
		ObjectData[index][oRY] = ry;
		ObjectData[index][oRZ] = rz;
		ObjectData[index][oAttachedVehicle] = -1;
		ObjectData[index][oSlot] = slot;
		printf("on create: %d", ObjectData[index][oSlot]);

		return index;
	}
	else print("Error: Tried to add too many dynamic objects");
	return index;
}

stock OEH_DestroyDynamicObject(slot, index)
{
	new next;
	if(Iter_Contains(Objects[slot], index))
	{
		if(ObjectData[index][oAttachedVehicle] > -1)
		{
			new refindex = GetCarObjectIndex(ObjectData[index][oAttachedVehicle], index);
			if(refindex > -1) AttachedObj[ObjectData[index][oAttachedVehicle]][refindex] = -1;
		}
		DestroyDynamicObject(ObjectData[index][oID]);
		Iter_SafeRemove(Objects[slot], index, next);
		ResetObjectIndex(index);
		return next;
	}
	print("Error: Tried to delete a object which does not exist");
	return -1;
}

stock DeleteAllObjects(slot)
{
	foreach(new i : Objects[slot])
	{
		if(i != -1) i = OEH_DestroyDynamicObject(slot, i);
	}
	// Reset any player variables
	foreach(new i : Player)
	{
		CurrObject[i] = -1;
	}
	return 1;
}

DestroyAttachedObject(index)
{
	for(new i = 0; i < MAX_CAR_OBJECTS; i++)
	{
		if(AttachedObj[index][i] > -1) {
			OEH_DestroyDynamicObject(5, AttachedObj[index][i]);
			printf("[debug] DestroyAttachedObject index(vid): %d, i(slot): %d", index, i);
		}
	}
}

stock UpdateAttachedObject(carindex, objindex)
{
	new refindex = GetCarObjectIndex(carindex, objindex);
	if(refindex > -1)
	{
		AttachedObj[carindex][refindex] = -1;
		return 1;
	}
	return 0;
}

GetCarObjectIndex(carindex, objindex)
{
	for(new i = 0; i < MAX_CAR_OBJECTS; i++)
	{
		if(AttachedObj[carindex][i] == objindex) return i;
	}
	return -1;
}

GetFreeObjectSlotInCar(carid)
{
	for(new i = 0; i < MAX_CAR_OBJECTS; i++)
	{
		if(AttachedObj[carid][i] == -1) return i;
	}
	return -1;
}

stock OEH_SetObjectPos(index, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
	ObjectData[index][oX] = x;
	ObjectData[index][oY] = y;
	ObjectData[index][oZ] = z;
	ObjectData[index][oRX] = rx;
	ObjectData[index][oRY] = ry;
	ObjectData[index][oRZ] = rz;

	SetDynamicObjectPos(ObjectData[index][oID], ObjectData[index][oX], ObjectData[index][oY], ObjectData[index][oZ]);
	SetDynamicObjectRot(ObjectData[index][oID], ObjectData[index][oRX], ObjectData[index][oRY], ObjectData[index][oRZ]);
	return 1;
}

stock UpdateObjectMaterialText(index)
{
	SetDynamicObjectMaterialText(ObjectData[index][oID], 0,
		ObjectData[index][oText], ObjectData[index][oMSize],
		ObjectData[index][oFontFace], ObjectData[index][oFontSize],
		ObjectData[index][oFontBold], ObjectData[index][oFontColor],
		ObjectData[index][oBackColor], ObjectData[index][oAlignment]);
	return 1;
}

// Resets all data on a object slot
stock ResetObjectIndex(index)
{
	new tmpobject[ObjectInfo];
	ObjectData[index] = tmpobject;
	return 1;
}

stock SaveObjects(slot, path[])
{
	new File:pFile;
	pFile = fopen(path, io_append);

	if(!pFile) return printf("[warning] Failed to write to file: %s", path);

	fwrite(pFile, "// Only On Foot Object Editor //\r\n");

	new string[256];
	foreach(new i : Objects[slot])
	{
		if(ObjectData[i][oAttachedVehicle] > -1) continue;
		
		//new bool:writeobject = true;

		// Write objects to file
		format(string, sizeof(string), "CreateDynamicObject(%d, %.4f, %.4f, %.4f, %.4f, %.4f, %.4f);\r\n",
		ObjectData[i][oModel], ObjectData[i][oX], ObjectData[i][oY], ObjectData[i][oZ],
		ObjectData[i][oRX], ObjectData[i][oRY], ObjectData[i][oRZ]);
		fwrite(pFile, string);
	}
	fclose(pFile);
	return 1;
}

LoadObjects(playerid, slot, path[])
{
	new templine[256], count;
	new tmpobject[ObjectInfo];
	new File:pFile;
	pFile = fopen(path, io_read);

	if(!pFile) return printf("[warning] Failed to open file: %s", path);

	while(fread(pFile, templine))
	{
		strtrim(templine);
		new skip;
		if(strfind(templine, "CreateDynamicObject", true) == -1) skip = 1;
		if(skip == 1) continue;

		// Only fetch data after "CreateDynamicObject("
		strmid(templine, templine, 20, sizeof(templine), sizeof(templine));
		// Remove ");"
		strmid(templine, templine, 0, strfind(templine, ");", true), sizeof(templine));

		sscanf(templine, "p<,>dffffff", tmpobject[oModel], tmpobject[oX], tmpobject[oY], tmpobject[oZ],
			tmpobject[oRX], tmpobject[oRY], tmpobject[oRZ]);

		// Create object that we retrieved from file.
		new index;
		index = OEH_CreateDynamicObject(slot, tmpobject[oModel], tmpobject[oX], tmpobject[oY], tmpobject[oZ], tmpobject[oRX], tmpobject[oRY], tmpobject[oRZ]);
		count++;
		if(debugmsg == true) {
			new string[128];
			format(string, sizeof string, "loading objects: slot: %d index: %d, model id: %d", slot, index, tmpobject[oModel]);
			SCMToAdmin(COLOR_GREEN, string, 3);
		}
	}

	format(templine, sizeof(templine), "Loaded %d objects!", count);
	SendClientMessage(playerid, STEALTH_GREEN, templine);
	fclose(pFile);
	return 1;
}

/*stock UpdateAttachedObjectRef(carindex, objindex)
{
	new refindex = GetCarObjectRefIndex(carindex, objindex);
	if(refindex > -1)
	{
		CarData[carindex][CarObjectRef][refindex] = -1;
		sqlite_SaveVehicleObjectData(carindex);
	return 1;
	}
	return 0;
}*/

stock FixText(text[])
{
	new len = strlen(text);
	if(len > 1)
	{
		for(new i = 0; i < len; i++)
		{
			if(text[i] == 92)
			{
				// New Line
				if(text[i+1] == 'n')
				{
					text[i] = '\n';
					for(new j = i+1; j < len; j++) text[j] = text[j+1], text[j+1] = 0;
					continue;
				}

				// Tab
				if(text[i+1] == 't')
				{
					text[i] = '\t';
					for(new j = i+1; j < len-1; j++) text[j] = text[j+1], text[j+1] = 0;
					continue;
				}

				// Literal
				if(text[i+1] == 92)
				{
					text[i] = 92;
					for(new j = i+1; j < len-1; j++) text[j] = text[j+1], text[j+1] = 0;
				}
			}
		}
	}
	return 1;
}
