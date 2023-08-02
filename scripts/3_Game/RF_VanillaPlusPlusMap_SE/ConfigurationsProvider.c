class RF_VanillaPlusPlusMap_SE_ConfigurationsProvider: Managed {

    // MARK: - Private Properties

    private string adminPath = "$profile:RF/VanillaPlusPlusMap/admin.json";

    // MARK: - Init

    void RF_VanillaPlusPlusMap_SE_ConfigurationsProvider() {
        GetAdminConfiguration();
    }

    // MARK: - Internal

    RF_VanillaPlusPlusMap_SE_AdminConfiguration GetAdminConfiguration() {
        return fetchAdminConfiguration();
    }

    void SetAdminConfiguration(RF_VanillaPlusPlusMap_SE_AdminConfiguration config) {
		writeAdminConfuguration(config);
    }

    // MARK: - Private

    private RF_VanillaPlusPlusMap_SE_AdminConfiguration fetchAdminConfiguration() {
        makeDirectory();
        RF_VanillaPlusPlusMap_SE_AdminConfiguration config = loadAdminConfiguration();
        if (!config) {
            config = adminExample();
            if (FileExist(adminPath)) {
                RF_VanillaPlusPlusMap_Log().Error("Configuration file is damaged. I'm going to use default configuration. Repair configuration file or remove it and restart server");
            } else {
                RF_VanillaPlusPlusMap_Log().Info("Configuration file doesn't exist. I'm going to write and use default configuration at: " + adminPath);
                writeAdminConfuguration(config);
            }
        }
        return config;
    }

    private void makeDirectory() {
		string rfFolder = "$profile:RF/";
		string modFolder = rfFolder + "VanillaPlusPlusMap/";

		if (!FileExist(rfFolder)) MakeDirectory(rfFolder);
		if (!FileExist(modFolder)) MakeDirectory(modFolder);
    }

	private RF_VanillaPlusPlusMap_SE_AdminConfiguration loadAdminConfiguration() {
        RF_VanillaPlusPlusMap_SE_AdminConfiguration config;
		JSONService<RF_VanillaPlusPlusMap_SE_AdminConfiguration>.ReadFile(adminPath, config);
        return config;
	}

    private void writeAdminConfuguration(RF_VanillaPlusPlusMap_SE_AdminConfiguration config) {
        JSONService<RF_VanillaPlusPlusMap_SE_AdminConfiguration>.WriteFile(adminPath, config);
    }

    private RF_VanillaPlusPlusMap_SE_AdminConfiguration adminExample() {
        RF_VanillaPlusPlusMap_SE_AdminConfiguration object = new RF_VanillaPlusPlusMap_SE_AdminConfiguration();
        object.updateInterval = 5.0;
        return object;
    }
}