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
        answer.push_back(root->val);

        while(!pq.empty())
        {
            int size=pq.size();
            vector<int>currnodes;

            while(size--)
            {
                TreeNode* temp=pq.front();
                pq.pop();
        
                if(temp->left!=nullptr)
                {
                    pq.push(temp->left);
                    currnodes.push_back(temp->left->val);
                }
                if(temp->right!=nullptr)
                {
                    pq.push(temp->right);
                    currnodes.push_back(temp->right->val);
                }
                    
            }

            if(!currnodes.empty())
            {
                int value=*max_element(currnodes.begin(),currnodes.end());
                answer.push_back(value);
            }

        }


        return answer;
        
    }
};