#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x == A + B) {
            cout << i + 1 << endl;
        }
    }
    return 0;
}