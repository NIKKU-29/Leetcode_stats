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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<pair<TreeNode*, int>> st; // (Node, Depth)
    int i = 0, n = traversal.size();

    while (i < n) {
        int depth = 0;
        while (i < n && traversal[i] == '-') {
            depth++;
            i++;
        }

        string value = "";
        while (i < n && isdigit(traversal[i])) {
            value += traversal[i];
            i++;
        }

        TreeNode* newNode = new TreeNode(stoi(value));

        // Pop stack until we reach correct parent depth
        while (!st.empty() && st.top().second >= depth) {
            st.pop();
        }

        if (!st.empty()) {
            if (!st.top().first->left) {
                st.top().first->left = newNode;
            } else {
                st.top().first->right = newNode;
            }
        }

        st.push({newNode, depth});
    }

    // Root node is the bottom-most element in the stack
    while (st.size() > 1) {
        st.pop();
    }

    return st.top().first;

    }
};