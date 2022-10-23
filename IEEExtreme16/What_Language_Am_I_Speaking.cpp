#include <bits/stdc++.h>
#include <iostream>
#include <locale>
#include <vector>

using namespace std;

uint32_t convert(string s) {
    uint32_t res = 0;
    for (uint32_t i = 0; i < s.size(); i++) {
        res <<= 8;
        res += (s[i] & 255);
    }
    return res;
}

struct node;

unordered_map<uint32_t, node*> nodes;
unordered_map<uint32_t, node*> query;

vector<string> ans;

struct node {
    uint32_t l, r;
    uint32_t ch;
    string lang;

    void go(bool yes, set<uint32_t>& chs) {
        if (lang != "") {
            ans.push_back(lang);
            return;
        }

        bool is_yes = chs.count(ch);

        nodes[l]->go(is_yes, chs);
        if (!is_yes) {
            nodes[r]->go(false, chs);
        }
    }
};

int main() {
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> utf32conv;

    uint32_t n, p;
    cin >> n >> p;

    map<uint32_t, uint32_t> referenced;

    for (uint32_t i = 0; i < n; i++) {
        char c;
        cin >> c;

        if (c == 'I') {
            uint32_t id_node;
            string s;
            uint32_t l, r;
            cin >> id_node >> s >> l >> r;

            referenced[id_node] = max(referenced[id_node], (uint32_t)0);

            uint32_t ch = convert(s);
            node* new_node = new node{
                l, r, ch, ""
            };
            
            nodes[id_node] = new_node;
            query[ch] = new_node;
            referenced[l] = 1;
            referenced[r] = 1;
        } else {
            uint32_t id_node;
            string lang;
            cin >> id_node >> lang;

            node* new_node = new node{
                id_node, id_node, 0, lang
            };

            nodes[id_node] = new_node;
        }
    }

    uint32_t root_id = -1;
    for (auto el: referenced) {
        if (el.second == 0) {
            root_id = el.first;
            break;
        }
    }

    for (uint32_t i = 0; i < p; i++) {
        ans.clear();

        string s;
        getline(cin >> ws, s);

        set<uint32_t> chs;
        std::u32string utf32 = utf32conv.from_bytes(s);
        for (char32_t c : utf32) {
            uint32_t ch = convert(utf32conv.to_bytes(c));
            chs.insert(ch);
        }

        nodes[root_id]->go(false, chs);
        sort(ans.begin(), ans.end());
        for (auto el: ans) {
            cout << el << " ";
        } cout << endl;
    }
}