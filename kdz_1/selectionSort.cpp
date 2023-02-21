#include <vector>

void selectionSort(std::vector<int> &v, int n, int &count) {
    int i, j, min_index;
    count += 3;
    for (i = 0; i < n - 1; ++i) {
        // Находим минимальный элемент
        min_index = i;
        for (j = i + 1; j < n; ++j) {
            count += 3;
            if (v[j] < v[min_index]) {
                min_index = j;
                ++count;
            }
        }
        count += 2;
        // Меняем минимальный элемент с первым
        if (min_index != i) {
            std::swap(v[min_index], v[i]);
            ++count;
        }
    }
}