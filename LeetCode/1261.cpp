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

class FindElements {
public:
    TreeNode* root;
    vector<bool> visited;

    void recover(TreeNode* u, int x) {
        u->val = x;
        if (x < visited.size()) {
            visited[x] = true;
        } else {
            return;
        }
        if (u->left != nullptr) {
            recover(u->left, 2 * x + 1);
        }
        if (u->right != nullptr) {
            recover(u->right, 2 * x + 2);
        }
    }

    FindElements(TreeNode* root) {
        this->root = root;
        visited.resize(1e6 + 10);
        recover(this->root, 0);
    }

    bool find(int target) {
        return visited[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */