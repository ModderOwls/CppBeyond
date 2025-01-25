#include "NpcOrc.h"

NpcOrc::NpcOrc(const std::string& name)
{
	this->name = name;
}

void NpcOrc::render()
{
	std::cout << "Orc (" << name << "): ";
}