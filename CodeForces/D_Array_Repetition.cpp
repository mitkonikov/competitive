#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, Q;
    cin >> N >> Q;
    struct Block {
        int type = 1; // { 1 - add }, { 2 - replicate }
        ll period = 0; // only at 1
        ll prev_size = 0;
        vector<int> elements; // only at 2
    };
    vector<Block> blocks;
    blocks.push_back({ 1, 0, {} });
    ll size = 0;
    for (int i = 0; i < N; i++) {
        ll B, X;
        cin >> B >> X;
        if (size > ((ll)1e18 + 10)) continue;
        if (B == 1) {
            // append at the end
            auto& b = blocks.back();
            if (b.type != 1) {
                blocks.push_back({ 1, 0, size });
            }
            blocks.back().elements.push_back(X);
            size++;
        } else if (B == 2) {
            // append X copies of the array at the end
            blocks.push_back({ 2, size });
            if (((ll)(1e18) + 10) / size < (X + 1)) {
                size = (ll)(1e18) + 20;
                continue;
            }
            size += (X * size);
        }
    }
    for (int i = 0; i < Q; i++) {
        ll K;
        cin >> K;
        K--;
        for (int j = blocks.size() - 1; j >= 0; j--) {
            auto& b = blocks[j];
            if (b.type == 1) {
                if (K >= b.prev_size) {
                    cout << b.elements[K - b.prev_size] << " ";
                    break;
                }
            } else {
                K = K % b.period;
            }
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}