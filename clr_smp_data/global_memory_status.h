#pragma once
#include <windows.h>

namespace clr_smp_data 
{
	public ref class global_memory_status 
	{
	public:
		global_memory_status(MEMORYSTATUSEX status) 
		{
			dwLength = status.dwLength;
			dwMemoryLoad = status.dwMemoryLoad;
			ullTotalPhys = status.ullTotalPhys;
			ullAvailPhys = status.ullAvailPhys;
			ullTotalPageFile = status.ullTotalPageFile;
			ullAvailPageFile = status.ullAvailPageFile;
			ullTotalVirtual = status.ullTotalVirtual;
			ullAvailVirtual = status.ullAvailVirtual;
			ullAvailExtendedVirtual = status.ullAvailExtendedVirtual;
		}
		property unsigned __int64 dwLength;
		property unsigned __int64 dwMemoryLoad;
		property unsigned __int64 ullTotalPhys;
		property unsigned __int64 ullAvailPhys;
		property unsigned __int64 ullTotalPageFile;
		property unsigned __int64 ullAvailPageFile;
		property unsigned __int64 ullTotalVirtual;
		property unsigned __int64 ullAvailVirtual;
		property unsigned __int64 ullAvailExtendedVirtual;
	};
};