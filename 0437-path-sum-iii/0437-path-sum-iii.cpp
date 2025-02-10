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

    void solver(long long currsum,TreeNode *root, int k , int & count,unordered_map<long long,long long>&mp)
    {
        if(root==nullptr) return;
        
        currsum+=root->val;
        count+=mp[currsum-k];
        
        mp[currsum]++;
        solver(currsum,root->left,k,count,mp);
        solver(currsum,root->right,k,count,mp);
        
        mp[currsum]--;
    }


    int pathSum(TreeNode* root, int targetSum) {
        int count=0;
        unordered_map<long long,long long>mp;
        mp[0]=1;
        solver(0,root,targetSum,count,mp);
        return count;
    }
};