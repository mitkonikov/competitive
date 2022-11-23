#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

bool solve(string s) {
    int n = s.size();
    int count01 = 0;
    int count10 = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == '1' && s[i-1] == '0') {
            count01++;
        }

        if (s[i] == '0' && s[i-1] == '1') {
            count10++;
        }
    }

    return (count10 == count01);
}

void testCase() {
    string s;
    cin >> s;
    int count01 = 0;
    int count10 = 0;
    int n = s.size();
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == '1' && s[i-1] == '0') {
            count01++;
        }

        if (s[i] == '0' && s[i-1] == '1') {
            count10++;
        }
    }

    for (int i = 1; i < n - 1; i++) {
        string t = s.substr(i - 1, 3);
        int mv01 = 0;
        int mv10 = 0;
        for (int i = 1; i < 3; i++) {
            if (t[i] == '1' && t[i-1] == '0') {
                mv01--;
            }

            if (t[i] == '0' && t[i-1] == '1') {
                mv10--;
            }
        }
        
        t[1] = (t[1] == '0' ? '1' : '0');
        for (int i = 1; i < 3; i++) {
            if (t[i] == '1' && t[i-1] == '0') {
                mv01++;
            }

            if (t[i] == '0' && t[i-1] == '1') {
                mv10++;
            }
        }

        if (count01 + mv01 == count10 + mv10) {
            ans++;
        }
    }
    
    s[0] = (s[0] == '0' ? '1' : '0');
    ans += solve(s);
    s[0] = (s[0] == '0' ? '1' : '0');
    s[n-1] = (s[n-1] == '0' ? '1' : '0');
    ans += solve(s);
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}