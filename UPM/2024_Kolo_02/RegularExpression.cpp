#include "bits/stdc++.h"
#define ll long long
 
using namespace std;
 
struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    char type = '@';
    char value = '$';
 
    Node(string S) {
        process(S);
    }
 
    void process(string S) {
        int balance = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') balance++;
            else if (S[i] == ')') balance--;
            if (balance == 0 && S[i] == '+') {
                string left_S = S.substr(0, i);
                string right_S = S.substr(i+1);
                type = '+';
                left = new Node(left_S);
                right = new Node(right_S);
                return;
            }
        }
 
        if (S[0] == '(') {
            int balance = 0;
            for (int i = 0; i < S.size(); i++) {
                if (S[i] == '(') balance++;
                else if (S[i] == ')') balance--;
                if (balance == 0) {
                    string left_S = S.substr(1, i - 1);
                    string right_S = S.substr(i + 1);
                    if (right_S.empty()) {
                        process(left_S);
                        return;
                    }
                    type = '*';
                    left = new Node(left_S);
                    right = new Node(right_S);
                    return;
                }
            }
        } else {
            if (S.size() == 1) {
                value = S[0];
            } else {
                type = '*';
                string left_S = S.substr(0, 1);
                string right_S = S.substr(1);
                left = new Node(left_S);
                right = new Node(right_S);
            }
        }
    }
 
    vector<string> eval() {
        if (type == '@') {
            if (value == 'E') {
                return vector<string>{ "" };
            }
            if (value == 'N') {
                return {};
            }
            string S = "";
            S += value;
            return vector<string>{ S };
        }
 
        auto l = (left != nullptr ? left->eval() : std::vector<string>());
        auto r = (right != nullptr ? right->eval() : std::vector<string>());
 
        if (type == '*') {
            vector<string> new_v;
            for (int i = 0; i < l.size() && new_v.size() < 1000; i++) {
                for (int j = 0; j < r.size() && new_v.size() < 1000; j++) {
                    new_v.push_back(l[i] + r[j]);
                }
            }
            return new_v;
        } else if (type == '+') {
            for (auto el: r) {
                if (l.size() >= 1000) break;
                l.push_back(el);
            }
            return l;
        } else {
            assert(false);
        }
        return {};
    }
 
    void print(string depth = "") {
        if (left != nullptr) left->print(depth + " ");
        // cout << depth << " ";
        if (type == '@') cout << value << endl;
        else cout << type << endl;
        if (right != nullptr) right->print(depth + " ");
        // cout << endl;
    }
};
 
int main() {
    string S;
    cin >> S;
    Node* tree = new Node(S);
    // tree->print();
    auto e = tree->eval();
    for (auto el: e) {
        cout << "<" << el << ">" << endl;
    }
    return 0;
}