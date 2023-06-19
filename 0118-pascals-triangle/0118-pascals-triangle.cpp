class Solution {
public:
    vector<vector<int>> generate(int n,vector<int> curr={1},vector<vector<int>> res={}) {
        if(n==0){
           
            return res;
        }
        if(curr.size()==1){
            
            res.push_back(curr);
            curr.push_back(1);
            return generate(n-1,curr,res);
        }else{
            
            res.push_back(curr);
            vector<int> c1={1};
            for(int i=1;i<curr.size();i++){
                c1.push_back(curr[i]+curr[i-1]);
            }
            c1.push_back(1);//inserting last 1
            curr=c1;
            return generate(n-1,curr,res);        
        }
       
    }
};