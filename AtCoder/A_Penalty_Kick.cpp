#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cout << ((i + 1) % 3 == 0 ? 'x' : 'o');
    }
    cout << endl;
    return 0;
}