#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (map.count(complement))
            {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    vector<int> nums = {2,7,11,15};
    int target = 9;
    Solution solution;
    
    vector<int> response =  solution.twoSum(nums, target);
    for(int i = 0; i < response.size(); i++){
        if(i==0){
            cout << "[";
        }
        cout << response[i];
        if(i!=response.size()-1){
            cout << ",";
        }else{
            cout << "]"<<endl;
        }
    }
    return 0;
}