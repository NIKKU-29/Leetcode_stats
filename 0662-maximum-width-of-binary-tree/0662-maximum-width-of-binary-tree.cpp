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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
        return 0;
    }

    std::queue<std::pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});
    int maxWidth = 0;

    while (!q.empty()) {
        int size = q.size();
        unsigned long long minIndex = q.front().second;
        unsigned long long first, last;

        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front().first;
            unsigned long long currentIndex = q.front().second - minIndex;
            q.pop();

            if (i == 0) {
                first = currentIndex;
            }
            if (i == size - 1) {
                last = currentIndex;
            }

            if (node->left) {
                q.push({node->left, 2 * currentIndex + 1});
            }
            if (node->right) {
                q.push({node->right, 2 * currentIndex + 2});
            }
        }
        maxWidth = std::max(maxWidth, (int)(last - first + 1));
    }

    return maxWidth;
    }
};