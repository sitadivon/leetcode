class MySolution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> return_vec;
        vector<string> temp_vec;
        auto cons_map = constructMap(strs);
        auto map_iter = cons_map.cbegin();
        auto next_iter = map_iter;            // Add3: use val after definition!
        if(map_iter != cons_map.cend()){
            // auto next_iter = map_iter + 1; // Modify1: Only string & vector can use +  +=  -  > operators.
            // auto next_iter = map_iter;     // Delete3:
            ++next_iter;
            // temp_vec = {strs[0]};          // Modify4: The first string to be pushed into the vec should be the first entry of the constructed map, instead of the original raw vector.
            temp_vec = {map_iter->second};
        }
        else
            return return_vec;
        while(next_iter != cons_map.cend()){
            if(next_iter->first != map_iter->first){
                return_vec.push_back(temp_vec);
                temp_vec = {next_iter->second};
                map_iter = next_iter;
            }
            else{
                temp_vec.push_back(next_iter->second);
            }
            ++next_iter;
        }
        return_vec.push_back(temp_vec);             // Add5: After the last iteration, the last vec<str> should be push.
        return return_vec;
    }
private:
    multimap<multiset<char>, string> constructMap(vector<string>& strs){
        multimap<multiset<char>, string> cons_map;
        // multi_map<multi_set<char>, string> cons_map; // Modify2: no underline after 'multi' keyword.
        for(string s:strs){
            multiset<char> char_set;
            for(char ch:s){
                char_set.insert(ch);
            }
            cons_map.insert({char_set, s});
        }
        return cons_map;
    }
};

class BestSolution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> hashmap;
        int k = 0;
        vector<string> s = strs;
        for (int i = 0; i<s.size(); ++i){
            sort(s[i].begin(), s[i].end());
            if (!hashmap.count(s[i])){
                hashmap[s[i]] = k++;
                res.push_back(vector<string>{});
            }
            res[hashmap[s[i]]].push_back(strs[i]);
        }
        return res;
    }
};
/* 
    Note:
        1. Combine construct hash table operation & element insertion.
        2. String is comparable inherently.
        3. use k as index, instead of string. Index always promotes performance.
*/