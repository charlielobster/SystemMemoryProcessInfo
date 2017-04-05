using System.ComponentModel.DataAnnotations;
using clr_smp_data;
using System;

namespace CsSmpData
{
    public class FileTime
    {
        public FileTime() { }
        public FileTime(file_time time)
        {
            LowDateTime = (Int64)time.dwLowDateTime;
            HighDateTime = (Int64)time.dwHighDateTime;
        }
        [Key]
        public int Key { get; set; }
        public Int64 LowDateTime { get; set; }
        public Int64 HighDateTime { get; set; }
    }
}
