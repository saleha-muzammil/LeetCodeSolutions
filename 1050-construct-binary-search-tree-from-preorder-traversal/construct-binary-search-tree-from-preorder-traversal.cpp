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
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        if (preorder.size()==0)
        return NULL;

        TreeNode* root = new TreeNode ; 
        root->val = preorder[0];  

        int index = preorder.size(); 

        for (int i=1 ; i < preorder.size(); i++)
        {
            if (preorder[i] > root->val)
            {
               index= i ; 
               break ;
            }
        }

        vector<int> leftSubtree, rightSubtree;

        leftSubtree.assign(preorder.begin() + 1, preorder.begin() + index);
        rightSubtree.assign(preorder.begin() + index, preorder.end());

        root-> left = bstFromPreorder(leftSubtree); 
        root-> right= bstFromPreorder(rightSubtree);

        return root; 
    }
};