#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool searchMatrix(vector<vector<int> > matrix, int target){
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        while(row<m-1){
            if(target >=  matrix[row][0] && target <= matrix[row][n-1]){
                break;
            }
            row++;
        }
        return binarySearch(matrix[row],target,0,n-1);
    }

private:
    bool binarySearch(vector<int> v, int target,int low,int high){
        if(low<=high){
            int mid = low + (high-low) / 2;
            if(target == v[mid]){
                return true;
            }
            if(v[mid] >= target){
                return binarySearch(v,target,low,mid-1);
            }else{
                return binarySearch(v,target,mid+1,high);
            }
        }
        return false;
    }
};

int main(){
    Solution solution;

    vector<vector<int> > v = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 60;
    
    bool res = solution.searchMatrix(v, target);
    if(res){
        cout<< "74. Search a 2D Matrix: true"<<endl;
    }else{
        cout<< "74. Search a 2D Matrix: false"<<endl;
    }

    return 0;
}

// 74. Search a 2D Matrix

// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

 

// Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true


// Example 2:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false