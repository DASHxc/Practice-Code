#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> graph[n];
        vector<int> indegree(n,0);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        queue<int> q;
        vector<int> visited(n,0);
        for(int i=0; i<n;i++){
            if(!visited[i] && indegree[i] == 0){
                ans.push_back(i);
                q.push(i);
                visited[i]= 1;
                while(!q.empty()){
                    int temp = q.front();
                    q.pop();
                    for(auto it : graph[temp]){
                        if(!visited[it]){
                            visited[it] = 1;
                            q.push(it);
                        }
                    }
                }
            }
        }
        return ans;
    }
};