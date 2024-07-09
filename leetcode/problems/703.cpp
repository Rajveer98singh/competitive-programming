#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int kth = 0;
    void KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>kth){
            pq.pop();
        }
        return pq.top();
    }
};

int main() {
    Solution solution;

    int k = 3;
    vector<int> nums = {4,5,8,2};
    solution.KthLargest(k, nums);
    cout<< solution.add(3)<<endl;
    cout<< solution.add(5)<<endl;
    cout<< solution.add(10)<<endl;
    cout<< solution.add(9)<<endl;
    cout<< solution.add(4)<<endl;

    // Write your main logic here

    return 0;
}