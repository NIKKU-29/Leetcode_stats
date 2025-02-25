class Solution {
public:

    int mod= 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {

        int oddcount=0;
        int evencount=0;
        int ans=0;
        int n=arr.size();
        vector<int>presum(n,0);
        
        int sum=0;

        for(int i=0 ;i< n ;i++)
        {
            sum+=arr[i];
            presum[i]=sum;
        }

        //1 4 9

        for(int i=0 ;i< n ;i++)
        {

            if(presum[i]%2==1){     //odd
                 
                    ans+=1;
                    oddcount+=1;
                    ans+= evencount;
            }

            else{    
                    evencount+=1;
                    ans+= oddcount;      
            }

             ans=ans%mod;
        }
        
        return ans;
    }
};