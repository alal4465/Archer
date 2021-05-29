#pragma once
#include "../DebuggerBase.hpp"
#include "./utils.hpp"

namespace Coverage::Os {
	class Debugger : public Coverage::DebuggerBase {
	public:
		Debugger();
		~Debugger() override = default;
	private:
	};
}