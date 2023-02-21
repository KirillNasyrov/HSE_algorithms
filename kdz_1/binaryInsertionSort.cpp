#include <vector>

int binSearch(std::vector<int> &v, int item, int low, int high, int &count) {
    if (high <= low) {
        count += 4;
        return (item > v[low]) ? (low + 1) : low;
    }

    int mid = (low + high) / 2;

    if (item == v[mid]) {
        count += 6;
        return mid + 1;
    }

    if (item > v[mid]) {
        count += 7;
        return binSearch(v, item, mid + 1, high, count);
    }
    count += 7;
    return binSearch(v, item, low, mid - 1, count);
}

void binaryInsertionSort(std::vector<int> &v, int n, int &count) {
    int i, loc, j, k, selected;
    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = v[i];

        // бинарный поиск
        loc = binSearch(v, selected, 0, j, count);
        while (j >= loc) {
            v[j + 1] = v[j];
            j--;
            count += 5;
        }
        v[j + 1] = selected;
        count += 7;
    }
}