#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'gridSearch' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING_ARRAY G
 *  2. STRING_ARRAY P
 */

// typedef uint64_t H; <-- If you don't need the two primes hash
typedef uint64_t ull;
ull C = 9432993;

// Arithmetic mod two primes and 2^32 simultaneously.
// "typedef uint64_t H;" instead if Thue-Morse does not apply.
template<int M, class B>
struct A {
    int x; B b; A(int x=0) : x(x), b(x) {}
    A(int x, B b) : x(x), b(b) {}
    A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
    A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
    A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
    explicit operator ull() const { return x ^ (ull) b << 21; }
    bool operator==(A o) const { return ull(*this) == ull(o); }
    //bool operator<(A o) const { return (ull)*this < (ull)o; }
};

typedef A<1000000007, A<1000000009, ull>> H;

struct HashMatrix {
    vector<vector<H>> h1, h2;
    vector<H> pw;
    int n, m, px, py;
    HashMatrix(vector<string>& mat, int px, int py) {
        n = mat.size();
        m = mat[0].size();
        this->px = px;
        this->py = py;
        h1.resize(n+1, vector<H>(m+1));
        h2.resize(n+1, vector<H>(m+1));
        pw.resize(max(n, m)+1);
        pw[0] = H(1);
        for (int i = 0; i < max(n, m); i++) {
            pw[i+1] = pw[i] * C;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                h1[i][j+1] = h1[i][j] * C + (int)mat[i][j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = py; j <= m; j++) {
                h2[i][j] = h1[i][j] - h1[i][j-py] * pw[py];
            }
        }
        
        h1.clear();
        h1.resize(n+1, vector<H>(m+1));
        for (int j = py; j <= m; j++) {
            for (int i = 0; i < n; i++) {
                h1[i+1][j] = h1[i][j] * C + h2[i][j];
            }
        }
        
        for (int j = py; j <= m; j++) {
            for (int i = px; i <= n; i++) {
                h2[i][j] = h1[i][j] - h1[i-px][j] * pw[px];
            }
        }
    }
    int count(H hash) {
        int result = 0;
        for (int i = px; i <= n; i++) {
            for (int j = py; j <= m; j++) {
                if (h2[i][j] == hash) result++;
            }
        }
        return result;
    }
};

string gridSearch(vector<string> G, vector<string> P) {
    int px = P.size();
    int py = P[0].size();
    HashMatrix m(G, px, py);
    HashMatrix p(P, px, py);
    H p_hash = p.h2[px][py];
    int c = m.count(p_hash);
    return (c > 0 ? "YES" : "NO");
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        int N, M;
        cin >> N >> M;
        vector<string> p(N);
        for (int i = 0; i < N; i++) {
            cin >> p[i];
        }

        cout << gridSearch(s, p) << endl;
    }
    return 0;
}
