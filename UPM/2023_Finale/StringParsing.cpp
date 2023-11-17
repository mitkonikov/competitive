#include <bits/stdc++.h>
 
using namespace std;
 
inline bool is_valid(char c) {
    if (c == '\'' || c == '\"') return true;
    return false;
}
 
char v[] = { '\\', '\'', '\"', 'a', 'b', 'f', 'n', 'r', 't', 'v' };
inline bool is_escape(char c) {
    for (int i = 0; i < 10; i++) {
        if (v[i] == c) return true;
    }
    return false;
}
 
inline bool is_valid_hex(char s) {
    if (s >= '0' && s <= '9') return true;
    if (s >= 'a' && s <= 'f') return true;
    if (s >= 'A' && s <= 'F') return true;
    return false;
}
 
inline bool is_oct(char s) {
    return (s >= '0' && s <= '7');
}
 
int count(string s, string start) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (start.size() == 3) {
            if (i + 3 < s.size() && s.substr(i, 3) == start) return -1;
            if (i == s.size() - 1 && s[i] == start[0]) return -1;
        }
        if (start.size() == 1 && s.substr(i, 1) == start) {
            return -1;
        }
        if (s[i] == '\\') {
            if (i + 1 >= s.size()) return -1;
            if (is_escape(s[i+1])) {
                ans++;
                i++;
                continue;
            }
            if (s[i+1] == 'x') {
                if (i + 3 >= s.size()) {
                    return -1;
                }
                if (is_valid_hex(s[i+2]) && is_valid_hex(s[i+3])) {
                    ans++;
                    i += 3;
                    continue;
                } else {
                    return -1;
                }
            }
            if (s[i+1] >= '0' && s[i+1] <= '7') {
                if (i + 2 >= s.size()) {
                    ans++;
                    break;
                }
                if (i + 3 >= s.size()) {
                    if (is_oct(s[i+2])) {
                        ans++;
                        break;
                    }
                    ans++;
                    i++;
                    continue;
                }
                if (is_oct(s[i+2]) && is_oct(s[i+3])) {
                    ans++;
                    i += 3;
                    continue;
                } else if (is_oct(s[i+2])) {
                    ans++;
                    i += 2;
                    continue;
                } else {
                    ans++;
                    i++;
                    continue;
                }
            }
            i++;
            ans += 2;
        } else {
            ans++;
        }
    }
    return ans;
}
 
int main() {
    string S;
    while (!getline(cin, S).eof()) {
        int ans = -1;
        int N = S.size();
 
        if (N <= 1) {
            cout << -1 << endl;
            continue;
        }
 
        if (N <= 2) {
            if (S == "\'\'" || S == "\"\"") {
                cout << 0 << endl;
            } else {
                cout << -1 << endl;
            }
            continue;
        }
 
        auto start = S.substr(0, 3);
        if (start == "\"\"\"" || start == "\'\'\'") {
            if (N < 6) {
                cout << -1 << endl;
            } else {
                auto start = S.substr(0, 3);
                auto end = S.substr(N - 3);
 
                if (start == end && (start == "\"\"\"" || start == "\'\'\'")) {
                    ans = count(S.substr(3, N - 6), start);
                } else {
                    ans = -1;
                }
                cout << ans << endl;
            }
            continue;
        }
 
        char s = S[0];
        char e = S[N-1];
        if (s == e && is_valid(s)) {
            ans = count(S.substr(1, N - 2), S.substr(0, 1));
        } else {
            ans = -1;
        }
        cout << ans << endl;
    }
    return 0;
}