#include <bits/stdc++.h>
#define s first
#define ll long long

using namespace std;

string conc(vector<string>& ans) {
    string res = "";
    for (int i = 0; i < ans.size(); i++) {
        res += ans[i] + "\n";
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int b;
    cin >> b;

    vector<vector<pair<int, string>>> v(5);
    for (int i = 0; i < 5; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            string name;
            cin >> name;
            int cost;
            cin >> cost;
            v[i].push_back({ cost, name });
        }
    }

    for (int i = 0; i < 5; i++)
        sort(v[i].begin(), v[i].end());

    for (int i = 0; i < 5; i++) {
        vector<pair<int, string>> new_v;
        new_v.push_back(v[i][0]);
        for (int j = 1; j < v[i].size(); j++) {
            if (v[i][j-1].first == v[i][j].first) {
                continue;
            }
            new_v.push_back(v[i][j]);
        }
        v[i] = new_v;
    }

    vector<string> possible;
    vector<string> ans(5);
    ll best = INT_MAX;
    for (int p1 = 0; p1 < v[4].size(); p1++) {
        for (int p2 = 0; p2 < v[3].size(); p2++) {
            for (int p3 = 0; p3 < v[2].size(); p3++) {
                for (int p4 = 0; p4 < v[1].size(); p4++) {
                    ll sum = (ll)v[1][p4].s + v[2][p3].s + v[3][p2].s + v[4][p1].s;       
                    if (sum > b) continue;

                    int L = 0, R = v[0].size();
                    while (R - L > 1) {
                        int mid = (R + L) / 2;
                        if (v[0][mid].first > b - sum) {
                            R = mid;
                        } else {
                            L = mid;
                        }
                    }

                    sum += v[0][L].first;
                    if (sum <= b && b - sum <= best) {
                        if (b - sum != best) {
                            possible.clear();
                        }
                        
                        best = b - sum;
                        ans = {
                        v[0][L].second,
                        v[1][p4].second,
                        v[2][p3].second,
                        v[3][p2].second,
                        v[4][p1].second };
                        possible.push_back(conc(ans));
                    }
                }
            }
        }
    }

    sort(possible.begin(), possible.end());
    cout << possible[0] << endl;
    return 0;
}