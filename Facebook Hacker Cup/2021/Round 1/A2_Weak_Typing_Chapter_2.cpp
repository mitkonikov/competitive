#include <iostream>
#include <vector>
#include <string>
#define ll long long

using namespace std;

const ll MOD = 1000000007LL;

void testCase() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int count = 0;

    ll ans = 0;

    char letter = 'a';
    ll lastSwitch = 0;
    ll lastContributed = 0;

    ll last[2] = { 0, 0 };

    for (int i = 0; i < n; i++) {
        if (s[i] == 'O') s[i] = '0';
        else if (s[i] == 'X') s[i] = '1';
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '1' || s[i] == '0') {
            if (letter == 'a') {
                letter = s[i];
                last[s[i] - '0'] = i;

                continue;
            }

            if (letter != s[i]) {
                lastSwitch = last[(s[i] - '0') ^ 1];

                ans = (ans + lastSwitch + 1 + lastContributed) % MOD;
                lastContributed = (lastContributed + lastSwitch + 1) % MOD;

                letter = s[i];
                last[s[i] - '0'] = i;
                continue;
            }

            letter = s[i];
            last[s[i] - '0'] = i;
        }
        
        ans = (ans + lastContributed) % MOD;
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    for (int tt = 0; tt < t; tt++) {
        cout << "Case #" << tt+1 << ": ";
        testCase();
    }

    return 0;
}