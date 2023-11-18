#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> longest(26, 0);
    int block = 1;
    for (int i = 0; i < N; i++) {
        if (i && S[i] == S[i-1]) {
            block++;
        } else {
            block = 1;
        }
        longest[S[i] - 'a'] = max(longest[S[i] - 'a'], block);
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += longest[i];
    }
    cout << ans << endl;
    return 0;
}