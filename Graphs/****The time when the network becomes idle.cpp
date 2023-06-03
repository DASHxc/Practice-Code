#include<vector>
#include<unordered_map>
#include<set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<int> graph[n];
        int ans = INT_MIN;
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> dist(n,INT_MAX);
        queue<pair<int,int>> q;
        q.push({0,0});
        dist[0] = 0;
        while(!q.empty()){
            pair<int,int> temp = q.front();
            q.pop();
            for(auto it : graph[temp.first]){
                if(dist[it] > 1+temp.second){
                    dist[it] = 1 + temp.second;
                    q.push({it,dist[it]});
                }
            }
        }
        int maxNode = 0;
        int maxDist = INT_MIN;
        for(int i =1;i<n;i++){
            int msgSent = 2*dist[i]/patience[i];
            if(2*dist[i]%patience[i] == 0)
                msgSent--;
            //cout<<msgSent<<"  "<<patience[i]<<"   "<<2*dist[i]<<endl;
            int currAns = msgSent * patience[i] + 2*dist[i];
            ans = max(ans,currAns);
        }
        return ans + 1;
    }
};