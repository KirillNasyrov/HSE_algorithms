#include <vector>

void heapify(std::vector<int> &v, int n, int i, int &count) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && v[left] > v[largest]) {
        largest = left;
        ++count;
    }
    if (right < n && v[right] > v[largest]) {
        largest = right;
        ++count;
    }
    if (largest != i) {
        std::swap(v[i], v[largest]);
        heapify(v, n, largest, count);
        ++count;
    }
    count += 16;
}

void heapSort(std::vector<int> &v, int n, int &count) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(v, n, i, count);
        count += 3;
    }
    for (int i = n - 1; i >= 0; i--) {
        std::swap(v[0], v[i]);
        heapify(v, i, 0, count);
        count += 4;
    }
}