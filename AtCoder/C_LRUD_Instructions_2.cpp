#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    int x = 0, y = 0;
    set<pair<int, int>> s;
    s.insert({ x, y });
    string S;
    cin >> S;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') x++;
        else if (S[i] == 'L') x--;
        else if (S[i] == 'U') y++;
        else y--;
        if (s.count({ x, y })) {
            cout << "Yes" << endl;
            return 0;
        }
        s.insert({ x, y });
    }
    cout << "No" << endl;
    return 0;
}