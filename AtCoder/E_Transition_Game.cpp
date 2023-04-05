#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    vector<int> comp(N, 0);
    vector<bool> ans(N);
    int id = 1;
    for (int i = 0; i < N; i++) {
        if (comp[i]) continue;
        int here = i;
        bool cycle = false;
        vector<int> current({ i });
        int start = -1;
        while (true) {
            if (comp[here]) {
                if (comp[here] == id) {
                    cycle = true;
                    start = here;
                }
                break;
            }
            comp[here] = id;
            here = A[here];
            current.push_back(here);
        }
        id++;
        if (cycle) {
            bool s = false;
            for (auto el: current) {
                if (el == start) s = true;
                if (s) ans[el] = 1;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        count += ans[i];
    }
    cout << count << endl;
    return 0;
}