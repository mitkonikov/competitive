#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            if (x == 0) cout << ".";
            else cout << (char)('A' + x - 1);
        }
        cout << endl;
    }
    return 0;
}