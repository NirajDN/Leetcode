class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> res;
        
        init_maps(wordlist, queries);
        
        for (int i = 0; i < queries.size(); i++) {
            string lower = to_lower(queries[i]), no_vowels = remove_vowels(queries[i]);
            
            if (word_set.find(queries[i]) != word_set.end())
                res.push_back(queries[i]);
            
            else if (tolower_map.find(lower) != tolower_map.end())
                res.push_back(tolower_map[lower]);
            
            else if (no_vowel_map.find(no_vowels) != no_vowel_map.end())
                res.push_back(no_vowel_map[no_vowels]);
            
            else res.push_back("");
        }
        return res;
    }
    
private:
    unordered_set<string> word_set;
    unordered_map<string, string> tolower_map, no_vowel_map;
    
    // helper function to initialize maps
    void init_maps(vector<string>& wordlist, vector<string>& queries) {
        for (auto word : wordlist) {
            word_set.insert(word);
            tolower_map.insert({to_lower(word), word});
            no_vowel_map.insert({remove_vowels(word), word});
        }
    }
    
    // helper function to make string lower case
    string to_lower(string word) {
        for (auto& letter : word)
            letter = tolower(letter);
        return word;
    }
    
    // helper function to remove vowels from string and insert '-' instead
    string remove_vowels(string word) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        for (auto& letter : word) {
            if (vowels.find(letter) != vowels.end()) {
                letter = '-';
            }
        }
        return word;
    }
};