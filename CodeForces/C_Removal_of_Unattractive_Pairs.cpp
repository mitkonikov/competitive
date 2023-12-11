#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> frq(26);
    for (int i = 0; i < N; i++) frq[S[i] - 'a']++;
    for (int i = 0; i < N; i++) {
        // find the smallest frq
        int sm = -1;
        for (int j = 0; j < 26; j++) {
            if (frq[j] == 0) continue;
            if (sm == -1 || frq[j] < frq[sm]) {
                sm = j;
            }
        }
        if (sm == -1) break;
        int bg = -1;
        for (int j = 0; j < 26; j++) {
            if (frq[j] == 0) continue;
            if (bg == -1 || (bg == sm && frq[j] >= frq[bg]) || frq[j] > frq[bg]) {
                bg = j;
            }
        }
        if (sm != bg) {
            frq[sm]--;
            frq[bg]--;
        }
    }
    int sum = 0;
    for (int i = 0; i < 26; i++) sum += frq[i];
    cout << sum << endl;
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