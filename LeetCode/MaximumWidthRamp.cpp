class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int N = nums.size();
        map<int, int> convex;
        int lowest = INT_MAX;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            auto it = convex.lower_bound(-nums[i]);
            if (it != convex.end()) {
                ans = max(ans, i - it->second);
            }

            if (nums[i] < lowest) {
                lowest = nums[i];
                convex[-lowest] = i;
            }
        }
        return ans;
    }
};