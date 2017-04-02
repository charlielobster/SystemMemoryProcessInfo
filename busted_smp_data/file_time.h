#pragma once
#include <windows.h>

namespace clr_smp_data {
	public ref class file_time {
	public: 
		file_time() {
			FILETIME fileTime;
			GetSystemTimeAsFileTime(&fileTime);
			dwLowDateTime = fileTime.dwLowDateTime;
			dwHighDateTime = fileTime.dwHighDateTime;
		}
		unsigned long dwLowDateTime;
		unsigned long dwHighDateTime;
	};
};