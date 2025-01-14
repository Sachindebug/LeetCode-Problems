class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> res;
        int n=A.size();
        set<int> s1;
        set<int> s2;
        int count = 0;
        for(int i=0;i<n;i++)
        {
            s1.insert(A[i]);
            s2.insert(B[i]);
            if(s1.find(B[i])!=s1.end()) count++;
            if(s2.find(A[i])!=s2.end()) count++;
            if(A[i]==B[i]) count--;
            res.push_back(count);
        }
        return res;
    }
};