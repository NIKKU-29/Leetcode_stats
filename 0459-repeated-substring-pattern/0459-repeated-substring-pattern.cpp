class Solution {
public:

//APPROACH 1 - DOUBLE THE ORIGNAL STRING REMOVE 1st AND Nth Character 
//             FIND STRING IN IT

     //a .bc|abcabcabcab|cabcabcab. c
     //     |abcabcabcab|

 bool repeatedSubstringPattern(string s) {

    string doubled=s+s;
    string removedEnds=doubled.substr(1,doubled.size()-2);
    if(removedEnds.find(s)!=string::npos) return true;
    return false;
     


//APPROACH 2 - TAKE THE STRING~SUBSTRINGS ONE BY ONE


    // bool repeatedSubstringPattern(string s) {

    //     int n=s.size();
    //     for(int i=1 ; i<= n/2 ; i++)
    //     {
    //         if(n % i == 0) //uneven length
    //         {
    //             string curr=s.substr(0,i);
    //             string concatinated="";
    //             for(int j=0 ; j< n/i ; j++)
    //             {
    //                 concatinated+=curr;
    //             }

    //             if(concatinated==s) return true;
    //         }
    //     }
        
    //     return false;
    }
};