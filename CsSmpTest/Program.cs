using CsSmpData;
using clr_smp_data;
using System;
using System.Linq;

namespace CsSmpTest
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var context = new SmpContext())
            {
                var info = new system_info();
                var sysInfo = new SystemInfo(info);

                var time = new file_time();
                var fileTime = new FileTime(time);

                var status = new global_memory_status();
                var memStatus = new GlobalMemoryStatus(status);

                context.SystemInfoes.Add(sysInfo);
                context.FileTimes.Add(fileTime);
                context.GlobalMemoryStatuses.Add(memStatus);

                context.SaveChanges();

                var systemInfo = context.SystemInfoes.FirstOrDefault();
                var globalMemStatus = context.GlobalMemoryStatuses.FirstOrDefault();
            }

            Console.WriteLine("Press any key to exit...");
            Console.ReadKey();

        }
    }
}
