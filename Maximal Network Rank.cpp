#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_set<int> graph[n];
        vector<int> indegree(n,0);
        for(int i=0;i<roads.size();i++){
            graph[roads[i][0]].insert(roads[i][1]);
            graph[roads[i][1]].insert(roads[i][0]);
            indegree[roads[i][0]]++;
            indegree[roads[i][1]]++;
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int tempAns = indegree[i] + indegree[j];
                if(graph[i].find(j) != graph[i].end())
                    tempAns--;
                ans = max(ans,tempAns);
            }
        }
        return ans;
    }
};