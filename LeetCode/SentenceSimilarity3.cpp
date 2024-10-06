class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        auto split = [](string s) {
            vector<string> vec;
            int prev = -1;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == ' ') {
                    vec.push_back(s.substr(prev + 1, i - prev - 1));
                    prev = i;
                }
            }
            string rem = s.substr(prev + 1);
            if (!rem.empty()) vec.push_back(rem);
            return vec;
        };

        vector<string> S = split(sentence1);
        vector<string> T = split(sentence2);

        if (S.size() < T.size()) swap(S, T);
        
        int p1 = 0;
        while (p1 < (int)T.size() 
            && p1 < (int)S.size() 
            && S[p1] == T[p1]) p1++;
        
        int p2 = 0;
        while ((int)T.size() - p2 - 1 >= 0 
            && (int)S.size() - p2 - 1 >= 0 
            && S[(int)S.size() - p2 - 1] == T[(int)T.size() - p2 - 1]) p2++;
        
        return ((int)T.size() - 1 - p2) < p1;
    }
};