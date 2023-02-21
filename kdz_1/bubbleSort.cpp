#include <vector>

void bubbleSort(std::vector<int> &v, int n, int &count) {
    int i, j;
    for (i = 0; i < n - 1; ++i) {
        for (j = 0; j < n - i - 1; ++j) {
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
            }
            count += 5;
        }
    }
}