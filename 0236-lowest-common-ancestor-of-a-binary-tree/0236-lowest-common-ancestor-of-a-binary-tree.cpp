/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
TreeNode* parent = nullptr;

    bool solver(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;

        // Check if `p` or `q` exists in the left or right subtree
        bool left = solver(root->left, p, q);
        bool right = solver(root->right, p, q);
        
        // Check if the current node is either `p` or `q`
        bool mid = (root == p || root == q);

        // If any two of the three (left, right, mid) are true, set `parent`
        if (left + right + mid >= 2) {
            parent = root;
        }

        // Return true if the node is found in either subtree or current node
        return (left || right || mid);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solver(root, p, q);
        return parent;
    }
};