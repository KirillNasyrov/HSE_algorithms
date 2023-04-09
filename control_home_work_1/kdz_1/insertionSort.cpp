#include <vector>

void insertionSort(std::vector<int> &v, int n, int &count)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = v[i];
        j = i - 1;

        // Двигаем элементы arr[0..i-1],
        // который больше key, на одну
        // позицию дальше от их
        // текущей позиции
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j = j - 1;
            count += 5;
        }
        v[j + 1] = key;
        count += 6;
    }
}