class CfgPatches
{
	class A3_Language_F_EPA
	{
		author="$STR_A3_Bohemia_Interactive";
		name="Arma 3 Survive Episode - Texts and Translations";
		url="https://www.arma3.com";
		requiredAddons[]=
		{
			"A3_Language_F_Gamma"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]={};
	};
};
class CfgMods
{
	EPA=1;
};
class CfgHints
{
	class Default
	{
	};
	class WeaponList
	{
		class bluforMarksman
		{
			displayName="%11";
			description="%12";
			tip="";
			arguments[]=
			{
				
				{
					"str_a3_cfgweapons_srifle_abr0"
				},
				
				{
					"STR_A3_CfgWeapons_srifle_ABR_Library0"
				}
			};
			image="\a3\ui_f\data\gui\cfg\hints\Ranged_ca.paa";
		};
		class opfroMarksman
		{
			displayName="%11";
			description="%12";
			tip="";
			arguments[]=
			{
				
				{
					"str_a3_cfgweapons_srifle_dmr_01_f0"
				},
				
				{
					"STR_A3_CfgWeapons_srifle_DMR_01_F_library"
				}
			};
			image="\a3\ui_f\data\gui\cfg\hints\Ranged_ca.paa";
		};
		class bluforpistol2
		{
			displayName="%11";
			description="%12";
			tip="";
			arguments[]=
			{
				
				{
					"str_a3_cfgweapons_hgun_pistol_heavy_01_f0"
				},
				
				{
					"str_a3_cfgweapons_hgun_pistol_heavy_01_f_library0"
				}
			};
			image="\a3\ui_f\data\gui\cfg\hints\Handgun_ca.paa";
			weapon="hgun_Pistol_heavy_01_F";
			logicalOrder=1;
		};
		class opforpistol2
		{
			displayName="%11";
			description="%12";
			tip="";
			arguments[]=
			{
				
				{
					"str_a3_cfgweapons_hgun_pistol_heavy_02_f0"
				},
				
				{
					"str_a3_cfgweapons_hgun_pistol_heavy_02_f_library0"
				}
			};
			image="\a3\ui_f\data\gui\cfg\hints\Handgun_ca.paa";
			weapon="hgun_Pistol_heavy_02_F";
		};
	};
};
