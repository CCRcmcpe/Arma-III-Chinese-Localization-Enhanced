class CfgPatches
{
	class A3_Language_F_Exp_B
	{
		author="$STR_A3_Bohemia_Interactive";
		name="Arma 3 Eden Update - Texts and Translations";
		url="https://www.arma3.com";
		requiredAddons[]=
		{
			"A3_Data_F_Exp_B"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]={};
	};
};
class CfgHints
{
	class EdenUpdate
	{
		displayName="$STR_A3_CfgHints_EdenUpdate_EdenUpdate_displayName";
		logicalOrder=20;
		category="Product";
		class EdenUpdate
		{
			displayName="$STR_A3_CfgHints_EdenUpdate_EdenUpdate_displayName";
			description="$STR_A3_CfgHints_EdenUpdate_EdenUpdate_description";
			arguments[]={};
			image="\a3\ui_f\data\gui\cfg\hints\Commanding_ca.paa";
			logicalOrder=1;
		};
		class EdenEditor: EdenUpdate
		{
			displayName="$STR_A3_CfgHints_EdenUpdate_EdenEditor_displayName";
			description="$STR_A3_CfgHints_EdenUpdate_EdenEditor_description";
			logicalOrder=2;
		};
		class CombatAudio: EdenUpdate
		{
			displayName="$STR_A3_CfgHints_EdenUpdate_CombatAudio_displayName";
			description="$STR_A3_CfgHints_EdenUpdate_CombatAudio_description";
			logicalOrder=3;
		};
		class LauncherServerBrowser: EdenUpdate
		{
			displayName="$STR_A3_CfgHints_EdenUpdate_LauncherServerBrowser_displayName";
			description="$STR_A3_CfgHints_EdenUpdate_LauncherServerBrowser_description";
			logicalOrder=4;
		};
		class Font: EdenUpdate
		{
			displayName="$STR_A3_CfgHints_EdenUpdate_Font_displayName";
			description="$STR_A3_CfgHints_EdenUpdate_Font_description";
			logicalOrder=5;
		};
		class Analytics: EdenUpdate
		{
			displayName="$STR_A3_CfgHints_EdenUpdate_Analytics_displayName";
			description="$STR_A3_CfgHints_EdenUpdate_Analytics_description";
			logicalOrder=6;
		};
		class SteamLeaderboards: EdenUpdate
		{
			displayName="$STR_A3_CfgHints_EdenUpdate_SteamLeaderboards_displayName";
			description="$STR_A3_CfgHints_EdenUpdate_SteamLeaderboards_description";
			logicalOrder=7;
		};
	};
};
