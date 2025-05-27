#include <bits/stdc++.h>
using namespace std;

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
    function<T(T, T)> f;
	RMQ(const vector<T>& V, function<T(T, T)> _f) : jmp(1, V), f(_f) {
		for (int pw = 1, k = 1; pw * 2 <= V.size(); pw *= 2, ++k) {
			jmp.emplace_back(V.size() - pw * 2 + 1);
			for (int j = 0; j < jmp[k].size(); j++)
				jmp[k][j] = f(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return f(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        const int N = nums.size();
        
        // add aux
        nums.insert(nums.begin(), { -1 });
        RMQ<int> rmin(nums, [](int a, int b) { return min(a, b); });
        
        nums[0] = 1e9;
        RMQ<int> rmax(nums, [](int a, int b) { return max(a, b); });
        
        // rmin:
        //      -----
        //     -
        // ----

        // rmax:
        // ------
        //       ----
        //           --

        long long ans = 0;
        for (int i = 1; i <= N; i++) {
            int last_number_smaller_than_minK = 0;
            int first_number_bigger_than_minK = 0;
            int last_number_bigger_than_maxK = 0;
            int first_number_smaller_than_maxK = 0;
            
            {
                int L = 0, R = i + 1;
                while (R - L > 1) {
                    int M = (R + L) / 2;
                    if (rmin.query(M, i + 1) < minK) {
                        L = M;
                    } else {
                        R = M;
                    }
                }

                last_number_smaller_than_minK = L;
            }

            {
                int L = 0, R = i + 1;
                while (R - L > 1) {
                    int M = (R + L) / 2;
                    if (rmin.query(M, i + 1) <= minK) {
                        L = M;
                    } else {
                        R = M;
                    }
                }

                first_number_bigger_than_minK = L + 1;
            }

            {
                int L = 0, R = i + 1;
                while (R - L > 1) {
                    int M = (R + L) / 2;
                    if (rmax.query(M, i + 1) > maxK) {
                        L = M;
                    } else {
                        R = M;
                    }
                }

                last_number_bigger_than_maxK = L;
            }

            {
                int L = 0, R = i + 1;
                while (R - L > 1) {
                    int M = (R + L) / 2;
                    if (rmax.query(M, i + 1) >= maxK) {
                        L = M;
                    } else {
                        R = M;
                    }
                }

                first_number_smaller_than_maxK = L + 1;
            }

            int L1 = last_number_smaller_than_minK + 1;
            int R1 = first_number_bigger_than_minK - 1;
            if (L1 > R1) continue;

            int L2 = last_number_bigger_than_maxK + 1;
            int R2 = first_number_smaller_than_maxK - 1;
            if (L2 > R2) continue;

            int L = max(L1, L2);
            int R = min(R1, R2);
            if (L > R) continue;

            ans += (R - L + 1);
        }
        return ans;
    }
};