class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> f(26,0);
        vector<int> s(26,0);
        for(int i=0;i<word1.size();i++){
            f[word1[i]-'a']++;
        }
        for(int i=0;i<word2.size();i++){
            s[word2[i]-'a']++;
        }
        int as1=0,as2=0;
        for(auto it: f){
            if(it>0){
                as1+=1;
            }
        }
        for(auto it: s){
            if(it>0){
                as2+=1;
            }
        }
        if((as1==as2)&&(as1==word1.size())&&(as2==word2.size())){
            return true;
        }
        for(char i='a';i<='z';i++){
            for(char j='a';j<='z';j++){
                if(f[i-'a']<=0 || s[j-'a']<=0){
                    continue;
                }
                f[i-'a']--,f[j-'a']++;
                s[j-'a']--,s[i-'a']++;
                int ans1=0,ans2=0;
                for(auto it: s){
                    if(it>0){
                        ans2++;
                    }
                }
                for(auto it: f){
                    if(it>0){
                        ans1++;
                    }
                }
                if(ans1==ans2){
                    return true;
                }
                f[i-'a']++,f[j-'a']--;
                s[j-'a']++,s[i-'a']--;
            }
        }
        return false;
    
    }
};