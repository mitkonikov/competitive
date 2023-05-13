#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    int now = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (i == 0) {
            now = x;
            cout << now << " ";
            continue;
        }
        while (now != x) {
            if (now > x) {
                now--;
            } else {
                now++;
            }
            cout << now << " ";
        }
    }
    cout << endl;
    return 0;
}