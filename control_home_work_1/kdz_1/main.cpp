#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include "binaryInsertionSort.cpp"
#include "bubbleSort.cpp"
#include "bubbleSortIversonOne.cpp"
#include "bubbleSortIversonTwo.cpp"
#include "countSort.cpp"
#include "heapSort.cpp"
#include "insertionSort.cpp"
#include "mergeSort.cpp"
#include "quickSort.cpp"
#include "radixSort.cpp"
#include "selectionSort.cpp"
#include "shellSort.cpp"
#include "shellSortCiura.cpp"

std::vector<int> randomFrom0To5(int n) {
    std::vector<int> v(n);
    srand(time(nullptr));
    for (int i = 0; i < n; ++i) {
        v[i] = random() % 6;
    }
    return v;
}

std::vector<int> randomFrom0To4000(int n) {
    std::vector<int> v(n);
    srand(time(nullptr));
    for (int i = 0; i < n; ++i) {
        v[i] = random() % 6;
    }
    return v;
}

std::vector<int> randomAlmostSorted(int n) {
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i;
    }
    srand(time(nullptr));
    for (int i = 0; i < 5; ++i) {
        int start, end;
        start = random() % n;
        end = random() % n;
        std::swap(v[start], v[end]);
    }
    return v;
}

std::vector<int> randomSortedReverse(int n) {
    std::vector<int> v(4100);
    for (int i = 1; i <= 4100; ++i) {
        v[i] = i;
    }
    std::reverse(v.begin(), v.end());
    return v;
}

int64_t test(std::vector<int> &v, void (*func)(std::vector<int> &, int, int &), int &operations) {
    int64_t totalTime = 0;
    for (int i = 0; i < 10; ++i) {
        std::vector<int> copy_v(v.size());
        std::copy(v.begin(), v.end(), copy_v.begin());
        auto start = std::chrono::high_resolution_clock::now();
        func(copy_v, v.size(), operations);
        auto end = std::chrono::high_resolution_clock::now();
        auto nseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        totalTime += nseconds;
    }
    operations /= 10;
    return totalTime / 10;
}

void writeFile(const std::string &name,  std::vector<std::vector<int64_t>> &v) {
    std::ofstream fs;
    fs.open(name, std::ios_base::app);
    for (const auto &vec: v) {
        for (const auto &item: vec) {
            fs << item << ";";
        }
        fs << '\n';
    }
    fs << '\n';
    fs.close();
}

int main() {
    //std::string file_name1 = "fileOfTimes.csv";
    //std::string file_name2 = "fileOfOperations.csv";

    std::ofstream fs1, fs2;
    fs1.open("fileOfTimes.csv", std::ios_base::app);
    fs2.open("fileOfOperations.csv", std::ios_base::app);

    std::vector<std::vector<int>> random_vec(4);
    random_vec[0] = randomFrom0To5(4100);
    random_vec[1] = randomFrom0To4000(4100);
    random_vec[2] = randomAlmostSorted(4100);
    random_vec[3] = randomSortedReverse(4100);

    std::vector<std::vector<int64_t>> timesFor50To300(13);
    std::vector<std::vector<int64_t>> timesFor100To4000(13);

    std::vector<std::vector<int64_t>> operationsFor50To300(13);
    std::vector<std::vector<int64_t>> operationsFor100To4000(13);

    std::vector<void (*)(std::vector<int> &, int, int &)> function_v(13);
    function_v[0] = binaryInsertionSort;
    function_v[1] = bubbleSort;
    function_v[2] = bubbleSortIversonOne;
    function_v[3] = bubbleSortIversonTwo;
    function_v[4] = countSort;
    function_v[5] = heapSort;
    function_v[6] = insertionSort;
    function_v[7] = mergeSort;
    function_v[8] = quickSort;
    function_v[9] = radixSort;
    function_v[10] = selectionSort;
    function_v[11] = shellSortCiura;
    function_v[12] = shellSort;

    fs1 << "type;number of algorithm;size;time;\n";
    fs2 << "type;number of algorithm;size;operations;\n";
    for (int type = 0; type < 4; ++type) {
        for (int length = 50; length <= 300; length += 50) {
            for (int srt = 0; srt < 13; ++srt) {
                if (type == 0) {
                    fs1 << "рандом от 0 до 5_1;";
                    fs2 << "рандом от 0 до 5_1;";
                } else if (type == 1) {
                    fs1 << "рандом от 0 до 4000_1;";
                    fs2 << "рандом от 0 до 4000_1;";
                } else if (type == 2) {
                    fs1 << "почти отсортирован_1;";
                    fs2 << "почти отсортирован_1;";
                } else {
                    fs1 << "обратно отсортирован_1;";
                    fs2 << "обратно отсортирован_1;";
                }

                fs1 << srt << ";";
                fs2 << srt << ";";

                fs1 << length << ";";
                fs2 << length << ";";

                int operations = 0;
                std::vector<int> vec(random_vec[type].begin(), random_vec[type].begin() + length);
                fs1 << test(vec, function_v[srt], operations) << ";\n";
                fs2 << operations << ";\n";
            }
        }
    }

    for (int type = 0; type < 4; ++type) {
        for (int length = 100; length <= 4100; length += 100) {
            for (int srt = 0; srt < 13; ++srt) {
                if (type == 0) {
                    fs1 << "рандом от 0 до 5_2;";
                    fs2 << "рандом от 0 до 5_2;";
                } else if (type == 1) {
                    fs1 << "рандом от 0 до 4000_2;";
                    fs2 << "рандом от 0 до 4000_2;";
                } else if (type == 2) {
                    fs1 << "почти отсортирован_2;";
                    fs2 << "почти отсортирован_2;";
                } else {
                    fs1 << "обратно отсортирован_2;";
                    fs2 << "обратно отсортирован_2;";
                }

                fs1 << srt << ";";
                fs2 << srt << ";";

                fs1 << length << ";";
                fs2 << length << ";";

                int operations = 0;
                std::vector<int> vec(random_vec[type].begin(), random_vec[type].begin() + length);
                fs1 << test(vec, function_v[srt], operations) << ";\n";
                fs2 << operations << ";\n";
            }
        }
    }
    fs1.close();
    fs2.close();
    return 0;
}
