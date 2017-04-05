#pragma once
#include <windows.h>

namespace clr_smp_data 
{
	public ref class system_info 
	{
	public:
		system_info(SYSTEM_INFO info) 
		{
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
		property unsigned int wProcessorArchitecture;
		property unsigned __int64 dwPageSize;
		property unsigned __int64 lpMinimumApplicationAddress;
		property unsigned __int64 lpMaximumApplicationAddress;
		property unsigned __int64 dwActiveProcessorMask;
		property unsigned __int64 dwNumberOfProcessors;
		property unsigned __int64 dwProcessorType;
		property unsigned __int64 dwAllocationGranularity;
		property unsigned int wProcessorLevel;
		property unsigned int wProcessorRevision;
	};
};


