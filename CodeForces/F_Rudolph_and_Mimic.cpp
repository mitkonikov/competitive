#include <bits/stdc++.h>
#define ll long long

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> frq(10);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        frq[A[i]]++;
    }
    vector<int> new_A(N);
    vector<int> new_frq(10);
    cout << "- 0" << endl;
    for (int i = 0; i < N; i++) {
        cin >> new_A[i];
        new_frq[new_A[i]]++;
    }
    int mimic = -1;
    for (int i = 0; i < 10; i++) {
        if (frq[i] < new_frq[i]) {
            mimic = i;
            swap(new_A, A);
            swap(new_frq, frq);
            break;
        }
    }
    if (mimic == -1) {
        vector<int> new_A(N);
        vector<int> new_frq(10);
        cout << "- 0" << endl;
        for (int i = 0; i < N; i++) {
            cin >> new_A[i];
            new_frq[new_A[i]]++;
        }
        for (int i = 0; i < 10; i++) {
            if (frq[i] < new_frq[i]) {
                mimic = i;
                swap(new_A, A);
                swap(new_frq, frq);
                break;
            }
        }
    }
    assert(mimic != -1);
    cout << "- ";
    vector<int> remove;
    for (int i = 0; i < N; i++) {
        if (A[i] != mimic) {
            remove.push_back(i + 1);
        }
    }
    cout << remove.size() << " ";
    for (auto el: remove) cout << el << " ";
    cout << endl;

    for (int r = 0; r < 4; r++) {
        vector<int> new_A(N);
        vector<int> new_frq(10);
        for (int i = 0; i < N - remove.size(); i++) {
            cin >> new_A[i];
            new_frq[new_A[i]]++;
        }
        for (int i = 0; i < N - remove.size(); i++) {
            if (new_A[i] != mimic) {
                cout << "! " << i + 1 << endl;
                return;
            }
        }
        cout << "- 0" << endl;
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