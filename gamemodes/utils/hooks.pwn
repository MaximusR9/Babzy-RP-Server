//** HOOKS
stock VIH_AddStaticVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2)
{
	new vehicleid = AddStaticVehicle(modelid, spawn_x, spawn_y, spawn_z, z_angle, color1, color2);
	Iter_Add(Vehicle, vehicleid);
	SetVehicleHealth(vehicleid, MAX_VEHICLE_HEALTH);
	return vehicleid;
}

#if defined _ALS_AddStaticVeihcle
	#undef AddStaticVehicle
#else
	#define _ALS_AddStaticVeihcle
#endif
#define AddStaticVehicle VIH_AddStaticVehicle
//==================================================================================
stock VIH_AddStaticVehicleEx(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2, respawn_delay)
{
	new vehicleid = AddStaticVehicleEx(modelid, spawn_x, spawn_y, spawn_z, z_angle, color1, color2, respawn_delay);
	Iter_Add(Vehicle, vehicleid);
	SetVehicleHealth(vehicleid, MAX_VEHICLE_HEALTH);
	return vehicleid;
}

#if defined _ALS_AddStaticVehicleEx
	#undef AddStaticVehicleEx
#else
	#define _ALS_AddStaticVehicleEx
#endif
#define AddStaticVehicleEx VIH_AddStaticVehicleEx
//===============================================================
stock VIH_CreateVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2, respawn_delay, addsiren=0)
{
	if(debugmsg == true) print("[debug] ooffunc calls here. createvehicle");
	new vehicleid = CreateVehicle(modelid, spawn_x, spawn_y, spawn_z, z_angle, color1, color2, respawn_delay, addsiren);
	Iter_Add(Vehicle, vehicleid);
	SetVehicleHealth(vehicleid, MAX_VEHICLE_HEALTH);
	return vehicleid;
}

stock VIH_CreateAdminVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2, respawn_delay, addsiren=0)
{
	if(debugmsg == true) print("[debug] ooffunc calls here.");
	new vehicleid = CreateVehicle(modelid, spawn_x, spawn_y, spawn_z, z_angle, color1, color2, respawn_delay, addsiren);
	Iter_Add(AdminVeh, vehicleid);
	if(debugmsg == true)
	{
		printf("[debug] ooffunc vehicle id %d", vehicleid);
		printf("Iter_Contains AdminVeh %d", Iter_Contains(AdminVeh, vehicleid));
		printf("Iter_Contains Vehicle %d", Iter_Contains(Vehicle, vehicleid));
	}
	SetVehicleHealth(vehicleid, MAX_VEHICLE_HEALTH);
	return vehicleid;
}