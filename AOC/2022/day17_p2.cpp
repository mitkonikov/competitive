#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll buffer = 100;
const ll rounds = 1000000000000;

const int mod = buffer;
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

int main() {
    string s;
    cin >> s;
    vector<vector<char>> mat(buffer, vector<char>(7, '.'));
    for (int i = 0; i < 7; i++) {
        mat[buffer-1][i] = '#';
    }
    mi floor = buffer-1;
    vector<vector<string>> rocks(5);
    rocks[0] = { "####" };
    rocks[1] = { ".#.", "###", ".#." };
    rocks[2] = { "..#", "..#", "###" };
    rocks[3] = { "#", "#", "#", "#" };
    rocks[4] = { "##", "##" };
    int jet = 0;
    auto valid = [&](mi x, int y, mi prev_x) {
        return (y >= 0 && y < 7 && mat[x.v][y] == '.');
    };
    vector<vector<char>> rem;
    ll MAGIC = 1213;
    ll LAST_MAGIC_ANS = -1;
    ll ans = 0;
    for (ll i = 0; i < rounds; i++) {
        // Magic stuff
        if (i % 1000000 == 0) cout << "done: " << i+1 << endl;
        if (i == MAGIC) {
            rem = mat;
            LAST_MAGIC_ANS = ans;
        }
        if (i > MAGIC) {
            bool ok = true;
            for (int ci = 0; ci < buffer && ok; ci++) {
                for (int cj = 0; cj < 7 && ok; cj++) {
                    ok &= (mat[ci][cj] == rem[ci][cj]);
                }
            }
            if (ok) {
                cout << "We found a cycle at round: " << i << endl;
                ll diff = ans - LAST_MAGIC_ANS;
                ll cycles = (rounds - i) / (i - MAGIC);
                ans += cycles * diff;
                i += cycles * (i - MAGIC);
            }
        }

        mi x = floor - 3 - (int)rocks[i%5].size();
        int y = 2;
        int index = 0;
        mi init_x = x;
        // Clear the buffer from the current position to the floor
        for (mi X = x; X != floor; X++) {
            for (int y = 0; y < 7; y++) {
                mat[X.v][y] = '.';
            }
        }
        // Simulate
        while (true) {
            if (index % 2 == 0) {
                // The rock should be pushed
                bool ok = true;
                for (int k = 0; k < rocks[i%5].size(); k++) {
                    for (int l = 0; l < rocks[i%5][k].size(); l++) {
                        if (rocks[i%5][k][l] != '.' && 
                            !valid(x + k, y + l + (s[jet] == '>' ? 1 : -1), init_x - 1)) {
                                ok = false;
                        }
                    }
                }
                if (ok) {
                    y += (s[jet] == '>' ? 1 : -1);
                }
                jet = (jet + 1) % s.size();
            } else {
                // It falls
                bool ok = true;
                for (int k = 0; k < rocks[i%5].size(); k++) {
                    for (int l = 0; l < rocks[i%5][k].size(); l++) {
                        if (rocks[i%5][k][l] != '.' && !valid(x + k + 1, y + l, init_x - 1)) {
                            ok = false;
                        }
                    }
                }
                if (ok) {
                    x++;
                } else {
                    break;
                }
            }
            index++;
        }
        for (int k = 0; k < rocks[i%5].size(); k++) {
            for (int l = 0; l < rocks[i%5][k].size(); l++) {
                if (rocks[i%5][k][l] != '.') mat[(x+k).v][y+l] = '#';
            }
        }
        bool skip = false;
        int count = 0;
        for (mi X = init_x; X != floor; X++) {
            for (int y = 0; y < 7; y++) {
                if (mat[X.v][y] != '.') {
                    floor = X;
                    skip = true;
                    break;
                }
            }
            if (skip) break;
            count++;
        }
        ans += 3 + rocks[i%5].size() - count;
    }
    cout << ans << endl;
    return 0;
}