#include <iostream>
#include <fstream>
#include <cstdint>
#include <sstream>
#include <string>

#include <unistd.h>

static constexpr char Filename[] = "/proc/stat";
static constexpr size_t RunLoop4 = 2; /* WARNING: dont change this */

/* Got all the info from https://support.checkpoint.com/results/sk/sk65143 */

typedef struct CpuWorks {
   uint64_t user;    /* Time spent executing user level processes */
   uint64_t nice;    /* Time spent executing user level processes with lesser priority */
   uint64_t system;  /* Time Spent executing system/kernel level processes */
   uint64_t idle;    /* Time Spent doing nothing -> This is what we are going to calculate */
   uint64_t iowait;  /* Time spent doing nothing (is part of idle) but just waiting for input/output tasks to finish */
   uint64_t irq;     /* Time Spent servicing hardware interrupts */
   uint64_t softirq; /* Time spent servicing soft interrupts */
   uint64_t steal;   /* Time spent executing other virtual hosts */
   uint64_t guest;   /* Time spent running a virtual CPU for guest OS under the control of the Linux kernel */
   uint64_t guest_nice; /* Time spent running a niced guest */
} Cpu_works;

void checkIfnOpened(const std::ifstream& file, const char* errmsg) {
   if (!file.is_open()) {
      std::cerr << errmsg << std::endl;
      std::cerr << "Quitting program with error code 1" << std::endl;
      exit(1);
   }
}

void fillup(Cpu_works& cpuWorks, const std::string& first_line) {
   std::istringstream stream(first_line);

   std::string garbageCpuText;
   stream >> garbageCpuText;

   stream >> cpuWorks.user
      >> cpuWorks.nice
      >> cpuWorks.system
      >> cpuWorks.idle
      >> cpuWorks.iowait
      >> cpuWorks.irq
      >> cpuWorks.softirq
      >> cpuWorks.steal
      >> cpuWorks.guest
      >> cpuWorks.guest_nice;
}

inline uint64_t sum(const Cpu_works& cpuWorks) {
   return cpuWorks.user + cpuWorks.nice + cpuWorks.system + cpuWorks.idle +
   cpuWorks.iowait + cpuWorks.irq + cpuWorks.softirq + cpuWorks.steal +
   cpuWorks.guest + cpuWorks.guest_nice;
}

static size_t getCpuPerc() {
   Cpu_works currentWorks;
   uint64_t totalTimesx[RunLoop4], activeTimesx[RunLoop4];

   std::string line1;

   for (size_t idx = 0; idx < RunLoop4; idx++) {
      currentWorks = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

      std::ifstream statFile(Filename);
      checkIfnOpened(statFile, "Error: Failed to open /proc/stat");

      std::getline(statFile, line1);
      fillup(currentWorks, line1);

      totalTimesx[idx] = sum(currentWorks);
      activeTimesx[idx] = totalTimesx[idx] - currentWorks.idle - currentWorks.iowait;

      statFile.close();

      usleep(290000);
   }

   uint64_t totalDifference = totalTimesx[1] - totalTimesx[0];
   uint64_t activeDifference = activeTimesx[1] - activeTimesx[0];

   size_t cpuPerc = 100 * activeDifference/totalDifference;
   return cpuPerc;
}

int main() {
   std::cout << getCpuPerc() << '\n'; 
   return 0;
}
