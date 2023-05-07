#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
//My Solution with only 37/38 testcases passed.
/*class Solution {
public:
    string lastString(string st, int n){
        if(st.size() <= n)
            return st;
        return st.substr(st.size()-n);
    }
    bool DFS(string curr, string& ans, unordered_set<string> visited,int total,int n,int k){
        
        string ls = lastString(curr,n);
        if(visited.find(ls) != visited.end())
            return false;
        if(ls.length() == n)
            visited.insert(ls);
        if(visited.size() == total){
            ans = curr;
            return true;
        }
        for(int i=0;i<k;i++){
            string temp = lastString(curr + to_string(i),n);
            if(visited.find(temp) == visited.end()){
                if(DFS(curr + to_string(i),ans,visited,total,n,k))
                    return true;
                
            }
        }
        visited.erase(ls);
        return false;
    }
    string crackSafe(int n, int k) {
        string curr = "";
        string ans = "";
        int totalLen = pow(k,n);
        unordered_set<string> st;
        DFS(curr,ans,st,totalLen,n,k);
        return ans;
    }
};*/

//correct solution.
class Solution {
public:
    string ans;
    unordered_set<string>mp;
    void util(string str,int k){
        for(int i=0;i<k;i++){
            string temp = str + to_string(i);
            if(!mp.count(temp)){
                mp.insert(temp);
                util(temp.substr(1),k);
                ans += to_string(i);
            }
        }
    }
    string crackSafe(int n, int k) {
        string start(n-1,'0');
        util(start,k);
        return ans + start;
    }
};