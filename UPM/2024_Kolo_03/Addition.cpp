#include "bits/stdc++.h"
#define ll long long
 
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<int> A(2e6 + 10);
 
    string S;
    while (true) {
        int off = getline(cin, S).eof();
        int N = S.size() - 2;
        for (int i = N; i >= 0; i--) {
            int k = N - 1 - i;
            A[max(0, k)] += (S[i] - '0');
        }
        if (off) break;
    }
 
    while (true) {
        bool cn = false;
        
        for (int i = 0; i < 1500000; i++) {
            int m = min(A[i], A[i+1]);
            A[i] -= m;
            A[i+1] -= m;
            A[i+2] += m;
            if (m > 0) cn = true;
            if (A[i] >= 2) {
                int n = A[i] / 2;
                A[i] = A[i] % 2;
                if (i == 0) {
                    A[1] += n;
                } else if (i == 1) {
                    A[2] += n;
                    A[0] += n;
                } else {
                    A[i+1] += n;
                    A[i-2] += n;
                }
            }
            for (int j = max(0, i - 5); j <= i + 5; j++) {
                if (A[j] > 1) cn = true;
                if (A[j] >= 1 && A[j+1] >= 1) cn = true;
            }
        }
 
        if (!cn) break;
    }
 
    bool printing = false;
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] > 0) printing = true;
        if (printing) cout << A[i];
    }
    if (!printing) {
        cout << 0 << endl;
    } else {
        cout << "00" << endl;
    }
    return 0;
}