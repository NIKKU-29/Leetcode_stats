class NumArray {
public:
    vector<int>n;
    NumArray(vector<int>& nums) {

        int sum=0;
        for(auto elem : nums)
        {
            sum+=elem;
            n.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0){
            return n[right];
        }
        return n[right]-n[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */