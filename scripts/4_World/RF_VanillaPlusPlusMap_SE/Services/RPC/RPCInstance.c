class RF_VanillaPlusPlusMap_SE_RPCInstance: RF_RPCInstance {

    // MARK: - Override Properties

    override int GetRPCType() { return RF_VanillaPlusPlusMap_Constant.RPC_TYPE; }

    override string GetModName() { return RF_VanillaPlusPlusMap_Constant.MOD_NAME; }

    // MARK: - Internal

    void Send(string key, RF_VanillaPlusPlusMap_CL_RPCData rpcObject, PlayerIdentity playerIdentity = null) {
        Param3<string, string, RF_VanillaPlusPlusMap_CL_RPCData> param = new Param3<string, string, RF_VanillaPlusPlusMap_CL_RPCData>(GetModName(), key, rpcObject);
        GetGame().RPCSingleParam(null, GetRPCType(), param, true, playerIdentity);
    }
}