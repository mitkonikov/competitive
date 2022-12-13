#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int S, K;
    cin >> S >> K;
    vector<int> frq(10);
    for (int i = S; i <= K; i++) {
        int t = i;
        while (t > 0) {
            frq[t % 10]++;
            t /= 10;
        }
    }
    for (int i = 0; i < 10; i++) {
        cout << frq[i] << " ";
    } cout << endl;
    return 0;
}