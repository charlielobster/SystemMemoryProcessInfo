using System.ComponentModel.DataAnnotations;

namespace CsSmpData
{
    public class ProcessMemoryCounter
    {
        [Key]
        public int Key { get; set; }
        public long PageFaultCount { get; set; }
        public long PeakWorkingSetSize { get; set; }
        public long WorkingSetSize { get; set; }
        public long QuotaPeakPagedPoolUsage { get; set; }
        public long QuotaPagedPoolUsage { get; set; }
        public long QuotaPeakNonPagedPoolUsage { get; set; }
        public long QuotaNonPagedPoolUsage { get; set; }
        public long PagefileUsage { get; set; }
        public long PeakPagefileUsage { get; set; }
    }
}
