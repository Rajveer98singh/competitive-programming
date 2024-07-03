#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums,target,0,nums.size()-1);
    }

    int binarySearch(vector<int> v,int target,int low,int high){
        if(low<=high){
            int mid = low + (high - low)/2;
            if(v[mid] == target) return mid;
            if(v[mid] > target){
                return binarySearch(v,target,low,mid-1);
            }else{
                return binarySearch(v,target,mid+1,high);
            }
        }
        return -1;
    }
};

int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9,10,11,12};
    int target = 11;

    Solution solution;

    cout<< solution.search(v,target)<<endl;


    return 0;
}