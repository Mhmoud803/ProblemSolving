class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.length();
        // Array of vectors to store indices of occurrences for each of the 26 letters
        vector<int> char_indices[26];
        
        // Initialize all letters with the left boundary (-1)
        for (int i = 0; i < 26; ++i) {
            char_indices[i].push_back(-1);
        }
        
        // Populate the actual indices
        for (int i = 0; i < n; ++i) {
            char_indices[s[i] - 'A'].push_back(i);
        }
        
        int total_unique_chars = 0;
        
        // Calculate contribution for each character
        for (int i = 0; i < 26; ++i) {
            // Add the right boundary (n)
            char_indices[i].push_back(n);
            
            // Loop through actual occurrences (skipping the -1 and n boundaries)
            for (int j = 1; j < char_indices[i].size() - 1; ++j) {
                int left_choices = char_indices[i][j] - char_indices[i][j - 1];
                int right_choices = char_indices[i][j + 1] - char_indices[i][j];
                
                total_unique_chars += left_choices * right_choices;
            }
        }
        
        return total_unique_chars;
        
    }
};