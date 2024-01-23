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

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        if (nums.size()==0)
        return NULL ;

        int max= INT_MIN ;
        int index= -1  ;

        for (int i=0 ; i< nums.size() ; i++)
        {
            if (nums[i]> max)
            {
            max= nums[i]; 
            index= i ; 
            }
        }

        vector<int> left ; 
        vector<int> right; 

        for (int i=0 ;i < index ; i++)
        left.push_back(nums[i]); 

        for (int i= index+ 1 ; i < nums.size() ; i++)
        right.push_back(nums[i]); 

        TreeNode* node= new TreeNode ; 
        node->val = max ; 

        node->left = constructMaximumBinaryTree(left) ; 
        node-> right = constructMaximumBinaryTree(right); 

        for (int i=0 ;i < left.size(); i++)
        left.pop_back(); 

        for (int i=0 ;i < right.size(); i++)
        right.pop_back() ;

        return node; 
    }
};