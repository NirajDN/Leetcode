 
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalTime = 0; // Initialize the total time to 0
        int i = 0, j = 0; // Initialize two pointers i and j

        // Loop until either pointer reaches the end of the 'neededTime' array
        while (i < neededTime.size() && j < neededTime.size()) {
            int currTotal = 0, currMax = 0; // Initialize variables to calculate current total and maximum time

            // Find all the balloons having the same color as the balloon indexed at i
            while (j < neededTime.size() && colors[i] == colors[j]) {
                currTotal += neededTime[j]; // Accumulate total removal time for the same color group
                currMax = max(currMax, neededTime[j]); // Track maximum removal time within the group
                j++; // Move the pointer to the next balloon
            }

            // Once the end of the current color group is reached, add the cost of this group to totalTime
            totalTime += currTotal - currMax; // Deduct the maximum removal time from the total removal time
            i = j; // Move the starting pointer to the next color group
        }
        return totalTime; // Return the calculated total time
    }
};

