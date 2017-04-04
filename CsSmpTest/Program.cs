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
                var smp_delegate = new clr_smp_delegate();
/* 
  
 
                context.SaveChanges();

                var systemInfo = context.SystemInfoes.FirstOrDefault();
                var globalMemStatus = context.GlobalMemoryStatuses.FirstOrDefault();
  */          }

            Console.WriteLine("Press any key to exit...");
            Console.ReadKey();

        }
    }
}
