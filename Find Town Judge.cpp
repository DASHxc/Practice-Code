#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1,0);
        vector<int> outdegree(n+1,0);
        for(int i=0;i<trust.size();i++){
            int u = trust[i][0];
            int v = trust[i][1];
            indegree[v]++;
            outdegree[u]++;
        }
        for(int i=1;i<=n;i++){
            if(indegree[i] == n-1 && outdegree[i] == 0)
                return i;
        }
        return -1;
    }
    
};