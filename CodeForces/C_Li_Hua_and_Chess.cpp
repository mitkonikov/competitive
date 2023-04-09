#include <bits/stdc++.h>
#define ll long long

using namespace std;

void testCase() {
    int N, M;
    cin >> N >> M;
    cout << "? 1 1" << endl;
    int ans;
    cin >> ans;
    if (ans < N && ans < M) {
        cout << "? " << ans + 1 << " " << 1 << endl;
        int new_ansN;
        cin >> new_ansN;
        cout << "? " << 1 << " " << ans + 1 << endl;
        int new_ansM;
        cin >> new_ansM;
        if (new_ansN < new_ansM) {
            cout << "! " << ans + 1 << " " << new_ansN + 1 << endl;
        } else {
            cout << "! " << new_ansM + 1 << " " << ans + 1 << endl;
        }
        return;
    }

    if (ans < N) {
        cout << "? " << ans + 1 << " " << 1 << endl;
        int new_ans;
        cin >> new_ans;
        if (new_ans <= ans) {
            cout << "! " << ans + 1 << " " << new_ans + 1 << endl;
        } else {
            cout << "? " << 1 << " " << ans + 1 << endl;
            int new_ans2;
            cin >> new_ans2;
            cout << "! " << new_ans2 + 1 << " " << ans + 1 << endl;
        }
        return;
    } else {
        cout << "? " << 1 << " " << ans + 1 << endl;
        int new_ans;
        cin >> new_ans;
        if (new_ans <= ans) {
            cout << "! " << new_ans + 1 << " " << ans + 1 << endl;
        } else {
            cout << "? " << ans + 1 << " " << 1 << endl;
            int new_ans2;
            cin >> new_ans2;
            cout << "! " << ans + 1 << " " << new_ans2 + 1 << endl;
        }
        return;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}