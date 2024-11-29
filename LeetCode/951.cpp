/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return true;
        if (root1 == nullptr || root2 == nullptr) return false;
        if (root1->val != root2->val) return false;

        auto l1 = root1->left;
        auto r1 = root1->right;
        if (l1 == nullptr) swap(l1, r1);

        auto l2 = root2->left;
        auto r2 = root2->right;
        if (l2 == nullptr) swap(l2, r2);

        if (l1 == nullptr && r1 == nullptr) {
            if (l2 == nullptr && r2 == nullptr) return true;
            return false;
        }

        if (l2 == nullptr && r2 == nullptr) {
            if (l1 == nullptr && r1 == nullptr) return true;
            return false;
        }

        // at least l1 and l2 are not nulls
        
        // check for mismatch in rs
        if (r1 == nullptr && r2 != nullptr) return false;
        if (r2 == nullptr && r1 != nullptr) return false;

        if (r1 == nullptr) {
            if (l1->val != l2->val) return false;
            return flipEquiv(l1, l2);
        }

        if (l1->val == l2->val && r1->val == r2->val) {
            return flipEquiv(l1, l2) && flipEquiv(r1, r2);
        }

        if (l1->val == r2->val && r1->val == l2->val) {
            return flipEquiv(l1, r2) && flipEquiv(r1, l2);
        }
        
        return false;
    }
};