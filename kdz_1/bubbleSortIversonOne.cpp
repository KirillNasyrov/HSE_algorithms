#include <vector>

void bubbleSortIversonOne(std::vector<int> &v, int n, int &count) {
    int i = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int j = 0; j < n - i - 1; ++j) {
            count += 4;
            if (v[j] < v[j + 1]) {
                std::swap(v[j], v[j + 1]);
                flag = true;
                count += 5;
            }
        }
        ++i;
        count += 2;
    }
}