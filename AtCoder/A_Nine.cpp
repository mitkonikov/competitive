#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    if (A > B) swap(A, B);
    bool ok = (A == B - 1 && A % 3 != 0);
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}