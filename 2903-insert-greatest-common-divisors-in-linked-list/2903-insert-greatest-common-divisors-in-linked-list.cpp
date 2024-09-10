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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        ListNode* first = head;

        while(first!=nullptr && first->next!=nullptr)
        {
            int second= __gcd(first->val,first->next->val);

            ListNode * third = first->next;
            first->next= new ListNode(second);
            first->next->next=third;

            first=first->next->next;
        }


        return head;
        
    }
};