class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        // vector<int>Nnums=nums;
        // sort(Nnums.begin(),Nnums.end());
        // int n=nums.size();
        // int mid=(n+1)/2;

        // int i=mid-1;
        // int j=n-1;
        // int k=0;

        // while(k<n)
        // {
        //     if(k%2==0)
        //     {
        //         nums[k]=Nnums[i];
        //         i--;
        //         k++;
        //     }
        //     else{
        //         nums[k]=Nnums[j];
        //         j--;
        //         k++;
        //     }
        // }


        int maxi=*max_element(nums.begin(),nums.end());
        vector<int>vec(maxi+1,0);

        for(auto elem : nums)
        {
            vec[elem]++;
        }

        int j=vec.size()-1;
        
        //filling odd places
        for(int i=1 ; i< nums.size() ; i+=2)
        {
            while(vec[j]==0) j--;

            nums[i]=j;
            vec[j]--;
        }

        //filling even
        
        for(int i=0 ; i< nums.size() ; i+=2)
        {
            while(vec[j]==0) j--;

            nums[i]=j;
            vec[j]--;
        }

    }
};