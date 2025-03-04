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
    

    TreeNode* solver(TreeNode* root,TreeNode* p ,TreeNode* q, bool findp,bool findq)
    { 
        
        if (root == nullptr) return nullptr;

         if (root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode* left =solver(root->left, p, q, findp, findq);
        TreeNode* right=solver(root->right, p, q, findp, findq);

        if(left && right)
        {
            return root;
        }

        return left ? left : right;

    }
    


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

            bool findp=false;
            bool findq=false;
            return solver(root,p,q,findp,findq);
    
    }
};