#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int mod=998244353;
const int primitive_root=3;
 
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
 
void ntt(vector<mi> &a)
{
    int n=a.size(),L=31-__builtin_clz(n);
    vector<int> rev(n);
    for(int i=0;i<n;i++) rev[i]=(rev[i/2]+((i&1)<<L))/2;
    for(int i=0;i<n;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
    static vector<mi> rt(2,1);
    for(static int k=2,s=2;k<n;k*=2,s++)
    {
        rt.resize(n);
        mi z=pow(mi(primitive_root),mod>>s);
        for(int i=k;i<2*k;i++) rt[i]=rt[i/2]*((i&1)?z:1);
    }
    for(int k=1;k<n;k*=2)
    {
        for(int i=0;i<n;i+=2*k)
        {
            for(int j=0;j<k;j++)
            {
                mi z=rt[j+k]*a[i+j+k];
                a[i+j+k]=a[i+j]-z;
                a[i+j]+=z;
            }
        }
    }
}
 
vector<mi> conv(vector<mi> &a,vector<mi> &b)
{
    int sa=a.size(),sb=b.size();
    if(sa==0||sb==0) return {};
    int n=1<<(32-__builtin_clz(sa+sb-2));
    mi inv=1/mi(n);
    vector<mi> f(a),g(b),h(n);
    f.resize(n); g.resize(n);
    ntt(f); ntt(g);
    for(int i=0;i<n;i++) h[(-i)&(n-1)]=(f[i]*g[i]*inv);
    ntt(h);
    h.resize(sa+sb-1);
    return h;
}
 
vector<mi> multipoly(vector<vector<mi>> v)
{
    auto cmp=[&](const vector<mi> &a,const vector<mi> &b){return (a.size()>b.size());};
    priority_queue<vector<mi>,vector<vector<mi>>,decltype(cmp)> q(cmp);
    for(auto &u:v) q.push(u);
    while(q.size()>=2)
    {
        auto a=q.top();
        q.pop();
        auto b=q.top();
        q.pop();
        q.push(conv(a,b));
    }
    return q.top();
}

template<typename T>
struct poly {
    vector<T> v;
    void add(vector<T> other) {
        for (int i = 0; i < min(other.size(), v.size()); i++) {
            v[i] += other[i];
        }
    }
    void addMax(vector<T> other) {
        if (v.size() < other.size()) v.resize(other.size());
        add(other);
    }
    static poly identity() {
        return { { 1 } };
    }
};

#define MX vector<vector<poly<T>>>
// it's matrix of polynomials

template<typename T>
class Matrix { // Only for NxN matrix
public:
    MX m;
    int n;
    Matrix(int n) {
        this->n = n;
        m.resize(n, vector<poly<T>>(n));
    }

    Matrix(const MX &copy) {
        this->m = MX(copy);
        this->n = copy.size();
    }

    Matrix<T> operator*(Matrix<T> &b) {
        Matrix<T> result(n);
        result.m[0][0].addMax(conv(this->m[0][0].v, b.m[0][0].v));
        result.m[0][0].addMax(conv(this->m[0][1].v, b.m[0][1].v));
        result.m[0][1].addMax(conv(this->m[0][1].v, b.m[0][0].v));
        result.m[0][1].addMax(conv(this->m[0][0].v, b.m[0][1].v));
        return result;
    }

    void symMult(Matrix<T> &b) {
        Matrix<T> result(n);
        result.m[0][0].addMax(conv(this->m[0][0].v, b.m[0][0].v));
        result.m[0][0].addMax(conv(this->m[0][1].v, b.m[0][1].v));
        result.m[0][1].addMax(conv(this->m[0][1].v, b.m[0][0].v));
        result.m[0][1].addMax(conv(this->m[0][0].v, b.m[0][1].v));
        m = result.m;
    }

    void square() {
        Matrix<T> result(n);
        #define A m[0][0]
        #define B m[0][1]
        result.m[0][0].addMax(conv(A.v, A.v));
        result.m[0][0].addMax(conv(B.v, B.v));
        result.m[0][1].v = conv(A.v, B.v);
        for (auto &el: result.m[0][1].v) {
            el *= 2;
        }
        m = result.m;
    }

    Matrix<T> binary(long long power) const {
        Matrix<T> a(this->m);
        Matrix<T> result(n);
        for (int i = 0; i < n; i++) result.m[i][i] = poly<T>::identity();

        while (power > 0) {
            if (power % 2 == 1) {
                result.symMult(a);
                power--;
            }

            power /= 2;
            if (power == 0) break;
            a.square();
        }

        return result;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> frq(10, 0);
    for (int i = 1; i <= n; i++) {
        int c;
        scanf("%d", &c);
        c--;
        frq[c]++;
    }

    vector<Matrix<mi>> matrices(10, Matrix<mi>(2));

    for (int i = 0; i < 10; i++) {
        if (frq[i] == 0) continue;
        poly<mi> p;
        p.v = vector<mi>(11);
        p.v[i+1] = 1;
        matrices[i].m[0][0] = poly<mi>::identity();
        matrices[i].m[0][1] = p;
        matrices[i] = matrices[i].binary(frq[i]);
    }

    for (int i = 1; i < matrices.size(); i++) {
        if (frq[i] == 0) continue;
        matrices[0] = matrices[0] * matrices[i];
    }

    auto& q = matrices[0].m[0][1].v;
    if (m >= q.size()) {
        cout << 0 << endl;
    } else {
        cout << q[m] << endl;
    }

    return 0;
}