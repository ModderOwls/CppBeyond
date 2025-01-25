#pragma once

#include <iostream>

#include "../Types/NpcDecorator.h"

class Soldier : public NpcDecorator
{
public:
	Soldier(Npc* npc);
	void render() override;
};