using System.Data.Entity;

namespace CsSmpData
{
    public class SmpContext : DbContext
    {
        public SmpContext() : base("name=smp_context") { }

        public virtual DbSet<ProcessInfo> ProcessInfos { get; set; }
        public virtual DbSet<FileTime> FileTimes { get; set; }
        public virtual DbSet<ProcessMemoryCounter> ProcessMemoryCounters { get; set; }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {

        }
    }
}
