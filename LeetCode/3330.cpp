#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1;
        for (int i = 1; i < word.size(); i++) {
            count += word[i] == word[i-1];
        }
        return count;
    }
};