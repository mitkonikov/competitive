// Task: https://mendo.mk/Task.do?id=276

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int INF = 1e5;
int n;
string s;

inline bool is_op(string s) {
    return (s == "*" || s == "+");
}

inline bool is_op(char s) {
    return (s == '*' || s == '+');
}

inline int priority(string s) {
    return (s == "*" ? 2 : 1);
}

int eval(vector<string>& exp) {
    stack<int> values;
    stack<string> ops;
    bool flag = false;
    auto process_op = [&]() {
        assert(values.size() >= 2);
        int r = values.top(); values.pop();
        int l = values.top(); values.pop();
        string op = ops.top(); ops.pop();
        if (op == "*") {
            if (l * r > 5000) flag = true;
            values.push(l * r);
        } else {
            if (l + r > 5000) flag = true;
            values.push(l + r);
        }
    };

    for (int i = 0; i < exp.size(); i++) {
        if (!is_op(exp[i])) {
            if (exp[i].empty()) {
                values.push(0);
                break;
            }
            values.push(stoi(exp[i]));
        } else {
            if (i == exp.size() - 1) break;
            while (!ops.empty() && priority(ops.top()) >= priority(exp[i])) {
                process_op();
            }
            if (flag) return 5000;
            ops.push(exp[i]);
        }
    }
    while (!ops.empty()) process_op();
    if (flag) return 5000;
    return values.top();
}

vector<string> convert(string exp) {
    if (exp.empty()) return { "" };
    vector<string> res;
    for (int i = 0; i < (int)exp.size(); i++) {
        if (is_op(exp.substr(i, 1))) {
            res.push_back("");
            res.back() += exp[i];
        } else {
            res.push_back("");
            while (i < (int)exp.size() && !is_op(exp.substr(i, 1))) {
                res.back() += exp[i];
                i++;
            }
            i--;
        }
    }
    return res;
}

int bfs() {
    vector<bool> visited(5100, false);
    queue<pair<string, int>> q;
    q.push({ { "" }, 0 });
    while (!q.empty()) {
        auto top = q.front();
        q.pop();

        vector<string> v = convert(top.first);

        int e = eval(v);
        if (e > n) continue;
        if (e == n) return top.second;

        auto& exp = top.first;
        if (!exp.empty() && !is_op(exp.back())) {
            if (v.back() != "1") {
                exp += "*";
                q.push({ exp, top.second + 1 });
                exp.pop_back();
            }
            
            if (!visited[e]) {
                exp += "+";
                q.push({ exp, top.second + 1 });
                exp.pop_back();
            }
        }

        visited[e] = true;
        
        if (v.back().size() >= 4) continue;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '0' && (v.back().empty() || is_op(v.back()))) continue;
            if (!is_op(v.back()) && stoi(v.back() + s[i]) > 5000) {
                continue;
            }

            exp.push_back(s[i]);
            q.push({ exp, top.second + 1 });
            exp.pop_back();
        }
    }
    return -1;
}

int main() {
    cin >> s >> n;
    cout << bfs() << endl;
    return 0;
}