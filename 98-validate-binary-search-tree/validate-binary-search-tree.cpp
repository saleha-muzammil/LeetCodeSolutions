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
    bool extremecheck(TreeNode* root, long long int min, long long int max) {
        if (!root)
            return true;

        if (root->val <= min || root->val >= max)
            return false;

        return extremecheck(root->left, min, root->val) && extremecheck(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;

        long long int min = LLONG_MIN;
        long long int max = LLONG_MAX;

        return extremecheck(root, min, max);
    }
};
