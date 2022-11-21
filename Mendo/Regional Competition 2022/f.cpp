#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
  
using namespace std;
  
struct FenwickTree {
    vector<int> fwt;
  
    FenwickTree(int n) {
        fwt.resize(n, 0);
    }
  
    void maxFWT(int ind, int val = 1) {
        for (ind++; ind < fwt.size(); ind+=ind&-ind)
            fwt[ind] = max(fwt[ind], val);
    }
  
    int getFWT(int ind) {
        int s = 0;
        for (ind++; ind > 0; ind-=ind&-ind)
            s = max(s, fwt[ind]);
        return s;
    }
  
    void reset() {
        fill(fwt.begin(), fwt.end(), 0);
    }
};
 
int main() {
    const int MXN = 510;
    int n, mxK;
    cin >> n >> mxK;
      
    vector<int> v(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
      
    auto update = [](FenwickTree &fwt, int element) {
        int mx = fwt.getFWT(element);
        fwt.maxFWT(element, mx + 1);
        return mx + 1;
    };
  
    // precomp
    FenwickTree fwt_init(MXN);
    vector<FenwickTree> dp_up(n, FenwickTree(MXN));
    for (int i = 0; i < n; i++) {
        update(fwt_init, v[i]);
        copy(fwt_init.fwt.begin(), fwt_init.fwt.end(), dp_up[i].fwt.begin());
    }
 
    fwt_init.reset();
    vector<FenwickTree> dp_down(n, FenwickTree(MXN));
    for (int i = n-1; i >= 0; i--) {
        update(fwt_init, mxK - v[i]);
        copy(fwt_init.fwt.begin(), fwt_init.fwt.end(), dp_down[i].fwt.begin());
    }
     
    int ans = 1;
    for (int i = n - 1; i >= 0; i--) {
        vector<int> tail;
        for (int j = i; j >= 0; j--) {
            if (v[j] < v[i]) continue;
            auto b = tail.begin(), e = tail.end();
            auto it = lower_bound(b, e, v[j]);
     
            if (it == tail.end()) tail.push_back(v[j]);
            else {
                while (it != tail.end() && *it == v[j]) {
                    it++;
                }
 
                if (it == tail.end()) tail.push_back(v[j]);
                else *it = v[j];
            }
 
            int left = (j - 1 >= 0) ? dp_up[j - 1].getFWT(v[i]) : 0;
 
            for (int l = 0; l < tail.size(); l++) {            
                int right = (i + 1 < n) ? dp_down[i + 1].getFWT(mxK - tail[l]) : 0;
                ans = max(ans, left + l + 1 + right);
            }
        }
    }
  
    cout << ans << endl;
    return 0;
}