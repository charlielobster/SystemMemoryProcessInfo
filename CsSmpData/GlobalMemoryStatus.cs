using System.ComponentModel.DataAnnotations;
using clr_smp_data;

namespace CsSmpData
{
    public class GlobalMemoryStatus
    {
        public GlobalMemoryStatus() { }
        public GlobalMemoryStatus(global_memory_status info)
        {
            dwLength = info.dwLength;
            dwMemoryLoad = info.dwMemoryLoad;
            ullTotalPhys = info.ullTotalPhys;
            ullAvailPhys = info.ullAvailPhys;
            ullTotalPageFile = info.ullTotalPageFile;
            ullAvailPageFile = info.ullAvailPageFile;
            ullTotalVirtual = info.ullTotalVirtual;
            ullAvailVirtual = info.ullAvailVirtual;
            ullAvailExtendedVirtual = info.ullAvailExtendedVirtual;
        }
        [Key]
        public int Key { get; set; }
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
