class Solution {
public:
    int compress(vector<char>& chars) {
        int count=1;
        string res="";
        for(int i=1;i<chars.size();i++)
        {
            if(chars[i]!=chars[i-1])
            {
                res+=chars[i-1];
                if(count!=1)
                {
                    res+=to_string(count);
                }
                count=1;
            }
            else
            {
                count++;
            }
        }
        res+=chars[chars.size()-1];
        if(count!=1)
        {
            res+=to_string(count);
        }
        for(int i=0;i<res.length();i++)
        {
            chars[i]=res[i];
        }
        return res.length();
        
    }
};