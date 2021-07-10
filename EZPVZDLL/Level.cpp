#include "pch.h"
#include "Level.h"

const char* PVZLevel::ToString(PVZLevel pvzl)
{
	switch (pvzl)
	{
	case PVZLevel::Adventure:
		return "Adventure";
	case PVZLevel::Survival_Day:
		return "Survival_Day";
	case PVZLevel::Survival_Night:
		return "Survival_Night";
	case PVZLevel::Survival_Pool:
		return "Survival_Pool";
	case PVZLevel::Survival_Fog:
		return "Survival_Fog";
	case PVZLevel::Survival_Roof:
		return "Survival_Roof";
	case PVZLevel::Survival_Day_Hard:
		return "Survival_Day_Hard";
	case PVZLevel::Survival_Night_Hard:
		return "Survival_Night_Hard";
	case PVZLevel::Survival_Pool_Hard:
		return "Survival_Pool_Hard";
	case PVZLevel::Survival_Fog_Hard:
		return "Survival_Fog_Hard";
	case PVZLevel::Survival_Roof_Hard:
		return "Survival_Roof_Hard";
	case PVZLevel::Survival_Day_Endless:
		return "Survival_Day_Endless";
	case PVZLevel::Survival_Night_Endless:
		return "Survival_Night_Endless";
	case PVZLevel::Survival_Pool_Endless:
		return "Survival_Pool_Endless";
	case PVZLevel::Survival_Fog_Endless:
		return "Survival_Fog_Endless";
	case PVZLevel::Survival_Roof_Endless:
		return "Survival_Roof_Endless";
	case PVZLevel::ZomBotany:
		return "ZomBotany";
	case PVZLevel::Wallnut_Bowling:
		return "Wallnut_Bowling";
	case PVZLevel::Slot_Machine:
		return "Slot_Machine";
	case PVZLevel::It_s_RainingSeeds:
		return "It_s_RainingSeeds";
	case PVZLevel::Beghouled:
		return "Beghouled";
	case PVZLevel::Invisighoul:
		return "Invisighoul";
	case PVZLevel::Seeing_Stars:
		return "Seeing_Stars";
	case PVZLevel::Zombiguarium:
		return "Zombiguarium";
	case PVZLevel::Beghouled_Twist:
		return "Beghouled_Twist";
	case PVZLevel::Big_Trouble_Little_Zombie:
		return "Big_Trouble_Little_Zombie";
	case PVZLevel::Portal_Combat:
		return "Portal_Combat";
	case PVZLevel::Colum_Like_You_See_Em:
		return "Colum_Like_You_See_Em";
	case PVZLevel::Bobsied_Bonanza:
		return "Bobsied_Bonanza";
	case PVZLevel::Zombie_Nimble_Zombie_Quick:
		return "Zombie_Nimble_Zombie_Quick";
	case PVZLevel::Wharka_Zombie:
		return "Wharka_Zombie";
	case PVZLevel::Last_Stand:
		return "Last_Stand";
	case PVZLevel::Zombotany2:
		return "Zombotany2";
	case PVZLevel::Wallnut_Bowling2:
		return "Wallnut_Bowling2";
	case PVZLevel::Pogo_Party:
		return "Pogo_Party";
	case PVZLevel::Dr_Zomboss_s_Revenge:
		return "Dr_Zomboss_s_Revenge";
	case PVZLevel::Art_Challenge_Wallnut:
		return "Art_Challenge_Wallnut";
	case PVZLevel::Sunny_Day:
		return "Sunny_Day";
	case PVZLevel::Unsodded:
		return "Unsodded";
	case PVZLevel::Big_Time:
		return "Big_Time";
	case PVZLevel::Art_Challenge_Sunflower:
		return "Art_Challenge_Sunflower";
	case PVZLevel::Air_Raid:
		return "Air_Raid";
	case PVZLevel::Ice_Level:
		return "Ice_Level";
	case PVZLevel::Zen_Garden:
		return "Zen_Garden";
	case PVZLevel::High_Gravity:
		return "High_Gravity";
	case PVZLevel::Grave_Danger:
		return "Grave_Danger";
	case PVZLevel::Can_You_DigIt:
		return "Can_You_DigIt";
	case PVZLevel::Dark_Stormy_Night:
		return "Dark_Stormy_Night";
	case PVZLevel::Bungee_Blitz:
		return "Bungee_Blitz";
	case PVZLevel::Squirrel:
		return "Squirrel";
	case PVZLevel::Treeof_Wisdom:
		return "Treeof_Wisdom";
	case PVZLevel::Vasebreaker:
		return "Vasebreaker";
	case PVZLevel::To_the_Left:
		return "To_the_Left";
	case PVZLevel::Third_Vase:
		return "Third_Vase";
	case PVZLevel::Chain_Rection:
		return "Chain_Rection";
	case PVZLevel::Mis_forM_etal:
		return "Mis_forM_etal";
	case PVZLevel::Scary_Potter:
		return "Scary_Potter";
	case PVZLevel::Hokey_Pokey:
		return "Hokey_Pokey";
	case PVZLevel::Another_Chain_Rection:
		return "Another_Chain_Rection";
	case PVZLevel::Aceof_Vace:
		return "Aceof_Vace";
	case PVZLevel::Vasebreaker_Endless:
		return "Vasebreaker_Endless";
	case PVZLevel::I_Zombie:
		return "I_Zombie";
	case PVZLevel::I_ZombieToo:
		return "I_ZombieToo";
	case PVZLevel::IZ_CanYouDigIt:
		return "IZ_CanYouDigIt";
	case PVZLevel::Totally_Nuts:
		return "Totally_Nuts";
	case PVZLevel::Dead_Zeppelin:
		return "Dead_Zeppelin";
	case PVZLevel::Me_Smash:
		return "Me_Smash";
	case PVZLevel::Zom_Boogie:
		return "Zom_Boogie";
	case PVZLevel::Three_Hit_Wonder:
		return "Three_Hit_Wonder";
	case PVZLevel::All_your_brain_z_r_belong_to_us:
		return "All_your_brain_z_r_belong_to_us";
	case PVZLevel::I_Zombie_Endless:
		return "I_Zombie_Endless";
	case PVZLevel::Upsell:
		return "Upsell";
	case PVZLevel::Intro:
		return "Intro";
	default:
		return "InValid_Value_Of_PVZLevel";
	}
}