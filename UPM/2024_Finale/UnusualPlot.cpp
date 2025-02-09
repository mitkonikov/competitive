#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
template<typename T>
T gcd(T a, T b) {
    return (a == 0) ? b : gcd(b % a, a);
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    vector<array<int, 2>> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i][0] >> points[i][1];
    }
    vector<array<int, 2>> new_points;
    for (int i = 0; i < N; i++) {
        int a = points[i][0];
        int b = points[i][1];
        int c = points[(i+1)%N][0];
        int d = points[(i+1)%N][1];
 
        int da = (c - a);
        int db = (d - b);
        
        int g = gcd(abs(da), abs(db));
        
        if (g == 1) continue;
 
        int a_first = da / g;
        int b_first = db / g;
        int a_last = da - da / g;
        int b_last = db - db / g;
 
        a_first += a;
        b_first += b;
        a_last += a;
        b_last += b;
 
        if (a_first == a_last && b_first == b_last) {
            new_points.push_back({ a_first, b_first });
        } else {
            new_points.push_back({ a_first, b_first });
            new_points.push_back({ a_last, b_last });
        }
    }
 
    int M = new_points.size();
    if (M <= 2) {
        cout << 0 << endl;
        return 0;
    }
 
    ll ans = 0;
    for (int i = 0; i < M; i++) {
        ll a = new_points[i][0];
        ll b = new_points[i][1];
        ll c = new_points[(i+1)%M][0];
        ll d = new_points[(i+1)%M][1];
        
        ans += a * d - b * c;
    }
 
    if (ans % 2 == 0) {
        cout << ans / 2 << endl;
    } else {
        cout << ans << "/2" << endl;
    }
 
    return 0;
}