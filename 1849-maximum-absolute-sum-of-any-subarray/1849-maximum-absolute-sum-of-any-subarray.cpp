class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int Mpos=0;
        int Mneg=0;
        int suma=0;
        int sumb=0;

        for(auto elem : nums)
        {
            suma+=elem;
            if(suma <= 0) suma=0;
            Mpos=max(suma,Mpos);

            sumb+=elem;
            if(sumb >= 0) sumb=0;
            Mneg=min(sumb,Mneg);
        }


        return max(Mpos,abs(Mneg));
    }
};