#include <string>

std::vector<size_t> naive_search(const std::string& text, const std::string& pattern) {
    std::vector<size_t> positions;
    size_t n = text.length();
    size_t m = pattern.length();
    for (size_t i = 0; i <= n - m; ++i) {
        bool flag = true;
        for (size_t j = 0; j < m; ++j) {
            if (text[i + j] != pattern[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            //std::cout << "Found pattern at index " << i << "\n";
            positions.push_back(i);
        }
    }
    return positions;
}

void naive_search_with_mask(const std::string &text, const std::vector<std::string> &q,
                                   const std::vector<size_t> &l) {
    size_t n = text.size();
    size_t k = q.size();

    std::vector<size_t> c(n, 0);

    std::vector<size_t> positions;
    for (size_t i = 0; i < k; ++i) {
        positions = naive_search(text, q[i]);
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