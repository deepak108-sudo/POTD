//--------------------t.c: O(1)-----------
//--------------------s.c: O(1)-----------

class Solution {
public:
    string triangleType(vector<int>& nums) {

        // bool isValid=nums[0]+nums[1]>nums[2] && nums[1]+nums[2]>nums[0] && nums[0]+nums[2]>nums[1];
        
        //-------------Reduce condition by sorting
        sort(begin(nums),end(nums));
        if(!(nums[0]+nums[1]>nums[2])) return "none";   //a+c>b and b+c>a is already true

        if(nums[0]==nums[1]&& nums[1]==nums[2])
        {
            return "equilateral";
        }
        else if(nums[0]!=nums[1] && nums[1]!=nums[2] && nums[0]!=nums[2])
        {
            return "scalene";
        }
        else{
            return "isosceles"; 
        }
    }
};