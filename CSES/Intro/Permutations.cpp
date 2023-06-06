#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (N == 2 || N == 3) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    if (N == 4) {
        cout << "2 4 1 3" << endl;
        return 0;
    }
    int last = 1;
    for (int i = 0; i < N; i++) {
        cout << last << " ";
        if (i % 2 == 0) last += N / 2 + (N % 2 == 1);
        else last -= N / 2 - 1 + (N % 2 == 1);
    }
    return 0;
}