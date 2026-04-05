#include <iostream>
#include <stdio.h>
#include "Memory.hpp"

int main()
{
	std::cout << "First v0.1\n";

	for (int i = 1; i <= 10;i++) {
		std::cout << i << "\n";
	}

	Memory mem(256);
	mem.write<uint8_t>(0x00, 0x0A);
	mem.write<uint8_t>(0x01, 0x0B);

	printf("0x%0.2X\n", mem.read<uint8_t>(0x00));
	printf("0x%0.2X\n", mem.read<uint8_t>(0x01));
	printf("0x%0.4X\n", mem.read<uint16_t>(0x00));

	return 0;
}
