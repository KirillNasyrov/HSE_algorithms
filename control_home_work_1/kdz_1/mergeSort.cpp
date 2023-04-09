#include <vector>

void merge(std::vector<int> &v, int left, int mid, int right, int &count) {
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];
    count += 7;
    for (auto i = 0; i < subArrayOne; ++i) {
        leftArray[i] = v[left + i];
        count += 4;
    }
    for (auto j = 0; j < subArrayTwo; ++j) {
        rightArray[j] = v[mid + 1 + j];
        count += 5;
    }

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    count += 9;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            v[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            count += 7;
        } else {
            v[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            count += 4;
        }
        indexOfMergedArray++;
        count++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        v[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
        count += 6;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        v[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
        count += 6;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(std::vector<int> &v, int begin, int end, int &count) {
    if (begin >= end) {
        return;
    }
    auto mid = begin + (end - begin) / 2;
    count += 4;
    mergeSort(v, begin, mid, count);
    mergeSort(v, mid + 1, end, count);
    merge(v, begin, mid, end, count);
}

void mergeSort(std::vector<int> &v, int n, int &count) {
    mergeSort(v, 0, n - 1, count);
}