#include <vector>

int getMax(std::vector<int> &v, int n, int &count) {
    int mx = v[0];
    for (int i = 1; i < n; ++i) {
        count += 2;
        if (v[i] > mx) {
            mx = v[i];
            count += 2;
        }
    }
    count += 3;
    return mx;
}

void countSortRadix(std::vector<int> &v, int n, int exp, int &cnt) {
    int output[n];
    int i, count[256] = {0};
    cnt += 3;
    for (i = 0; i < n; ++i) {
        ++count[(v[i] / exp) % 256];
        cnt += 5;
    }

    for (i = 1; i < 256; ++i) {
        count[i] += count[i - 1];
        cnt += 4;
    }

    for (i = n - 1; i >= 0; --i) {
        output[count[(v[i] / exp) % 256] - 1] = v[i];
        --count[(v[i] / exp) % 256];
        cnt += 3;
    }

    for (i = 0; i < n; ++i) {
        v[i] = output[i];
        cnt += 3;
    }
}

void radixSort(std::vector<int> &v, int n, int &count) {
    int m = getMax(v, n, count);
    ++count;
    for (int exp = 1; m / exp > 0; exp *= 256) {
        countSortRadix(v, n, exp, count);
        ++count;
    }
}