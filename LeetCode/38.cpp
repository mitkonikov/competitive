#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string S = "1";
        for (int i = 0; i < n - 1; i++) {
            char current = S[0];
            int count = 1;
            string T = "";
            for (int j = 1; j < S.size(); j++) {
                if (S[j] != current) {
                    T += to_string(count) + current;
                    current = S[j];
                    count = 1;
                } else {
                    count++;
                }
            }
            if (count) {
                T += to_string(count) + current;
            }
            S = T;
        }
        return S;
    }
};