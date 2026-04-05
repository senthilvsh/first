#pragma once

#include <stdint.h>
#include <vector>
#include <cassert>

class Memory
{
public:
	explicit Memory(uint64_t size);

	///
	/// @brief Read a value of type T from memory.
	/// 
	/// @tparam T The type to read (uint8_t, uint16_t, uint32_t, uint64_t).
	/// 
	/// @param addr The memory address.
	/// 
	/// @return	The value stored.
	/// 
	template<typename T>
	T read(uint64_t addr) const
	{
		assert(addr + sizeof(T) <= data.size());

		T value{};
		std::memcpy(&value, &data[addr], sizeof(T));
		return value;
	}

	///
	/// @brief Write a value of type T to memory.
	/// 
	/// @tparam T The type to write (uint8_t, uint16_t, uint32_t, uint64_t).
	/// 
	/// @param addr The memory address.	
	/// @param value The value to be written.
	/// 
	template<typename T>
	void write(uint64_t addr, T value)
	{
		assert(addr + sizeof(T) <= data.size());

		std::memcpy(&data[addr], &value, sizeof(T));
	}

private:
	std::vector<uint8_t> data;
};
