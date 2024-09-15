/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // Create a dummy node and point it to the head to manage edge cases.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Initialize prev to dummy, we'll use it to move to the node just before the 'm' position.
        ListNode* prev = dummy;
        
        // Move prev to the (m-1)th position (just before the sublist starts).
        for (int i = 1; i < m; i++) {
            prev = prev->next;
        }
        
        // curr points to the first node to be reversed.
        ListNode* curr = prev->next;
        ListNode* next = nullptr; // This will help us keep track of the next node during reversal.
        
        // Reverse the sublist between m and n.
        for (int i = 0; i < n - m; i++) {
            // Store the node next to curr.
            next = curr->next;
            
            // Reversing the links step by step.
            curr->next = next->next; // Bypass 'next'
            next->next = prev->next; // Insert 'next' between prev and curr
            prev->next = next;       // Move 'next' to the front of the sublist
        }
        
        // Return the modified list's head.
        return dummy->next;
    }
};
