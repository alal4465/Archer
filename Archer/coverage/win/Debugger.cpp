#include "Debugger.hpp"

Coverage::Os::Debugger::Debugger() {
	Coverage::Os::enable_sedebug_privileges();
}