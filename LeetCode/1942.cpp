class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        struct op {
            int fid;
            bool enter;
        };
        const int MAX = 1e5 + 100;
        vector<vector<op>> ops(MAX);
        for (int i = 0; i < times.size(); i++) {
            int start = times[i][0];
            int end = times[i][1];
            ops[start].push_back({ i, true });
            ops[end].push_back({ i, false });
        }
        set<int> chairs;
        for (int i = 0; i < MAX; i++) {
            chairs.insert(i);
        }
        for (int i = 0; i < MAX; i++) {
            sort(ops[i].begin(), ops[i].end(), [](op a, op b) {
                if (a.enter == b.enter) return a.fid < b.fid;
                return !a.enter;
            });
        }
        vector<int> chair_ids(times.size());
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < ops[i].size(); j++) {
                if (!ops[i][j].enter) {
                    int chair_id = chair_ids[ops[i][j].fid];
                    chairs.insert(chair_id);
                } else {
                    auto it = chairs.begin();
                    chair_ids[ops[i][j].fid] = *it;
                    chairs.erase(it);
                }
            }
        }
        return chair_ids[targetFriend];
    }
};