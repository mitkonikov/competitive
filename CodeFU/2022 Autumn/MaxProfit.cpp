#include <string>
#include <vector>
using namespace std;

class MaxProfit {
   public:
    int findMaxProfit(int k, int w, vector<int> returnInvestment,
                      vector<int> capital) {
        int n = returnInvestment.size();
        vector<bool> seen(n);
        int ans = -1;
        for (int i = 0; i < k; i++) {
            int pick1 = -1, pick2 = -1;
            int cap = -1;
            int best_profit = -10000000;
            for (int j = 0; j < n; j++) {
                for (int jj = 0; jj < n; jj++) {
                    if (j == jj) continue;
                    if (seen[j] || seen[jj]) continue;
                    int profit1 = returnInvestment[j] - capital[j];
                    int profit2 = returnInvestment[jj] - capital[jj];
                    if ((capital[j] + capital[jj]) <= w) {
                        if ((profit1 + profit2) > best_profit) {
                            best_profit = profit1 + profit2;
                            cap = capital[j] + capital[jj];
                            pick1 = j;
                            pick2 = jj;
                        } else if ((profit1 + profit2) >= 0 &&
                                   (profit1 + profit2) == best_profit) {
                            if (cap < capital[j] + capital[jj]) {
                                cap = capital[j] + capital[jj];
                                pick1 = j;
                                pick2 = jj;
                            }
                        }
                    }
                }
            }
            if (pick1 == -1) {
                return -1;
            }
            seen[pick1] = true;
            seen[pick2] = true;
            if (ans == -1) ans = 0;
            w += best_profit;
            ans += best_profit;
        }
        if (w <= 0) return -1;
        return ans;
    }
};