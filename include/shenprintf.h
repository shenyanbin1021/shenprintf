#pragma once
#include <string>

#if !defined(SHENPRINTF_EXPORT)
#define SHENPRINTF_EXPORT
#endif

namespace shenprintf
{
	SHENPRINTF_EXPORT void shenprintf(const std::string& str);
}
