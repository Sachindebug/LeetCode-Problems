class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<string> v_s,v_d;  //v_s stores the strings with same characters whereas v_d stores the strings with different characters
        for(int i=0;i<words.size();i++){
            if(words[i][0]==words[i][1]){
                v_s.push_back(words[i]);
            }
            else{
                v_d.push_back(words[i]);
            }
        }
        int ans=0;
        unordered_map<string,int> um_d;  //um_d stores the count of strings having different characters
        for(int i=0;i<v_d.size();i++){ 
            um_d[v_d[i]]++;
        }
        for(auto it : um_d){
            string temp="";
            temp+=it.first[1];
            temp+=it.first[0];
            if(um_d[temp]){
                ans+=(min(um_d[temp],it.second))*4;
                um_d[temp]=0;
                it.second=0;
            }
        }
        int flag = 0;
        unordered_map<string,int> um_s; //um_s stores the count of strings having same characters
        for(int i=0;i<v_s.size();i++){ 
            um_s[v_s[i]]++;
        }
        for(auto it : um_s){
            if(it.second%2){
                flag=1;
                
            }
            ans+=(it.second/2)*4;
        }
        if(flag==1)
            ans+=2;
        
        return ans;
    }
        
    
};