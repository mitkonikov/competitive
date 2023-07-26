#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<pair<int, int>> even, odd;
    vector<int> evenId, oddId;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] % 2 == 0) {
            even.push_back({ A[i], i });
            evenId.push_back(i);
        } else {
            odd.push_back({ A[i], i });
            oddId.push_back(i);
        }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    for (int i = 0; i < even.size(); i++) {
        A[evenId[i]] = even[i].first;
    }
    for (int i = 0; i < odd.size(); i++) {
        A[oddId[i]] = odd[i].first;
    }
    
    cout << (is_sorted(A.begin(), A.end()) ? "YES" : "NO") << endl;
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