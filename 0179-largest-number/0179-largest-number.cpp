class Solution {
public:
    static bool customComp(const string &a, const string &b) {
        return (a + b) > (b + a);
    }

    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> ToS(n);

        for (int i = 0; i < n; ++i) {
            ToS[i] = to_string(nums[i]);
        }

        sort(ToS.begin(), ToS.end(), customComp);

        string result;
        for (const string& num : ToS) {
            result += num;
        }

        if(result[0]=='0')
        {
            return "0";
        }

        return result;
    }
};
