#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int a = 0; a <= N; a++) {
        for (int b = 0; b <= N - a; b++) {
            for (int c = 0; c <= N - a - b; c++) {
                cout << a << " " << b << " " << c << endl;
            }
        }
    }
    return 0;
}