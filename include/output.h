#ifndef OUTPUT_H
#define OUTPUT_H

#include <GroupingSet.h>

namespace file_writing
{

    void writeSummary(GroupingSet dataset, std::string folderPath, int k, std::string algorithm, std::string inputFilename, std::vector<long long> timers);

    std::tuple<int, int, int> out(GroupingSet dataset, std::string filename);
    void stat(GroupingSet dataset, std::string filename, int k, std::vector<long long> timers, std::string inputFilename, std::tuple<int, int, int> counters);
    void kpnn(GroupingSet dataset, std::string filename);

}

#endif