#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> balance(N);
    vector<int> ind(N);
    for (int i = 0; i < 3 * N; i++) {
        int x;
        cin >> x;
        x--;
        if (balance[x] == 1) {
            ind[x] = i;
        }
        balance[x] ^= 1;
    }
    vector<int> order(N);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return ind[a] < ind[b];
    });
    for (auto el: order) {
        cout << el + 1 << " ";
    }
    cout << endl;
    return 0;
}