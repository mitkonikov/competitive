#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    vector<int> A(9);
    for (int i = 0; i < 9; i++) cin >> A[i];
    vector<int> order(9);
    iota(order.begin(), order.end(), 0);
    int count = 0;
    int all = 0;
    do {
        vector<int> time(10);
        for (int i = 0; i < 9; i++) {
            time[order[i]] = i;
        }
        bool dis = 0;
        for (int i = 0; i < 3 && !dis; i++) {
            vector<pair<int, int>> ts;            
            for (int j = 0; j < 3; j++) {
                ts.push_back({ time[i * 3 + j], A[i * 3 + j] });
            }
            sort(ts.begin(), ts.end());
            if (ts[0].second == ts[1].second && ts[0].second != ts[2].second) dis = 1;
        }
        for (int i = 0; i < 3 && !dis; i++) {
            vector<pair<int, int>> ts;            
            for (int j = 0; j < 3; j++) {
                ts.push_back({ time[j * 3 + i], A[j * 3 + i] });
            }
            sort(ts.begin(), ts.end());
            if (ts[0].second == ts[1].second && ts[0].second != ts[2].second) dis = 1;
        }
        {
            vector<pair<int, int>> ts;            
            for (int j = 0; j < 3; j++) {
                ts.push_back({ time[j * 3 + j], A[j * 3 + j] });
            }
            sort(ts.begin(), ts.end());
            if (ts[0].second == ts[1].second && ts[0].second != ts[2].second) dis = 1;
        }
        {
            vector<pair<int, int>> ts;            
            for (int j = 0; j < 3; j++) {
                ts.push_back({ time[j * 3 + 2 - j], A[j * 3 + 2 - j] });
            }
            sort(ts.begin(), ts.end());
            if (ts[0].second == ts[1].second && ts[0].second != ts[2].second) dis = 1;
        }
        if (!dis) {
            count++;
        }
        all++;
    } while (next_permutation(order.begin(), order.end()));
    cout << fixed << setprecision(16) << (double)count / all << endl;
    return 0;
}