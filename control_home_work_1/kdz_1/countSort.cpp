#include <vector>
#include <algorithm>

void countSort(std::vector<int> &v, int n, int &cnt) {
    int max = *max_element(v.begin(), v.end());
    int min = *min_element(v.begin(), v.end());
    int range = max - min + 1;
    cnt += 7;

    std::vector<int> count(range), output(v.size());
    for (int i = 0; i < n; i++) {
        count[v[i] - min]++;
        cnt += 5;
    }

    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
        cnt += 4;
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[v[i] - min] - 1] = v[i];
        count[v[i] - min]--;
        cnt += 11;
    }

    for (int i = 0; i < n; i++) {
        v[i] = output[i];
        cnt += 3;
    }
}