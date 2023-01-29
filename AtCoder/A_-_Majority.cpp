#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    int f = 0, a = 0;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        if (S == "For") f++;
        else a++;
    }
    cout << (a > f ? "No" : "Yes") << endl;
    return 0;
}