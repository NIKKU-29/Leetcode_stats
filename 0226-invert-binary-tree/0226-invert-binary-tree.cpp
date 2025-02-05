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

    void solver(TreeNode* temp)
    {
        if(temp==nullptr) return; 

        invertTree(temp->left);
        invertTree(temp->right);

        swap(temp->left,temp->right);

    }
    TreeNode* invertTree(TreeNode* root) {
        
        solver(root);
        return root;
        
    }
};