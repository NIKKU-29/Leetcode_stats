class Solution {
public:                   
    bool Valid_Partition(int idx, int currsum, string s, int target) {  
        if (currsum > target) return false;  

        if (idx == s.size()) {  
            return currsum == target;
        }  

          int num = 0;
          
            for (int j = idx; j < s.size(); j++) {  

                num = num * 10 + (s[j] - '0');     
                if (num > target) break;           
                if (Valid_Partition(j + 1, currsum + num, s, target)) {
                    return true; 
            }
        }

        return false;
    }  

    int punishmentNumber(int n) {  
        int sum = 0;  

        for (int i = 1; i <= n; i++) {  
            int prod = (i * i);  
            string s = to_string(prod);  
            
            if (Valid_Partition(0, 0, s, i)) {  
                sum += prod;  
            }  
        }  

        return sum;  
    }  
};
