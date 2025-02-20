#include <bits/stdc++.h>
#define ll long long
using namespace std;

class ProductOfNumbers {
public:
    vector<ll> pref;
    int last_zero = -1;

    ProductOfNumbers() {
        pref = { 1 };
    }
    
    void add(int num) {
        if (num == 0) {
            last_zero = 0;
            pref.push_back(1);
        } else {
            if (last_zero != -1) last_zero++;
            pref.push_back(pref.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (last_zero != -1 && k >= last_zero + 1) return 0;
        return pref.back() / pref[pref.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */