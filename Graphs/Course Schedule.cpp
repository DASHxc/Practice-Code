#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool cycleCheck(int i,vector<int>& visited,vector<int> graph[]){
        visited[i] = 1;
        for(auto v: graph[i]){
            if(visited[v] ==1 )
                return true;
            if(visited[v] == 0 && cycleCheck(v,visited,graph))
                return true;
        }
        visited[i] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> visited(numCourses,0);
        vector<int> graph[numCourses];
        for(int i=0;i<n;i++){
            graph[arr[i][1]].push_back(arr[i][0]);
        }
        for(int i=0;i<numCourses;i++){
            if(visited[i] == 0 && cycleCheck(i,visited,graph))
                return false;
        }
        return true;
    }
};