#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N, P, Q, R, S;
    cin >> N >> P >> Q >> R >> S;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    P--; Q--; R--; S--;
    for (int i = P; i <= Q; i++) {
        swap(A[i], A[i-P+R]);
    }
    for (auto el: A) {
        cout << el << " ";
    } 
    cout << endl;
    return 0;
}