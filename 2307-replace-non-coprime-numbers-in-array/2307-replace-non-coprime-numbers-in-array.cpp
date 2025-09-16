class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result;
        for(int &i:nums) {
            result.push_back(i);        // Push the new element in stack.
            while(result.size()>1&&__gcd(result.back(),result[result.size()-2])>1) {    // While we have two elements and they are not co-prime.
                long long a=result.back(),b=result[result.size()-2],g=__gcd(a,b);  // Get the last two numbers in the stack and their GCD.
                
                // Remove the two elements.
                result.pop_back();      
                result.pop_back();
                result.push_back(a*b/g); // Push the LCM of the two numbers, replacing them.
            }
        }
        return result;
    }
};