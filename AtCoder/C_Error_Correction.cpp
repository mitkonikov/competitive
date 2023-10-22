#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    string T;
    cin >> N >> T;
    vector<int> ans;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        if (S == T) {
            ans.push_back(i);
            continue;
        }
        if (S.size() == T.size() + 1) {
            int p = 0;
            int mistake = 0;
            for (int j = 0; j < T.size(); j++) {
                while (p < S.size() && S[p] != T[j]) {
                    p++;
                    mistake++;
                }
                p++;
            }
            if (mistake <= 1) {
                ans.push_back(i);
            }
            continue;
        }
        if (S.size() + 1 == T.size()) {
            int p = 0;
            int mistake = 0;
            for (int j = 0; j < S.size(); j++) {
                while (p < T.size() && S[j] != T[p]) {
                    p++;
                    mistake++;
                }
                p++;
            }
            if (mistake <= 1) {
                ans.push_back(i);
            }
            continue;
        }
        if (S.size() == T.size()) {
            int mistake = 0;
            for (int j = 0; j < S.size(); j++) {
                mistake += S[j] != T[j];
            }
            if (mistake == 1) {
                ans.push_back(i);
            }
            continue;
        }
    }
    cout << ans.size() << endl;
    for (auto el: ans) cout << el + 1 << " ";
    cout << endl;
    return 0;
}