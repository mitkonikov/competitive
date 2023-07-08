#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    string S = "";
    for (int i = 0; i < N; i++) S += A[0][i];
    for (int i = 1; i < N; i++) S += A[i][N-1];
    for (int i = N-2; i >= 0; i--) S += A[N-1][i];
    for (int i = N-2; i >= 1; i--) S += A[i][0];
    
    int p = S.size() - 1;
    for (int i = 0; i < N; i++, p%=S.size()) A[0][i] = S[p++];
    for (int i = 1; i < N; i++, p%=S.size()) A[i][N-1] = S[p++];
    for (int i = N-2; i >= 0; i--, p%=S.size()) A[N-1][i] = S[p++];
    for (int i = N-2; i >= 1; i--, p%=S.size()) A[i][0] = S[p++];

    for (int i = 0; i < N; i++) cout << A[i] << endl;
    return 0;
}