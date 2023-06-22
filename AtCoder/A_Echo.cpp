#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    for (int i = 0; i < N; i++) {
        cout << S[i] << S[i];
    }
    cout << endl;
    cout << flush;
    return 0;
}