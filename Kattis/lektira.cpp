#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string s;
    cin >> s;
    string ans = "";
    for (int i = 1; i < s.size() - 1; i++) {
        for (int j = 1; j < s.size() - i; j++) {
            string first = s.substr(0, i);
            string second = s.substr(i, j);
            string third = s.substr(i+j);
            reverse(first.begin(), first.end());
            reverse(second.begin(), second.end());
            reverse(third.begin(), third.end());
            if (ans == "") ans = first + second + third;
            else ans = min(ans, first + second + third);
        }
    }
    cout << ans << endl;
    cout << flush;
    return 0;
}