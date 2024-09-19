class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>ans;
        int n=expression.size();

        for(int i=0;i<n;i++)
        {
            if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*')
            {
                vector<int>FirstPart=diffWaysToCompute(expression.substr(0,i));
                vector<int>OtherPart=diffWaysToCompute(expression.substr(i+1));

                for(auto a : FirstPart)
                {
                for(auto b : OtherPart)    
                {
                    if(expression[i]=='+') ans.push_back(a + b);
                    else if(expression[i]=='-') ans.push_back(a - b);
                    else if(expression[i]=='*') ans.push_back(a * b);
                }

                }
            }
        }

        if (ans.empty()) ans.push_back(stoi(expression));
        return ans;
        
    }
};