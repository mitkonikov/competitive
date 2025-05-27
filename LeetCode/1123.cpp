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
    int deepest(TreeNode* u, int d) {
        int result = d;
        if (u->left != nullptr) result = max(result, deepest(u->left, d + 1));
        if (u->right != nullptr) result = max(result, deepest(u->right, d + 1));
        return result;
    }

    TreeNode* lca(TreeNode* u, int d, int target) {
        if (d == target) return u;
        TreeNode* l = nullptr;
        TreeNode* r = nullptr;
        if (u->left != nullptr) l = lca(u->left, d + 1, target);
        if (u->right != nullptr) r = lca(u->right, d + 1, target);
        if (l != nullptr && r != nullptr) return u;
        if (l != nullptr) return l;
        if (r != nullptr) return r;
        return nullptr;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int D = deepest(root, 0);
        return lca(root, 0, D);
    }
};