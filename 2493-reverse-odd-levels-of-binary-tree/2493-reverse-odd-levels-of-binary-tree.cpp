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
    TreeNode* reverseOddLevels(TreeNode* root) {

        int level=0;
        TreeNode* temp=root;
        queue<TreeNode*>q;
        q.push(temp);

        while(!q.empty())
        {
            int size=q.size();
            vector<TreeNode*>CurrNodes;


            while(size--)
            {
                TreeNode* curr=q.front();
                q.pop();

                if(level % 2 == 1) //odd level
                {
                    CurrNodes.push_back(curr);
                }

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        

        if(level%2==1)
        {
            int n=CurrNodes.size();

            for(int i=0 ; i < n/2 ; i++)
            {
                swap(CurrNodes[i]->val,CurrNodes[n-i-1]->val);
            }   
        }

        ++level;
    }

        return root;

    }
};