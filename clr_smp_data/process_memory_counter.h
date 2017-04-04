#pragma once
#include <psapi.h>

namespace clr_smp_data {
	public ref class process_memory_counter {
	public:
		process_memory_counter(PROCESS_MEMORY_COUNTERS p) : 
			PageFaultCount(p.PageFaultCount),
			PeakWorkingSetSize(p.PeakWorkingSetSize),
			WorkingSetSize(p.WorkingSetSize),
			QuotaPeakPagedPoolUsage(p.QuotaPeakPagedPoolUsage),
			QuotaPagedPoolUsage(p.QuotaPagedPoolUsage),
			QuotaPeakNonPagedPoolUsage(p.QuotaPeakNonPagedPoolUsage),
			QuotaNonPagedPoolUsage(p.QuotaNonPagedPoolUsage),
			PagefileUsage(p.PagefileUsage),
			PeakPagefileUsage(p.PeakPagefileUsage) 
		{ }
		unsigned __int64 PageFaultCount;
		unsigned __int64 PeakWorkingSetSize;
		unsigned __int64 WorkingSetSize;
		unsigned __int64 QuotaPeakPagedPoolUsage;
		unsigned __int64 QuotaPagedPoolUsage;
		unsigned __int64 QuotaPeakNonPagedPoolUsage;
		unsigned __int64 QuotaNonPagedPoolUsage;
		unsigned __int64 PagefileUsage;
		unsigned __int64 PeakPagefileUsage;
	};
};