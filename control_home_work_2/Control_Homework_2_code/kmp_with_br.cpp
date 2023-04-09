#include <iostream>
#include <string>
#include <vector>

std::vector<size_t> get_br(const std::string &pattern) {
    size_t n = pattern.size();
    std::vector<size_t> br(n);
    size_t k = 0;
    for (size_t i = 1; i < n; i++) {
        while (k > 0 && pattern[i] != pattern[k]) {
            k = br[k - 1];
        }
        if (pattern[i] == pattern[k]) {
            k++;
        }
        br[i] = k;
    }
    for (auto num: br) {
        //std::cout << num << " ";
    }
    //std::cout << "\n";
    return br;
}

std::vector<size_t> kmp_search_using_br(const std::string &text, const std::string &pattern) {
    std::vector<size_t> positions;
    std::vector<size_t> br = get_br(pattern);
    size_t n = text.size(), m = pattern.size(), j = 0;
    for (size_t i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = br[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) {
            //std::cout << "Found pattern at index " << i - m + 1 << "\n";
            positions.push_back(i - m + 1);
            j = br[j - 1];
        }
    }
    return positions;
}

void kmp_search_using_br_with_mask(const std::string &text, const std::vector<std::string> &q,
                                   const std::vector<size_t> &l) {
    size_t n = text.size();
    size_t k = q.size();

    std::vector<size_t> c(n, 0);

    std::vector<size_t> positions;
    for (size_t i = 0; i < k; ++i) {
        positions = kmp_search_using_br(text, q[i]);
        for (size_t position : positions) {
            if (position - l[i] >= 0 && position - l[i] < n) {
                ++c[position - l[i]];
            }
        }
    }

    for (size_t i = 0; i < n; ++i) {
        if (c[i] == k) {
            //std::cout << "Found pattern at index " << i << "\n";
        }
    }
}