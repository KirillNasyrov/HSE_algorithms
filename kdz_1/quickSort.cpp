#include <vector>

int partition(std::vector<int> &v, int low, int high, int &count) {
    int pivot = v[high];
    int i = low - 1;
    count += 6;
    for (int j = low; j <= high - 1; j++) {
        count += 2;
        if (v[j] < pivot) {
            i++;
            std::swap(v[i], v[j]);
            count += 2;
        }
    }
    std::swap(v[i + 1], v[high]);
    return (i + 1);
}

void quickSort(std::vector<int> &v, int low, int high, int &count) {
    ++count;
    if (low < high) {
        int pi = partition(v, low, high, count);
        quickSort(v, low, pi - 1, count);
        quickSort(v, pi + 1, high, count);
        count += 3;
    }
}

void quickSort(std::vector<int> &v, int n, int &count) {
    quickSort(v, 0, n - 1, count);
}