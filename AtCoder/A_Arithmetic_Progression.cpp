#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int A, B, D;
    cin >> A >> B >> D;
    while (A <= B) {
        cout << A << " ";
        A += D;
    }
    cout << endl;
    return 0;
}