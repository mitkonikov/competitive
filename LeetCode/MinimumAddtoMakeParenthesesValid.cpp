class Solution {
public:
    int minAddToMakeValid(string s) {
        int N = s.size();
        int balance = 0;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] == '(') {
                balance++;
            } else {
                balance--;
            }

            if (balance < 0) {
                ans++;
                balance++;
            }
        }
        ans += balance;
        return ans;
    }
};