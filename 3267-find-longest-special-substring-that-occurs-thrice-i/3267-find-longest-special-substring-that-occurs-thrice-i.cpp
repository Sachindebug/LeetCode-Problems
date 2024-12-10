class Solution {
public:
    int maximumLength(string s) {
        int res = 0;
        for(int i = 0;i<26;i++){
            char c = 'a'+i;
            map<int,int> lengthFreq;
            int count = 0;
            for(auto x:s){
                if(x==c){
                    count++;
                }
                else if(count>0){
                    for(int j = 1;j<=count;j++){
                        lengthFreq[j]+=(count-j+1);
                    }
                    count=0;
                }
            }
            if(count>0){
                for(int j = 1;j<=count;j++){
                        lengthFreq[j]+=(count-j+1);
                }
            }
            for(auto x:lengthFreq){
                if(x.second>=3) res = max(res,x.first);
            }
            cout<<res<<" ";
        }
        return res>0?res:-1;
    }
};