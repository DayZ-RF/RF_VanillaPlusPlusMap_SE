modded class MissionServer {

    // MARK: - Private Properties

	// MARK: - Modded Methods

	override void OnInit() {
		super.OnInit();
		RF_VanillaPlusPlusMap_SE_Global.InitializeUnits();
	}

    // MARK: - Internal

	void RF_VanillaPlusPlusMap_SE_AddMarker(string uuid, string markerName, string iconPath, vector color, vector position, Param2<bool, bool> isActive, Param2<bool, bool> is3DActive) {
		auto rpcMarker = RF_VanillaPlusPlusMap_CL_RPCMarker();
		rpcMarker.uuid = uuid;
		rpcMarker.markerName = markerName;
		rpcMarker.iconPath = iconPath;
		rpcMarker.color = color;
		rpcMarker.position = position;
		rpcMarker.isActive.isEnabled = isActive.param1;
		rpcMarker.isActive.isForced = isActive.param2;
		rpcMarker.is3DActive.isEnabled = is3DActive.param1;
		rpcMarker.is3DActive.isForced = is3DActive.param2;
		RF_VanillaPlusPlusMap_SE_Global.updateService.AddRPCMarker(rpcMarker);
	}

	void RF_VanillaPlusPlusMap_SE_RemoveMarker(string uuid) {
		RF_VanillaPlusPlusMap_SE_Global.updateService.RemoveRPCMarker(uuid);
	}
}