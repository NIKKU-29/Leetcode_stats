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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        unordered_map<int,int>mp;

        for(auto elem : nums)
        {
            mp[elem]++;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail=dummy;

        while(head!=nullptr)
        {
            if(mp.find(head->val)==0)
            {
               tail->next=new ListNode(head->val);
               tail=tail->next;
            }

            head=head->next;
        }

        return dummy->next;
        
    }
};