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

#define ll long long

class Solution {
public:
    const int MOD = 1e9 + 7;
    ll sum(TreeNode* root) {
        ll ans = root->val;
        if (root->left != nullptr) ans += sum(root->left);
        if (root->right != nullptr) ans += sum(root->right);
        return ans;
    }
    pair<ll, ll> calc(TreeNode* u, ll all) {
        ll ans = 0;
        ll sub = u->val;
        if (u->left != nullptr) {
            auto [ans_subtree, sum_subtree] = calc(u->left, all);
            ans = max(ans, ans_subtree);
            sub += sum_subtree;
        }
        if (u->right != nullptr) {
            auto [ans_subtree, sum_subtree] = calc(u->right, all);
            ans = max(ans, ans_subtree);
            sub += sum_subtree;
        }
        ans = max(ans, (sub * (all - sub)));
        return make_pair(ans, sub);
    }
    int maxProduct(TreeNode* root) {
        return calc(root, sum(root)).first % MOD;
    }
};