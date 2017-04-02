#pragma once
#include <windows.h>

namespace clr_smp_data {

	public ref class system_info {
	public:
		system_info() {
			SYSTEM_INFO info;
			GetSystemInfo(&info);
			wProcessorArchitecture = info.wProcessorArchitecture;
			dwPageSize = info.dwPageSize;
			lpMinimumApplicationAddress = (unsigned long)info.lpMinimumApplicationAddress;
			lpMaximumApplicationAddress = (unsigned long)info.lpMaximumApplicationAddress;
			dwActiveProcessorMask = info.dwActiveProcessorMask;
			dwNumberOfProcessors = info.dwNumberOfProcessors;
			dwProcessorType = info.dwProcessorType;
			dwAllocationGranularity = info.dwAllocationGranularity;
			wProcessorLevel = info.wProcessorLevel;
			wProcessorRevision = info.wProcessorRevision;
		}
		unsigned int wProcessorArchitecture;
		unsigned long dwPageSize;
		unsigned long lpMinimumApplicationAddress;
		unsigned long lpMaximumApplicationAddress;
		unsigned long dwActiveProcessorMask;
		unsigned long dwNumberOfProcessors;
		unsigned long dwProcessorType;
		unsigned long dwAllocationGranularity;
		unsigned int wProcessorLevel;
		unsigned int wProcessorRevision;
	};
};


