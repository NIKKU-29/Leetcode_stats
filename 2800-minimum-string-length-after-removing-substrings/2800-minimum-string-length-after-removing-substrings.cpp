class Solution {
public:
    int minLength(string s) {
        int n = s.size();
        int i = 0; 
        
        while (i < n - 1) {
            
            if ((s[i] == 'A' && s[i + 1] == 'B') || (s[i] == 'C' && s[i + 1] == 'D')) {
               
                s.erase(i, 2);
                
                if (i > 0) i--;
              
                n = s.size();
            } else {
                
                i++;
            }
        }
        
        
        return s.size();
    }
};
