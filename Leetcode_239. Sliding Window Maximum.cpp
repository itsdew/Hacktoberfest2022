class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n= nums.size();
       
        vector<int> prefixMax(n, 0), suffixMax(n, 0);
        
        //creating the prefixMax array
        for(int i=0; i<n; i++){
            if(i%k==0) prefixMax[i]= nums[i]; //reset value 
            else prefixMax[i]= max(prefixMax[i-1], nums[i]);      
        }
        
        //creating the suffixMax array
        suffixMax[n-1]= nums[n-1];
        for(int i=n-2; i>=0; i--){
            if((i+1)%k==0) suffixMax[i]= nums[i]; //reset value
            else suffixMax[i]= max(suffixMax[i+1], nums[i]);
        }
        
        vector<int> ans(n-k+1, 0);
        
        for(int i=0; i<n-k+1; i++){
            ans[i]= max(prefixMax[i+k-1], suffixMax[i]);
        }
        
        return ans;
    }
};
