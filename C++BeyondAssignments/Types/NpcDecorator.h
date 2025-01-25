#pragma once

#include "Npc.h"

//Abstract class for decorating (changing) the Npc's render function.
class NpcDecorator : public Npc
{
protected:
	Npc* npc;

public:
	NpcDecorator(Npc* npc);
	virtual void render() override;
};