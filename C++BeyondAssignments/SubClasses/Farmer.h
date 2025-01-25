#pragma once

#include <iostream>

#include "../Types/NpcDecorator.h"

class Farmer : public NpcDecorator
{
public:
	Farmer(Npc* npc);
	void render() override;
};