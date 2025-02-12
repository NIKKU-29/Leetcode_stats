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

    // 
    
//     class Solution {
// public:
    bool findTarget(TreeNode* root, int k) {
        TreeNode *left = root, *right = root;
        stack<TreeNode*> leftStack, rightStack;

        // Function to get the next smallest element in BST
        auto getNextSmallest = [&]() -> int {
            while (left) {
                leftStack.push(left);
                left = left->left;
            }
            TreeNode* node = leftStack.top();
            leftStack.pop();
            left = node->right;
            return node->val;
        };

        // Function to get the next largest element in BST
        auto getNextLargest = [&]() -> int {
            while (right) {
                rightStack.push(right);
                right = right->right;
            }
            TreeNode* node = rightStack.top();
            rightStack.pop();
            right = node->left;
            return node->val;
        };

        int leftValue = getNextSmallest();
        int rightValue = getNextLargest();

        while (leftValue < rightValue) {
            int sum = leftValue + rightValue;
            if (sum == k) return true;
            if (sum < k) leftValue = getNextSmallest();
            else rightValue = getNextLargest();
        }

        return false;
    }
};
