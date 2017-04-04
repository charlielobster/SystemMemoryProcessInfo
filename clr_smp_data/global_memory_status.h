#pragma once
#include <windows.h>

namespace clr_smp_data {
	public ref class global_memory_status {
	public:
		void clone(MEMORYSTATUSEX status) {
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
		unsigned __int64 dwLength;
		unsigned __int64 dwMemoryLoad;
		unsigned __int64 ullTotalPhys;
		unsigned __int64 ullAvailPhys;
		unsigned __int64 ullTotalPageFile;
		unsigned __int64 ullAvailPageFile;
		unsigned __int64 ullTotalVirtual;
		unsigned __int64 ullAvailVirtual;
		unsigned __int64 ullAvailExtendedVirtual;
	};
};