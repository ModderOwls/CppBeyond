
#include "NpcElf.h"

NpcElf::NpcElf(const std::string& name)
{
	this->name = name;
}

void NpcElf::render()
{
	std::cout << "Elf (" << name << "): ";
}