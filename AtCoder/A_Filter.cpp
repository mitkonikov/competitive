#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x % 2 == 0) {
            cout << x << " ";
        }
    }
    cout << endl;
    cout << flush;
    return 0;
}