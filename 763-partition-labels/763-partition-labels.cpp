class Solution {
public:
    vector<int> partitionLabels(string s) {      
        unordered_map<char,int> last_occur;
        vector<int> res;
        for(int i=0;s[i];i++)
        {
            last_occur[s[i]]=i;
        }
        int i=0;
        while(i<s.length())
        {
            int idx=last_occur[s[i]];
            int j=i;
            while(j!=idx)
            {
                idx=max(idx,last_occur[s[j++]]);
            }
            res.push_back(j-i+1);
            i=j+1;
            
            
        }
        return res;
    }
};