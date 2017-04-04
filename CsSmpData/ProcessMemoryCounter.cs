using System;
using System.ComponentModel.DataAnnotations;

namespace CsSmpData
{
    public class ProcessMemoryCounter
    {
        [Key]
        public UInt64 Key { get; set; }
        public UInt64 PageFaultCount { get; set; }
        public UInt64 PeakWorkingSetSize { get; set; }
        public UInt64 WorkingSetSize { get; set; }
        public UInt64 QuotaPeakPagedPoolUsage { get; set; }
        public UInt64 QuotaPagedPoolUsage { get; set; }
        public UInt64 QuotaPeakNonPagedPoolUsage { get; set; }
        public UInt64 QuotaNonPagedPoolUsage { get; set; }
        public UInt64 PagefileUsage { get; set; }
        public UInt64 PeakPagefileUsage { get; set; }
    }
}
