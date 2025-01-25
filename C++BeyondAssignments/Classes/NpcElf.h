#pragma once

#include <iostream>

#include "../Types/Npc.h"

class NpcElf : public Npc 
{
private:
    std::string name;

public:
    NpcElf(const std::string& name);
    void render() override;
};