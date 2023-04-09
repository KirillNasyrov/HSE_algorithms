#include <fstream>
#include <chrono>
#include "kmp_with_br.cpp"
#include "kmp_with_brs.cpp"
#include "naive.cpp"

void parse_pattern(std::string& pattern,
                   std::vector<std::string> &strings_in_mask, std::vector<size_t> &indexes_of_string_in_masks) {
    strings_in_mask.clear();
    indexes_of_string_in_masks.clear();

    size_t pos, left_pos = 0;
    std::string token;

    while ((pos = pattern.find('?')) != std::string::npos) {
        token = pattern.substr(0, pos);

        if (!token.empty()) {
            strings_in_mask.push_back(token);
            indexes_of_string_in_masks.push_back(left_pos);
        }

        left_pos += pos + 1;
        pattern.erase(0, pos + 1);
    }
    if (!pattern.empty()) {
        strings_in_mask.push_back(pattern);
        indexes_of_string_in_masks.push_back(left_pos);
    }
}

std::string generate_text(size_t size_of_text, size_t size_of_alphabet) {
    srand(time(nullptr));
    char text[size_of_text + 1];
    for (int i = 0; i < size_of_text; i++) {
        text[i] = static_cast<char>('a' + random() % size_of_alphabet);
    }
    text[size_of_text] = '\0';
    return static_cast<std::string>(text);
}

std::string generate_pattern(const std::string &text, size_t size_of_pattern, size_t number_of_substitution) {
    srand(time(nullptr));
    size_t i = random() % (text.size() - size_of_pattern);
    char mask[size_of_pattern + 1];

    for (size_t j = 0; j < size_of_pattern; ++j) {
        mask[j] = text[j + i];
    }

    for (size_t j = 0; j < number_of_substitution; ++j) {
        size_t index = random() % size_of_pattern;
        mask[index] = '?';
    }
    mask[size_of_pattern] = '\0';

    return static_cast<std::string>(mask);
}

int64_t test(void (*func)(const std::string &, const std::vector<std::string> &, const std::vector<size_t> &),
             const std::string &text, const std::vector<std::string> &q, const std::vector<size_t> &l) {

    int64_t totalTime = 0;
    for (int i = 0; i < 5; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        func(text, q, l);
        auto end = std::chrono::high_resolution_clock::now();
        auto nseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        totalTime += nseconds;
    }
    return totalTime / 5;
}

int main() {
    std::ofstream fs1;
    fs1.open("fileOfTimes.csv", std::ios_base::app);

    std::vector<void (*)(const std::string &, const std::vector<std::string> &, const std::vector<size_t> &)> functions(3);
    functions[0] = naive_search_with_mask;
    functions[1] = kmp_search_using_br_with_mask;
    functions[2] = kmp_search_using_brs_with_mask;


    std::vector<std::string> strings_in_mask;
    std::vector<size_t> indexes_of_string_in_masks;

    //parse_pattern(pattern, strings_in_mask, indexes_of_string_in_masks);

    //kmp_search_using_br_with_mask(text, strings_in_mask, indexes_of_string_in_masks);

    //std::string text = "absabcdfbcabc";
    //std::string pattern = "ab?";

    std::string text;
    std::string pattern;

    fs1 << "Number of substitution;Size of text;Size of alphabet;Size of pattern;Type of algorithm;Time(ns)\n";

    for (size_t number_of_substitution = 0; number_of_substitution <= 4; ++number_of_substitution) {
        for (size_t size_of_text = 10000; size_of_text <= 100000; size_of_text += 90000) {
            for (size_t size_of_alphabet = 2; size_of_alphabet <= 4; size_of_alphabet += 2) {
                text = generate_text(size_of_text, size_of_alphabet);

                for (size_t size_of_pattern = 100; size_of_pattern <= 3000; size_of_pattern += 100) {

                    pattern = generate_pattern(text, size_of_pattern, number_of_substitution);

                    parse_pattern(pattern, strings_in_mask, indexes_of_string_in_masks);

                    for (size_t type = 0; type < 3; ++type) {
                        fs1 << number_of_substitution << ";";
                        fs1 << size_of_text << ";";
                        fs1 << size_of_alphabet << ";";
                        fs1 << size_of_pattern << ";";
                        switch (type) {
                            case 0:
                                fs1 << "Наивный алгоритм;";
                                break;
                            case 1:
                                fs1 << "Алгоритм КМП с применением стандартных граней;";
                                break;
                            case 2:
                                fs1 << "Алгоритм КМП с применением уточненных граней;";
                                break;
                            default:
                                break;
                        }
                        fs1 << test(functions[type], text, strings_in_mask, indexes_of_string_in_masks) << "\n";
                    }
                }
            }
        }
    }

    return 0;
}
