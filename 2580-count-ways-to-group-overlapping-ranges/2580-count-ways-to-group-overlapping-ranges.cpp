class Solution {
public:
    int merge(vector<vector<int>>& arr) {
        vector<vector<int>> res;
        if(arr.size()<=1) return arr.size();
        sort(arr.begin(),arr.end());
        vector<int> temp=arr[0];
        int i=0;
        while(i<arr.size())
        {
            int x=arr[i][0];
            int y=arr[i][1];
            int a=temp[1];
            if(a>=x)
            {
                temp[1]=max(temp[1],y);
            }
            else
            {
                res.push_back(temp);
                temp=arr[i];
            }
            i++;
        }
        res.push_back(temp);
        return res.size();
    }
    int mod=1e9+7;
    long long int power(long long int x, long long int y)
    {
        long long int res = 1; 
        long long int p=mod;// Initialize result

        x = x % p; // Update x if it is more than or
                    // equal to p

        if (x == 0) return 0; // In case x is divisible by p;

        while (y > 0)
        {
            // If y is odd, multiply x with result
            if (y & 1)
                res = (res*x) % p;

            // y must be even now
            y = y>>1; // y = y/2
            x = (x%p*x%p) % p;
        }
    return res;
}
    int countWays(vector<vector<int>>& ranges) {
        long long int n=merge(ranges);
        // cout<<n<<endl;
        return power(2,n);
    }
};