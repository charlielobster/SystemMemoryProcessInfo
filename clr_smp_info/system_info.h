#pragma once

#include <windows.h>

namespace clr_smp_info {

	public ref class system_info
	{
	public:
		system_info(SYSTEM_INFO info) {
			wProcessorArchitecture = info.wProcessorArchitecture;
			dwPageSize = info.dwPageSize;
//			lpMinimumApplicationAddress = info.lpMinimumApplicationAddress;
//			lpMaximumApplicationAddress = info.lpMaximumApplicationAddress;
			dwActiveProcessorMask = info.dwActiveProcessorMask;
			dwNumberOfProcessors = info.dwNumberOfProcessors;
			dwProcessorType = info.dwProcessorType;
			dwAllocationGranularity = info.dwAllocationGranularity;
			wProcessorLevel = info.wProcessorLevel;
			wProcessorRevision = info.wProcessorRevision;
		}
		unsigned  int wProcessorArchitecture;
		unsigned long dwPageSize;
		long lpMinimumApplicationAddress;
		long lpMaximumApplicationAddress;
		unsigned long dwActiveProcessorMask;
		unsigned long dwNumberOfProcessors;
		unsigned long dwProcessorType;
		unsigned long dwAllocationGranularity;
		unsigned int wProcessorLevel;
		unsigned int wProcessorRevision;
	};
};


