#define _ARMA_

class CfgPatches {
	class RF_VanillaPlusPlusMap_SE {
		author = "Dad Fedor & romabeorn";
		name = "RF_VanillaPlusPlusMap_SE";
		url = "https://discord.gg/d9kP7ezX3n";
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {"DZ_Data", "DZ_Sounds_Effects", "RF_VanillaPlusPlusMap_CL", "VanillaPlusPlus"};
		requiredVersion = 0.1;
	};

    class DZ_Gear_Camping {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data"};
    };
};

class CfgMods {
	class RF_VanillaPlusPlusMap_SE {
		type="mod";
		dir="RF_VanillaPlusPlusMap_SE";
		class defs {
			class gameScriptModule {
				value = "";
				files[] = { "RF_VanillaPlusPlusMap_SE/scripts/3_Game" };
			};
			class worldScriptModule {
				value = "";
				files[] = { "RF_VanillaPlusPlusMap_SE/scripts/4_World" };
			};
			class missionScriptModule {
				value = "";
				files[] = { "RF_VanillaPlusPlusMap_SE/scripts/5_Mission" };
			};
		};
	};
};
