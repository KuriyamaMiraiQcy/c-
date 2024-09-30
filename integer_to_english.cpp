//
// Created by 62339 on 2023/8/21.
//
#include <vector>
#include <numeric>
#include <cmath>

class integer_to_english {
public:
    const int ones[10] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};
    const int teens[10] = {3, 6, 6, 8, 8, 7, 7, 9, 9, 8};
    const int tens[10] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
    const int twenty = 107;

    long long count_words(int n) {
        long long result = 0;
        if (n < 10) {
            for (int i = 0; i <= n; ++i) {
                result += ones[i];
            }
            return result;
        }
        if (n < 20) {
            for (int i = 0; i + 10 <= n; ++i) {
                result += teens[i];
            }
            return result + 36;
        }
        if (n < 100) {
            int ten = n / 10;
            int one = n % 10;
            result += (ten - 2) * 36 + 107;
            for (int i = 0; i < ten; ++i) {
                result += tens[i] * 10;
            }
            result += tens[ten] * (one + 1);
            for (int i = 0; i <= one; ++i) {
                result += ones[i];
            }
            return result;
        }
        if (n < 1000) {
            int hundred = n / 100;
            int count_hundred = 0;
            for (int i = 0; i < hundred; ++i) {
                count_hundred += ones[i] + 7;
            }
            return count_hundred * 100 + hundred * count_words(99) + count_words(n % 100) +
                   (ones[hundred] + 7) * (n % 100 + 1);
        }
        if (n < 1e6) {
            int thousand = n / 1000;
            int mod = n % 1000;
            result += thousand * count_words(999) + count_words(mod) + count_words(thousand - 1) * 1000 + 8 * (n - 999);
            result += number_to_english(thousand) * (mod + 1);
            return result;
        }
        if (n < 1e9) {
            int million = n / 1000000;
            int mod = n % 1000000;
            result += million * count_words(999999) + count_words(mod) + count_words(million - 1) * 1000000 +
                      7 * (n - 999999);
            result += number_to_english(million) * (mod + 1);
            return result;
        }
    }

    int number_to_english(int n) {
        if (n < 10) {
            return ones[n];
        }
        if (n < 20) {
            return teens[n - 10];
        }
        if (n < 100) {
            int ten = n / 10;
            return tens[ten] + ones[n % 10];
        }
        return ones[n % 100] + 7 + number_to_english(n % 100);
    }
};