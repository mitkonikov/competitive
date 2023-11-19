#include <cassert>
#include <cstdio>
#include <ctime>
#include <random>
using namespace std;
using u64 = unsigned long long;
constexpr int N_MAX = 1e6 + 10;
int N, Q;
u64 A[N_MAX];

// 
//  Addition => XOR
//  Multiplication => NIM PRODUCT
//  

u64 pw[N_MAX], hs[N_MAX], basis, small[256][256];
template <bool is_pre = false>
u64 nim_product(u64 a, u64 b, int p = 64) {
  if (min(a, b) <= 1) return a * b;
  if (!is_pre and p <= 8) return small[a][b];
  p >>= 1;
  u64 a1 = a >> p, a2 = a & ((1ull << p) - 1);
  u64 b1 = b >> p, b2 = b & ((1ull << p) - 1);
  u64 c = nim_product<is_pre>(a1, b1, p);
  u64 d = nim_product<is_pre>(a2, b2, p);
  u64 e = nim_product<is_pre>(a1 ^ a2, b1 ^ b2, p);
  return nim_product<is_pre>(c, 1uLL << (p - 1), p) ^ d ^ ((d ^ e) << p);
}

void init() {
  for (int i = 0; i < 256; i++)
    for (int j = 0; j < 256; j++) small[i][j] = nim_product<true>(i, j, 8);
  pw[0] = 1, hs[0] = basis = 0;
  mt19937_64 rng(time(NULL));
  basis = rng();
  for (int i = 1; i <= N; i++) {
    pw[i] = nim_product(pw[i - 1], basis);
    hs[i] = nim_product(hs[i - 1], basis) ^ A[i - 1];
  }
}

u64 get(int l, int r) { return nim_product(hs[l], pw[r - l]) ^ hs[r]; }
void send(int flag) { printf(flag ? "Yes\n" : "No\n"); }

int main() {
  scanf("%d %d", &N, &Q);
  for (int i = 0; i < N; i++) scanf("%llu", &(A[i]));
  init();
  while (Q--) {
    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    --a, --c, --e;
    int l = 0, h = min(f - e, b - a) + 1;
    while (l + 1 < h) {
      int m = (l + h) / 2;
      ((get(a, a + m) ^ get(c, c + m) ^ get(e, e + m)) ? h : l) = m;
    }
    send(e + l != f and (a + l == b or (A[a + l] ^ A[c + l]) < A[e + l]));
  }
}