#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    ll power = 1;
    for (int i = 0; i < B; i++) {
        power *= A;
    }
    cout << power << endl;
    return 0;
}