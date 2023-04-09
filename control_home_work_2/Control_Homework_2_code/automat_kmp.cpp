#include <string>
#include <vector>
#include <iostream>

std::vector<int> prefixFunction(const std::string &pattern) {
    size_t n = pattern.size();
    std::vector<int> pi(n);
    int k = 0;
    for (size_t i = 1; i < n; ++i) {
        while (k > 0 && pattern[i] != pattern[k]) {
            k = pi[k - 1];
        }
        if (pattern[i] == pattern[k]) {
            ++k;
        }
        pi[i] = k;
    }
    return pi;
}

std::vector<size_t> search_using_automat_kmp(const std::string &text, const std::string &pattern, size_t alphabet) {
    std::vector<size_t> positions;

    size_t n = text.size();
    size_t m = pattern.size();

    std::vector<int> pi = prefixFunction(pattern);
    std::vector<std::vector<int>> automat_kmp(m + 1, std::vector<int>(alphabet));
    for (int i = 0; i <= m; ++i) {
        for (char letter = 97; letter < static_cast<char>(97 + alphabet); ++letter) {
            if (i > 0 && letter != pattern[i]) {
                automat_kmp[i][letter - 97] = automat_kmp[pi[i - 1]][letter - 97];
            } else {
                automat_kmp[i][letter - 97] = i + (letter == pattern[i]);
            }
        }
    }

    size_t q = 0;
    for (size_t i = 0; i < n; i++) {
        q = automat_kmp[q][text[i] - 'a'];
        if (q == m) {
            positions.push_back(i - m + 1);
            //std::cout << "Pattern found at index " << i - m + 1 << "\n";
        }
    }
    return positions;
}

void search_using_automat_kmp_with_mask(const std::string &text, const std::vector<std::string> &q,
                                   const std::vector<size_t> &l, size_t alphabet) {
    size_t n = text.size();
    size_t k = q.size();

    std::vector<size_t> c(n, 0);

    std::vector<size_t> positions;
    for (size_t i = 0; i < k; ++i) {
        positions = search_using_automat_kmp(text, q[i], alphabet);
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