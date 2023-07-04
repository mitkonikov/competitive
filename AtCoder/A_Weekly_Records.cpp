#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll sum = 0;
        for (int j = 0; j < 7; j++) {
            int x;
            cin >> x;
            sum += x;
        }
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}