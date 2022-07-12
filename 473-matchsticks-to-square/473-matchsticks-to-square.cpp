class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        int maxV = 0;
        for(int v : matchsticks){
            sum+=v;
            maxV = max(maxV, v);
        }
        if(sum%4 || matchsticks.size()<4 || maxV>(sum/4)) return false;
        sort(matchsticks.begin(), matchsticks.end());
        vector<bool>used(matchsticks.size(), false);
        return helper(matchsticks, 0, 0, 0, sum/4, used);
    }
    
    bool helper(vector<int>& matchsticks, int pos, int createdStick, int curLen, int target, vector<bool>& used){
        int len = matchsticks.size();
        if(createdStick == 4) return true;
        for(int i=pos; i<len; i++){
            if(used[i]) continue;
            if(i>pos && matchsticks[i] == matchsticks[i-1] && !used[i-1]) { // duplicated case, return. Same as permutation 
                continue;
            }
            
            bool curRes = false;
            if((curLen+matchsticks[i]) == target){
                used[i] = true;
                if(helper(matchsticks, 0, createdStick+1, 0, target, used)){
                    return true;
                }
                used[i] = false;
            }else if((curLen+matchsticks[i]) > target){  //return first since it is already sorted. The rest is invalid. 
                break;
            }else{  // <
                used[i] = true;
                if(helper(matchsticks, i+1, createdStick, curLen+matchsticks[i], target, used)){
                    return true;
                }
                used[i] = false;
            }
        }
        return false;
    }
};