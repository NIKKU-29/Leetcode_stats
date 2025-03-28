class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 1) return 0;  
        if (nums[0] == 0) return -1;

        int maxreach = nums[0];
        int steps = nums[0];
        int jump = 1;

        for(int i = 1 ; i<n ; i++)
        {
            if(i == n-1) return jump;
            maxreach = max(maxreach, i + nums[i]);
            steps--;

            if(!steps)  //nahi bachee steps ab is range me max pata lagao
            {
                jump++;
                if(maxreach <= i) return -1;
                steps = maxreach - i;    //kuki last index jaha tak pohche ho vaha se kitne aga ja sakte ho maxrange to index hai
            }
        } 

        return -1;
    }
};