
#ifndef J2AE_HANDLE_H
#define J2AE_HANDLE_H

#include <cstdint>

namespace J2AE
{
	struct Handle
	{
		uint32_t index: 12;
		uint32_t counter: 15;
		uint32_t type: 5;

		Handle(): index(0), counter(0), type(0)
		{}

		Handle(uint32_t index, uint32_t counter, uint32_t type)
			: index(index), counter(counter), type(type)
		{}

		inline
		explicit operator uint32_t() const
		{
			return type << 27 | counter << 12 | index;
		}
	};

}

#endif
