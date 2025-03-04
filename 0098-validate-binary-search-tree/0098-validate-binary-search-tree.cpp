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

    bool solver(TreeNode* root,long min,long max)
    {
            if(root == nullptr) return true;
            
            if(root->val <= min || root->val >= max) return false;
            
            bool left = solver(root->left,min,root->val);
            bool right = solver(root->right,root->val,max);

            return left && right;
    }

    bool isValidBST(TreeNode* root) {
        
        return solver(root,LONG_MIN,LONG_MAX);

    }
};