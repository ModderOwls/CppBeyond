
#include "NpcDecorator.h"

NpcDecorator::NpcDecorator(Npc* npc)
{
	this->npc = npc;
}

void NpcDecorator::render()
{
	npc->render();
}