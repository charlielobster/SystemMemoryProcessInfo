using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using clr_smp_data;

namespace CsSmpData
{
    public class GlobalMemoryStatus
    {
        public GlobalMemoryStatus() { }
        public GlobalMemoryStatus(global_memory_status status)
        {
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

        [Key]
        public long Key { get; set; }

        [ForeignKey("SystemInfo")]
        public long SystemInfo_Key { get; set; }
        public virtual SystemInfo SystemInfo { get; set; }

        public long dwLength { get; set; }
        public long dwMemoryLoad { get; set; }
        public long ullTotalPhys { get; set; }
        public long ullAvailPhys { get; set; }
        public long ullTotalPageFile { get; set; }
        public long ullAvailPageFile { get; set; }
        public long ullTotalVirtual { get; set; }
        public long ullAvailVirtual { get; set; }
        public long ullAvailExtendedVirtual { get; set; }
    }
}
