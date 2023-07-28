#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    set<char> s;
    for (int i = 0; i < N; i++) {
        s.insert(S[i]);
        if (s.size() == 3) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    return 0;
}