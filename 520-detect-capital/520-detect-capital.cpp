class Solution {
public:
    bool detectCapitalUse(string word) {
        bool first=false;
        bool all=true;
        bool allsmall=true;
        if(word[0]<96) first=true;
        for(int i=1;i<word.length();i++)
        {
            if(word[i]>96) all=false;
            if(word[i]<96) allsmall=false;
        }
        if(first && allsmall) return true;
        if(!first && allsmall) return true;
        if(first && all) return true;
        return false;
        
    }
};