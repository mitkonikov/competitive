class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());

        int N = skill.size();
        long long sum = 0, ans = 0;
        for (int i = 0; i < N / 2; i++) {
            if (i == 0) sum = skill[i] + skill[N - 1 - i];
            else {
                if (skill[i] + skill[N - 1 - i] != sum) {
                    return -1;
                }
            }

            ans += (long long)skill[i] * skill[N - 1 -i];
        }

        return ans;
    }
};