class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        
        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;
        long long sum = 0;
        
        for(auto elem : differences)
        {
            sum+=elem;
            maxi = max(maxi,sum);
            mini = min(mini,sum);
        }

        int count = 0;

        for(int i = lower ; i <= upper ; i++)
        {
            if( i - mini >= lower && i - mini <= upper && i - maxi >= lower && i - maxi <= upper)
            {
                count++;
            }
        }
           
           return count;
    }
};