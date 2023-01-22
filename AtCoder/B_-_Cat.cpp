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
        if (i < N - 1 && S.substr(i, 2) == "na") {
            cout << "nya";
            i++;
            continue;
        } else {
            cout << S[i];
        }
    }
    return 0;
}