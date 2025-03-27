class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>Main;

        for(auto elem : nums) Main[elem]++;

        unordered_map<int,int>checker;
        for(int i = 0 ;i< n-1 ;i++)
        {
            int elem = nums[i];
            checker[elem]++;
            int leftpartLen = i+1,rightpartLen = n - leftpartLen;
            int freqdiff = Main[elem] - checker[elem];

            if(leftpartLen < (checker[elem] * 2) && rightpartLen < (freqdiff * 2))
            {
                return i;
            } 
        }

        return -1;
    }
};