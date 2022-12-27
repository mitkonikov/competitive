#include <bits/stdc++.h>
#define ll long long

using namespace std;

unordered_map<string, ll> mp;
struct node;
vector<node*> nodes;

ll id = 0;
inline ll add(string s) {
    auto it = mp.find(s);
    if (it == mp.end()) {
        mp[s] = id++;
        return id-1;
    }
    return it->second;
}

struct node {
    string left;
    string right;
    char op;
    std::optional<ll> value = std::nullopt;

    ll calc() {
        if (value.has_value()) return value.value();

        switch (op) {
            case '+': {
                return (value = nodes[mp[left]]->calc() + nodes[mp[right]]->calc()).value();
                break;
            }
            case '-': {
                return (value = nodes[mp[left]]->calc() - nodes[mp[right]]->calc()).value();
                break;
            }
            case '/': {
                return (value = nodes[mp[left]]->calc() / nodes[mp[right]]->calc()).value();
                break;
            }
            case '*': {
                return (value = nodes[mp[left]]->calc() * nodes[mp[right]]->calc()).value();
                break;
            }
        }

        return 0;
    }
};

int main() {
    ll N;
    cin >> N;
    nodes.resize(N);
    auto split = [](string s) {
        vector<string> result;
        string last_string = "";
        for (ll i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (!last_string.empty()) result.push_back(last_string);
                last_string = "";
            } else {
                last_string += s[i];
            }
        }
        if (!last_string.empty()) result.push_back(last_string);
        return result;
    };
    string line;
    getline(cin, line);
    for (ll i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        auto s = split(line);
        s[0] = s[0].substr(0, s[0].size() - 1);
        node* me = new node();
        if (s.size() == 2) {
            me->value = stoi(s[1]);
        } else {
            me->left = s[1];
            me->op = s[2][0];
            me->right = s[3];
        }
        ll myID = add(s[0]);
        nodes[myID] = me;
    }
    cout << nodes[mp["root"]]->calc() << endl;
    return 0;
}