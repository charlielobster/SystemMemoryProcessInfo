#pragma once
#include <windows.h>

namespace clr_smp_data {
	public ref class file_time {
	public:
		void clone(FILETIME f) {
			dwLowDateTime = f.dwLowDateTime;
			dwHighDateTime = f.dwHighDateTime;
		}
		file_time() { }
		file_time(FILETIME f) : 
			dwLowDateTime(f.dwLowDateTime), 
			dwHighDateTime(f.dwHighDateTime) 
		{}
		unsigned __int64 dwLowDateTime;
		unsigned __int64 dwHighDateTime;
	};
};