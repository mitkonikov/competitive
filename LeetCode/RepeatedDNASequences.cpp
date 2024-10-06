class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, bool> mp;

        set<string> ans;
        int N = s.size();
        for (int i = 0; i < N - 10 + 1; i++) {
            string current_string = s.substr(i, 10);
            if (mp.count(current_string)) {
                ans.insert(current_string);
            } else {
                mp[current_string] = true;
            }
        }

        vector<string> ans_v;
        for (auto el: ans) ans_v.push_back(el);
        return ans_v;
    }
};