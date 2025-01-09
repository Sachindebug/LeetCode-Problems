class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        int p=pref.length();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(words[i].length()<p) continue;
            else
            {
                string s;
                s=words[i];
                bool found=false;
                for(int j=0;j<p;j++)
                {
                    if(s[j]!=pref[j])
                    {
                        found=true;
                        break;
                    }
                }
                if(!found) count++;
            }
        }
        return count;
        
    }
};