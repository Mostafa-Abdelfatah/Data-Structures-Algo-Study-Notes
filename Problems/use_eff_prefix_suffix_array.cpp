#include "../includes.h"

using namespace std;

/**
 * problem link:https://leetcode.com/problems/product-of-array-except-self/
 * this problem I need too use like
 * if I have {1,2,3,4}
 * then at index = 2 {3}
 * I need the product on the left which called prefix = 2
 * I need the product on the right which called sufix = 4
 * and at ans[2] = 2 * 4;
 * and not use division
 * */


vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans;
    ans.push_back(nums[0]);
    for(int i = 1; i < nums.size(); i++){
        ans.push_back(ans[i -1] * nums[i]);
    }
    int right = 1;
    for(int i = nums.size() -1; i>=0; i--){
        if(i == 0){
            ans[i] = right;
        }
        else {
            ans[i] = right * ans[i - 1];
            right *= nums[i];
        }
    }
    return ans;
}
