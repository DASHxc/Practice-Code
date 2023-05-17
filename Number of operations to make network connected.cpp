#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int findParent(int i){
        if(i == parent[i])
            return i;
        return parent[i] = findParent(parent[i]);
    }
    void unionMerge(int i,int j,int& extraEdge){
        int iP = findParent(i);
        int jP = findParent(j);
        if(iP == jP){
            extraEdge++;
            return;
        }
        if(rank[iP] >= rank[jP]){
            parent[jP] = iP;
            rank[iP]++;
        }else{
            parent[iP] = jP;
            rank[jP]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        for(int i=0;i<n;i++){
            parent.push_back(i);
            rank.push_back(1);
        }
        int extraEdge = 0;
        for(int i=0;i<connections.size();i++){
            unionMerge(connections[i][0],connections[i][1],extraEdge);
        }
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(findParent(i));
        }
        if(st.size() - 1 <= extraEdge)
            return st.size()-1;
        return -1;
    }
};