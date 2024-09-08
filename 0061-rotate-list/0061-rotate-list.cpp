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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==nullptr || k==0 || head->next==nullptr) return head;

        deque<int>dq;
        ListNode* temp=head;


        while(temp!=nullptr)
        {
            dq.push_back(temp->val);
            temp=temp->next;
        }

        if(k>dq.size()) k%=dq.size();

        while(k--)
        {
            int val=dq.back();
            dq.pop_back();
            dq.push_front(val);
        }

        ListNode* ans=new ListNode(dq.front());
        ListNode* curr=ans;  
        dq.pop_front();

        while(!dq.empty())
        {
            curr->next=new ListNode(dq.front());
            dq.pop_front();
            curr=curr->next;

        }   


        return ans;

    }

};