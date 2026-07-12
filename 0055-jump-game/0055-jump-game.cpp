class Solution {
public:
    int mem[10001];
    int n;
    vector<int>arr;

    bool dp(int idx){
        if(idx>=n-1)
        return true;

        int& ret  = mem[idx];
        if(~ret)
        return ret;

        for(int i =1;i<=arr[idx];i++){
            if (dp(idx + i)) {
                return ret = 1;
            }
        }
        return ret = 0;
    }

    bool canJump(vector<int>& nums) {
        n = nums.size();

        for(int i =0;i<10001;i++) mem[i]=-1;
        arr = nums;
        return dp (0);


        
    }
};