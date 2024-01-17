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

int maxValue(TreeNode* node)
{
    if (node == NULL) {
        return INT16_MIN;
    }
    int value = node->val;
    int leftMax = maxValue(node->left);
    int rightMax = maxValue(node->right);
 
    return max(value, max(leftMax, rightMax));
}

TreeNode* findMaxNode(TreeNode* node) {
    if (node == NULL) {
        return NULL;
    }

    TreeNode* maxNode = node;
    TreeNode* leftMaxNode = findMaxNode(node->left);
    TreeNode* rightMaxNode = findMaxNode(node->right);

    if (leftMaxNode != NULL && leftMaxNode->val > maxNode->val) {
        maxNode = leftMaxNode;
    }

    if (rightMaxNode != NULL && rightMaxNode->val > maxNode->val) {
        maxNode = rightMaxNode;
    }

    return maxNode;
}

int minValue(TreeNode* node)
{
    if (node == NULL) {
        return INT16_MAX;
    }
    int value = node->val;
    int leftMax = minValue(node->left);
    int rightMax = minValue(node->right);
 
    return min(value, min(leftMax, rightMax));
}

TreeNode* findMinNode(TreeNode* node) {
    if (node == NULL) {
        return NULL;
    }

    TreeNode* minNode = node;
    TreeNode* leftMinNode = findMinNode(node->left);
    TreeNode* rightMinNode = findMinNode(node->right);

    if (leftMinNode != NULL && leftMinNode->val < minNode->val) {
        minNode = leftMinNode;
    }

    if (rightMinNode != NULL && rightMinNode->val < minNode->val) {
        minNode = rightMinNode;
    }

    return minNode;
}
 
 int recoveringTree(TreeNode* node)
{

    if (node == NULL)
        return -1;

    TreeNode* maxNode= findMaxNode(node->left);
    TreeNode* minNode = findMinNode(node->right); 
 

    if (node->left != NULL
        && maxNode->val >= node->val)
        {
        int tmp = node->val ; 
        node->val = maxNode->val ; 
        maxNode-> val = tmp ;
        recoveringTree(node); 
        }
 
    /* false if the min of the right is <= than us */
    if (node->right != NULL
        && minNode->val <= node->val)
        {
        int tmp = node->val ; 
        node->val = minNode-> val; 
        minNode-> val = tmp ;
        recoveringTree(node); 
        }

    int checkingLeft= recoveringTree(node->left); 
    int checkingRight= recoveringTree(node->right); 

    if (checkingLeft!=-1)
    return checkingLeft ; 

    if (checkingRight!= -1)
    return checkingRight ;

    return -1;
}
    void recoverTree(TreeNode* root) {

        cout << recoveringTree(root) ; 

    }

};