#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

pair<string, int> solve(int N, string S) {
    string R = S;
    reverse(R.begin(), R.end());
    string T1 = S + "#" + R;
    string T2 = R + "#" + S;
    auto t1 = z_function(T1);
    auto t2 = z_function(T2);

    for (int i = 0; i <= N; i++) {
        if (t1[2*N+i+1] >= N-i && t2[2*N+(N-i+1)] >= i) {
            reverse(S.begin(), S.end());
            string ans = S.substr(i, N);
            return { ans, N - i };
        }
    }

    return { "", -1 };
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    auto ans = solve(N, S);
    cout << ans.first << endl;
    cout << ans.second << endl;
    return 0;
}