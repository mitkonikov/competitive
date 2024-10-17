class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int N = intervals.size();
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        multiset<int> ending_points;
        for (int i = 0; i < N; i++) {
            int l = intervals[i][0];
            int r = intervals[i][1];
            auto it = ending_points.upper_bound(-l);
            if (it == ending_points.end()) {
                // start a new group
                ending_points.insert(-r);
            } else {
                ending_points.erase(it);
                ending_points.insert(-r);
            }
        }
        return (int)ending_points.size();
    }
};