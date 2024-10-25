class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end(),[](string &a, string &b){
            return a.length()<b.length();
        });
        vector<string> res;
        map<string,int> ump;
        for(auto s: folder){
            string temp = "";
            bool found = false;
            for(int i = 0;i<s.length();i++){
                if(s[i]>='a' && s[i]<='z')  temp+=s[i];
                else{
                    if(ump.find(temp)!=ump.end()){
                        found = true;
                        break;
                    }
                    temp+=s[i];
                }
            }
            if(!found) {
                ump[temp]++;
                res.push_back(temp);
            }
        }
        return res;
    }
};