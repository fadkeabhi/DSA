#include <iostream>
#include <vector>
#include <set>

using namespace std;

int ans, k;
int costOfSegment(vector<int> arr);

void printarr(vector<vector<int>> arr)
{
    // print arr to test working
    for (vector<int> s : arr)
    {
        for (int num : s)
        {
            cout << num << " ";
        }
        cout << "cost" << costOfSegment(s);
        cout << std::endl;
    }
}

int costOfSegment(vector<int> arr)
{
    int cost = 0;
    set<int> counted;
    for (int i = 0; i < arr.size(); i++)
    {
        if (counted.find(arr[i]) == counted.end())
        {
            counted.insert(arr[i]);
            // element is not counted
            // find last occurance of element
            int pos;
            for (int j = arr.size() - 1; j > -1; j--)
            {
                if (arr[j] == arr[i])
                {
                    pos = j;
                    break;
                }
            }
            if (i != pos)
            {
                // first and last occurance is not same
                cost += pos - i;
            }
        }
    }
    return cost;
}

void f(vector<vector<int>> arr, int n, int value)
{

    // printarr(arr);
    if (arr.size() <= k)
    {
        ans = min(value, ans);
        return;
    }
    if (n <= 0)
        return;
    // not take condition
    f(arr, n - 1, value);

    // take condition
    int oldValue = costOfSegment(arr[n]) + costOfSegment(arr[n - 1]);
    // add all elements from n to n-1
    for (int i : arr[n])
    {
        arr[n - 1].push_back(i);
    }
    // delete arr[n]
    arr.erase(arr.begin() + n);
    int newValue = costOfSegment(arr[n - 1]);

    // call recursive function
    f(arr, n - 1, value - (oldValue - newValue));
}

// Function to be completed
int minSegmentCost(int N, int K, std::vector<int> &A)
{
    // Your code here

    ans = INT16_MAX;
    k = K;
    vector<vector<int>> arr;
    set<int> tempSet;
    vector<int> tempVec;
    for (int i : A)
    {
        // check if i in curr set
        if (tempSet.find(i) == tempSet.end())
        {
            // not in set
            tempSet.insert(i);
            tempVec.push_back(i);
        }
        else
        {
            // in set
            arr.push_back(tempVec);
            tempSet.clear();
            tempSet.insert(i);
            tempVec.clear();
            tempVec.push_back(i);
        }
    }
    arr.push_back(tempVec);
    tempVec.clear();
    tempSet.clear();

    // printarr(arr);

    int currCost = 0;
    for (auto i : arr)
    {
        currCost += costOfSegment(i);
    }

    f(arr, arr.size() - 1, currCost);

    return ans;
}

int main()
{
    // Test Case 1
    std::vector<int> a1 = {1, 2, 3, 2, 1};
    int N1 = 5, K1 = 3;
    std::cout << "Test Case 1: " << minSegmentCost(N1, K1, a1) << std::endl;

    // Test Case 2
    std::vector<int> a2 = {4, 5, 6, 5, 4};
    int N2 = 5, K2 = 2;
    std::cout << "Test Case 2: " << minSegmentCost(N2, K2, a2) << std::endl;

    // Test Case 3
    std::vector<int> a3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int N3 = 10, K3 = 5;
    std::cout << "Test Case 3: " << minSegmentCost(N3, K3, a3) << std::endl;

    // Test Case 4
    std::vector<int> a4 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int N4 = 10, K4 = 5;
    std::cout << "Test Case 4: " << minSegmentCost(N4, K4, a4) << std::endl;

    // Test Case 5
    std::vector<int> a5 = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
    int N5 = 10, K5 = 2;
    std::cout << "Test Case 5: " << minSegmentCost(N5, K5, a5) << std::endl;

    // Test Case 6
    std::vector<int> a6 = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1};
    int N6 = 10, K6 = 3;
    std::cout << "Test Case 6: " << minSegmentCost(N6, K6, a6) << std::endl;

    // Test Case 7
    std::vector<int> a7 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int N7 = 10, K7 = 10;
    std::cout << "Test Case 7: " << minSegmentCost(N7, K7, a7) << std::endl;

    // Test Case 8
    std::vector<int> a8 = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    int N8 = 10, K8 = 10;
    std::cout << "Test Case 8: " << minSegmentCost(N8, K8, a8) << std::endl;

    // Test Case 9
    std::vector<int> a9 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int N9 = 15, K9 = 5;
    std::cout << "Test Case 9: " << minSegmentCost(N9, K9, a9) << std::endl;

    // Test Case 10
    std::vector<int> a10 = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int N10 = 15, K10 = 5;
    std::cout << "Test Case 10: " << minSegmentCost(N10, K10, a10) << std::endl;

    return 0;
}