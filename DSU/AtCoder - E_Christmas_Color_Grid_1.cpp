#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct dsu_save {
    int u, v, parent_u, parent_v;
};

struct dsu {
    vector<int> parent;
    vector<dsu_save> saves;
    int comps = 0;

    dsu(int n) {
        parent.resize(n, -1);
        saves.reserve(n);
        comps = n;
    }

    int find_set(int a) {
        if (parent[a] < 0) return a;
        return find_set(parent[a]);
    }

    bool merge(int a, int b, bool save = false) {
        int x = find_set(a), y = find_set(b);
        if (x == y) return false;
        if (-parent[x] < -parent[y]) swap(x, y);
        if (save) saves.push_back({ x, y, parent[x], parent[y] });
        parent[x] += parent[y];
        parent[y] = x;
        comps--;
        return save;
    }

    void rollback() {
        if (saves.empty()) return;
        dsu_save top = saves.back();
        saves.pop_back();
        comps++;
        parent[top.u] = top.parent_u;
        parent[top.v] = top.parent_v;
    }

    bool are_same(int a, int b) {
        return find_set(a) == find_set(b);
    }

    int size(int a) {
        return -parent[find_set(a)];
    }
};

const int mod=998244353;
struct mi {
    int v;
    mi(){v=0;}
    mi(ll _v){v=int(-mod<=_v&&_v<mod?_v:_v%mod); if(v<0)v+=mod;}
    explicit operator int()const{return v;}
    friend bool operator==(const mi &a,const mi &b){return (a.v==b.v);}
    friend bool operator!=(const mi &a,const mi &b){return (a.v!=b.v);}
    friend bool operator<(const mi &a,const mi &b){return (a.v<b.v);}
    mi& operator+=(const mi &m){if((v+=m.v)>=mod)v-=mod; return *this;}
    mi& operator-=(const mi &m){if((v-=m.v)<0)v+=mod; return *this;}
    mi& operator*=(const mi &m){v=((ll)(v)*m.v)%mod; return *this;}
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

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    auto valid = [&](int x, int y) {
        return (x >= 0 && x < N && y >= 0 && y < M);
    };
    dsu dsu(N * M);
    auto coord = [&](int x, int y) {
        return (x * M + y);
    };
    mi red_count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == '#') {
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (valid(nx, ny) && A[nx][ny] == '#') {
                        dsu.merge(coord(i, j), coord(nx, ny));
                    }
                }
            } else {
                red_count++;
            }
        }
    }
    mi ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == '.') {
                // try to connect it
                int roll = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (valid(nx, ny) && A[nx][ny] == '#') {
                        roll += dsu.merge(coord(i, j), coord(nx, ny), true);
                    }
                }

                ans += mi(dsu.comps - red_count + 1) / red_count;

                for (int r = 0; r < roll; r++) dsu.rollback();
            }
        }
    }
    cout << ans << endl;
    return 0;
}