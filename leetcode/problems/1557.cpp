#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // find nodes which have indegree zero, because the elements or node which 
        // have indegree more than 1 can be reached from other nodes
        vector<int> inDegree (n,0);
        for(int i=0;i<edges.size();i++){
            inDegree[edges[i][1]]++;
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0)res.push_back(i);
        }
        return res;
    }

};

int main() {
    Solution solution;

    int n = 6;
    vector<vector<int> > edges = {{0,1},{0,2},{2,5},{3,4},{4,2}};
    vector<int> res = solution.findSmallestSetOfVertices(n,edges);
    for(int i =0;i<res.size();i++){
        cout<< res[i]<<" ";
    }
    cout<<endl;
    // Write your main logic here

    return 0;
}