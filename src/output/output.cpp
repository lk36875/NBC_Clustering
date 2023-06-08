#include <output.h>
#include <rating.h>
#include <iomanip>
#include <filesystem>
#include <tuple>
namespace fs = std::filesystem;

namespace file_writing
{

    void writeSummary(GroupingSet dataset, std::string folderPath, int k, std::string algorithm, std::string inputFilename, std::vector<long long> timers)
    {
        std::cout << "Creating Summary..." << std::endl;
        int datasetLen = dataset.getSize();
        int pointShape = dataset[0].getDatapoint().getParameterCount();
        std::string filename = folderPath + "/NBC-" + algorithm + "_" + inputFilename + "_D" + std::to_string(pointShape) + "_R" + std::to_string(datasetLen) + "_k" + std::to_string(k);

        fs::create_directories(folderPath);
        auto counter = out(dataset, filename);
        stat(dataset, filename, k, timers, inputFilename, counter);
        kpnn(dataset, filename);
        std::cout << "Summary finished. Folder: " << folderPath << std::endl
                  << std::endl;
    }

    std::tuple<int, int, int> out(GroupingSet dataset, std::string filename)
    {
        int core_count = 0;
        int boundary_count = 0;
        int noise_count = 0;
        int output_space = 8;

        std::string outFilename = filename + "_OUT.csv";
        std::ofstream outfile(outFilename);
        outfile << std::fixed << std::setprecision(2);

        std::string values[] = {"Id", "Type", "Group", "Values"};
        for (const std::string &value : values)
        {
            outfile << std::left << std::setw(output_space) << value;
        }
        outfile << std::endl;

        for (std::vector<GroupingPoint>::iterator it = dataset.begin(); it != dataset.end(); ++it)
        {
            GroupingPoint currentPoint = *it;
            outfile << std::setw(output_space) << currentPoint.getDatapoint().getId();

            int pointClass = currentPoint.getAssignedClass();
            double ndf = currentPoint.getNdfRatio();
            int pointType;
            if (pointClass == -1)
            {
                pointType = -1;
                noise_count++;
            }
            else if (ndf >= 1)
            {
                pointType = 1;
                core_count++;
            }
            else
            {
                pointType = 0;
                boundary_count++;
            }
            outfile << std::setw(output_space) << pointType;
            outfile << std::setw(output_space) << pointClass;

            for (int i = 0; i < currentPoint.getDatapoint().getParameterCount(); ++i)
            {
                if (i != 0)
                {
                    outfile << ", ";
                }

                if (currentPoint.getDatapoint()[i].isMissing())
                {
                    outfile << "NA";
                }
                else
                {
                    auto value = currentPoint.getDatapoint()[i].getValue();
                    std::string stringValue;
                    if (std::holds_alternative<int>(value))
                    {
                        stringValue = std::to_string(std::get<int>(value));
                    }
                    else if (std::holds_alternative<double>(value))
                    {
                        std::ostringstream ss;
                        ss << std::fixed << std::setprecision(2) << std::get<double>(value);
                        stringValue = ss.str();
                    }
                    else if (std::holds_alternative<bool>(value))
                    {
                        stringValue = std::get<bool>(value) ? "true" : "false";
                    }
                    else
                    {
                        stringValue = std::get<std::string>(value);
                    }
                    outfile << stringValue;
                }
            }
            outfile << std::endl;
        }

        outfile.close();
        return std::make_tuple(core_count, boundary_count, noise_count);
    }

    void stat(GroupingSet dataset, std::string filename, int k, std::vector<long long> timers, std::string inputFilename, std::tuple<int, int, int> counters)
    {
        std::string outFilename = filename + "_STAT.csv";
        std::ofstream outfile(outFilename);

        outfile << std::fixed << std::setprecision(2);

        outfile << "Input filename: " << inputFilename << std::endl;
        outfile << "Number of rows: " << dataset.getSize() << std::endl;
        outfile << "Number of attributes: " << dataset[0].getDatapoint().getParameterCount() << std::endl;
        outfile << "K: " << k << std::endl;
        outfile << "File reading Time: " << timers[0] << " ms." << std::endl;
        outfile << "K+NN Time: " << timers[1] << " ms." << std::endl;
        outfile << "Grouping Time: " << timers[2] << " ms." << std::endl;
        outfile << "Sum: " << timers[0] + timers[1] + timers[2] << " ms." << std::endl;
        outfile << "Number of core points: " << std::get<0>(counters) << std::endl;
        outfile << "Number of boundary points: " << std::get<1>(counters) << std::endl;
        outfile << "Number of noise points: " << std::get<2>(counters) << std::endl;

        outfile << "TP: " << rating::truePositives(dataset) << std::endl;
        outfile << "TN: " << rating::trueNegatives(dataset) << std::endl;
        outfile << "Rand: " << rating::rand(dataset) << std::endl;

        outfile.close();
    }

    void kpnn(GroupingSet dataset, std::string filename)
    {
        std::string outFilename = filename + "_K+NN.csv";
        std::ofstream outfile(outFilename);
        int output_space = 12;

        outfile << std::fixed << std::setprecision(2);

        std::string values[] = {"Id", "Eps", "maxEps", "NDF", "rk+nn", "k+nn_value", "k+nn"};
        for (const std::string &value : values)
        {
            outfile << std::left << std::setw(output_space) << value;
        }
        outfile << std::endl;

        for (std::vector<GroupingPoint>::iterator it = dataset.begin(); it != dataset.end(); ++it)
        {
            GroupingPoint currentPoint = *it;
            outfile << std::setw(output_space) << currentPoint.getDatapoint().getId();
            outfile << std::setw(output_space) << currentPoint.getDistanceToFurthestNeighbour();
            outfile << std::setw(output_space) << currentPoint.getDistanceToFurthestPoint();
            outfile << std::setw(output_space) << currentPoint.getNdfRatio();
            outfile << std::setw(output_space) << currentPoint.getReverseKPlusNeighbourhoodSize();
            outfile << std::setw(output_space) << currentPoint.getKPlusNeighbourhoodSize();
            for (auto number : currentPoint.getKPlusNeighbourhood())
            {
                outfile << " " << number;
            }
            outfile << std::endl;
        }

        outfile.close();
    }

}
