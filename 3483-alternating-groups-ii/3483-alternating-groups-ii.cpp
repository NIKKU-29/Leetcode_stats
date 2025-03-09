class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int i = 0;
        int j = 0;
        int count = 0;
        int n = colors.size();

        while(j < n + k -1)
        {
            if(j > 0 && colors[j%n] == colors[(j-1)%n])
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