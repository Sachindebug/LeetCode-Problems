class Solution {
public:
    set<int> SieveOfEratosthenes(int n)
    {
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));

        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
               for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        set<int> res;
        for (int p = 2; p <= n; p++)
            if (prime[p])
                res.insert(p);
        
        return res;
    }
    vector<vector<int>> findPrimePairs(int n) {
        set<int> prime = SieveOfEratosthenes(n);
        vector<vector<int>> res;
        for(auto x:prime)
        {
            int a = x;
            int b = n-x;
            if(a<=b && prime.find(b)!=prime.end())
            {
                res.push_back({a,b});
            }
        }
        return res;
    }
};