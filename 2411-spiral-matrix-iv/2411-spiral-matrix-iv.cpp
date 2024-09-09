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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        vector<vector<int>>ans(m,vector<int>(n,-1));

        int top=0;
        int bottom=m-1;
        int left=0;
        int right=n-1;
        ListNode* curr=head;

         while(top<=bottom && left<=right)
        {
            for(int j=left;j<=right && curr!=nullptr;++j)
            {
                ans[top][j]=curr->val;
                curr=curr->next;
            }
            top++;

            for(int i=top;i<=bottom && curr!=nullptr;++i)
            {
                ans[i][right]=curr->val;
                curr=curr->next;
            }
            right--;

            if(top<=bottom)
            {
            for(int k=right;k>=left && curr!=nullptr;--k)
            {
                ans[bottom][k]=curr->val;
                curr=curr->next;
            }
            bottom--;
            }

            if(left<=right)
            {
            for(int l=bottom;l>=top && curr!=nullptr;--l)
            {
                ans[l][left]=curr->val;
                curr=curr->next;
            }
            left++;
            }
        }

        return ans;
        
    }
};