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

    TreeNode* solver(int prestart,int poststart,int preend,vector<int>& preorder, vector<int>& postorder)
    {
        if(prestart > preend)
        {
            return nullptr;
        }   

        TreeNode* tree = new TreeNode(preorder[prestart]);

        if(prestart == preend)
        {
            return tree;
        }

        int leftnode = preorder[prestart + 1]; //this to be find in postorder
        int j=poststart;

        while(postorder[j] != leftnode)
        {
            j++;
        }

        int num = j- poststart + 1;

        tree->left = solver(prestart + 1,poststart,prestart + num,preorder,postorder);

        tree->right= solver(prestart + num + 1, j + 1 , preend,preorder,postorder);


        return tree;

    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

            int n=preorder.size();
            return solver(0,0,n-1,preorder,postorder);
    }
};