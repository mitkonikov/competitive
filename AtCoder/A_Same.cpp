#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    set<int> S;
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        S.insert(X);
    }
    cout << (S.size() == 1 ? "Yes" : "No") << endl;
    return 0;
}