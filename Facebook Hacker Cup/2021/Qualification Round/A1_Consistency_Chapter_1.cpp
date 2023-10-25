#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

void testCase() {
    string s;
    cin >> s;

    int n = s.size();
    int count[26];
    memset(count, 0, sizeof(int) * 26);

    for (int i = 0; i < n; i++) {
        count[s[i] - 'A']++;
    }

    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    int vowelCount = 0;
    int notVowelCount = 0;
    for (int i = 0; i < 26; i++) {
        bool isVowel = false;
        for (int j = 0; j < 5; j++) {
            if (vowels[j] == 'A' + i) {
                isVowel = true;
                break;
            }
        }

        if (isVowel) {
            vowelCount += count[i];
        } else {
            notVowelCount += count[i];
        }
    }

    int best = INT_MAX;
    for (int i = 0; i < 26; i++) {
        bool isVowel = false;
        for (int j = 0; j < 5; j++) {
            if (vowels[j] == 'A' + i) {
                isVowel = true;
                break;
            }
        }

        if (isVowel) {
            best = min(best, notVowelCount + (vowelCount - count[i]) * 2);
        } else {
            best = min(best, vowelCount + (notVowelCount - count[i]) * 2);
        }
    }

    cout << best << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        testCase();
    }

    return 0;
}