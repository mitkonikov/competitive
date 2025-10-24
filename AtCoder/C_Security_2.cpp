#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    ll count = 0;
    int offset = 0;
    int N = S.size();
    for (int i = N - 1; i >= 0; i--) {
        int dig = S[i] - '0';
        dig = ((dig - offset) + 20) % 10;
        count += dig;
        offset = (offset + dig) % 10;
    }
    cout << count + N << endl;
    return 0;
}