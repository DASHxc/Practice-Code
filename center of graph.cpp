#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> st[n+1];
        for(int i= 0;i<edges.size();i++){
            st[edges[i][0]].push_back(edges[i][1]);
            st[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=1;i<n+1;i++){
            if(st[i].size() == n-1)
                return i;
        }
        return -1;
    }
};