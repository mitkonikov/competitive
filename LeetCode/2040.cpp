#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lll __int128_t

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        // neg * pos ... pos * neg   == 0 ... M-1
        // zer * wha ... wha * zer   == M ... N-1
        // pos * pos ... neg * neg   == N ... T
        k--;
        int z1 = 0, z2 = 0;
        vector<vector<int>> A(2), B(2);
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        auto sign = [&](int n) {
            return (n >= 0);
        };
        for (int i = 0; i < N1; i++) {
            if (nums1[i] == 0) {
                z1++;
                continue;
            }

            A[sign(nums1[i])].push_back(nums1[i]);
        }
        for (int i = 0; i < N2; i++) {
            if (nums2[i] == 0) {
                z2++;
                continue;
            }

            B[sign(nums2[i])].push_back(nums2[i]);
        }

        // O(log(10^10) * log(N2) * N)
        ll M = (ll)A[0].size() * B[1].size() + (ll)A[1].size() * B[0].size();
        ll N = M + (ll)z1 * N2 + (ll)z2 * N1 - (ll)z1 * z2;

        auto solve = [&](vector<vector<int>> a, vector<vector<int>> b) {
            lll L = lll(-1e10 - 10), R = lll(1e10 + 10);
            while (R - L > 1) {
                ll M = (ll)(L + (R - L) / 2);
                ll count = 0;
                for (int rep: { 0, 1 }) {
                    for (int i = 0; i < a[rep].size(); i++) {
                        int L1 = 0, R1 = b[rep].size();
                        while (R1 - L1 > 1) {
                            int M1 = (L1 + R1) / 2;
                            if ((ll)a[rep][i] * b[rep][M1] <= M) {
                                L1 = M1;
                            } else {
                                R1 = M1;
                            }
                        }
                        for (int l = L1 + 2; l >= max(L1 - 2, 0); l--) {
                            if (l < b[rep].size() && (ll)a[rep][i] * b[rep][l] <= M) {
                                count += l + 1;
                                break;
                            }
                        }
                    }
                }
                if (count <= k) {
                    L = M;
                } else {
                    R = M;
                }
            }
            return L + 1;
        };

        if (M <= k && k < N) {
            return 0;
        }

        if (k < M) {
            reverse(A[1].begin(), A[1].end());
            reverse(B[1].begin(), B[1].end());
            return solve({ A[0], A[1] }, { B[1], B[0] });
        }

        k -= N;
        reverse(A[0].begin(), A[0].end());
        reverse(B[0].begin(), B[0].end());
        return solve({ A[0], A[1] }, { B[0], B[1] });
    }
};

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    Solution s;
    cout << s.kthSmallestProduct(A, B, K) << endl;
    return 0;
}