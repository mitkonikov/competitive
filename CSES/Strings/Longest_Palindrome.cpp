#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

#define vi vector<int>
#define rep(i,s,e) for (int i = (s); i < (e); i++)
#define sz(a) ((int)a.size())

array<vi, 2> manacher(const string& s) {
	int n = sz(s);
	array<vi,2> p = {vi(n+1), vi(n)};
	rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
		int t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		int L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
	return p;
}

int main() {
    string S;
    cin >> S;
    auto M = manacher(S);
    int longest = 0;
    int start = -1;
    for (int r = 0; r < 2; r++) {
        for (int i = 0; i < M[r].size(); i++) {
            int size = M[r][i] * 2 + r;
            if (size > longest) {
                longest = size;
                start = i - M[r][i];
            }
        }
    }
    cout << S.substr(start, longest) << endl;
    return 0;
}