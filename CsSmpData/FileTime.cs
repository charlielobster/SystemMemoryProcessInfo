using System.ComponentModel.DataAnnotations;
using clr_smp_data;

namespace CsSmpData
{
    public class FileTime
    {
        public FileTime() { }
        public FileTime(file_time time)
        {
            dwLowDateTime = time.dwLowDateTime;
            dwHighDateTime = time.dwHighDateTime;
        }
        [Key]
        public ulong Key { get; set; }
        public ulong dwLowDateTime { get; set; }
        public ulong dwHighDateTime { get; set; }
    }
}
