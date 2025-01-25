
#include "Shaman.h"

Shaman::Shaman(Npc* npc) : NpcDecorator(npc) { }

void Shaman::render()
{
	NpcDecorator::render();
	std::cout << " Shaman";
}