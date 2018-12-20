class FirstSolution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size();
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                if((nums[i] + nums[j]) == target)
                    return vector<int>{i, j};
            }
        }
    }
};

class SecondSolution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size();
        for(int i = 0; i < N; ++i){
            for(int j = i - 1; j >= 0; --j){
                if((nums[i] + nums[j]) == target)
                    return vector<int>{i, j};
            }
        }
    }
};

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        int N = nums.size();
        map<int, int> imap;
        for(int i = 0; i < N; ++i){
            auto result = imap.find(target - nums[i]);
            if(result != imap.end())
                return vector<int>{result->second, i};
            else
                imap[nums[i]] = i;
        }
    }
};