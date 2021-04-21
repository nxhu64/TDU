#pragma once
#include "tdf_Memory.h"

/*
	Taken from SK83RJOSH's Teardown repo
	https://github.com/SK83RJOSH/Teardown/blob/master/types.h
*/

/*
* Helper class for interacting with Teardown strings.
*
* This string is only meant to be used to forward and receive data from the game.
*
* It does not support:
*     Copying and assignment
*     Modifications
*
* You are welcome to submit pull requests for these if you wish.
*/

class small_string
{
public:
	small_string() {};
	small_string(const char* str) {

		size_t len = str ? strlen(str) : 0;
		char* dst = m_StackBuffer[15] ? m_HeapBuffer : &m_StackBuffer[0];

		if (len > 15)
		{
			dst = (char*)Teardown::MemoryFunctions::Alloc(sizeof(char) * (len + 1));

			if (dst == nullptr)
				return;

			if (m_StackBuffer[15])
				Teardown::MemoryFunctions::Free(m_HeapBuffer);
			else
				m_StackBuffer[15] = 1;

			m_HeapBuffer = dst;
		}

		memcpy(dst, str, len);
		dst[len] = 0;
	}
	small_string(const small_string&) = delete;

	~small_string() {
		if (m_StackBuffer[15])
			Teardown::MemoryFunctions::Free(m_HeapBuffer);
	}

	const char* c_str() const { return m_StackBuffer[15] ? m_HeapBuffer : &m_StackBuffer[0]; }

private:
	union {
		char* m_HeapBuffer;
		char m_StackBuffer[16] = { 0 };
	};
};

/*
* Helper class for interacting with Teardown vectors.
*
* This vector is only meant to be used to forward and receive data from the game.
*
* It does not support:
*     Copying and assignment
*     Non-trivially constructible types
*     Deletion
*
* You are welcome to submit pull requests for these if you wish.
*/

template<typename T>
class small_vector {
public:
	small_vector() {};
	small_vector(uint32_t capacity) { reserve(capacity); };
	//small_vector(const small_vector&) = delete;
	//void operator=(const small_vector&) = delete;
	~small_vector() { clear(); }

	T* begin() const { return m_Data; }
	T* end() const { return m_Data + m_Size; }
	T* data() const { return m_Data; }
	uint32_t size() const { return m_Size; }
	uint32_t capacity() const { return m_Capacity; }

	void push_back(const T& value)
	{
		if (m_Capacity <= m_Size)
		{
			reserve(2 * m_Capacity + 1);
		}

		m_Data[m_Size] = value;
		++m_Size;
	}

	void reserve(uint32_t capacity) {
		if (auto memory = MemoryNew<T>(capacity))
		{
			T* data = m_Data;
			uint32_t size = m_Size;

			if (data != nullptr)
			{
				if (size >= capacity)
				{
					size = capacity;
				}
				else
				{
					memset(memory, sizeof(T) * size, sizeof(T) * capacity - size);
				}

				memcpy(m_Data, data, sizeof(T) * size);
				Teardown::MemoryFunctions::Free(data);
				m_Size = size;
			}
			else
			{
				m_Size = 0;
				memset(memory, 0, sizeof(T) * capacity);
			}

			m_Data = memory;
			m_Capacity = capacity;
		}
	}

	void clear()
	{
		if (m_Data != nullptr)
		{
			m_Size = 0;
			m_Capacity = 0;
			Teardown::MemoryFunctions::Free(m_Data);
			m_Data = nullptr;
		}
	}

private:
	uint32_t m_Size = 0;
	uint32_t m_Capacity = 0;
	T* m_Data = nullptr;
};