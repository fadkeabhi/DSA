#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Function to be completed

int k;
int ans = 0;

void printarr(vector<set<int>> arr)
{
    // print arr to test working
    for (set<int> s : arr)
    {
        for (int num : s)
        {
            cout << num << " ";
        }
        cout << std::endl;
    }
}

void f(vector<set<int>> arr, int n, int value)
{
    if (arr.size() <= k)
    {
        ans = max(value, ans);
        return;
    }
    if (n <= 0)
        return;
    // not take condition
    f(arr, n - 1, value);

    // take condition
    int oldValue = arr[n].size() + arr[n - 1].size();
    // add all elements from n to n-1
    for (int i : arr[n])
    {
        arr[n - 1].insert(i);
    }
    // delete arr[n]
    arr.erase(arr.begin() + n);
    int newValue = arr[n - 1].size();

    // call recursive function
    f(arr, n - 1, value - (oldValue - newValue));
}

int maximizeValue(int N, int K, std::vector<int> &A)
{
    ans = 0;
    // Your code here
    k = K;

    // split array into set with unique elements
    vector<set<int>> arr;
    set<int> temp;
    for (int i : A)
    {
        // check if i in curr set
        if (temp.find(i) == temp.end())
        {
            // not in set
            temp.insert(i);
        }
        else
        {
            // in set
            arr.push_back(temp);
            temp.clear();
            temp.insert(i);
        }
    }
    arr.push_back(temp);
    temp.clear();

    int currValue = 0;
    for (auto i : arr)
    {
        currValue += i.size();
    }

    f(arr, arr.size() - 1, currValue);

    return ans;
}

int main()
{
    // Test Case 1 ans = 5
    std::vector<int> A1 = {1, 2, 3, 2, 1};
    int N1 = 5, K1 = 3;
    std::cout << "Test Case 1: " << maximizeValue(N1, K1, A1) << std::endl;

    // Test Case 2 ans = 1
    std::vector<int> A2 = {1, 1, 1, 1, 1};
    int N2 = 5, K2 = 1;
    std::cout << "Test Case 2: " << maximizeValue(N2, K2, A2) << std::endl;

    // Test Case 3 ans = 5
    std::vector<int> A3 = {1, 2, 3, 4, 5};
    int N3 = 5, K3 = 5;
    std::cout << "Test Case 3: " << maximizeValue(N3, K3, A3) << std::endl;

    // Test Case 4 ans = 5
    std::vector<int> A4 = {1, 1, 2, 2, 3, 3};
    int N4 = 6, K4 = 3;
    std::cout << "Test Case 4: " << maximizeValue(N4, K4, A4) << std::endl;

    // Test Case 5 ans = 4
    std::vector<int> A5 = {1, 2, 2, 3, 3, 3};
    int N5 = 6, K5 = 2;
    std::cout << "Test Case 5: " << maximizeValue(N5, K5, A5) << std::endl;

    // Test Case 6 ans = 3
    std::vector<int> A6 = {1, 1, 1, 2, 2, 2};
    int N6 = 6, K6 = 2;
    std::cout << "Test Case 6: " << maximizeValue(N6, K6, A6) << std::endl;

    // Test Case 7 ans = 6
    std::vector<int> A7 = {1, 2, 3, 4, 5, 6};
    int N7 = 6, K7 = 1;
    std::cout << "Test Case 7: " << maximizeValue(N7, K7, A7) << std::endl;

    // Test Case 8 ans = 6
    std::vector<int> A8 = {1, 1, 1, 1, 1, 1};
    int N8 = 6, K8 = 6;
    std::cout << "Test Case 8: " << maximizeValue(N8, K8, A8) << std::endl;

    return 0;
}
