#include <vector>

void shellSort(std::vector<int> &v, int n, int &count) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = v[i];
            int j;
            for (j = i; j >= gap && v[j - gap] > temp; j -= gap) {
                v[j] = v[j - gap];
                count += 3;
            }
            v[j] = temp;
            count += 5;
        }
    }
}