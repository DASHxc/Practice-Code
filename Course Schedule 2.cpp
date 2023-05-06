class Solution {
public:
    bool cycleCheck(int u, vector<int>& visited, vector<int> graph[],stack<int>& ans){
        visited[u] = 1;
        for(auto v: graph[u]){
            if(visited[v] == 1)
                return true;
            if(visited[v] == 0 && cycleCheck(v,visited,graph,ans))
                return true;
        }
        ans.push(u);
        visited[u] = 2;
        return false;
    }    
    vector<int> findOrder(int numCourses, vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> visited(numCourses, 0);
        vector<int> graph[numCourses];
        for(int i=0;i<n;i++){
            graph[arr[i][1]].push_back(arr[i][0]);
        }
        stack<int> ans;
        vector<int> finalAns;
        int flag = 0;
        for(int i=0;i<numCourses;i++){
            if(visited[i] == 0 && cycleCheck(i,visited,graph,ans))
                flag = 1;
        }
        if(flag == 1)
            return finalAns;
        while(!ans.empty()){
            finalAns.push_back(ans.top());
            ans.pop();
        }
        return finalAns;
    }
};