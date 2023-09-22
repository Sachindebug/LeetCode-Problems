class Solution {
public:
    int countPairs(vector<vector<int>>& arr, int k) {
        unordered_map<string,long long int> ump;
        for(auto x:arr)
        {
            string a = to_string(x[0]);
            string b = to_string(x[1]);
            string t = a+"+"+b;
            ump[t]++;
        }
        long long int res=0;
        for(int i=0;i<=k;i++)
        {
            int x = i;
            int y = k-i;
            for(int j=0;j<arr.size();j++)
            {
                int a = arr[j][0] ^ x;
                int b = arr[j][1] ^ y;
                string s = to_string(a)+"+"+to_string(b);
                int c = arr[j][0];
                int d = arr[j][1];
                if(a==c && b==d)
                {
                    res+=((ump[s]-1));
                }
                else
                    res+=ump[s];
            }
            
        }
        
        return res/2;
    }
};