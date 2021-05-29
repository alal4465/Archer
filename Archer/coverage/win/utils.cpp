#include "utils.hpp"

void Coverage::Os::enable_sedebug_privileges() {
	Handle hToken = Os::make_handle(nullptr);
	assert(OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, hToken.get()));

	LUID luid{ 0 };
	assert(LookupPrivilegeValueA(nullptr, "SeDebugPrivilege", &luid));

	TOKEN_PRIVILEGES token_priv{ 0 };
	token_priv.PrivilegeCount = 1;
	token_priv.Privileges[0].Luid = luid;
	token_priv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	assert(AdjustTokenPrivileges(*hToken.get(), false, &token_priv, sizeof(TOKEN_PRIVILEGES), nullptr, nullptr));
	LOG_INFO("SeDebugPrivilege enabled on source process");
}