#include <bits/stdc++.h>
using namespace std;

// ✅ Brute-force Approach:
// Use vector for memory and usage tracking. On every request, search linearly in both.
// Time: O(n * c), where n = #pageRequests, c = capacity
// Space: O(c)

int findPageIndexBrute(const vector<int> &memory, int page)
{
    for (int i = 0; i < memory.size(); i++)
    {
        if (memory[i] == page)
            return i;
    }
    return -1;
}

int lruPageReplacementBrute(const vector<int> &pageRequests, int capacity)
{
    vector<int> memory;       // Stores pages currently in memory
    vector<int> recentlyUsed; // Maintains access order, MRU at end
    int pageFaults = 0;

    for (int page : pageRequests)
    {
        int index = findPageIndexBrute(memory, page);

        if (index != -1)
        {
            // Page hit → update recent usage
            auto it = find(recentlyUsed.begin(), recentlyUsed.end(), page);
            recentlyUsed.erase(it);
            recentlyUsed.push_back(page);
        }
        else
        {
            // Page fault
            pageFaults++;

            if (memory.size() == capacity)
            {
                // Remove LRU page from memory
                int lruPage = recentlyUsed.front();
                recentlyUsed.erase(recentlyUsed.begin());
                memory.erase(find(memory.begin(), memory.end(), lruPage));
            }

            // Insert new page
            memory.push_back(page);
            recentlyUsed.push_back(page);
        }
    }

    return pageFaults;
}

// ✅ Better Approach using `list` + `unordered_map`
// Doubly linked list stores usage order (MRU at back)
// Hash map maps page number to iterator in list
// Time: O(n) overall due to O(1) access + erase + insert
// Space: O(c) for map and list

int lruPageReplacementBetter(const vector<int> &pageRequests, int capacity)
{
    unordered_map<int, list<int>::iterator> pageToIterator;
    list<int> usageList; // Front = LRU, Back = MRU
    int pageFaults = 0;

    for (int page : pageRequests)
    {
        // Page is already in memory (hit)
        if (pageToIterator.find(page) != pageToIterator.end())
        {
            usageList.erase(pageToIterator[page]); // Remove old position
        }
        else
        {
            // Page fault
            pageFaults++;

            // If memory is full, remove LRU page
            if (usageList.size() == capacity)
            {
                int lruPage = usageList.front();
                usageList.pop_front();
                pageToIterator.erase(lruPage);
            }
        }

        // Insert current page as most recently used
        usageList.push_back(page);
        pageToIterator[page] = prev(usageList.end());
    }

    return pageFaults;
}

// ✅ Optimal Approach using `LRU Cache` concept
// Encapsulate logic into class for reusability
// Time: O(n), Space: O(c)

class LRUCache
{
private:
    int capacity;
    list<int> usageList; // LRU to MRU
    unordered_map<int, list<int>::iterator> pageMap;

public:
    LRUCache(int cap)
    {
        capacity = cap;
    }

    int processRequests(const vector<int> &pageRequests)
    {
        int pageFaults = 0;

        for (int page : pageRequests)
        {
            if (pageMap.find(page) != pageMap.end())
            {
                // Page hit → move to MRU
                usageList.erase(pageMap[page]);
            }
            else
            {
                // Page fault
                pageFaults++;
                if (usageList.size() == capacity)
                {
                    int lruPage = usageList.front();
                    usageList.pop_front();
                    pageMap.erase(lruPage);
                }
            }

            usageList.push_back(page);
            pageMap[page] = prev(usageList.end());
        }

        return pageFaults;
    }
};

// ✅ Test Cases (Based on LeetCode-style problems)

void runTestCases()
{
    vector<pair<vector<int>, int>> tests = {
        {{1, 2, 3, 4, 2, 5}, 3},       // Basic LRU with faults
        {{1, 2, 1, 3, 1, 4}, 2},       // Repeated access pattern
        {{1, 2, 3, 1, 4, 5}, 4},       // Moderate size memory
        {{1, 1, 1, 1, 1}, 1},          // All same pages
        {{}, 3},                       // Empty request
        {{1, 2, 3, 4, 5}, 0},          // No memory capacity
        {{7, 0, 1, 2, 0, 3, 0, 4}, 4}, // Classic LRU problem
        {{1, 2, 3, 4, 5}, 5}           // No faults after fill
    };

    for (int i = 0; i < tests.size(); ++i)
    {
        const auto &[pages, capacity] = tests[i];
        int brute = lruPageReplacementBrute(pages, capacity);
        int better = lruPageReplacementBetter(pages, capacity);
        LRUCache optimal(capacity);
        int optimalResult = optimal.processRequests(pages);

        cout << "Test Case " << i + 1 << ": ";
        cout << "Brute = " << brute << ", Better = " << better << ", Optimal = " << optimalResult << "\n";

        assert(brute == better && better == optimalResult); // All should match
    }

    cout << "✅ All test cases passed!\n";
}

int main()
{
    runTestCases();
    return 0;
}
