#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto num:nums){
            pq.push(num);
        }
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout<< solution.findKthLargest(nums,k)<<endl;
    // Write your main logic here

    return 0;
}