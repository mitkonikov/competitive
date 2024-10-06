#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) cin >> nums[i];

    vector<int> order(N);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&nums](int a, int b) {
        string A = to_string(nums[a]);
        string B = to_string(nums[b]);
        string AB = A + B;
        string BA = B + A;
        for (int i = 0; i < AB.size(); i++) {
            if (AB[i] < BA[i]) return false;
            if (AB[i] > BA[i]) return true;
        }
        return a < b;
    });
    
    string ans = "";
    for (int i = 0; i < order.size(); i++) {
        ans += to_string(nums[order[i]]);
    }

    reverse(ans.begin(), ans.end());
    while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());

    cout << ans << endl;
    return 0;
}