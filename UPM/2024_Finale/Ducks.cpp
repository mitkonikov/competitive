#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main() {
    string S;
    vector<string> ans;
    while (true) {
        getline(cin, S);
        if (S == "") break;
        ans.push_back(S);
        if (cin.eof()) break;
    }
    vector<string> pattern = {
        "*....***",
        "..##.***",
        ".###....",
        "...####.",
        "**.###..",
        "**.....*"
    };
    for (int i = 0; i < ans.size(); i++) {
        ans[i] = "." + ans[i] + ".";
    }
    string aux(ans[0].size(), '.');
    ans.push_back(aux);
    ans.insert(ans.begin(), aux);
    int X = pattern.size();
    int Y = pattern[0].size();
    int N = ans.size();
    int M = ans[0].size();
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            bool fail = false;
            for (int x = 0; x < pattern.size() && !fail; x++) {
                for (int y = 0; y < pattern[0].size() && !fail; y++) {
                    if (i + x >= N) {
                        fail = true;
                        break;
                    }
                    if (j + y >= M) {
                        fail = true;
                        break;
                    }
                    if (pattern[x][y] == '*') continue;
                    if (pattern[x][y] != ans[i+x][j+y]) {
                        fail = true;
                        break;
                    }
                }
            }
            if (!fail) count++;
 
            {
                bool fail = false;
                for (int x = 0; x < pattern.size() && !fail; x++) {
                    for (int y = 0; y < pattern[0].size() && !fail; y++) {
                        if (i + x >= N) {
                            fail = true;
                            break;
                        }
                        if (j + y >= M) {
                            fail = true;
                            break;
                        }
                        if (pattern[x][Y-y-1] == '*') continue;
                        if (pattern[x][Y-y-1] != ans[i+x][j+y]) {
                            fail = true;
                            break;
                        }
                    }
                }
                if (!fail) count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}