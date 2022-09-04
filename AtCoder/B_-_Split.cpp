#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string s;
    cin >> s;
    bool ok = false;
    
    vector<vector<int>> col = { {7}, {4}, {2, 8}, {5}, {3, 9}, {6}, {10} };
    int n = col.size();
    for (int i = 0; i < n-2 && !ok; i++) {
        for (int ii = i + 2; ii < n && !ok; ii++) {
            bool okk1 = false;
            for (int j = 0; j < col[i].size(); j++) {
                if (s[col[i][j]-1] == '1') {
                    okk1 = true;
                }
            }
            bool okk2 = false;
            for (int j = 0; j < col[ii].size(); j++) {
                if (s[col[ii][j]-1] == '1') {
                    okk2 = true;
                }
            }
            if (okk1 && okk2) {
                for (int iii = i + 1; iii < ii; iii++) {
                    bool okk = true;
                    for (int j = 0; j < col[iii].size(); j++) {
                        if (s[col[iii][j]-1] == '1') {
                            okk = false;
                        }
                    }
                    if (okk) {
                        ok = true;
                        break;
                    }
                }
            }
        }
    }

    cout << ((ok & (s[0] == '0')) ? "Yes" : "No") << endl;

    cout << flush;
    return 0;
}