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

     bool aresame(TreeNode* root, TreeNode* subroot) {
        if (!root && !subroot) return true;
        if (!root || !subroot || root->val != subroot->val) return false;
    
        return aresame(root->left, subroot->left) && aresame(root->right, subroot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if (!root) return false;
        if (!subroot) return true;  // Edge case: empty subtree is always a subtree

        // First, check if current root matches subroot
        if(root->val==subroot->val){

        if (aresame(root, subroot)) return true;
       
        }
        // Otherwise, check in left and right subtrees
        return isSubtree(root->left, subroot) || isSubtree(root->right, subroot);
    }
};