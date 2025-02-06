class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // 1 tupple contribute to ->>8 combinations
        
        //fix a and b in starting 2

        // [abcd] -> [abcd]-> [bacd] -> [badc]   4 Tuples
        
        //ab was in start now cs would be so

        // [cdab] -> [cdba] -> [dcab] -> [dcba]  4 Tuples


        unordered_map<int,int>mp;
        int n=nums.size();
        for(auto i=0 ;i <n-1 ; i++)
       {
            for(auto j=i+1 ; j < n ; j++)
            {
                int a=nums[i];
                int b=nums[j];
                mp[a*b]++;
            }
       }


       // if we have three pairs with same product take example of 12 as 1*12=12 
       // also 2*6=12 and 3*4 =12 we have 3 pairs with same product
       //now u can select any 2 from these 3 at any instant to make tuple

       // take [1,12,2,6] then take [1,12,3,4] and last take [2,6,3,4]
       
       // which make our Valid touple count to 3 now we have 3 tuples
       // that gives total 24 combinatinons 8 from each  

       //dircet formula is n(n-1)/2; to found number of valid tuples
       //where n is the SameProductCount.

       int count=0;

       for(auto &[key,SameProductCount] : mp)
       {
            if( SameProductCount > 1)
            {
                int times= (SameProductCount * (SameProductCount -1))/2;
                count+=(8*times);
            }
       }

       return count;

    }
};