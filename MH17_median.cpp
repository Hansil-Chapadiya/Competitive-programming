#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;

        // Combine the elements of nums1 and nums2 into a single vector
        for (int i = 0; i < nums1.size(); i++) {
            v.push_back(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++) {
            v.push_back(nums2[i]);
        }

        sort(v.begin(), v.end());

        int len = v.size();
        double median = 0.0;

        if (len % 2 == 0) {
            median = (v[len / 2 - 1] + v[len / 2]) / 2.0;
        } else {
            median = v[len / 2];
        }

        return median;
    }
};

int main() {
    Solution s1;
    vector<int> v1 = {};
    vector<int> v2 = {5,2};

    double median = s1.findMedianSortedArrays(v1, v2);
    cout << "Median: " << median << endl;

    return 0;
}
