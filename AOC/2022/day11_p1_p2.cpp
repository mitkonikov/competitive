#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct item {
    vector<int> vals;
    vector<int> divs;
    void set(int v, vector<int>& tests) {
        for (int i = 0; i < tests.size(); i++) {
            vals.push_back(v % tests[i]);
            divs.push_back(tests[i]);
        }
    }
    void mul(ll n) {
        for (int i = 0; i < divs.size(); i++) {
            vals[i] = ((ll)vals[i] * n) % divs[i];
        }
    }
    void add(ll n) {
        for (int i = 0; i < divs.size(); i++) {
            vals[i] = ((ll)vals[i] + n) % divs[i];
        }
    }
    void mulself() {
        for (int i = 0; i < divs.size(); i++) {
            vals[i] = ((ll)vals[i] * vals[i]) % divs[i];
        }
    }
    void addself() {
        for (int i = 0; i < divs.size(); i++) {
            vals[i] = ((ll)vals[i] + vals[i]) % divs[i];
        }
    }
};

struct Monkey {
    vector<item> items;
    int test;
    int throwTo[2];
    char op;
    string operand;
    int inspected = 0;
    vector<int> tmp;
    void read() {
        int k;
        cin >> k;
        items.resize(k);
        tmp.resize(k);
        for (int i = 0; i < k; i++) {
            cin >> tmp[i];
        }
        cin >> op >> operand;
        cin >> test;
        cin >> throwTo[0] >> throwTo[1];
    }
    void getNew(int item) {
        inspected++;
        if (op == '+') {
            if (operand == "old") items[item].addself();
            else items[item].add(stoi(operand));
        } else {
            if (operand == "old") items[item].mulself();
            else items[item].mul(stoi(operand));
        }
    }
    void updateItems(vector<int>& tests) {
        for (int i = 0; i < items.size(); i++) {
            items[i].set(tmp[i], tests);
        }
    }
};

// I modify the input using find-replace
// for easier C++ parsing :D
int main() {
    int M;
    cin >> M;
    vector<Monkey> m(M);
    for (int i = 0; i < M; i++) m[i].read();
    vector<int> tests(M);
    for (int i = 0; i < M; i++) tests[i] = m[i].test;
    for (int i = 0; i < M; i++) m[i].updateItems(tests);
    for (int round = 0; round < 10000; round++) {
        for (int i = 0; i < M; i++) {
            for (int item = 0; item < m[i].items.size(); item++) {
                m[i].getNew(item);
                int to = m[i].throwTo[(m[i].items[item].vals[i] != 0)];
                m[to].items.push_back(m[i].items[item]);
            }
            m[i].items.clear();
        }
    }
    vector<int> ans;
    for (int i = 0; i < M; i++) ans.push_back(m[i].inspected);
    sort(ans.rbegin(), ans.rend());
    ll result = 1;
    for (int i = 0; i < 2; i++) result *= ans[i];
    cout << result << endl;
    return 0;
}