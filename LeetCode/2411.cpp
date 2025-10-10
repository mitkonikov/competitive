#include <bits/stdc++.h>
using namespace std;
#define ll long long

template <typename T, auto identity>
class DisjointSparseTable {
public:
	explicit DisjointSparseTable(vector<T> arr) {
		// Find the highest cnt such that pow2 = 2^cnt >= x
		int pow2 = 1, cnt = 0;
		for (; pow2 < arr.size(); pow2 *= 2, ++cnt);
		
		arr.resize(pow2, identity);
		sum.resize(cnt, vector<T>(pow2));
		
		for(int level = 0; level < sum.size(); ++level) {
			for(int block = 0; block < 1 << level; ++block) {
				// The first half of the block contains suffix sums,
				// the second half contains prefix sums
				const auto start = block << (sum.size() - level);
				const auto end = (block + 1) << (sum.size() - level);
				const auto middle = (end + start) / 2;
				
				auto val = arr[middle];
				sum[level][middle] = val;
				for(int x = middle + 1; x < end; ++x) {
					val = val | arr[x];
					sum[level][x] = val;
				}
				
				val = arr[middle - 1];
				sum[level][middle - 1] = val;
				for(int x = middle-2; x >= start; --x) {
					val = val | arr[x];
					sum[level][x] = val;
				}
			}
		}
	}
	/*! Returns Monoid sum over range [l, r)*/
	T query(int l, int r) const {
		assert(l < r);
		// Convert half open interval to closed interval
		--r;
		if(r == l-1){
			return identity;
		}
		if(l == r){
			return sum.back()[l];
		}
		// Position of the leftmost different bit from the right
		const auto pos_diff = (sizeof(ll) * CHAR_BIT) - 1 - __builtin_clzll(l ^ r);
		const auto level = sum.size() - 1 - pos_diff;
		return sum[level][l] | sum[level][r];
	}
private:
	vector<vector<T>> sum;
};

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        const int N = nums.size();
        vector<int> result(N);
        DisjointSparseTable<int, 0> table(nums);
        for (int i = 0; i < N; i++) {
            if (i == N - 1) {
                result[i] = 1;
                continue;
            }
            int L = i, R = N;
            int mx = table.query(L, N);
            if (nums[L] == mx) {
                result[i] = 1;
                continue;
            }
            while (R - L > 1) {
                int M = (L + R) / 2;
                if (table.query(i, M + 1) < mx) {
                    L = M;
                } else {
                    R = M;
                }
            }
            result[i] = L + 1 - i + 1;
        }
        return result;
    }
};