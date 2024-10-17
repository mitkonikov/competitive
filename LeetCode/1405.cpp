#include <bits/stdc++.h>
using namespace std;

inline bool same(int a, int b, int c) {
    return (a == b && b == c);
}

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        const int MX = 110;
        vector<vector<vector<vector<vector<int>>>>> dp(3, 
                vector<vector<vector<vector<int>>>>(3, 
                        vector<vector<vector<int>>>(MX,
                                vector<vector<int>>(MX,
                                    vector<int>(MX, 0)))));

        for (int ll = 0; ll < 3; ll++) {
            for (int l = 0; l < 3; l++) {
                dp[ll][l][0][0][0] = 4;
            }
        }

        int longest = 0, na = 0, nb = 0, nc = 0;
        for (int A = 0; A <= a; A++) {
            for (int B = 0; B <= b; B++) {
                for (int C = 0; C <= c; C++) {
                    for (int ll = 0; ll < 3; ll++) {
                        for (int l = 0; l < 3; l++) {
                            if (dp[ll][l][A][B][C]) {
                                // add A
                                if (!same(ll, l, 0)) {
                                    dp[l][0][A+1][B][C] = 1;
                                }
                                
                                // add B
                                if (!same(ll, l, 1)) {
                                    dp[l][1][A][B+1][C] = 2;
                                }

                                // add C
                                if (!same(ll, l, 2)) {
                                    dp[l][2][A][B][C+1] = 3;
                                }

                                if (A + B + C > longest) {
                                    longest = A + B + C;
                                    na = A;
                                    nb = B;
                                    nc = C;
                                }
                            }
                        }
                    }
                }
            }
        }

        a = na;
        b = nb;
        c = nc; 

        for (int ll = 0; ll < 3; ll++) {
            for (int l = 0; l < 3; l++) {
                if (dp[ll][l][a][b][c]) {
                    string ans = "";

                    int LL = ll, L = l, A = a, B = b, C = c;
                    for (int i = 0; i < a + b + c; i++) {
                        if (dp[LL][L][A][B][C] == 1) {
                            int iLL = LL;
                            for (int nll = 0; nll < 3; nll++) {
                                if (!same(nll, LL, L) && dp[nll][LL][A-1][B][C]) {
                                    LL = nll;
                                    break;
                                }
                            }

                            L = iLL;
                            ans.push_back('a');
                            A--;
                        } else if (dp[LL][L][A][B][C] == 2) {
                            int iLL = LL;
                            for (int nll = 0; nll < 3; nll++) {
                                if (!same(nll, LL, L) && dp[nll][LL][A][B-1][C]) {
                                    LL = nll;
                                    break;
                                }
                            }

                            L = iLL;
                            ans.push_back('b');
                            B--;
                        } else if (dp[LL][L][A][B][C] == 3) {
                            int iLL = LL;
                            for (int nll = 0; nll < 3; nll++) {
                                if (!same(nll, LL, L) && dp[nll][LL][A][B][C-1]) {
                                    LL = nll;
                                    break;
                                }
                            }

                            ans.push_back('c');
                            L = iLL;
                            C--;
                        }
                    }

                    reverse(ans.begin(), ans.end());
                    return ans;
                }
            }
        }

        return "";
    }
};