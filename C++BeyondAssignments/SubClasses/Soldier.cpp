
#include "Soldier.h"

Soldier::Soldier(Npc* npc) : NpcDecorator(npc) { }

void Soldier::render()
{
	NpcDecorator::render();
	std::cout << " Soldier";
}