#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;
        bool v = false;
        bool c = false;
        for (int i = 0; i < word.size(); i++) {
            if (!(
                (word[i] >= 'a' && word[i] <= 'z') ||
                (word[i] >= 'A' && word[i] <= 'Z') ||
                (word[i] >= '0' && word[i] <= '9')
                )) return false;
            
            if ((word[i] >= 'a' && word[i] <= 'z') ||
                (word[i] >= 'A' && word[i] <= 'Z')) {
                    for (auto el: { 'a', 'e', 'i', 'o', 'u' }) {
                        if (tolower(word[i]) == el) {
                            v = true;
                            goto skip;
                        }
                    }
                    c = true;
                    skip:
                }
        }

        return (v && c);
    }
};