class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int T = s1.size();
        int S = s2.size();
        if (T > S) return false;
        if (T == S) {
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            return s1 == s2;
        }
        vector<vector<int>> pref(S, vector<int>(26, 0));
        pref[0][s2[0] - 'a']++;
        for (int i = 1; i < S; i++) {
            for (int j = 0; j < 26; j++) {
                pref[i][j] = pref[i-1][j];
            }
            pref[i][s2[i] - 'a']++;
        }
        vector<int> alp(26, 0);
        for (int i = 0; i < T; i++) {
            alp[s1[i] - 'a']++;
        }
        for (int i = T-1; i < S; i++) {
            bool ok = true;
            for (int j = 0; j < 26; j++) {
                int c = pref[i][j] - ((i-T)>=0 ? pref[i-T][j] : 0);
                ok &= (c == alp[j]);
            }
            if (ok) return true;
        }
        return false;
    }
};