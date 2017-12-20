/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mymap;

        for (Employee* emp : employees) {
            mymap[emp->id] = emp;
        }
        
        int total = 0;
        stack<int> st;
        
        st.push(mymap[id]->id);
        
        while (!st.empty()) {
            int id = st.top();
            st.pop();
            total += mymap[id]->importance;
            for (int x : mymap[id]->subordinates) {
                st.push(x);
            }
        }
        
        return total;
    }
};
