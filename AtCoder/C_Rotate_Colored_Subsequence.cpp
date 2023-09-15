#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    vector<int> C(N);
    for (int i = 0; i < N; i++) cin >> C[i];
    vector<string> A(M, "");
    for (int i = 0; i < N; i++) {
        A[C[i] - 1] += S[i];
    }
    vector<int> pointers(M);
    for (int i = 0; i < N; i++) {
        int size = A[C[i] - 1].size();
        cout << A[C[i] - 1][(pointers[C[i] - 1]-1+size)%size];
        pointers[C[i] - 1]++;
    }
    cout << endl;
    return 0;
}