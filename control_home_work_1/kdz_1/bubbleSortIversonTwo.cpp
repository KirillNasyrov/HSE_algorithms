#include <vector>

void bubbleSortIversonTwo(std::vector<int> &v, int n, int &count) {
    int i = 0;
    int last_swap = n - i - 1;
    bool flag = true;
    count += 5;
    count++;
    while (flag) {
        flag = false;
        count += 2;
        int ls;
        for (int j = 0; j < last_swap; ++j) {
            count += 4;
            count += 4;
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
                ls = j;
                count += 2;
                flag = true;
                count += 1;
            }
        }
        last_swap = ls;
        ++i;
        count += 2;
    }
}