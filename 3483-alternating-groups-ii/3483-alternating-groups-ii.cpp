class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int i = 0;
        int j = 0;
        int count = 0;

        vector<int>temp(colors.begin(),colors.begin() + (k-1));

        colors.insert(colors.end(),temp.begin(),temp.end());
        int n = colors.size();

        while(j < n)
        {
            if(j > 0 && colors[j] == colors[j-1])
            {
                i = j;
            }
            
            if(j - i + 1 == k)
            {
                count++;
                i++;
            }

            j++;
      }

        return count;        
    }
};