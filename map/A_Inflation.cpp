#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    map<ll, int> frq;
    map<ll, int> not_in;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        frq[x]++;
        sum += x;
    }
    
    int Q;
    cin >> Q;
    ll inflation = 0;
    for (int i = 0; i < Q; i++) {
        string S;
        cin >> S;
        if (S == "INFLATION") {
            ll X;
            cin >> X;
            inflation += X;
            sum += N * X;
            for (auto& [v, f]: not_in) {
                frq[v + X - inflation] += f;
            }
            not_in.clear();
        } else if (S == "SET") {
            ll X, Y;
            cin >> X >> Y;

            auto it = not_in.find(X);
            if (it != not_in.end()) {
                sum -= it->second * X;
                sum += it->second * Y;
                ll value = it->second;
                not_in.erase(it);
                not_in[Y] += value;
            }
            
            X -= inflation;

            sum -= frq[X] * (X + inflation);
            sum += frq[X] * Y;
            
            not_in[Y] += frq[X];
            frq[X] = 0;
        }
        cout << sum << endl;
    }
    return 0;
}