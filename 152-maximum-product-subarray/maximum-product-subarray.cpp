class Solution {
public:
    // Brute Force
    // T.C. = O(n^2)
    // S.C. = O(1)
    int maxProduct1(vector<int>& nums) {
        int n = nums.size();
        int maxProd = INT_MIN;
        for(int i = 0; i < n; i++) {
            int prod = 1;
            for(int j = i; j < n; j++) {
                prod *= nums[j];
                maxProd = max(maxProd, prod);
            }
        }
        return maxProd;
    }

    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(1)
    int maxProduct2(vector<int>& nums) {
        int n = nums.size();
        int maxProd = INT_MIN;
        int prefixProd = 1, suffixProd = 1;

        for(int i = 0; i < n; i++) {
            if(prefixProd == 0)
                prefixProd = 1;
            if(suffixProd == 0)
                suffixProd = 1;

            prefixProd *= nums[i];
            suffixProd *= nums[n-1-i];
            maxProd = max(maxProd, max(prefixProd, suffixProd));
        }

        return maxProd;
    }
    
    int maxProduct(vector<int>& nums) {
        // Brute Force
        // return maxProduct1(nums);

        // Optimal Approach
        return maxProduct2(nums);
    }
};