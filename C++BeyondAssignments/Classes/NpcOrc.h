#pragma once

#include <iostream>

#include "../Types/Npc.h"

class NpcOrc : public Npc 
{
private:
    std::string name;

public:
    NpcOrc(const std::string& name);
    void render() override;
};