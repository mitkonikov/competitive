#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        struct coupon {
            string code;
            int line;
        };
        vector<coupon> ans;
        const int N = code.size();
        map<string, int> mp;
        mp["electronics"] = 0;
        mp["grocery"] = 1;
        mp["pharmacy"] = 2;
        mp["restaurant"] = 3;
        for (int i = 0; i < N; i++) {
            bool ok = !code[i].empty();
            for (auto el : code[i]) {
                ok &= ( (el >= 'a' && el <= 'z') ||
                        (el >= 'A' && el <= 'Z') ||
                        (el >= '0' && el <= '9') ||
                        el == '_');
            }
            ok &= ( businessLine[i] == "electronics" ||
                    businessLine[i] == "grocery" ||
                    businessLine[i] == "pharmacy" ||
                    businessLine[i] == "restaurant");
            ok &= isActive[i];
            if (ok) ans.push_back({ code[i], mp[businessLine[i]] });
        }
        sort(ans.begin(), ans.end(), [](auto& a, auto& b) {
            if (a.line == b.line) return a.code < b.code;
            return a.line < b.line;
        });
        vector<string> codes;
        for (auto& el : ans) codes.push_back(el.code);
        return codes;
    }
};