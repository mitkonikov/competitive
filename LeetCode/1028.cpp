#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        vector<string> splits;
        for (int i = 0; i < traversal.size(); i++) {
            if (splits.empty()) {
                splits.push_back("");
                splits.back() += traversal[i];
                continue;
            }
            if (splits.back().back() == '-' && traversal[i] == '-') {
                splits.back() += '-';
                continue;
            }
            if (splits.back().back() != '-' && traversal[i] != '-') {
                splits.back() += traversal[i];
                continue;
            }
            splits.push_back("");
            splits.back() += traversal[i];
        }
        vector<pair<int, int>> nodes;
        for (int i = 1; i < splits.size() - 1; i += 2) {
            int depth = splits[i].size();
            int val = stoi(splits[i+1]);
            nodes.push_back({ depth, val });
        }
        vector<TreeNode*> st;
        st.push_back(new TreeNode(stoi(splits[0])));
        for (int i = 0; i < nodes.size(); i++) {
            int depth = nodes[i].first;
            int val = nodes[i].second;
            if (depth >= st.size()) {
                if (st.back()->left == nullptr) {
                    st.back()->left = new TreeNode(val);
                    st.push_back(st.back()->left);
                } else {
                    st.back()->right = new TreeNode(val);
                    st.push_back(st.back()->right);
                }
            } else {
                while (depth < st.size()) {
                    st.pop_back();
                }
                if (st.back()->left == nullptr) {
                    st.back()->left = new TreeNode(val);
                    st.push_back(st.back()->left);
                } else {
                    st.back()->right = new TreeNode(val);
                    st.push_back(st.back()->right);
                }
            }
        }

        return st[0];
    }
};