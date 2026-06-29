class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlen = 0;

        // Try every starting index
        for (int i = 0; i < n; i++) {
            vector<int> hash(26, 0); // frequency array for A–Z
            int maxf = 0;            // max frequency in current substring

            // Expand substring from i to j
            for (int j = i; j < n; j++) {
                hash[s[j] - 'A']++;                  // count character
                maxf = max(maxf, hash[s[j] - 'A']); // update max frequency

                int change = (j - i + 1) - maxf;    // replacements needed
                if (change <= k) {
                    maxlen = max(maxlen, j - i + 1);
                } else {
                    break; // stop expanding if replacements exceed k
                }
            }
        }

        return maxlen;
    }
};
