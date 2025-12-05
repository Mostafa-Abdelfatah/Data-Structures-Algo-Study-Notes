#include "../includes.h"

using namespace std;
/**
 * problem link: https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 *
 * idea: let I have an array of length 10
 *       arr={1,2,2,4,4,4,4,5,5,6};
 *       so what it the max frequently of a number can be is 10 which is the lenght
 *       so we can create
 *       vector<vector<int>> freq(10 + 1);
 *       0  ,   1,  2,  3,  4,  5,  6,  7,  8,  9,  10    <- those are the index mean that the number in them frequently with this index
 *              1   2       4
 *              6   5
 *
 *       this means
 *       no number occurs 0 time
 *       1,6 occur 1 time  {1,6}
 *       2,5 occur 2 times {2,2,5,5}
 *       no number occurs 3 times
 *       4 occurs 4 times {4,4,4,4}
 *       it is like the reverse of frequently array
 *
 *
 * */

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    for(auto i: nums){
        mp[i]++;
    }
    vector<vector<int>> freq(nums.size() + 1);
    for(auto it : mp){
        freq[it.second].push_back(it.first);
    }
    vector<int> ans;
    for(int i = freq.size() - 1; i >= 0; i--){
        for(auto n : freq[i]){
            ans.push_back(n);
            if(ans.size() == k){
                return ans;
            }
        }
    }
    return ans;
}

