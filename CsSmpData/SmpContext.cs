using System.Data.Entity;

namespace CsSmpData
{
    public class SmpContext : DbContext
    {
        public SmpContext() : base("name=smp_context")
        {
        }

        public virtual DbSet<FileTime> FileTimes { get; set; }
        public virtual DbSet<SystemInfo> SystemInfoes { get; set; }
        public virtual DbSet<GlobalMemoryStatus> MemoryStatuses { get; set; }
        public virtual DbSet<ProcessMemoryCounter> MemoryCounters { get; set; }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
        }
    }
}
