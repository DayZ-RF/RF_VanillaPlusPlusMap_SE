class RF_VanillaPlusPlusMap_SE_UpdateService: Managed {

    // MARK: - Private Properties

	private autoptr map<string, autoptr RF_VanillaPlusPlusMap_CL_RPCMarker> markersMap = new map<string, autoptr RF_VanillaPlusPlusMap_CL_RPCMarker>();

    private autoptr Timer timer = new Timer();

    // MARK: - Init

    void RF_VanillaPlusPlusMap_SE_UpdateService() {
        auto configurationsProvider = new RF_VanillaPlusPlusMap_SE_ConfigurationsProvider();
		auto adminConfig = configurationsProvider.GetAdminConfiguration();
		auto updateInterval = adminConfig.updateInterval;
        timer.Run(updateInterval, this, "tick", NULL, true);
    }

    // MARK: - Internal

    void AddRPCMarker(RF_VanillaPlusPlusMap_CL_RPCMarker rpcMarker) {
		markersMap[rpcMarker.uuid] = rpcMarker;
    }

    void RemoveRPCMarker(string uuid) {
		markersMap.Remove(uuid);
    }

    // MARK: - Private

	private void tick() {
		auto rpcData = new RF_VanillaPlusPlusMap_CL_RPCData();
		rpcData.markersMap = markersMap;
		RF_VanillaPlusPlusMap_SE_Global.rpc.Send("didReceiveRPCData", rpcData);
	}
}