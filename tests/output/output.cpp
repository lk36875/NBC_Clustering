#include <gtest/gtest.h>
#include <filesystem>
#include <cmath>
#include <output.h>
#include <metrics.h>
#include <algorithms.h>
#include <vector>

double testDistance(GroupingSet dataset, int x, int y, double unused)
{
    double distance = 0;
    for (int i = 0; i < dataset[0].getDatapoint().getParameterCount(); ++i)
    {
        double temp = std::get<double>(dataset[x].getDatapoint()[i].getValue());
        temp -= std::get<double>(dataset[y].getDatapoint()[i].getValue());
        distance += (temp * temp);
    }
    return std::sqrt(distance);
}

TEST(outputTests, kpnn)
{
    std::vector<std::string> datatypes{"double", "double"};
    Dataset dataset = Dataset("../../data/lecture_data.csv",
                              datatypes,
                              "NA", "csv");

    GroupingSet set = grouping::nbc(dataset, 3, testDistance).first;

    std::string filepath = "./test_k+nn";
    file_writing::kpnn(set, filepath);
    ASSERT_TRUE(std::filesystem::exists("./test_k+nn_K+NN.csv"));
}

TEST(outputTests, out)
{
    std::vector<std::string> datatypes{"double", "double"};
    Dataset dataset = Dataset("../../data/lecture_data.csv",
                              datatypes,
                              "NA", "csv");

    GroupingSet set = grouping::nbc(dataset, 3, testDistance).first;
    std::string filepath = "./test_out";
    file_writing::out(set, filepath);
    ASSERT_TRUE(std::filesystem::exists("./test_out_OUT.csv"));
}

TEST(outputTests, stat)
{
    std::vector<std::string> datatypes{"double", "double"};
    Dataset dataset = Dataset("../../data/lecture_data.csv",
                              datatypes,
                              "NA", "csv");

    GroupingSet set = grouping::nbc(dataset, 3, testDistance).first;
    std::string filepath = "./test_stat";
    std::vector<long long> timers = {123, 21412, 12321};
    std::tuple<int, int, int> counters = {19, 19, 19};
    file_writing::stat(set, filepath, 3, timers, "input_filename.csv", counters);
    ASSERT_TRUE(std::filesystem::exists("./test_stat_STAT.csv"));
}

TEST(outputTests, summary)
{
    std::vector<std::string> datatypes{"int", "string", "string"};
    Dataset dataset = Dataset("../../data/test_gower_NA_lecture_67.csv",
                              datatypes,
                              "NA", "csv");

    auto nbc_res = grouping::nbc(dataset, 3, metrics::gower);

    GroupingSet set = nbc_res.first;
    std::string filepath = "./test_stat";
    std::vector<long long> timers = {0, nbc_res.second.first, nbc_res.second.second};

    file_writing::writeSummary(nbc_res.first, "../summary_folder", 3, "gower", "filepath", timers);
    ASSERT_TRUE(std::filesystem::exists("../summary_folder/NBC-gower_filepath_D3_R10_k3_K+NN.csv"));
    ASSERT_TRUE(std::filesystem::exists("../summary_folder/NBC-gower_filepath_D3_R10_k3_OUT.csv"));
    ASSERT_TRUE(std::filesystem::exists("../summary_folder/NBC-gower_filepath_D3_R10_k3_STAT.csv"));
}
