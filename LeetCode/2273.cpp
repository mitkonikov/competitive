#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            if (i + 1 < words.size()) {
                string a = words[i];
                string b = words[i + 1];
                sort(a.begin(), a.end());
                sort(b.begin(), b.end());
                if (a == b) {
                    words.erase(words.begin() + i + 1);
                    if (i) i--;
                    i--;
                }
            }
        }
        return words;
    }
};