#pragma once
#include <Windows.h>
#include <cassert>
#include "HandleWrapper.hpp"
#include "../../fuzzer/Logging.hpp"

namespace Coverage::Os {
	void enable_sedebug_privileges();
}