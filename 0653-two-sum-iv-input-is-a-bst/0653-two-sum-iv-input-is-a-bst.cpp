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


// bool solver(TreeNode* root , set<int>&st,int target)
//     {
//         if(root == nullptr) return false;
        
//         int value=(target - root->val);
        
//         if(st.count(value))
//         {
//             return true;
//         }
        
//         st.insert(root->val);
//         return solver(root->left,st,target)  || solver(root->right,st,target);
        
// //     }

//     bool findTarget(TreeNode* root, int k) {
//          set<int>st;
//         return solver(root,st,k);
//     }

    void inorder(TreeNode* root , vector<int>&vec)
    {
        if(root==nullptr) return ;
        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
    }


    bool findTarget(TreeNode* root, int k) {
        //2md apporcah building ana array using 2 pointers
        vector<int>vec;
        inorder(root,vec);

        int left=0;
        int right=vec.size()-1;

        while(left < right)
        {
            int value = vec[left] + vec[right];

            if(value == k) return true;

           else if(value > k)
            {
                right--;
            }

            else{
                left++;
            }
        }


        return false;
    }
};