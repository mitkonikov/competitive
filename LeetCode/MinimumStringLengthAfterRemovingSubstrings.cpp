class Solution {
public:
    int minLength(string s) {
        int N = s.size();
        for (int i = 0; i < N; i++) {
            string new_string = "";
            for (int j = 0; j < s.size(); j++) {
                if (j < s.size() - 1 && (s.substr(j, 2) == "AB" || s.substr(j, 2) == "CD")) {
                    j++;
                } else {
                    new_string += s[j];
                }
            }
            s = new_string;
        }
        return s.size();
    }
};