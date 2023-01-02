#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ll H, A, S;
    cin >> H >> A >> S;
    cout << max(0LL, min(H, A) - S) << endl;    
    return 0;
}