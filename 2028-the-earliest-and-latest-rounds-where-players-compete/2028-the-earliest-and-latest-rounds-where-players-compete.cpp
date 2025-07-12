class Solution {
public:

    typedef vector<int> pr;

    vector<int> earliestAndLatest(int n, int p1, int p2) {

            if(p1 - 1 == n - p2) return {1,1};
            if(p1 > n - p2 + 1)
            {
                int temp = n - p1  + 1;
                p1 = n - p2 + 1;
                p2 = temp;
            }


            int mini = n;
            int maxi = 0;


            if(p2 <= (n+1)/2 ) //same side
            {
                int leftp1 = (p1 -1);
                int mid_p1p2 = (p2 - p1 -1);

                for(int i = 0 ; i <= leftp1 ; ++i) // i -> count of elemts to left of p1
                {
                    for(int j = 0 ; j <= mid_p1p2 ; ++j) // j -> count of elements between p1 qand p2
                    {
                        pr ans = earliestAndLatest((n+1)/2,i+1,i+j+2);
                        mini = min(mini,ans[0] + 1);
                        maxi = max(maxi,ans[1] + 1);
                    }
                }
            }


            else{

                int left_mirror_of_p2 = n + 1 - p2 ;
                int leftp1 = p1 - 1;
                int p1_and_mirror_mid = left_mirror_of_p2 - p1 - 1;
                int leftp2_and_mirror_mid = p2 - left_mirror_of_p2 -1;
                int nextroundremain = (leftp2_and_mirror_mid + 1)/2 + 1;

                for(int i = 0 ; i <= leftp1 ; ++i)
                {
                    for(int j = 0 ; j <= p1_and_mirror_mid ; ++j)
                    {
                        int pos1 = i + 1;
                        int pos2 = i + 1 + j + nextroundremain;
                        pr ans = earliestAndLatest((n+1)/2,pos1,pos2);
                        mini = min(mini,ans[0] + 1);
                        maxi = max(maxi,ans[1] + 1);
                    }
                }

            }

            return {mini,maxi};
 
    }
};