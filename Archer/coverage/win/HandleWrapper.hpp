#pragma once
#include <Windows.h>
#include <memory>
#include "../../fuzzer/Logging.hpp"

namespace Coverage::Os {
	struct CloseHandleDeleter final {
		void operator()(::HANDLE* raw_handle_ptr) noexcept
		{
			try {
				if(!CloseHandle(*raw_handle_ptr)) {
					LOG_ERROR("CloseHandle failed with last err: " + GetLastError());
				}
			}
			catch (...) {}
			delete raw_handle_ptr;
		}
	};

	using HandleWrapper = std::unique_ptr<::HANDLE, CloseHandleDeleter>;

	inline HandleWrapper make_handle_wrapper(const ::HANDLE raw_handle) noexcept {
		return HandleWrapper(new ::HANDLE(raw_handle));
	}
}