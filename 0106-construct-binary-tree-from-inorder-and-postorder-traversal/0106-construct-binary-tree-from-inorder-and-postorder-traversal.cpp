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

    TreeNode* solver(int instart,int inend,int postend,vector<int>& inorder, vector<int>& postorder,unordered_map<int,int>&mp)
    {
        if(instart > inend)
        {
            return nullptr;
        }


        int rootval=postorder[postend];
        TreeNode* tree = new TreeNode(rootval);

        int idx=mp[rootval];

        int rightSize = inend - idx;

        tree->right = solver(idx+1,inend,postend-1,inorder,postorder,mp);
        tree->left = solver(instart,idx-1,postend - rightSize - 1,inorder,postorder,mp);

        return tree;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map<int,int>mp;
        int n=inorder.size();

        for(int i=0 ;i< n ;i++)
        {
            mp[inorder[i]]=i;
        }

        return solver(0,n-1,n-1,inorder,postorder,mp);
    }
};