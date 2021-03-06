#pragma once

#include <cstdint>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "Memory.h"
#include "GPU.h"

typedef unsigned char byte;
typedef uint16_t u16;

class CPU {
public:
	Memory& ram;
	Memory& hdd;
	int registerOP;
	int register0;
	int register1;
	int programCounter;
	int firstAvailableS;
	int sectorSize;
	int numSectors;
	int interruptRegister;
	int interPos;
	int interTartgetPos;
	int currentIntPos;
	bool interrupted;
	std::vector<int> interruptBuffer;
	u16 currentTime;
	GPU& gpu;
	bool halt;

	CPU(int, int, Memory&, Memory&, GPU&);
	int checkArgument(int, int);
	void execute(u16);
	void interrupt();
	void tick();
};