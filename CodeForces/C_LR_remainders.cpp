#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    string S;
    cin >> S;
    vector<int> remove;
    remove.reserve(N);
    int L = 0, R = N - 1;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'L') {
            remove.push_back(L);
            L++;
        } else {
            remove.push_back(R);
            R--;
        }
    }
    ll prod = 1;
    vector<int> prods;
    for (int i = N - 1; i >= 0; i--) {
        prod = (prod * A[remove[i]]) % M;
        prods.push_back(prod);
    }
    reverse(prods.begin(), prods.end());
    for (auto el: prods) cout << el << " ";
    cout << endl;
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