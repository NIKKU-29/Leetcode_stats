class Solution {

    typedef long l;

public:

    int solver( l curr,l next, int limit)
    {
        int num_count=0;

        while(curr<=limit)
        {
            num_count += min(next, (l)limit + 1) - curr;
            next*=10;
            curr*=10;
        }

        return num_count;
    }



    int findKthNumber(int n, int k) {


        int curr=1;
        k-=1;

        while(k>0)
        {
            int next=curr+1;
            int count=solver(curr,next,n);


            if(count <= k)
            {
                curr++;
                k-=count;
            }
            else
            {
                curr*=10;
                k--;
            }
        }


        return curr;
        
    }
};