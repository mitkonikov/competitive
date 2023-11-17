#include <bits/stdc++.h>
 
using namespace std;
 
inline bool is_symbol(char c) {
    if (c >= 'a' && c <= 'z') return false;
    if (c >= 'A' && c <= 'Z') return false;
    if (c >= '0' && c <= '9') return false;
    return true;
}
 
inline char change(char c) {
    if (c >= 'A' && c <= 'Z') return (c - 'A' + 'a');
    return c;
}
 
int main() {
    string S;
    map<string, int> mp;
    vector<string> answers;
    while (!getline(cin, S).eof()) {
        string ans = "";
        for (int i = 0; i < S.size(); i++) {
            bool sym = 0;
            while (i < S.size() && is_symbol(S[i])) {
                sym = 1;
                i++;
            }
            if (sym && i < S.size()) i--;
            if (sym) {
                ans += "-";
            } else {
                ans += change(S[i]);
            }
        }
        if (ans.front() == '-') ans = ans.substr(1);
        if (ans.back() == '-') ans.pop_back();
        auto it = mp.find(ans);
        int v = it->second;
        if (it == mp.end()) {
            mp[ans] = 1;
        } else {
            mp[ans]++;
            string new_ans = ans + "-" + to_string(v + 1);
            while (mp.find(new_ans) != mp.end()) {
                v++;
                new_ans = ans + "-" + to_string(v + 1);
            }
            mp[new_ans] = 1;
            ans = new_ans;
        }
        answers.push_back(ans);
    }
    for (auto el: answers) cout << el << endl;
    return 0;
}