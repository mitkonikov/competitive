#include <bits/stdc++.h>
#define ll long long

using namespace std;

int minRotation(string S) {
    int a = 0, N = S.size();
    S += S;
    for (int b = 0; b < N; b++) {
        for (int k = 0; k < N; k++) {
            if (a + k == b || S[a + k] < S[b + k]) {
                b += max(0, k - 1);
                break;
            }
            if (S[a + k] > S[b + k]) {
                a = b;
                break;
            }
        }
    }
    return a;
}

int main() {
    string S;
    cin >> S;
    int r = minRotation(S);
    rotate(S.begin(), S.begin() + r, S.end());
    cout << S << endl;
    return 0;
}