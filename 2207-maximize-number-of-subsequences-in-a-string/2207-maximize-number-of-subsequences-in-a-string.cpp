class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        char x=pattern[0];
        char y=pattern[1];
        int n=text.length();
        long long int count1=0;
        long long int count2=0;
        long long int count=0;
        for(int i=0;i<n;i++)
        {
            if(text[i]==y)
            {
                count+=count1;
                count2++;
            }
            if(text[i]==x)
            {
                count1++;
            }
            
                
        }
        
        return count+max(count1,count2);
        
        
        
    }
};