#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(Q);
    for (int i = 0; i < Q; i++) cin >> A[i];
    vector<int> frq(N);
    for (int i = 0; i < Q; i++) {
        if (A[i] == 0) {
            int mn_id = min_element(frq.begin(), frq.end()) - frq.begin();
            int k = 0;
            for (int j = 0; j < N; j++) {
                if (frq[j] == frq[mn_id]) {
                    k = j;
                    break;
                }
            }
            cout << k + 1 << " ";
            frq[k]++;
        } else {
            frq[A[i]-1]++;
            cout << A[i] << " ";
        }
    }
    cout << endl;
    return 0;
}