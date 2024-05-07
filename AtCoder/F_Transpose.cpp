#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

string S;
vector<int> connect;

void print(int L, int R, int depth) {
    while (L <= R) {
        if (S[(depth ? R : L)] == (depth ? ')' : '(')) {
            int nextL = depth ? connect[R] : L;
            int nextR = depth ? R  : connect[L];
            print(nextL + 1, nextR - 1, depth ^ 1);
            
            if (depth) R = connect[R];
            else L = connect[L];
        } else {
            cout << S[depth ? R : L];
        }
        if (depth) R--; else L++;
    }
}

int main() {
    cin >> S;
    int N = S.size();
    connect.resize(N);
    stack<int> st;
    int balance = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '(') {
            st.push(i);
            balance++;
        } else if (S[i] == ')') {
            auto t = st.top();
            st.pop();
            connect[t] = i;
            connect[i] = t;
            balance--;
        } else if (balance % 2 == 1) {
            if (S[i] >= 'A' && S[i] <= 'Z') S[i] = S[i] - 'A' + 'a';
            else S[i] = S[i] - 'a' + 'A';
        }
    }
    print(0, N - 1, 0);
    return 0;
}