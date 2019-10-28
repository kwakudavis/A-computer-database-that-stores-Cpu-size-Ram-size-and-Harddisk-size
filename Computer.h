#pragma once
#include "Harddisk.h"
#include "Cpu.h"
#include "Ram.h"
#include <ostream>
#include <fstream>
#include <iostream>
#include <string>
#define FILENAME "computers.txt"

using namespace std;


class Computer
{
private:
	Harddisk Harddisk;
	Cpu	Cpu;
	Ram	Ram;

public:
	//Constructor
	Computer(unsigned int cpuSpeed = 1000, unsigned int ramSize = 8192, unsigned int harddiskSize = 512000);

	void display();

	bool save(ostream& outputStream);
	
	bool load(istream& intputStream);
};

