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
    vector<int> largestValues(TreeNode* root) {

        vector<int>answer;
        if(!root) return answer;

        
        queue<TreeNode*>pq;
        pq.push(root);
        
        while(!pq.empty())
        {
            int size=pq.size();
            int maxi=INT_MIN;

            for (int i = 0; i < size; i++) {

                TreeNode* temp=pq.front();
                pq.pop();


                maxi=max(maxi,temp->val);
        
                if(temp->left!=nullptr)
                {
                    pq.push(temp->left);
                    
                }
                if(temp->right!=nullptr)
                {
                    pq.push(temp->right);
                }


            }
                  answer.push_back(maxi);  

        }


        return answer;
        
    }
};