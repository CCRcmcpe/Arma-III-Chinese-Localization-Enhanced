class CfgPatches
{
	class A3_Language_F_Tacops
	{
		author="$STR_A3_Bohemia_Interactive";
		name="Arma 3 Tac-Ops - Texts and Translations";
		url="https://www.arma3.com";
		requiredAddons[]=
		{
			"A3_Data_F_Tacops"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]={};
	};
};
class CfgHints
{
	class PremiumContent
	{
		class PremiumTacops
		{
			displayName="$STR_A3_TacOps_CfgMods_nameDLC";
			description="$STR_A3_TacOps_CfgHints_PremiumTacOps_description";
			tip="$STR_A3_CfgHints_PremiumContent_PremiumKarts2";
			arguments[]=
			{
				
				{
					"STR_A3_TacOps_CfgMods_overview"
				},
				"""<img size='9' shadow='0' image='A3\Data_F_tacops\Images\tacops_fm_overview_co.paa' />""",
				"""http://steamcommunity.com/stats/107410/achievements"""
			};
			image="\a3\Data_F_tacops\logos\arma3_tacops_logo_hint_ca.paa";
			logicalOrder=8;
			class Hint
			{
				displayName="$STR_A3_TacOps_CfgMods_nameDLC";
				description="%11%1%12";
				tip="$STR_A3_CfgHints_PremiumContent_PremiumKarts2";
				arguments[]=
				{
					
					{
						"STR_A3_Tacops_CfgMods_overview"
					},
					"""<img size='7' shadow='0' image='A3\Data_F_tacops\Images\tacops_fm_overview_co.paa' />"""
				};
				image="\a3\Data_F_tacops\logos\arma3_tacops_logo_hint_ca.paa";
			};
		};
	};
	class DlcMessage
	{
		class Dlc571710;
		class Dlc744950: Dlc571710
		{
			displayName="$STR_A3_TacOps_CfgMods_nameDLC";
			image="\a3\Data_F_tacops\logos\arma3_tacops_logo_hint_ca.paa";
		};
		class Dlc744950FM: Dlc744950
		{
		};
	};
};
