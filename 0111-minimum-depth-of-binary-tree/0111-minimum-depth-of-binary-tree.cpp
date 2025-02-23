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

        int left = INT_MAX, right = INT_MAX;  // Initialize left and right to a large value

        if(root->left) 
            left = solver(root->left);  // Recurse on left subtree
        if(root->right) 
            right = solver(root->right);  // Recurse on right subtree

        return 1+ min(left, right);  // Return the minimum depth
    }

    int minDepth(TreeNode* root) {
        return solver(root);
    }
};
