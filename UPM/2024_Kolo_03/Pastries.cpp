#include "bits/stdc++.h"
#define ll long long
 
using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    
    int p1 = 0, p2 = N - 1;
    int ans = 0;
    ll sum1 = 0, sum2 = 0;
    while (p1 <= p2) {
        if (sum1 == sum2) {
            ans = max(ans, p1 + (N - 1 - p2));
        }
 
        if (sum1 < sum2) {
            sum1 += A[p1];
            p1++;
        } else {
            sum2 += A[p2];
            p2--;
        }
    }
    if (sum1 == sum2) {
        ans = max(ans, p1 + (N - 1 - p2));
    }
    cout << ans << endl;
    return 0;
}