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

    TreeNode* solver(int& prestart,int n,int parent,vector<int>&preorder)
    {
        if(prestart == n || preorder[prestart] > parent)
        {
            return nullptr;
        }

        TreeNode* tree= new TreeNode(preorder[prestart]);
        prestart++;

        tree->left=solver(prestart,n,tree->val,preorder);
        tree->right=solver(prestart, n ,parent,preorder);

        return tree;
        
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int n=preorder.size();
        int prestart=0;
        return solver(prestart,n,INT_MAX,preorder);

    }
};