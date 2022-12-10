#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const int mod=45678;
struct mi
{
    int v;
    mi(){v=0;}
    mi(ll _v){v=int(-mod<=_v&&_v<mod?_v:_v%mod); if(v<0)v+=mod;}
    explicit operator int()const{return v;}
    friend bool operator==(const mi &a,const mi &b){return (a.v==b.v);}
    friend bool operator!=(const mi &a,const mi &b){return (a.v!=b.v);}
    friend bool operator<(const mi &a,const mi &b){return (a.v<b.v);}
    mi& operator+=(const mi &m){if((v+=m.v)>=mod)v-=mod; return *this;}
    mi& operator-=(const mi &m){if((v-=m.v)<0)v+=mod; return *this;}
    mi& operator*=(const mi &m){v=(ll(v)*m.v)%mod; return *this;}
    mi& operator/=(const mi &m){return (*this)*=inv(m);}
    friend mi pow(mi a,ll e){mi r=1; for(;e;a*=a,e/=2)if(e&1)r*=a; return r;}
    friend mi inv(mi a){return pow(a,mod-2);}
    mi operator-()const{return mi(-v);}
    mi& operator++(){return (*this)+=1;}
    mi& operator--(){return (*this)-=1;}
    friend mi operator++(mi &a,int){mi t=a; ++a; return t;}
    friend mi operator--(mi &a,int){mi t=a; --a; return t;}
    friend mi operator+(mi a,const mi &b){return a+=b;}
    friend mi operator-(mi a,const mi &b){return a-=b;}
    friend mi operator*(mi a,const mi &b){return a*=b;}
    friend mi operator/(mi a,const mi &b){return a/=b;}
    friend istream& operator>>(istream &is,mi &m){ll _v; is >> _v; m=mi(_v); return is;}
    friend ostream& operator<<(ostream &os,const mi &m){os << m.v; return os;}
};

struct Node {
    mi pref = 0;
    mi sum = 0;
    mi suff = 0;
    bool is_defined = false;
    bool is_duplicated = false;
    Node operator*(const Node &other) {
        if (!is_defined) return other;
        if (!other.is_defined) return *this;

        if (is_duplicated && other.is_duplicated) {
            return { suff * other.pref, 0, suff * other.pref, 1, 1 };
        } else if (is_duplicated) {
            return { suff * other.pref, other.sum, other.suff, 1 };
        } else if (other.is_duplicated) {
            return { pref, sum, suff * other.pref, 1 };
        }
        return { pref, sum + suff * other.pref + other.sum, other.suff, 1 };
    }
    Node operator+(const Node &other) {
        if (!is_defined) return other;
        if (!other.is_defined) return *this;
        
        if (is_duplicated && other.is_duplicated) {
            return { suff, 0, other.pref, 1 };
        } else if (is_duplicated) {
            return { suff, other.pref + other.sum, other.suff, 1 };
        } else if (other.is_duplicated) {
            return { pref, sum + suff, other.pref, 1 };
        }
        return { pref, sum + suff + other.pref + other.sum, other.suff, 1 };
    }
    void set(ll value) {
        pref = suff = value;
        is_duplicated = true;
        is_defined = true;
    }
};

struct SegmentTree {
    vector<char> sign;

    const static int pw = 1 << 19;
    int N = pw;

    vector<Node> seg;
    SegmentTree(int N, vector<char> signs) {
        this->N = N; seg.resize(2 * pw);
        this->sign = signs;
    }

    void build(vector<ll>& v, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) { seg[ind].set(v[l]); return; }
        int m = (l + r) / 2;
        build(v, ind * 2 + 1, l, m);
        build(v, ind * 2 + 2, m, r);
        if (sign[m-1] == '+') seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
        if (sign[m-1] == '*') seg[ind] = seg[ind * 2 + 1] * seg[ind * 2 + 2];
    }
    
    // result in [b,e) of node that covers [l,r)
    Node askLR(int b, int e, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (l>=e || r<=b) return { 0, 0, 0, false, true };
        if (l>=b && r<=e) return seg[ind];
        int m = (l + r) / 2;
        if (sign[m-1] == '+') return askLR(b, e, ind * 2 + 1, l, m) + askLR(b, e, ind * 2 + 2, m, r);
        if (sign[m-1] == '*') return askLR(b, e, ind * 2 + 1, l, m) * askLR(b, e, ind * 2 + 2, m, r);
        return {};
    }
};

void testCase() {
    int N;
    cin >> N;
    vector<ll> a(N);
    vector<char> signs(N-1);
    for (int i = 0; i < 2 * N - 1; i++) {
        if (i % 2 == 0) {
            cin >> a[i/2];
        } else {
            cin >> signs[i/2];
        }
    }
    SegmentTree seg(N, signs);
    seg.build(a);
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int L, R;
        cin >> L >> R;
        L--; R--;
        auto node = seg.askLR(L, R + 1);
        if (node.is_duplicated) {
            cout << node.pref + node.sum << endl;
        } else {
            cout << node.pref + node.sum + node.suff << endl;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        testCase();
    }
    return 0;
}