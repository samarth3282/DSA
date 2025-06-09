#include <bits/stdc++.h>
using namespace std;

// Struct to store an item with value, weight and value-to-weight ratio
struct Item
{
    int value;
    int weight;
    double ratio;

    Item(int val, int wt)
    {
        value = val;
        weight = wt;
        ratio = (double)val / wt;
    }
};

// ✅ Brute Force Approach (Try all combinations) - Recursion
// ❌ Not practical for large inputs
// Time Complexity: O(2^n)
// Space Complexity: O(n)
double fractionalKnapsackBruteRecursive(int index, int capacity, vector<Item> &items)
{
    if (index == items.size() || capacity == 0)
        return 0;

    // If item can be fully taken
    if (items[index].weight <= capacity)
    {
        double take = items[index].value + fractionalKnapsackBruteRecursive(index + 1, capacity - items[index].weight, items);
        double skip = fractionalKnapsackBruteRecursive(index + 1, capacity, items);
        return max(take, skip);
    }
    else
    {
        // Take fractional part
        double fraction = (double)capacity * items[index].ratio;
        return max(fraction, fractionalKnapsackBruteRecursive(index + 1, capacity, items));
    }
}

// ✅ Better Approach (Greedy using pair & sorting, no struct)
// Time Complexity: O(n log n)
// Space Complexity: O(n)
double fractionalKnapsackBetter(vector<int> &values, vector<int> &weights, int capacity)
{
    int n = values.size();
    vector<pair<double, int>> ratioIndexPairs;

    for (int i = 0; i < n; i++)
    {
        ratioIndexPairs.push_back({(double)values[i] / weights[i], i});
    }

    sort(ratioIndexPairs.rbegin(), ratioIndexPairs.rend()); // Sort by ratio descending

    double totalValue = 0.0;

    for (int i = 0; i < n && capacity > 0; i++)
    {
        int idx = ratioIndexPairs[i].second;
        if (weights[idx] <= capacity)
        {
            totalValue += values[idx];
            capacity -= weights[idx];
        }
        else
        {
            totalValue += (double)capacity * ((double)values[idx] / weights[idx]);
            break;
        }
    }

    return totalValue;
}

// ✅ Optimal Approach (Using custom struct and better readability)
// Time Complexity: O(n log n)
// Space Complexity: O(n)
double fractionalKnapsackOptimal(vector<int> &values, vector<int> &weights, int capacity)
{
    int n = values.size();
    vector<Item> items;

    for (int i = 0; i < n; i++)
    {
        items.emplace_back(values[i], weights[i]);
    }

    // Sort items by value-to-weight ratio in descending order
    sort(items.begin(), items.end(), [](Item &a, Item &b)
         { return a.ratio > b.ratio; });

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    for (Item &item : items)
    {
        if (item.weight <= remainingCapacity)
        {
            totalValue += item.value;
            remainingCapacity -= item.weight;
        }
        else
        {
            totalValue += remainingCapacity * item.ratio;
            break;
        }
    }

    return totalValue;
}

// 🔍 Utility function to run test cases
void runTestCases()
{
    vector<vector<int>> testValues = {
        {60, 100, 120},
        {10, 20, 30},
        {5, 10, 15}};

    vector<vector<int>> testWeights = {
        {10, 20, 30},
        {1, 1, 1},
        {10, 20, 30}};

    vector<int> testCapacities = {
        50, 2, 25};

    for (int i = 0; i < testValues.size(); i++)
    {
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Values: ";
        for (int v : testValues[i])
            cout << v << " ";
        cout << "\nWeights: ";
        for (int w : testWeights[i])
            cout << w << " ";
        cout << "\nCapacity: " << testCapacities[i] << "\n";

        double result = fractionalKnapsackOptimal(testValues[i], testWeights[i], testCapacities[i]);
        cout << "Max value in knapsack: " << fixed << setprecision(4) << result << "\n\n";
    }
}

int main()
{
    runTestCases();
    return 0;
}
