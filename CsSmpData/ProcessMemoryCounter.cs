using System;
using System.ComponentModel.DataAnnotations;
using clr_smp_data;

namespace CsSmpData
{
    public class ProcessMemoryCounter
    {
        public ProcessMemoryCounter() { }
        public ProcessMemoryCounter(process_memory_counter pmc)
        {
            PageFaultCount = (Int64)pmc.PageFaultCount;
            PeakWorkingSetSize = (Int64)pmc.PeakWorkingSetSize;
            WorkingSetSize = (Int64)pmc.WorkingSetSize;
            QuotaPeakPagedPoolUsage = (Int64)pmc.QuotaPeakPagedPoolUsage;
            QuotaPagedPoolUsage = (Int64)pmc.QuotaPagedPoolUsage;
            QuotaPeakNonPagedPoolUsage = (Int64)pmc.QuotaPeakNonPagedPoolUsage;
            QuotaNonPagedPoolUsage = (Int64)pmc.QuotaNonPagedPoolUsage;
            PagefileUsage = (Int64)pmc.PagefileUsage;
            PeakPagefileUsage = (Int64)pmc.PeakPagefileUsage;
        }
        [Key]
        public int Key { get; set; }
        public Int64 PageFaultCount { get; set; }
        public Int64 PeakWorkingSetSize { get; set; }
        public Int64 WorkingSetSize { get; set; }
        public Int64 QuotaPeakPagedPoolUsage { get; set; }
        public Int64 QuotaPagedPoolUsage { get; set; }
        public Int64 QuotaPeakNonPagedPoolUsage { get; set; }
        public Int64 QuotaNonPagedPoolUsage { get; set; }
        public Int64 PagefileUsage { get; set; }
        public Int64 PeakPagefileUsage { get; set; }
    }
}
