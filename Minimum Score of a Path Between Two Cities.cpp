#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> graph[n+1];
        vector<int> visited(n+1,0);
        for(int i=0;i<roads.size();i++){
            graph[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            graph[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        int ans = INT_MAX;
        queue<pair<int,int>> q;
        q.push({1,INT_MAX});
        visited[1] = 1;
        while(!q.empty()){
            pair<int,int> temp = q.front();
            q.pop();
            for(auto it : graph[temp.first]){
                ans = min(ans,it.second);
                if(!visited[it.first]){
                    visited[it.first] = 1;
                    q.push(it);
                }
            }
        }
        return ans;
    }
};