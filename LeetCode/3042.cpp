#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int N = words.size();
        int result = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int me = words[i].size();
                int him = words[j].size();
                if (me <= him) {
                    if (words[j].substr(0, me) == words[i] && 
                        words[j].substr(him - me, me) == words[i]) {
                            result++;
                        }
                }
            }
        }
        return result;
    }
};