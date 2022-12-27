#include <bits/stdc++.h>
#define ll64 long long
#define ull64 unsigned long long
#define ll __int128_t

using namespace std;

unordered_map<string, int> mp;
struct node;
vector<node*> nodes;

int id = 0;
inline int add(string s) {
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
    std::optional<ll> calculated = std::nullopt;
    std::optional<ll> value = std::nullopt;

    pair<ll, bool> calc() {
        if (value.has_value()) return { value.value(), false };
        if (calculated.has_value()) return { calculated.value(), true };

        auto L = nodes[mp[left]]->calc();
        auto R = nodes[mp[right]]->calc();
        ll l = L.first, r = R.first;
        bool save = (L.second && R.second);

        ll result = 0;
        switch (op) {
            case '+': {
                result = l + r;
                break;
            }
            case '-': {
                result = l - r;
                break;
            }
            case '/': {
                result = l / r;
                break;
            }
            case '*': {
                result = l * r;
                break;
            }
        }

        if (save) {
            calculated = result;
        }

        return { result, save };
    }
};

int main() {
    int N;
    cin >> N;
    nodes.resize(N);
    auto split = [](string s) {
        vector<string> result;
        string last_string = "";
        for (int i = 0; i < s.size(); i++) {
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
    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        auto s = split(line);
        s[0] = s[0].substr(0, s[0].size() - 1);
        node* me = new node();
        if (s.size() == 2) {
            me->calculated = stoi(s[1]);
        } else {
            me->left = s[1];
            me->op = s[2][0];
            me->right = s[3];
        }
        int myID = add(s[0]);
        nodes[myID] = me;
    }

    // Binary Search over the answer
    ll L = 0, R = 1e25;
    auto go = [&](ll MID) {
        nodes[mp["humn"]]->value = MID;
        string l = nodes[mp["root"]]->left;
        string r = nodes[mp["root"]]->right;
        auto LL = nodes[mp[l]]->calc();
        auto RR = nodes[mp[r]]->calc();
        return make_pair(LL.first, RR.first);
    };

    ll t = 0;
    while (R - L > 1) {
        ll MID = (R - L) / 2 + L;
        auto p = go(MID);
        if (p.first == p.second) {
            t = MID;
            break;
        }
        
        if (p.first > p.second) {
            L = MID;
            t = MID;
        } else if (p.first < p.second) {
            R = MID;
            t = MID;
        }
    }

    // Get it right
    for (ll MID = t - 100; MID <= t + 100; MID++) {
        auto p = go(MID);
        if (p.first == p.second) {
            cout << (ull64)MID << endl;
            return 0;
        }
    }

    return 0;
}