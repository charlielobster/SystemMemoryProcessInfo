#pragma once

namespace clr_smp_data {
	public ref class process_memory_counter {
	public:
		process_memory_counter() { }
		long PageFaultCount;
		long PeakWorkingSetSize;
		long WorkingSetSize;
		long QuotaPeakPagedPoolUsage;
		long QuotaPagedPoolUsage;
		long QuotaPeakNonPagedPoolUsage;
		long QuotaNonPagedPoolUsage;
		long PagefileUsage;
		long PeakPagefileUsage;
	};
};