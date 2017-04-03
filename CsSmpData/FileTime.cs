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
        public long Key { get; set; }
        public long dwLowDateTime { get; set; }
        public long dwHighDateTime { get; set; }
    }
}
