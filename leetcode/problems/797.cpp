#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        int n = graph.size();
        if(n ==0) return res;

        dfs(graph,res,path,0,n-1);
        return res;
    }

    void dfs(vector<vector<int>>& graph, vector<vector<int>>& res,vector<int> path, int start, int end){
        path.push_back(start);
        if(start == end){
            res.push_back(path);
            return;
        }
        for(auto node:graph[start]){
            dfs(graph,res,path,node,end);
        }
    }
};

int main() {
    Solution solution;

    vector<vector<int>> graph = {{1,2},{3},{3},{}};
    vector<vector<int>> res = solution.allPathsSourceTarget(graph);
    for(auto paths:res){
        for(auto n:paths){
            cout<<n<<"->";
        }
        cout<<endl;
    }

    // Write your main logic here

    return 0;
}