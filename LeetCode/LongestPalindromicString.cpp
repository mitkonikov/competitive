#include <bits/stdc++.h>
using namespace std;

array<vector<int>, 2> manacher(const string& s) {
	int n = s.size();
	array<vector<int>,2> p = {vector<int>(n+1), vector<int>(n)};
	for (int z = 0; z < 2; z++) {
        for (int i=0,l=0,r=0; i < n; i++) {
            int t = r-i+!z;
            if (i<r) p[z][i] = min(t, p[z][l+t]);
            int L = i-p[z][i], R = i+p[z][i]-!z;
            while (L>=1 && R+1<n && s[L-1] == s[R+1])
                p[z][i]++, L--, R++;
            if (R>r) l=L, r=R;
        }
	}
	return p;
}

class Solution {
public:
    string longestPalindrome(string s) {
        auto solve = manacher(s);
        int longest = 0;
        int longest_z = 0;
        int longest_id = 0;
        for (int z = 0; z < 2; z++) {
            for (int i = 0; i < solve[z].size(); i++) {
                if (longest < solve[z][i] * 2 + z) {
                    longest = solve[z][i] * 2 + z;
                    longest_id = i;
                    longest_z = z;
                }
            }
        }

        if (longest_z == 0) {
            return s.substr(longest_id - solve[longest_z][longest_id], solve[longest_z][longest_id] * 2);
        }

        return s.substr(longest_id - solve[longest_z][longest_id], solve[longest_z][longest_id] * 2 + 1);
    }
};