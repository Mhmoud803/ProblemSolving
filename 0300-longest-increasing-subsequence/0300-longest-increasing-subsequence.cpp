class Solution {
public:
    vector<int>v;
    int mem[2505][2505];
    int dp(int idx, int last){
        if(idx==v.size())
        return 0;


        int& ret = mem[idx][last];
        if(~ret)
        return ret;


        int sum1 =0;

        if(last>=(int)v.size() || v[idx]>v[last])
        sum1 = 1 + dp(idx+1,idx);



        int sum2 = dp(idx+1,last);

        return ret = max(sum1,sum2);
    }
    int lengthOfLIS(vector<int>& nums) {
        for(int i =0;i<nums.size()+1;i++){
            for(int j =0;j<nums.size()+1;j++){
                mem[i][j]=-1;
            }
        }
        v=nums;

        return dp(0,(int)v.size());
        
    }
};