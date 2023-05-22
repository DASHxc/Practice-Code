#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> graph[n];
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            if(leftChild[i] != -1){
                graph[i].push_back(leftChild[i]);
                indegree[leftChild[i]]++;
            }
            if(rightChild[i] != -1){
                graph[i].push_back(rightChild[i]);
                indegree[rightChild[i]]++;
            }
            
        }
        int root;
        int rootCnt = 0;;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                root = i;
                rootCnt++;
            }
        }
        if(rootCnt > 1)
            return false;
        vector<int> visited(n,0);
        queue<int> q;
        q.push(root);
        visited[root] = 1;
        int visitedCnt = 1;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            if(graph[temp].size() > 2)
                return false;
            for(auto it : graph[temp]){
                if(visited[it])
                    return false;
                else{
                    visitedCnt++;
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        if(visitedCnt != n)
            return false;
        return true;
    }
};