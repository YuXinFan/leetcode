#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target);
};

vector<int> Solution::twoSum(vector<int>& nums, int target)
{   
    map<int, int> hash;
    std::vector<int> result;
    for(int i = 0; i < nums.size(); i++)
    {
        hash[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        int value = target - nums[i];
        if (hash.find(value) != hash.end() && hash[value] != i)
        {
            result.push_back(i);
            result.push_back(hash[value]);
            return result;
        }
    }

}

int main()
{
    return 0;
}