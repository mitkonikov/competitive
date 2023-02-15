#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<string> A(K);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (i < K) A[i] = s;
    }
    sort(A.begin(), A.end());
    for (auto el: A) {
        cout << el << endl;
    }
    return 0;
}