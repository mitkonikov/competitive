// Task: https://mendo.mk/Task.do?id=303

#include <bits/stdc++.h>
#define ll long long

using namespace std;

#define fst first
#define snd second

struct bigint: vector<long long> {
    // smaller B ==> larger deals / slower operations
    // B = 100000000  (10^8) ==> it deals with 10^645636
    // B = 1000000000 (10^9) ==> it deals with 10^7378
    static const int B = 100000000;
    static const int W = 8;
    char sign;

    bigint& trim() {
        while (!empty() && !back()) pop_back();
        if (empty()) sign = 1;
        return *this;
    }

    bigint(long long v = 0): sign(1) {
        if (v < 0) {
            sign = -1;
            v = -v;
        }
        while (v > 0) {
            push_back(v % B);
            v /= B;
        }
    }

    bigint(string s): sign(+1) {
        int e = 0;
        for (; e < s.size() && (s[e] < '0' || s[e] > '9'); ++e)
            if (s[e] == '-') sign = -sign;
        for (int i = s.size() - 1; i >= e; i -= W) {
            push_back(0);
            for (int j = max(e, i - W + 1); j <= i; ++j)
                back() = 10 * back() + (s[j] - '0');
        }
        trim();
    }

    bigint operator-() const {
        bigint x = *this;
        if (!empty()) x.sign = -x.sign;
        return x;
    }

    bigint& operator+=(bigint x);
};

// input and output
ostream& operator<<(ostream& os, const bigint& x) {
    if (x.sign < 0) os << '-';
    os << (x.empty() ? 0 : x.back());
    for (int i = (int)x.size() - 2; i >= 0; --i)
        os << setfill('0') << setw(bigint::W) << x[i];
    return os;
}

istream& operator>>(istream& is, bigint& x) {
    string s;
    is >> s;
    x = bigint(s);
    return is;
}

string pad(ll x) {
    string res = to_string(x);
    while (res.size() < bigint::W) {
        res = "0" + res;
    }
    return res;
}

void tostr(string& s, bigint& x) {
    s += (x.empty() ? "" : to_string(x.back()));
    for (int i = (int)x.size() - 2; i >= 0; --i)
        s += pad(x[i]);
}

bigint operator-(bigint x, bigint y);

bigint operator+(bigint x, bigint y) {
    if (x.sign != y.sign) return x - (-y);
    if (x.size() < y.size()) swap(x, y);
    int c = 0;
    for (int i = 0; i < y.size(); ++i) {
        x[i] += y[i] + c;
        c = (x[i] >= bigint::B);
        if (c) x[i] -= bigint::B;
    }
    if (c) x.push_back(c);
    return x;
}

bigint operator-(bigint x, bigint y) {
    if (x.sign != y.sign) return x + (-y);
    int sign = x.sign;
    x.sign = y.sign = +1;
    if (x < y) {
        swap(x, y);
        sign = -sign;
    }
    int c = 0;
    for (int i = 0; i < x.size(); ++i) {
        x[i] -= (i < y.size() ? y[i] : 0) + c;
        c = (x[i] < 0);
        if (c) x[i] += bigint::B;
    }
    x.sign = sign;
    return x.trim();
}

bigint operator*(bigint x, int y) {
    if (y == 0) return bigint(0);
    if (y < 0) {
        x.sign = -x.sign;
        y = -y;
    }
    int c = 0;
    for (int i = 0; i < x.size() || c; ++i) {
        if (i == x.size()) x.push_back(0);
        x[i] = x[i] * y + c;
        c = x[i] / bigint::B;
        if (c) x[i] %= bigint::B;
    }
    return x;
}

bigint operator*(int x, bigint y) { return y * x; }

// Karatsuba multiplication
bigint operator*(bigint x, bigint y) {
    if (x.empty() || y.empty()) return bigint(0);
    function<void(long long*, int, long long*, int, long long*)>
        rec = [&](long long* x, int xn, long long* y, int yn, long long* z) {
        if (xn < yn) {
            swap(xn, yn);
            swap(x, y);
        }
        fill(z, z + xn + yn, 0);
        if (yn <= 2) {
            for (int i = 0; i < xn; ++i)
                for (int j = 0; j < yn; ++j)
                    z[i + j] += x[i] * y[j];
        } else {
            int m = (xn + 1) / 2, n = min(m, yn);
            for (int i = 0; i + m < xn; ++i) x[i] += x[i + m];
            for (int j = 0; j + m < yn; ++j) y[j] += y[j + m];
            rec(x, m, y, n, z + m);
            for (int i = 0; i + m < xn; ++i) x[i] -= x[i + m];
            for (int j = 0; j + m < yn; ++j) y[j] -= y[j + m];
            long long p[2 * m + 2];
            rec(x, m, y, n, p);
            for (int i = 0; i < m + n; ++i) {
                z[i] += p[i];
                z[i + m] -= p[i];
            }
            rec(x + m, xn - m, y + m, yn - n, p);
            for (int i = 0; i < xn + yn - m - n; ++i) {
                z[i + m] -= p[i];
                z[i + 2 * m] += p[i];
            }
        }
    };
    bigint z;
    z.resize(x.size() + y.size() + 2);
    z.sign = x.sign * y.sign;
    rec(&x[0], x.size(), &y[0], y.size(), &z[0]);
    for (int i = 0; i + 1 < z.size(); ++i) { // be careful with overflow
        z[i + 1] += z[i] / bigint::B;
        z[i] %= bigint::B;
        if (z[i] < 0) {
            z[i + 1] -= 1;
            z[i] += bigint::B;
        }
    }
    return z.trim();
}

bigint pow(bigint x, int b) {
    bigint y(1);
    for (; b > 0; b /= 2) {
        if (b % 2) y = y * x;
        x = x * x;
    }
    return y;
}

pair<bigint, int> divmod(bigint x, int y) {
    if (y < 0) {
        x.sign = -x.sign;
        y = -y;
    }
    int rem = 0;
    for (int i = x.size() - 1; i >= 0; --i) {
        x[i] += rem * bigint::B;
        rem = x[i] % y;
        x[i] /= y;
    }
    return { x.trim(), rem };
}

bigint operator/(bigint x, int y) { return divmod(x, y).fst; }

bigint operator%(bigint x, int y) { return divmod(x, y).snd; }

// Knuth's algorithm D 
pair<bigint, bigint> divmod(bigint x, bigint y) {
    auto norm = bigint::B / (y.back() + 1);
    int qsign = x.sign * y.sign, rsign = x.sign;
    x = x * norm;
    x.sign = +1;
    y = y * norm;
    y.sign = +1;
    bigint q, r;
    for (int i = (int)x.size() - 1; i >= 0; --i) {
        r.insert(r.begin(), x[i]);
        long long d = ((r.size() > y.size() ? bigint::B * r[y.size()] : 0)
                       + (r.size() + 1 > y.size() ? r[y.size() - 1] : 0)) / y.back();
        r = r - y * d;
        while (r.sign < 0) {
            r = r + y;
            d -= 1;
        }
        q.push_back(d);
    }
    reverse(q.begin(), q.end());
    q.sign = qsign;
    r.sign = rsign;
    return make_pair(q.trim(), divmod(r.trim(), norm).fst);
}

bigint operator/(bigint x, bigint y) { return divmod(x, y).fst; }

bigint operator%(bigint x, bigint y) { return divmod(x, y).snd; }

int main() {
    vector<int> frq(10);
    vector<int> all;
    for (int i = 1; i <= 9; i++) {
        cin >> frq[i];
        for (int k = 0; k < frq[i]; k++) {
            all.push_back(i);
        }
    }
    string AS = "", BS = "";
    reverse(all.begin(), all.end());
    AS.push_back('0' + all[0]);
    BS.push_back('0' + all[1]);
    auto comp = [&]() {
        if (BS.size() < AS.size()) return true;
        if (AS.size() < BS.size()) return false;
        for (int i = 0; i < AS.size(); i++) {
            if (BS[i] < AS[i]) return true;
            if (AS[i] < BS[i]) return false;
        }
        return true;
    };
    for (int i = 2; i < all.size(); i++) {
        if (comp()) {
            BS.push_back('0' + all[i]);
        } else {
            AS.push_back('0' + all[i]);
        }
    }
    bigint a(AS);
    bigint b(BS);
    cout << a * b << endl;
    return 0;
}