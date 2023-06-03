#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> graph[n];
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int finalAns = INT_MAX;
        int finalNode = 0;
        for(int i=0;i<n;i++){
            vector<int> dist(n,INT_MAX);
            queue<pair<int,int>> q;
            q.push({i,0});
            dist[i] = 0;
            while(!q.empty()){
                pair<int,int> temp = q.front();
                q.pop();
                for(auto it : graph[temp.first]){
                    if(dist[it.first] > temp.second + it.second){
                        dist[it.first] = temp.second + it.second;
                        q.push({it.first,dist[it.first]});
                    }
                }
            }
            int cnt = 0;
            for(auto it : dist){
                if(it <= distanceThreshold) 
                    cnt++;
            }
            if(cnt <= finalAns){
                finalAns = cnt;
                finalNode = max(finalNode,i);
            }
        }
        return finalNode;
    }
};