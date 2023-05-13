#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int last = 0, t = 0, a = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'T') {
            t++;
            last = 0;
        } else {
            a++;
            last = 1;
        }
    }
    if (t > a) {
        cout << "T" << endl;
    } else if (a > t) {
        cout << "A" << endl;
    } else {
        cout << (last == 0 ? "A" : "T") << endl;
    }
    return 0;
}