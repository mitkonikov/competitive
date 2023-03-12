#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    string S;
    cin >> S;
    for (int i = 0; i < S.size(); i += 2) {
        swap(S[i], S[i+1]);
    }
    cout << S << endl;
    return 0;
}