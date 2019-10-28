#pragma once
class Ram
{
private:
	unsigned int ram_size;

public:
	unsigned int getRamSize() { return ram_size; }

	void setRamSize(unsigned int ram_size) { this->ram_size = ram_size; }
};

