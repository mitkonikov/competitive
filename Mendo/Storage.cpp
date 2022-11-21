// Task: https://mendo.mk/Task.do?id=35

#include <bits/stdc++.h>

using namespace std;

vector<int> boxes;
int n;
bool must[8][8];

int best_cost = INT_MAX;
vector<int> arr, best_arr;

void backtrack(int set, int current, int cost) {
    int height_till = __builtin_popcount(set);

    if (height_till == n && best_cost > cost) {
        best_cost = cost;
        best_arr = arr;
        return;
    }
    
    bool failed = false;
    for (int k = 0; k < 8; k++) {
        if ((set & (1 << k)) == 0 && must[current][k]) {
            failed = true;
            break;
        }
    }

    if (failed) return;

    arr.push_back(current);
    set ^= (1 << current);
    cost += height_till * boxes[current];

    for (int i = 0; i < n; i++) {
        if (set & (1 << i)) continue;

        bool failed = false;
        for (int k = 0; k < 8; k++) {
            // cout << "must[" << i << "][" << k << "] = " << must[i][k] << " " << (int)(set & (1 << k)) << endl;
            if ((set & (1 << k)) == 0 && must[i][k]) {
                failed = true;
                break;
            }
        }

        if (!failed) {
            backtrack(set | (1 << current), i, cost);
        }
    }

    if (height_till + 1 == n && best_cost > cost) {
        best_cost = cost;
        best_arr = arr;
        set ^= (1 << current);
        arr.pop_back();
        return;
    }

    set ^= (1 << current);
    arr.pop_back();
}

int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            must[i][j] = false;
        }
    }
    
    cin >> n;

    boxes.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> boxes[i];
    }

    int D;
    cin >> D;

    for (int i = 0; i < D; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        must[a][b] = true;
    }

    for (int i = 0; i < n; i++) {
        backtrack(0, i, 0);
    }

    for (int i = 0; i < (int)best_arr.size(); i++) {
        cout << best_arr[i] + 1 << " ";
    }

    cout << endl;
    
    return 0;
}