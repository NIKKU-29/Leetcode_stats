class Solution {
public:
    const long long mod = 1e9 + 7; 

    vector<long long> sieve(long long limit) {
        vector<bool> isPrime(limit + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (long long i = 2; i * i <= limit; i++) {
            if (isPrime[i]) {
                for (long long j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<long long> primes;
        for (long long i = 2; i <= limit; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        return primes;
    }

    long long checker(long long num, vector<long long>& primes) {
        long long count = 0;

        for (auto prime : primes) {
            if (prime * prime > num) break;  // Stop early if prime^2 > num

            if (num % prime == 0) {
                count++;
                while (num % prime == 0) num /= prime;  // Remove all occurrences of this factor
            }
        }

        if (num > 1) count++;  // If num is still > 1, it is a prime itself

        return count;
    }

    long long power(long long base, long long exponent) {
        long long res = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            exponent /= 2;
        }
        return res;
    }

    int maximumScore(vector<int>& nums, int k) {
        long long maxi = *max_element(nums.begin(), nums.end());
        vector<long long> primes = sieve(maxi); // Precompute primes

        vector<long long> scores(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            scores[i] = checker(nums[i], primes);
        }

        long long n = nums.size();
        vector<long long> PrevGreater(n, -1);
        vector<long long> NextGreater(n, n);
        stack<long long> s;

        for (long long i = 0; i < n; i++) {
            while (!s.empty() && scores[i] > scores[s.top()]) {
                NextGreater[s.top()] = i;
                s.pop();
            }
            if (!s.empty()) {
                PrevGreater[i] = s.top();
            }
            s.push(i);
        }

        vector<pair<long long, long long>> sorted(n);
        for (long long i = 0; i < n; i++) {
            sorted[i] = {nums[i], i};
        }

        sort(sorted.rbegin(), sorted.rend());  

        vector<long long> ranges(n);
        for (long long i = 0; i < n; i++) {
            ranges[i] = (NextGreater[i] - i) * (i - PrevGreater[i]);
        }

        long long score = 1;
        int processingIndex = 0;

        while (k > 0) {
            auto [num, index] = sorted[processingIndex++];
            long long operations = min((long long)k, ranges[index]);
            score = (score * power(num, operations)) % mod;
            k -= operations;
        }

        return score;
    }
};
