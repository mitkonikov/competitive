#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        int cnt = 0;
        for (int j = 1; j * j <= x; j++) {
            if (x % j == 0) {
                if (j * j == x) cnt++;
                else cnt += 2;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}