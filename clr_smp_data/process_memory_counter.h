#pragma once
#include <psapi.h>

namespace clr_smp_data 
{
	public ref class process_memory_counter 
	{
	public:
		process_memory_counter(PROCESS_MEMORY_COUNTERS pmc)
		{
			PageFaultCount = pmc.PageFaultCount;
			PeakWorkingSetSize = pmc.PeakWorkingSetSize;
			WorkingSetSize = pmc.WorkingSetSize;
			QuotaPeakPagedPoolUsage = pmc.QuotaPeakPagedPoolUsage;
			QuotaPagedPoolUsage = pmc.QuotaPagedPoolUsage;
			QuotaPeakNonPagedPoolUsage = pmc.QuotaPeakNonPagedPoolUsage;
			QuotaNonPagedPoolUsage = pmc.QuotaNonPagedPoolUsage;
			PagefileUsage = pmc.PagefileUsage;
			PeakPagefileUsage = pmc.PeakPagefileUsage; 
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