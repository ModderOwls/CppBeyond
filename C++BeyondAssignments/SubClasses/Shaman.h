#pragma once

#include <iostream>

#include "../Types/NpcDecorator.h"

class Shaman : public NpcDecorator
{
public:
	Shaman(Npc* npc);
	void render() override;
};