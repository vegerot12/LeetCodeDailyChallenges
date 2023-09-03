class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool is_word;
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        auto root = buildTrie(dictionary);
        unordered_map<int, int> memo;
        memo[n] = 0;
        // The overall logic of the dp function is to consider both options: including the current character as part of a word from the dictionary (which might lead to no extra characters needed) and excluding the current character as an extra character. By taking the minimum of these two options, the function calculates the minimum number of extra characters needed to construct the string s using words from the dictionary.

        function<int(int)> dp = [&](int start) {
           
            if (memo.count(start)) {
                return memo[start];
            }

            // we have two choices - to include this char and try to find a word or to exclude this char and try to find a word

            // To count this character as a left over character 
            // move to index 'start + 1'
            int ans = dp(start + 1) + 1; // 1. find sol excluding this char meaning consider this char as extra char  -- + 1 is added to the result of dp(start + 1) because we are considering the current character as an extra character, meaning we are not using it to form any valid word from the dictionary. So, we are incrementing the count of extra characters by 1.

            TrieNode* node = root;
            for (int end = start; end < n; end++) {
                char c = s[end];
                // if. no word is in trie with this prefix we break , and return ans 
                if (node->children.find(c) == node->children.end()) {
                    break;
                }
                // if we found a prefix
                // we keep moving end ptr as long as it matches a word fully 
                node = node->children[c];
                // if word matched then find the answer for dp starting from next char of the word end -- cur word ends at end so start from end+1 and dp.
                // we compare current ans(consider cur start as extra char) and that ans( not considering cur char as extra and including it in word)
                if (node->is_word) {
                    ans = min(ans, dp(end + 1));
                }
            }
// memoise the updated ans 
            return memo[start] = ans;
        };

        return dp(0); // Function call intial 
    }

    TrieNode* buildTrie(vector<string>& dictionary) {
        auto root = new TrieNode();
        for (auto& word : dictionary) {
            auto node = root;
            for (auto& c : word) {
                if (node->children.find(c) == node->children.end()) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->is_word = true;
        }
        return root;
    }
};