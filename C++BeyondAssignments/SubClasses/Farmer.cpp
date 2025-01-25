
#include "Farmer.h"

Farmer::Farmer(Npc* npc) : NpcDecorator(npc) { }

void Farmer::render()
{
	NpcDecorator::render();
	std::cout << " Farmer";
}