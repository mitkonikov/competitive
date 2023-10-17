#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int counter = 1;
vector<int> ladj, radj;
vector<int> chr;
 
int max_depth = 0;
char root = ' ';
 
int rec(string S, int depth = 0) {
    if (S.empty()) { return -1; }
    if (S == "0") { return -1; }
    max_depth = max(max_depth, depth);
    int bal = 0;
    int N = S.size();
    int my_id = counter;
    counter++;
    for (int i = 0; i < N; i++) {
        if (S[i] == '(') bal++;
        else if (S[i] == ')') bal--;
        if (bal == 0 && S[i] >= 'A' && S[i] <= 'Z') {
            chr[my_id] = S[i];
            if (depth == 0) root = my_id;
            i++;
            continue;
        }
        if (bal == 0 && S[i] == ',') {
            int s1 = i - 4;
            int s2 = N - i - 3;
            if (S[i-1] == '0') {
                rec("0", depth + 1);
            }
            else {
                auto lid = rec(S.substr(3, s1), depth + 1);
                ladj[my_id] = lid;
            }
            if (S[i+1] == '0') {
                rec("0", depth + 1);
            }
            else {
                auto rid = rec(S.substr(i + 2, s2), depth + 1);
                radj[my_id] = rid;
            }
        }
    }
    return my_id;
}
 
int power(int a, int e) {
    int res = 1;
    for (int i = 0; i < e; i++) res *= a;
    return res;
}
 
int main() {
    string S;
    cin >> S;
    ladj.resize(50000, -1);
    radj.resize(50000, -1);
    chr.resize(50000);
    
    S = S.substr(1, S.size() - 2);
    rec(S);
 
    vector<string> ans(max_depth * 2 + 10, string(power(2, max_depth + 2), ' '));
    
    struct BFS {
        int t;
        int depth;
        int off;
        int x;
    };
    queue<BFS> bfs;
    bfs.push({ root, 0, power(2, max_depth), power(2, max_depth + 1) });
    while (!bfs.empty()) {
        auto S = bfs.front();
        bfs.pop();
 
        auto lc = ladj[S.t];
        auto rc = radj[S.t];
        bool l = (lc != -1);
        bool r = (rc != -1);
        
        int mn = (l ? S.x - S.off : S.x);
        int mx = (r ? S.x + S.off : S.x);
        for (int i = mn; i <= mx; i++) {
            ans[2 * S.depth][i] = '-';
        }
 
        ans[2 * S.depth][S.x] = chr[S.t];
        for (auto el: { 1, 2 }) {
            if (2 * S.depth - el >= 0) {
                ans[2 * S.depth - el][S.x] = '|';
            }
        }
        
        int off = S.off / 2;
        if (l) {
            bfs.push({ lc, S.depth + 1, off, S.x - S.off });
        }
        if (r) {
            bfs.push({ rc, S.depth + 1, off, S.x + S.off });
        }
    }
 
    for (int i = 0; i < max_depth * 2 + 1; i++) {
        cout << ans[i] << endl;
    }
 
    return 0;
}