#pragma once
#include <psapi.h>

namespace clr_smp_data 
{
	public ref class process_memory_counter 
	{
	public:
		process_memory_counter(PROCESS_MEMORY_COUNTERS counter)
		{
			PageFaultCount = counter.PageFaultCount;
			PeakWorkingSetSize = counter.PeakWorkingSetSize;
			WorkingSetSize = counter.WorkingSetSize;
			QuotaPeakPagedPoolUsage = counter.QuotaPeakPagedPoolUsage;
			QuotaPagedPoolUsage = counter.QuotaPagedPoolUsage;
			QuotaPeakNonPagedPoolUsage = counter.QuotaPeakNonPagedPoolUsage;
			QuotaNonPagedPoolUsage = counter.QuotaNonPagedPoolUsage;
			PagefileUsage = counter.PagefileUsage;
			PeakPagefileUsage = counter.PeakPagefileUsage; 
		}
		property unsigned __int64 PageFaultCount;
		property unsigned __int64 PeakWorkingSetSize;
		property unsigned __int64 WorkingSetSize;
		property unsigned __int64 QuotaPeakPagedPoolUsage;
		property unsigned __int64 QuotaPagedPoolUsage;
		property unsigned __int64 QuotaPeakNonPagedPoolUsage;
		property unsigned __int64 QuotaNonPagedPoolUsage;
		property unsigned __int64 PagefileUsage;
		property unsigned __int64 PeakPagefileUsage;
	};
};