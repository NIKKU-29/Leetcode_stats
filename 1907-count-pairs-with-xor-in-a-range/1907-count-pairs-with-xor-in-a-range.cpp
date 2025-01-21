class Solution {
private:
    struct TrieNode {
        TrieNode* child[2];
        int count;
        
        TrieNode() {
            child[0] = child[1] = nullptr;
            count = 0;
        }
    };
    
    void insert(TrieNode* root, int num) {
        TrieNode* curr = root;
        // Process from MSB to LSB (15 bits enough as constraints say num ≤ 2^14)
        for(int i = 14; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(!curr->child[bit]) {
                curr->child[bit] = new TrieNode();
            }
            curr = curr->child[bit];
            curr->count++;
        }
    }
    
    int countSmallerEqual(TrieNode* root, int num, int x) {
        if(!root) return 0;
        
        TrieNode* curr = root;
        int count = 0;
        
        // Process from MSB to LSB
        for(int i = 14; i >= 0; i--) {
            if(!curr) break;
            
            int bit = (num >> i) & 1;
            int xbit = (x >> i) & 1;
            
            if(xbit == 1) {
                // We can include numbers where bit is same
                if(curr->child[bit]) 
                    count += curr->child[bit]->count;
                // And move to opposite bit
                curr = curr->child[1-bit];
            } else {
                // Can only move to same bit
                curr = curr->child[bit];
            }
        }
        
        if(curr) count += curr->count;
        return count;
    }
    
public:
    int countPairs(vector<int>& nums, int low, int high) {
        int n = nums.size();
        TrieNode* root = new TrieNode();
        int ans = 0;
        
        // For each number
        for(int i = 0; i < n; i++) {
            // Count numbers before i that make pairs with nums[i]
            ans += countSmallerEqual(root, nums[i], high) - 
                   countSmallerEqual(root, nums[i], low-1);
            // Insert current number
            insert(root, nums[i]);
        }
        
        return ans;
    }
};