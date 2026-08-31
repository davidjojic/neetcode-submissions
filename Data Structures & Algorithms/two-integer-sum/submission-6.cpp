class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>v(nums.size());      
        for(int i =0;i<nums.size();i++){
            v[i] = {nums[i],i};
        }
        sort(v.begin(),v.end());
        vector<int>sol;
        int minimum = numeric_limits<int>::max();
        int i = 0, j = nums.size()-1;
        while(i<j){
            if(v[i].first + v[j].first == target){
                    sol.push_back(min(v[i].second,v[j].second));
                    sol.push_back(max(v[i].second,v[j].second));
                    return sol;
                
                i++;
                j--;
            }else if(v[i].first + v[j].first > target){
                j--;
            }else{
                i++;
            }
        
            
        }
        return sol;
    }
};
