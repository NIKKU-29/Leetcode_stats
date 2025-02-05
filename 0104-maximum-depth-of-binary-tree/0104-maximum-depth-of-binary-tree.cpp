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

    int solver(TreeNode* root)
    {
        if(root == nullptr) // Add this to handle the edge case when root is null
        {
            return 0;       
        }

        if(root->left == nullptr && root->right == nullptr) // Base case: leaf node
        {
            return 1;       
        }

        int left = 0, right = 0;  // Initialize left and right to a large value

        if(root->left) 
            left = 1 + solver(root->left);  // Recurse on left subtree
        if(root->right) 
            right = 1 + solver(root->right);  // Recurse on right subtree

        return max(left, right);  // Return the minimum depth
    }

    int maxDepth(TreeNode* root) {
        return solver(root);
    }
};
