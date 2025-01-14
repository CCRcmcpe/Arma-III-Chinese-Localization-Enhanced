class CfgPatches
{
	class A3_Language_F_Exp_A
	{
		author="$STR_A3_Bohemia_Interactive";
		name="Arma 3 Nexus Update - Texts and Translations";
		url="https://www.arma3.com";
		requiredAddons[]=
		{
			"A3_Data_F_Exp_A"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]={};
	};
};
class CfgHints
{
	class InfantryMovement
	{
		class Stamina
		{
			displayName="$STR_A3_Stamina1";
			description="$STR_A3_Stamina2";
			tip="";
			arguments[]={};
			image="\a3\ui_f\data\gui\cfg\hints\Stamina_ca.paa";
		};
		class Limping
		{
			displayName="$STR_A3_StaminaInjury1";
			description="$STR_A3_StaminaInjury2";
			tip="$STR_A3_StaminaInjury3";
			arguments[]={};
			image="\a3\ui_f\data\gui\cfg\hints\Stamina_Injury_ca.paa";
		};
		class OverEncumbrance
		{
			displayName="$STR_A3_StaminaOverEncumbrance1";
			description="$STR_A3_StaminaOverEncumbrance2";
			tip="$STR_A3_StaminaOverEncumbrance3";
			arguments[]={};
			image="\a3\ui_f\data\gui\cfg\hints\Stamina_OverEncumbrance_CA.paa";
		};
	};
	class NexusUpdate
	{
		displayName="$STR_A3_NexusUpdate";
		logicalOrder=20;
		category="Product";
		class Nexus
		{
			displayName="$STR_A3_Nexus1";
			description="$STR_A3_Nexus2";
			arguments[]={};
			image="\a3\ui_f\data\gui\cfg\hints\Commanding_ca.paa";
			logicalOrder=1;
		};
		class Units
		{
			displayName="$STR_A3_Units1";
			description="$STR_A3_Units2";
			tip="$STR_A3_Units3";
			arguments[]={};
			image="\a3\ui_f\data\gui\cfg\hints\Commanding_ca.paa";
			logicalOrder=2;
		};
		class EndGame
		{
			displayName="$STR_A3_EndGame1";
			description="$STR_A3_EndGame2";
			tip="$STR_A3_EndGame3";
			arguments[]={};
			image="\a3\ui_f\data\gui\cfg\hints\Commanding_ca.paa";
			logicalOrder=3;
		};
		class Armor
		{
			displayName="$STR_A3_Armor1";
			description="$STR_A3_Armor2";
			arguments[]={};
			image="\a3\ui_f\data\gui\cfg\hints\Commanding_ca.paa";
			logicalOrder=4;
		};
		class Audio
		{
			displayName="$STR_A3_Audio1";
			description="$STR_A3_Audio2";
			arguments[]={};
			image="\a3\ui_f\data\gui\cfg\hints\Commanding_ca.paa";
			logicalOrder=5;
		};
		class Stamina
		{
			displayName="$STR_A3_StaminaInfo1";
			description="$STR_A3_StaminaInfo2";
			arguments[]={};
			image="\a3\ui_f\data\gui\cfg\hints\Commanding_ca.paa";
			logicalOrder=6;
		};
		class ModDependency
		{
			displayName="$STR_A3_ModDependency1";
			description="$STR_A3_ModDependency2";
			tip="$STR_A3_ModDependency3";
			arguments[]={};
			image="\a3\ui_f\data\gui\cfg\hints\Commanding_ca.paa";
			logicalOrder=7;
		};
	};
};
