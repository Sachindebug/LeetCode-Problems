class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // [(0,1),(3,3),(5,1),(8,4),(10,2)] target = 12
        // timeToReach = [12,3,7,1,1]
        int n = position.size();
        vector<pair<int,int>> spepos;
        for(int i = 0; i<n ;i++){
            spepos.push_back({position[i],speed[i]});
        }
        sort(spepos.begin(),spepos.end());
        stack<double> st;
        int count = 0;
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && st.top()< (double(target-spepos[i].first)/double(spepos[i].second))){
                st.pop();
            }
            if(st.empty()) count++;
            st.push(double(target-spepos[i].first)/double(spepos[i].second));
        }
        return count;
    }
};