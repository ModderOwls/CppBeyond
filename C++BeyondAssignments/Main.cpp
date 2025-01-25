
#include <iostream>

#include "Classes/NpcElf.h"
#include "Classes/NpcOrc.h"

#include "SubClasses/Farmer.h"
#include "SubClasses/Shaman.h"
#include "SubClasses/Soldier.h"

int main()
{
	//Make Elf Npc class
	Npc* elf = new NpcElf("Bruh");

	//Attach a farmer role to it
	Npc* elfFarmer = new Farmer(elf);

	//Render (print/cout here) it
	elfFarmer->render();

	//Same goes for the rest, they're there to show you can add more or add no role at all.
	std::cout << std::endl;

	Npc* orc = new NpcOrc("Gruh");

	Npc* orcShaman = new Shaman(orc);
	Npc* orcShamanSoldier = new Soldier(orcShaman);

	orcShamanSoldier->render();

	std::cout << std::endl;

	Npc* elfRoleless = new NpcElf("Grugglo");

	elfRoleless->render();
}