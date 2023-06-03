#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans;
        vector<int> graph[n];
        for(int i=0;i<edges.size();i++){
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++){
            vector<int> visited(n,0);
            vector<int> tempV;
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while(!q.empty()){
                int temp = q.front();
                q.pop();
                for(auto it : graph[temp]){
                    if(!visited[it]){
                        visited[it] = 1;
                        q.push(it);
                        tempV.push_back(it);
                    }
                }
            }
            sort(tempV.begin(),tempV.end());
            ans.push_back(tempV);
        }
        return ans;
    }
};