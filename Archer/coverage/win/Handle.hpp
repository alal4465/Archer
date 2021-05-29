#pragma once
#include <Windows.h>
#include <memory>
#include "../../fuzzer/Logging.hpp"

namespace Coverage::Os {
	struct CloseHandleDeleter final {
		void operator()(::HANDLE* handle) noexcept
		{
			try {
				if(!CloseHandle(*handle)) {
					LOG_ERROR("CloseHandle failed with last err: " + GetLastError());
				}
			}
			catch (...) {}
			delete handle;
		}
	};

	using Handle = std::unique_ptr<::HANDLE, CloseHandleDeleter>;

	inline Handle make_handle(const ::HANDLE handle) noexcept {
		return Handle(new ::HANDLE(handle));
	}
}