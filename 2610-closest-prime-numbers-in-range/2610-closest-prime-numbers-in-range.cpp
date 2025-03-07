class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if(right<=2) return {-1,-1};
        vector<int> primes = SieveOfEratosthenes(right);
        int res=INT_MAX;
        for(int i=0;i<primes.size()-1;i++)
        {
            if(primes[i]>=left && primes[i+1]<=right)
            res=min(res,primes[i+1]-primes[i]);
        }
        if(res==INT_MAX) return {-1,-1};
        for(int i=0;i<primes.size()-1;i++)
        {
            if(primes[i]>=left && primes[i+1]<=right && res==primes[i+1]-primes[i])
            {
                return {primes[i],primes[i+1]};
            }
            
        }
        return {-1,-1};
        
        
    }
    vector<int> SieveOfEratosthenes(int n)
    {
        vector<int> res;
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));
        for (int p = 2; p * p <= n; p++)
        {
            if (prime[p] == true)
            {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        for (int p = 2; p <= n; p++)
            if (prime[p])
                res.push_back(p);
        return res;
    }
};