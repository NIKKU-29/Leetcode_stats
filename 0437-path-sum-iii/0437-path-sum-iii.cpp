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

    int count;

    void solver(long long currsum,TreeNode* root,int k,unordered_map<long long,long long>mp)
    {
        if(!root) return;

        currsum+=root->val;

        if(mp.find(currsum - k)!=mp.end())
        {
            count+=mp[currsum-k];
        }

        mp[currsum]++;

        solver(currsum,root->left,k,mp);
        solver(currsum,root->right,k,mp);

        mp[currsum]--;
    }


    int pathSum(TreeNode* root, int targetSum) {

        unordered_map<long long,long long>mp;
        mp[0]=1;
        solver(0,root,targetSum,mp);
        return count;
    }
};