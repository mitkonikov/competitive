#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    string ans = "";
    for (int i = 0; i < S.size(); i++) {
        ans.push_back(S[i]);
        while (ans.size() >= 3 && ans.substr(ans.size() - 3, 3) == "ABC") {
            ans.pop_back();
            ans.pop_back();
            ans.pop_back();
        }
    }
    cout << ans << endl;
    return 0;
}