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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(preorder[0]);

        const int N = preorder.size();
        vector<int> where_preorder(N + 1), where_postorder(N + 1);
        for (int i = 0; i < N; i++) {
            where_preorder[preorder[i]] = i;
            where_postorder[postorder[i]] = i;
        }

        vector<TreeNode*> st;
        st.push_back(root);
        for (int i = 1; i < N; i++) {
            int next = preorder[i];
            while (where_postorder[st.back()->val] < where_postorder[next]) {
                st.pop_back();
            }
            if (st.back()->left == nullptr) {
                st.back()->left = new TreeNode(next);
                st.push_back(st.back()->left);
            } else {
                st.back()->right = new TreeNode(next);
                st.push_back(st.back()->right);
            }
        }

        return st[0];
    }
};