#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, R;
    cin >> N >> R;

    vector<vector<int>> ans(R, vector<int>{ 0, 0, 0 });
    for (int i = 0; i < N; i++) {
        int members;
        int room;
        cin >> members >> room;
        room--;
        string t;
        getline(cin, t);

        for (int m = 0; m < members; m++) {
            cin >> t;
            
            if (t == "veganski") ans[room][1]++;
            else if (t == "sirov") ans[room][0]++;
            else ans[room][2]++;
            
            getline(cin, t);
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < 3; j++) {
            cout << ans[i][j] << " ";
        } cout << endl;
    }

    return 0;
}