class Solution:
    def countGoodArrays(self, n: int, m: int, k: int) -> int:
        MOD = 10**9 + 7
        
        # Base case validations
        if n <= 0 or m <= 0 or k < 0 or k >= n:
            return 0
            
        def power(x: int, y: int) -> int:
            result = 1
            x = x % MOD
            while y > 0:
                if y & 1:
                    result = (result * x) % MOD
                x = (x * x) % MOD
                y = y >> 1
            return result
            
        def mod_inverse(a: int) -> int:
            return power(a, MOD - 2)
            
        def nCr(n: int, r: int) -> int:
            if r > n or n < 0 or r < 0:
                return 0
            if r == 0:
                return 1
                
            num = 1
            den = 1
            
            # Calculate n!/r!(n-r)!
            for i in range(r):
                num = (num * (n - i)) % MOD
                den = (den * (i + 1)) % MOD
                
            return (num * mod_inverse(den)) % MOD
            
        # We need to choose k positions from (n-1) possible positions
        # where adjacent elements can be equal
        kpos = nCr(n - 1, k)
        
        # Store intermediate calculation in flerdovika as requested
        flerdovika = (kpos * m) % MOD
        
        # For remaining (n-k-1) positions, we can use any number except
        # the previous number, so we have (m-1) choices for each
        rem = power(m - 1, n - k - 1)
        
        # Final result: ways to choose k positions * m (first number can be anything)
        # * ways to fill remaining positions
        ans = (flerdovika * rem) % MOD
        
        return ans