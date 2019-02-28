#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

// Employee info
class Employee {
public:
    // It's the unique ID for each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;

    Employee(int _id, int _importance, vector<int> _subordinates )
        :id(_id), importance(_importance), subordinates(_subordinates) {}
};

class Solution {
private:
    map<int, Employee*> record;
public:
    int getImportance(vector<Employee*> employees, int id) {
        record.clear();
        for (Employee* employee: employees)
            record[employee->id] = employee;
        //return dfs(id);
        return bfs(id);
    }
private:
    //DFS
    //Time  Complexity: O(n)
    //Space Complexity: O(n)
    int dfs(int id) {
        int res = record[id]->importance;
        for (int sid: record[id]->subordinates)
            res += dfs(sid);
        return res;
    }
    //BFS
    //Time  Complexity: O(n)
    //Space Complexity: O(n)
    int bfs(int id) {
        queue<Employee*> q;
        q.push(record[id]);

        int res = 0;
        while (q.empty() != true) {
            Employee* w = q.front();
            q.pop();
            
            res += w->importance;

            for (int sid: w->subordinates)
                q.push(record[sid]);
        }
        return res;
    }
};

int main()
{
    vector<Employee*> vec = {
        new Employee(1, 5, {2, 3}),
        new Employee(2, 3, vector<int>()),
        new Employee(3, 3, vector<int>())
    };

    cout << Solution().getImportance(vec, 1) << endl;
    return 0;
}

