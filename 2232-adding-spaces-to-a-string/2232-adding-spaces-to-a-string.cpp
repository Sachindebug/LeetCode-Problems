class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        sort(spaces.begin(),spaces.end());
        string res="";
        int i=0;
        int j=0;
        while(i<s.length() && j<spaces.size())
        {
            if(i==spaces[j])
            {
                res+=' ';
                j++;
            }
            res+=s[i];
            i++;
            
        }
        while(i<s.length())
        {
            res+=s[i];
            i++;
        }
        return res;
    }
};