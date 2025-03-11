/**
 * @param {string} s
 * @return {number}
 */
var numberOfSubstrings = function(s) {
    
    let a = 0, b = 0, c = 0;
    let j = 0;
    let i = 0;
    let n = s.length;
    let ans = 0;

    while( j <  n)
    {
           if(s[j] == 'a') a++;
           if(s[j] == 'b') b++;
           if(s[j] == 'c') c++;

         while (a > 0 && b > 0 && c > 0) {  
            ans += n - j;
            if (s[i] == 'a') a--;
            if (s[i] == 'b') b--;
            if (s[i] == 'c') c--;
            i++;
        }

       j++;
    }
        return ans;
};