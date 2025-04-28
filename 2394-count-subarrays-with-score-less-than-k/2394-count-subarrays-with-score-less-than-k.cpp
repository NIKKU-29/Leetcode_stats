

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0;
        long long sum = 0;
        int i = 0, j = 0;
        
        while (j < n) {
            sum += nums[j];
            
            
            while (i <= j && sum * (j - i + 1) >= k) {
                sum -= nums[i];
                i++;
            }
            
            // ja ek valid window mil rahi hai iska malab uske sare combinations valid honge kuki puri vindow ka hum cumulative sum hi dekh rahe hain

            // ise samhjne ke liay take a exaple as 
            // [1,1,1] and k = 5
            // here we comdide forst the 
            
            //  1 at index 0 we increse count as this is vakli all upto this is valid
            // hence we are at index 0 so 0 - 0 + 1 = 1
            // count me + 1 ho gaya ab
            //[1] YE [] WINDOW SIZE BATA RAHE HAINN

            // valid we move j so ab sum = 2 ho gaya j pointer index 1 pe aa gaya
            // still sum->2 * 2 <- len < k(5) so we again do
            // 1 - 0 + 1 = 2
            // ab count me + 2 add ho gaya hai jo reprset arta hai
            // [_,1],1 <- VO KHUD
            // [1,1],1 <- AUR VALID START INDEX SE US INDEX TAK KE SARE VALID WINDOW INDEX

            // SAME WAY FOR
            // INDEX = 2 SUM IS 3 SO 3 * 3 > 5 NOT VALID
            // N0T VALID
            // WE MOVE THE J FORWARD SO TAT MEANS [1,1,1] IS INVALID WINDOW
            // NOW OUR WINOW BECOMES 1,[1,1] -->>>>  WE REMOVED THE SARTING INDEX 1
            //                       ^                       ^
            //                       |__________()___________|
            // NOW WE CAN SE THIS NEW WINDOW IS ALSO VALID WHICH GIVES
            // 1,[_,1]  <- VO KHUD
            // 1,[1,1] <-US TAKE KE SARE VALID WINDOW INDEX
            //THIS ALSO INCRESE THE COUNT BY 2 AS J- I + 1 IS 2 - 1 + 1 = 2;
              
            ans += (j - i + 1);
            // cout<<ans;
            
            j++;
        }
        
        return ans;
    }
};

