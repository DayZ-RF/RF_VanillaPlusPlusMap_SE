class RF_VanillaPlusPlusMap_SE_Global: Managed {

	// MARK: - Static Properties

	static ref RF_VanillaPlusPlusMap_SE_RPCInstance rpc;

	static ref RF_VanillaPlusPlusMap_SE_UpdateService updateService;

	// MARK: - Static

	static void InitializeUnits() {
		rpc = new RF_VanillaPlusPlusMap_SE_RPCInstance();
		updateService = new RF_VanillaPlusPlusMap_SE_UpdateService();
	}
}