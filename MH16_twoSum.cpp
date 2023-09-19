#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v1;
        for(int i=0;i<nums.size();i++){
            for (int j = i+1; j < nums.size(); j++)
            {
                int ans = (nums[i] + nums[j]);
                if (ans == target)
                {
                    v1.push_back(i);
                    return v1;
                    exit(0);
                }
            }
        }
        return;
    }
};
int main()
{
    Solution s1;
    vector<int> v1;
    v1.push_back(8);
    v1.push_back(2);
    v1.push_back(3);
    v1 = s1.twoSum(v1,10);
    for (int i = 0; i < v1.size(); i++)
    {
        cout<<v1[i]<<" ";
    }

}
