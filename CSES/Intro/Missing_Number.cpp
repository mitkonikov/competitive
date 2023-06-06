#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> frq(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int x;
        cin >> x;
        frq[x] = 1;
    }
    for (int i = 1; i <= N; i++) {
        if (frq[i] == 0) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}