#pragma once

#include <stdint.h>
#include <vector>
#include <cassert>

// Allowed types when calling read/write functions
template <typename T>
concept AllowedUnsignedInt =
	std::same_as<T, uint8_t> ||
	std::same_as<T, uint16_t> ||
	std::same_as<T, uint32_t> ||
	std::same_as<T, uint64_t>;

// Represents the physical RAM of the virtual machine
class Memory
{
public:
	// Create RAM of the given size
	explicit Memory(uint64_t size);

	// Read a value from the given address, in little-endian order.
	// The size of the value is determined using the template variable.
	template<AllowedUnsignedInt T>
	T read(uint64_t addr) const
	{
		assert(addr + sizeof(T) <= data.size());

		T value{};
		std::memcpy(&value, &data[addr], sizeof(T));
		return value;
	}

	// Write a value to the given address, in little-endian order.
	// The size of the value is determined using the template variable.
	template<AllowedUnsignedInt T>
	void write(uint64_t addr, T value)
	{
		assert(addr + sizeof(T) <= data.size());

		std::memcpy(&data[addr], &value, sizeof(T));
	}

private:
	std::vector<uint8_t> data;
};
