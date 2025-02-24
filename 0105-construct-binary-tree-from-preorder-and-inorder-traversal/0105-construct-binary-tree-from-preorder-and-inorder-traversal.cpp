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

    TreeNode* solver(int prestart,int preend,int instart,vector<int>& preorder, vector<int>& inorder)
    {
        if(preend < prestart)
        {
            return nullptr;
        }

        TreeNode* tree = new TreeNode(preorder[prestart]);

        if(prestart == preend)
        {
            return tree;
        }
        
        int j=instart;

        while(inorder[j] != preorder[prestart])
        {
            j++;
        }

        int num= j - instart + 1;

        tree->left = solver(prestart + 1, prestart + num - 1,instart,preorder,inorder);

        tree->right = solver(prestart + num ,preend,j + 1,preorder,inorder);

        return tree;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    int n=preorder.size();      
    return solver(0,n-1,0,preorder,inorder);

    }
};