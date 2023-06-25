class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        map<string,int> ump;
        for(auto x:words) ump[x]++;
        int ans=0;
        for(auto x:ump)
        {
            string t="";
            t+=x.first[1];
            t+=x.first[0];
            if(ump.find(t)!=ump.end() && t!=x.first)
            {
                ans+=min(x.second,ump[t]);
            }

        }
        return ans/2;
    }
};