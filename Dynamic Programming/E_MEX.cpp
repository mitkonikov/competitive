#include <bits/stdc++.h>
#define ll long long

using namespace std;

inline int mex(int a, int b, int c) {
    vector<bool> v(3);
    v[a]=1;
    v[b]=1;
    v[c]=1;
    for (int i = 0; i < 3; i++) {
        if (!v[i]) return i;
    }
    return 3;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    string S;
    cin >> S;
    ll ans = 0;
    vector<int> frq_left(4), frq_right(4);
    for (int i = 0; i < N; i++) {
        if (S[i] == 'X') {
            frq_right[A[i]]++;
        }
    }
    for (int i = 0; i < N; i++) {
        // remove from the frq_right
        if (S[i] == 'X') frq_right[A[i]]--;
        
        if (i && S[i] == 'E') {
            for (int l = 0; l < 3; l++) {
                for (int r = 0; r < 3; r++) {
                    ll res = mex(l, r, A[i]);
                    ans += res * frq_left[l] * frq_right[r];
                }
            }
        }

        // add this element to the left side
        if (S[i] == 'M') frq_left[A[i]]++;
    }
    cout << ans << endl;
    return 0;
}