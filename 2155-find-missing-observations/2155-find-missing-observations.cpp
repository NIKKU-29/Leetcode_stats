class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

        int sumH=0;

        for(int i=0;i<rolls.size();i++)
        {
            sumH+=rolls[i];
        }

        int RealSize=rolls.size() + n;
        int RealSum=mean * RealSize;
        int leftSum=RealSum-sumH;


        if(leftSum < n || leftSum > 6 * n) return {};

        int add=leftSum/n;
        int remaining = leftSum%n;
        vector<int>ad(n,add);

        for (int i = 0; i < remaining; ++i) {
           
            ad[i]++;
        }
        
        return ad;
            
            
    }
};