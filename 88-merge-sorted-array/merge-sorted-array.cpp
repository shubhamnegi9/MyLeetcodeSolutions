class Solution {
public:
    
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> mergedNums;

        int p1 = 0, p2 = 0;

        while(p1 < m && p2 < n) {
            if(nums1[p1] <= nums2[p2]) {
                mergedNums.push_back(nums1[p1]);
                p1++;
            } else {
                mergedNums.push_back(nums2[p2]);
                p2++;
            }
        }

        while(p1 < m) {
            mergedNums.push_back(nums1[p1]);
            p1++;
        }
        while(p2 < n) {
            mergedNums.push_back(nums2[p2]);
            p2++;
        }

        nums1 = mergedNums;
    }

    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m > 0 && n > 0) {
            int p1 = m-1, p2 = 0;
            while(p1 >= 0 && p2 < n) {
                if(nums1[p1] > nums2[p2]) {
                    swap(nums1[p1], nums2[p2]);
                    p1--;
                    p2++;
                } else {
                    break;
                }
            }

            sort(nums1.begin(), nums1.begin()+m);
            sort(nums2.begin(), nums2.end());

            for(int i = m; i < m+n; i++) {
                nums1[i] = nums2[i-m];
            }
        }
        else if(n > 0) {
            nums1 = nums2;
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // return merge1(nums1, m, nums2, n);

        return merge2(nums1, m, nums2, n);
    }
};