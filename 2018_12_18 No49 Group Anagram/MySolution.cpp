class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> return_vec;
        vector<string> temp_vec;
        auto cons_map = constructMap(strs);
        auto map_iter = cons_map.cbegin();
        auto next_iter = map_iter;            // Add3:
        if(map_iter != cons_map.cend()){
            // auto next_iter = map_iter + 1; // Modify1:
            // auto next_iter = map_iter;     // Delete3:
            ++next_iter;
            // temp_vec = {strs[0]};          // Modify4:
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
        return_vec.push_back(temp_vec);             // Add5:
        return return_vec;
    }
private:
    multimap<multiset<char>, string> constructMap(vector<string>& strs){
        multimap<multiset<char>, string> cons_map;
        // multi_map<multi_set<char>, string> cons_map; // Modify2:
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