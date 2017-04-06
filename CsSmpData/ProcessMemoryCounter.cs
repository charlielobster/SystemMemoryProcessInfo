using System;
using System.ComponentModel.DataAnnotations;
using clr_smp_data;

namespace CsSmpData
{
    public class ProcessMemoryCounter
    {
        public ProcessMemoryCounter() { }
        public ProcessMemoryCounter(process_memory_counter counter)
        {
            PageFaultCount = (Int64)counter.PageFaultCount;
            PeakWorkingSetSize = (Int64)counter.PeakWorkingSetSize;
            WorkingSetSize = (Int64)counter.WorkingSetSize;
            QuotaPeakPagedPoolUsage = (Int64)counter.QuotaPeakPagedPoolUsage;
            QuotaPagedPoolUsage = (Int64)counter.QuotaPagedPoolUsage;
            QuotaPeakNonPagedPoolUsage = (Int64)counter.QuotaPeakNonPagedPoolUsage;
            QuotaNonPagedPoolUsage = (Int64)counter.QuotaNonPagedPoolUsage;
            PagefileUsage = (Int64)counter.PagefileUsage;
            PeakPagefileUsage = (Int64)counter.PeakPagefileUsage;
        }
        [Key]
        public int Id { get; set; }
        public UInt64 uPageFaultCount { get { return (UInt64)PageFaultCount; } }
        public UInt64 uPeakWorkingSetSize { get { return (UInt64)PeakWorkingSetSize; } }
        public UInt64 uWorkingSetSize { get { return (UInt64)WorkingSetSize; } }
        public UInt64 uQuotaPeakPagedPoolUsage { get { return (UInt64)QuotaPeakPagedPoolUsage; } }
        public UInt64 uQuotaPagedPoolUsage { get { return (UInt64)QuotaPagedPoolUsage; } }
        public UInt64 uQuotaPeakNonPagedPoolUsage { get { return (UInt64)QuotaPeakNonPagedPoolUsage; } }
        public UInt64 uQuotaNonPagedPoolUsage { get { return (UInt64)QuotaNonPagedPoolUsage; } }
        public UInt64 uPagefileUsage { get { return (UInt64)PagefileUsage; } }
        public UInt64 uPeakPagefileUsage { get { return (UInt64)PeakPagefileUsage; } }
        public UInt64 uPageFaultUsage { get { return (UInt64)PageFaultUsage; } }
        public Int64 PageFaultCount { get; set; }
        public Int64 PeakWorkingSetSize { get; set; }
        public Int64 WorkingSetSize { get; set; }
        public Int64 QuotaPeakPagedPoolUsage { get; set; }
        public Int64 QuotaPagedPoolUsage { get; set; }
        public Int64 QuotaPeakNonPagedPoolUsage { get; set; }
        public Int64 QuotaNonPagedPoolUsage { get; set; }
        public Int64 PagefileUsage { get; set; }
        public Int64 PeakPagefileUsage { get; set; }
        public Int64 PageFaultUsage { get; set; }
    }
}
