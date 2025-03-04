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
    

    TreeNode* solver(TreeNode* root,TreeNode* p ,TreeNode* q)
    { 

         if (root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode* left =solver(root->left, p, q);
        TreeNode* right=solver(root->right, p, q);

        if(left && right)
        {
            return root;
        }

        return left ? left : right;

    }
    


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

            return solver(root,p,q);
    
    }
};