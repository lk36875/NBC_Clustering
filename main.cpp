#include <Dataset.h>
#include <GroupingSet.h>
#include <algorithms.h>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <metrics.h>
#include <output.h>
#include <string>
#include <vector>

using namespace std;
using namespace std::chrono;
namespace fs = std::filesystem;

bool isDataType(string dataType);
bool goodAlgorithmName(string name);

int main(int argc, char* argv[])
{

    // READING ARUMENTS
    if (argc != 6) {
        cerr << "Usage: " << argv[0] << " File k Algorithm OutputFolderPath Datatypes" << endl;
        // e.g. ../data/test5.csv 3 m_vdm ./output_gower int,bool,string
        return 1;
    }

    string filepath = argv[1];
    int k = stoi(argv[2]);
    string algorithm = argv[3];
    vector<string> datatypes;
    string outputFolderPath = argv[4];
    string datatypes_arg = argv[5];

    if (!std::filesystem::is_regular_file(filepath)) {
        cerr << "Invalid input file path" << endl;
        return 1;
    }

    fs::path p(filepath);
    std::string intputFilename = p.filename().string();

    // Parse the datatypes argument
    size_t start = 0, end = 0;
    while (end != string::npos) {
        end = datatypes_arg.find(',', start);
        string datatype = datatypes_arg.substr(start, end - start);
        if (!isDataType(datatype)) {
            cerr << "Invalid datatype" << endl;
            return 1;
        }
        datatypes.push_back(datatype);
        start = end + 1;
    }

    if (k < 1) {
        cerr << "Error: k must be greater than 1" << endl;
        return 1;
    }

    if (!goodAlgorithmName(algorithm)) {
        cerr << "Error: algorithm must be either m_vdm , m_vdm_0_5 or gower" << endl;
        return 1;
    }

    double categoricalScaling = 1;
    double (*metric)(GroupingSet dataset, int index1, int index2, double item) = NULL;
    if (algorithm == "gower") {
        metric = metrics::gower;
    } else if (algorithm == "m_vdm") {
        metric = metrics::manhattanVdm;
    } else if (algorithm == "m_vdm_0_5") {
        metric = metrics::manhattanVdm;
        categoricalScaling = 0.5;
    } else {
        throw std::invalid_argument("Wrong algorithm.");
    }

    // READING DATASET
    auto timer_reading_file_start = steady_clock::now();
    Dataset dataset = Dataset(filepath, datatypes, "NA", "csv");

    auto timer_reading_file_end = steady_clock::now();
    auto reading_duration = duration_cast<milliseconds>(timer_reading_file_end - timer_reading_file_start).count();

    // NBC
    cout << filepath << " NBC in progress..." << endl;
    auto nbc_tuple = grouping::nbc(dataset, k, metric, categoricalScaling);
    auto kpnn_duration = nbc_tuple.second.first;
    auto grouping_duration = nbc_tuple.second.second;
    auto result = nbc_tuple.first;

    // WRITE OUTPUT FILES
    vector<long long> timers = { reading_duration, kpnn_duration, grouping_duration };
    file_writing::writeSummary(result, outputFolderPath, k, algorithm, intputFilename, timers);

    return 0;
}

bool isDataType(string dataType)
{
    return (dataType == "bool" || dataType == "int" || dataType == "double" || dataType == "string");
}

bool goodAlgorithmName(string name)
{
    if (name == "m_vdm" || name == "gower" || name == "m_vdm_0_5") {
        return true;
    }
    return false;
}