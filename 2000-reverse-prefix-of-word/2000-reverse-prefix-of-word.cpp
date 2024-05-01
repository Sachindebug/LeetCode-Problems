class Solution {
public:
    string reversePrefix(string word, char ch) {
        int j=0;
        bool found=false;
        for(auto x:word)
        {
            j++;
            if(x==ch)
            {
                found=true;
                break;
                
            }
        }
        if(!found) return word;
        reverse(word.begin(),word.begin()+j);
        return word;
            
        
        
    }
};