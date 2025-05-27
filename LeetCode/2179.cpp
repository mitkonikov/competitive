#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        const int MAGIC = 310;
        const int N = nums1.size();
        const int BLOCKS = (N + MAGIC - 1) / MAGIC;
        vector<vector<int>> sqrt_left(BLOCKS + 1, vector<int>(BLOCKS + 1, 0));
        vector<vector<int>> sqrt_right(BLOCKS + 1, vector<int>(BLOCKS + 1, 0));
        vector<vector<bool>> ch_left1(BLOCKS + 1, vector<bool>(N));
        vector<vector<bool>> ch_right1(BLOCKS + 1, vector<bool>(N));
        vector<vector<bool>> ch_left2(BLOCKS + 1, vector<bool>(N));
        vector<vector<bool>> ch_right2(BLOCKS + 1, vector<bool>(N));
        
        auto preprocess = [&](vector<vector<int>>& sqrt, vector<vector<bool>>& ch1, vector<vector<bool>>& ch2) {
            for (int s1 = 0; s1 < N; s1 += MAGIC) {
                const int B1 = s1 / MAGIC + 1;
                ch1[B1] = ch1[B1 - 1];
                ch2[B1] = ch2[B1 - 1];
                for (int i = 0; i < MAGIC && s1 + i < N; i++) {
                    ch1[B1][nums1[s1 + i]] = true;
                    ch2[B1][nums2[s1 + i]] = true;
                }

                int running = 0;
                for (int s2 = 0; s2 < N; s2 += MAGIC) {
                    const int B2 = s2 / MAGIC + 1;
                    for (int j = 0; j < MAGIC && s2 + j < N; j++) {
                        running += ch1[B1][nums2[s2 + j]];
                    }
                    sqrt[B1][B2] += running;
                }
            }
        };

        preprocess(sqrt_left, ch_left1, ch_left2);
        reverse(nums1.begin(), nums1.end());
        reverse(nums2.begin(), nums2.end());
        preprocess(sqrt_right, ch_right1, ch_right2);
        reverse(nums1.begin(), nums1.end());
        reverse(nums2.begin(), nums2.end());

        vector<int> rev(N);
        for (int i = 0; i < N; i++) {
            rev[nums2[i]] = i;
        }

        vector<bool> visited(N);

        ll ans = 0;
        for (int i = 1; i < N - 1; i++) {
            const int NUM = nums1[i];
            const int j = rev[NUM];
            if (j == 0 || j == N - 1) continue;

            // we have i and j
            const int LEFT_i = i / MAGIC;
            const int LEFT_j = j / MAGIC;
            const int RIGHT_i = (N - i - 1) / MAGIC;
            const int RIGHT_j = (N - j - 1) / MAGIC;

            int more_left = 0;
            int more_right = 0;
            
            // compute the sqrt movements inside the current block
            for (int t = LEFT_i * MAGIC; t < i; t++) {
                ch_left1[LEFT_i][nums1[t]] = true;
                more_left += ch_left2[LEFT_j][nums1[t]];
            }

            for (int t = LEFT_j * MAGIC; t < j; t++) {
                more_left += ch_left1[LEFT_i][nums2[t]];
            }

            // reset the visited
            for (int t = LEFT_i * MAGIC; t < i; t++) {
                ch_left1[LEFT_i][nums1[t]] = false;
            }

            // do this for the sqrt_right
            for (int t = RIGHT_i * MAGIC; t < (N - 1 - i); t++) {
                ch_right1[RIGHT_i][nums1[N-1-t]] = true;
                more_right += ch_right2[RIGHT_j][nums1[N-1-t]];
            }

            for (int t = RIGHT_j * MAGIC; t < (N - 1 - j); t++) {
                more_right += ch_right1[RIGHT_i][nums2[N-1-t]];
            }

            // reset the visited
            for (int t = RIGHT_i * MAGIC; t < (N - 1 - i); t++) {
                ch_right1[RIGHT_i][nums1[N-1-t]] = false;
            }

            const ll left_count = sqrt_left[LEFT_i][LEFT_j] + more_left;
            const ll right_count = sqrt_right[RIGHT_i][RIGHT_j] + more_right;

            ans += left_count * right_count;
        }

        return ans;
    }
};