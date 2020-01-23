
#ifndef J2AE_MESSAGE_H
#define J2AE_MESSAGE_H

#include <string>

struct Message
{
	std::string message;
	void* payload = nullptr;
};

#endif
