class Solution {
public:
    vector<int> closestPrimes(int left, int right) {

    int n=right; 
    vector<bool> isPrime(n + 1, true); // Create a boolean array
    isPrime[0] = isPrime[1] = false;   // 0 and 1 are not prime

    for (int i = 2; i * i <= n; i++) { // Loop till sqrt(n)
        if (isPrime[i]) { // If i is prime
            for (int j = i * i; j <= n; j += i) { // Mark multiples as false
                if(j >= left) isPrime[j] = false;
            }
        }
    }


    int lastPrime = -1;
    int mini=INT_MAX;
    vector<int>ans={-1,-1};

    for(int i=left ; i<=right ; i++)
    {
        if(isPrime[i])
        {
            // // cout<<i<<" ";
            // cout<<i<<"++"<<lastPrime<<endl;

            // if(lastPrime == -1)
            // {
            //     lastPrime = i;
            // }

            if(i - lastPrime < mini)
            {       
                    cout<<i<<"__"<<lastPrime;
                    mini = i - lastPrime;
                    ans={lastPrime,i};
                    
            }

            lastPrime = i;
            
        }

    }

    if(ans[0] == -1 || ans[1] == -1)
    {
        return {-1,-1};
    }

    return ans;

    }
};