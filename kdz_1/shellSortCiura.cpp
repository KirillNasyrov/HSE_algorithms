#include <vector>

void shellSortCiura(std::vector<int> &vec, int n, int &count) {
    int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
    int gaps_size = sizeof(gaps) / sizeof(gaps[0]);
    count += 3;
    for (int index = 0; index < gaps_size; index++) {
        int gap = gaps[index];
        count += 2;
        for (int i = gap; i < n; i++) {
            int temp = vec[i];
            int j;
            for (j = i; j >= gap && vec[j - gap] > temp; j -= gap) {
                vec[j] = vec[j - gap];
                count += 4;
            }
            vec[j] = temp;
            count += 5;
        }
    }
}