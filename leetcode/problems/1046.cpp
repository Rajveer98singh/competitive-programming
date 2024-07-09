#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int i=0;i<stones.size();i++){
            maxHeap.push(stones[i]);
        }
        while(maxHeap.size() >1){
            int first = maxHeap.top();
            maxHeap.pop();
            int secont = maxHeap.top();
            maxHeap.pop();
            int res = abs(first-secont);
            if(res != 0){
                maxHeap.push(res);
            }
        }
        if(maxHeap.size() ==1){
            return maxHeap.top();
        }else{
            return 0;
        }
    }
};

int main() {
    Solution solution;
    vector<int> stones = {2,7,4,1,8,1};
    cout << solution.lastStoneWeight(stones) << endl;

    // Write your main logic here

    return 0;
}