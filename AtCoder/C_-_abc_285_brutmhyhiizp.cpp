#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    ll id = 0;
    reverse(S.begin(), S.end());
    while (S.size()) {
        id *= 26;
        id += (S.back() - 'A' + 1);
        S.pop_back();
    }
    cout << id << endl;
    cout << flush;
    return 0;
}
