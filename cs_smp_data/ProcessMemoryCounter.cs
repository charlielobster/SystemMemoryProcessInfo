using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cs_smp_data
{
    public class ProcessMemoryCounter
    {
        [Key]
        public uint ProcessId { get; set; }
        public ulong PageFaultCount { get; set; }
        public ulong PeakWorkingSetSize { get; set; }
        public ulong WorkingSetSize { get; set; }
        public ulong QuotaPeakPagedPoolUsage { get; set; }
        public ulong QuotaPagedPoolUsage { get; set; }
        public ulong QuotaPeakNonPagedPoolUsage { get; set; }
        public ulong QuotaNonPagedPoolUsage { get; set; }
        public ulong PagefileUsage { get; set; }
        public ulong PeakPagefileUsage { get; set; }
    }
}
