#pragma GCC optimize("O2")

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    
    struct Query {
        int l, r, id;
        void read(int i) {
            cin >> l >> r;
            l--; r--;
            id = i;
        }
        bool operator<(const Query& other) const {
            return (r < other.r);
        }
    };
    
    int MAGIC = 400;
    int BLOCKS = N / MAGIC + 10;
    vector<vector<Query>> buckets(BLOCKS);
    for (int i = 0; i < Q; i++) {
        Query q;
        q.read(i);
        buckets[q.l / MAGIC].push_back(q);
    }

    struct Rectangle {
        int height = 0, index = 0;
        ll cost = 0;
        bool operator<(const Rectangle& other) const {
            return height < other.height;
        }
    };

    vector<ll> ans(Q);
    vector<Rectangle> rects(N);
    int p = 0;
    for (int i = 0; i < (int)buckets.size(); i++) {
        sort(buckets[i].begin(), buckets[i].end());
        const int BLOCK = i * MAGIC;

        int last_r = (i + 1) * MAGIC - 1;
        int biggest = 0;
        ll cost = 0;
        p = 0;
        for (const auto& q: buckets[i]) {
            if (q.r <= BLOCK + MAGIC) {
                int biggest = A[q.l];
                ll current = 0;
                for (int k = q.l; k <= q.r; k++) {
                    if (A[k] < biggest) {
                        current += biggest - A[k];
                    } else {
                        biggest = A[k];
                    }
                }
                ans[q.id] = current;
            } else {
                for (int k = last_r + 1; k <= q.r; k++) {
                    if (A[k] <= biggest) {
                        rects[p-1].index++;
                        cost += biggest - A[k];
                    } else {
                        int prev = 1;
                        ll cost = 0;
                        if (p > 0) {
                            prev = rects[p-1].index + 1;
                            auto b = rects[p-1];
                            cost = b.cost + (ll)(A[k] - b.height) * b.index;
                        }
                        
                        biggest = A[k];
                        rects[p++] = { biggest, prev, cost };
                    }
                }

                int biggest = A[q.l];
                ll current = 0;
                for (int k = q.l; k < BLOCK + MAGIC; k++) {
                    if (A[k] < biggest) current += biggest - A[k];
                    else biggest = A[k];
                }

                ll need = 0;
                if (rects[0].height < biggest) {
                    auto it = lower_bound(rects.begin(), rects.begin() + p, Rectangle{ biggest, 0, 0 });
                    if (it != rects.begin()) {
                        it--;
                        need = (ll)(biggest - it->height) * (it->index) + it->cost;
                    }
                }

                ans[q.id] = current + cost + need;
                
                last_r = max(last_r, q.r);
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}