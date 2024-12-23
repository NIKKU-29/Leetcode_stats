#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

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
    int minSwapsToSort(vector<int>& arr) {
        int n = arr.size();  // Get the size of the array
        vector<pair<int, int>> arrPos(n);  // This will store the value and original index
        
        // Step 1: Create a pair of (value, index) for each element in the array
        for (int i = 0; i < n; i++) {
            arrPos[i] = {arr[i], i};
        }
        
        // Step 2: Sort the array based on the values, not the original indices
        sort(arrPos.begin(), arrPos.end());
        
        // Step 3: Initialize visited array to mark elements that have already been placed correctly
        vector<bool> visited(n, false);
        
        int swaps = 0;  // Initialize swap counter
        
        // Step 4: Loop through each element of the array
        for (int i = 0; i < n; i++) {
            // If already visited or already in the correct position, skip this element
            if (visited[i] || arrPos[i].second == i) {
                continue;  // Skip this cycle
            }
            
            // Step 5: Find the cycle size
            int cycle_size = 0;
            int j = i;
            
            // While the element is not visited, we follow the cycle
            while (!visited[j]) {
                visited[j] = true;  // Mark the element as visited
                j = arrPos[j].second;  // Move to the next element in the cycle (based on original index)
                cycle_size++;  // Increase the cycle size
            }
            
            // Step 6: If the cycle size is greater than 1, add (cycle_size - 1) to the swaps count
            if (cycle_size > 1) {
                swaps += (cycle_size - 1);  // To sort a cycle of length k, we need (k-1) swaps
            }
        }
        
        return swaps;  // Return the total swaps needed
    }

    int minimumOperations(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int count = 0;

        // Perform level order traversal
        while (!q.empty()) {
            int n = q.size();
            vector<int> currnodes;

            // Process the current level
            while (n--) {
                TreeNode* elem = q.front();
                q.pop();

                // Only add non-null children
                if (elem->left != nullptr) {
                    q.push(elem->left);
                    currnodes.push_back(elem->left->val);
                }
                if (elem->right != nullptr) {
                    q.push(elem->right);
                    currnodes.push_back(elem->right->val);
                }
            }

            // Apply the minSwapsToSort function to the values of the current level
            count += minSwapsToSort(currnodes);
        }
        
        return count;
    }
};
