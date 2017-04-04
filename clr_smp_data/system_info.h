#pragma once
#include <windows.h>

namespace clr_smp_data {

	public ref class system_info {
	public:
		void clone(SYSTEM_INFO info) {
			wProcessorArchitecture = info.wProcessorArchitecture;
			dwPageSize = info.dwPageSize;
			lpMinimumApplicationAddress = (unsigned __int64)info.lpMinimumApplicationAddress;
			lpMaximumApplicationAddress = (unsigned __int64)info.lpMaximumApplicationAddress;
			dwActiveProcessorMask = info.dwActiveProcessorMask;
			dwNumberOfProcessors = info.dwNumberOfProcessors;
			dwProcessorType = info.dwProcessorType;
			dwAllocationGranularity = info.dwAllocationGranularity;
			wProcessorLevel = info.wProcessorLevel;
			wProcessorRevision = info.wProcessorRevision;
		}
		unsigned int wProcessorArchitecture;
		unsigned __int64 dwPageSize;
		unsigned __int64 lpMinimumApplicationAddress;
		unsigned __int64 lpMaximumApplicationAddress;
		unsigned __int64 dwActiveProcessorMask;
		unsigned __int64 dwNumberOfProcessors;
		unsigned __int64 dwProcessorType;
		unsigned __int64 dwAllocationGranularity;
		unsigned int wProcessorLevel;
		unsigned int wProcessorRevision;
	};
};


