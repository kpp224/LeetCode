class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct = nums[0];
        int prod = 1;

        for(int i = 0; i < n; i++){
            prod *= nums[i];
            maxProduct = max(maxProduct, prod);

            if(prod == 0){
                prod = 1;
            }
        }

        prod = 1;

        for(int i = n-1; i >= 0; i--){
            prod *= nums[i];
            maxProduct = max(maxProduct, prod);

            if(prod == 0){
                prod = 1;
            }
        }

        return maxProduct;
    }
};