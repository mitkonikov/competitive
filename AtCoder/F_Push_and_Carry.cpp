#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

inline ll man(ll X, ll Y, ll TX, ll TY) {
    return abs(X - TX) + abs(Y - TY);
}

int main() {
    ll TX, TY, CX, CY, GX, GY;
    cin >> TX >> TY >> CX >> CY >> GX >> GY;
    // 1. Where should Takahashi position himself,
    //    before moving the cargo?
    // 2. Calculate the steps required
    //    Edge case: PX  < CX <  TX, TY = PY
    //                Y     Y     Y,  X =  X
    // 3. Calculate the steps required to move the cargo
    //    - CX == GX
    //    - CY == GY
    //    else

    ll global_ans = LLONG_MAX;
    auto solve = [&](ll PX, ll PY) {
        ll ans = 0;

        if (TY == PY && ((PX < CX && CX < TX) || (PX > CX && CX > TX))) {
            ans += man(TX, TY, PX, PY) + 2;
        } else if (TX == PX && ((PY < CY && CY < TY) || (PY > CY && CY > TY))) {
            ans += man(TX, TY, PX, PY) + 2;
        } else {
            ans += man(TX, TY, PX, PY);
        }

        if (CX == GX || CY == GY) {
            ans += man(CX, CY, GX, GY);
        } else {
            ans += man(CX, CY, GX, GY) + 2;
        }

        global_ans = min(global_ans, ans);
    };

    if (CX == GX) {
        if (CY > GY) solve(CX, CY + 1);
        else solve(CX, CY - 1);
    } else if (CY == GY) {
        if (CX > GX) solve(CX + 1, CY);
        else solve(CX - 1, CY);
    } else {
        if (CX < GX && CY < GY) {
            solve(CX - 1, CY);
            solve(CX, CY - 1);
        } else if (CX > GX && CY > GY) {
            solve(CX + 1, CY);
            solve(CX, CY + 1);
        } else if (CX > GX && CY < GY) {
            solve(CX, CY - 1);
            solve(CX + 1, CY);
        } else {
            solve(CX, CY + 1);
            solve(CX - 1, CY);
        }
    }

    cout << global_ans << endl;
    return 0;
}