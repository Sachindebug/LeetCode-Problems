class Solution {
public:
    
    char low(vector<int> & freq){
        
        for(int i=0;i<26;i++){
            if(freq[i]!=0)return 'a'+i;
        } 
        return 'a';   
    }
    
    string robotWithString(string s) {
        
        stack<char> t;
        string ans="";  
        vector<int> freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        
        
        for(char c:s){
            t.push(c);
             freq[c-'a']--; 
            while(t.size()>0 && t.top()<=low(freq)){
                char x = t.top(); 
                ans+= x;
                t.pop();  
            }    
        }
        
         while(t.size()>0){
             ans+= t.top();
             t.pop();   
        }
      
        return ans;
      
    }
};