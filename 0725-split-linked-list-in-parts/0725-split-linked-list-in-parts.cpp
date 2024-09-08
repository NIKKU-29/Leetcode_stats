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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        ListNode* temp=head;
        int length=0;

        while(temp!=nullptr)
        {   
            temp=temp->next;
            length++;
        }

        int normalnodes=length/k;
        int extranodes=length%k;


       vector<ListNode*>vec(k,NULL);
       ListNode* curr=head;

       for(int i=0; i<k && curr!=nullptr ;i++)
       {
             vec[i]=curr;

             int limit = normalnodes;

             if(extranodes > i)
             {
                limit+=1;
             }

             for(int j=1;j<limit;j++)
             {
                    curr=curr->next;
             }

             ListNode* newpart=curr->next;
             curr->next=nullptr;
             curr=newpart;
        

       }

        return vec;
        
    }
};