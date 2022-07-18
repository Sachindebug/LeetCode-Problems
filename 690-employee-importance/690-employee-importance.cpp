/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int count=0;
        dfs(employees,id,count);
        return count;
    }
    void dfs(vector<Employee*> employees, int id,int &count)
    {
        for(int i=0;i<employees.size();i++)
        {
            if(employees[i]->id==id)
            {
                count+=employees[i]->importance;
                for(auto x:employees[i]->subordinates)
                {
                    dfs(employees,x,count);
                }
            }
        }
        return;
    }
};