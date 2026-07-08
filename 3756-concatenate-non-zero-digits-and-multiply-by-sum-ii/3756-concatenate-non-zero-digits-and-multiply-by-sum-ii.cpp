class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1e9 + 7;
        
        // Precompute powers of 10 modulo 10^9 + 7
        vector<long long> p10(m + 1, 1);
        for (int i = 1; i <= m; ++i) {
            p10[i] = (p10[i - 1] * 10) % MOD;
        }
        
        // Prefix arrays (1-indexed for easier math)
        vector<int> cnt(m + 1, 0);
        vector<long long> pref_sum(m + 1, 0);
        vector<long long> val(m + 1, 0);
        
        for (int i = 0; i < m; ++i) {
            int d = s[i] - '0';
            if (d != 0) {
                cnt[i + 1] = cnt[i] + 1;
                pref_sum[i + 1] = pref_sum[i] + d;
                val[i + 1] = (val[i] * 10 + d) % MOD;
            } else {
                // Zeros are ignored, so the states simply carry over
                cnt[i + 1] = cnt[i];
                pref_sum[i + 1] = pref_sum[i];
                val[i + 1] = val[i];
            }
        }
        
        vector<int> ans;
        ans.reserve(queries.size()); // Pre-allocate memory for performance
        
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            
            // Number of non-zero digits in this range
            int length = cnt[r + 1] - cnt[l];
            
            // Sum of non-zero digits in this range
            long long S = pref_sum[r + 1] - pref_sum[l];
            
            // The concatenated value of non-zero digits in this range
            long long X = (val[r + 1] - (val[l] * p10[length]) % MOD) % MOD;
            
            // Strictly handle negative modulo results in C++
            X = (X + MOD) % MOD;
            
            // Final result for the query
            ans.push_back((X * S) % MOD);
        }
        
        return ans;
    }
};