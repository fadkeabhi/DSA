#include <iostream>
#include <vector>

using namespace std;

int x, y;

int f(vector<int> A)
{
    if (A.size() == 0)
        return 0;

    int yCost = A.size() * y;

    // find min in array
    int mini = A[0];
    for (int i : A)
    {
        if (i < mini)
            mini = i;
    }

    // reduce min form all
    for (int i = 0; i < A.size(); i++)
    {
        A[i] -= mini;
    }
    int xCost = mini * x;

    // break arrays into subarray
    vector<int> t;
    for (int i : A)
    {
        if (i == 0)
        {
            xCost += f(t);
            t.clear();
        }
        else
        {
            t.push_back(i);
        }
    }
    xCost += f(t);
    t.clear();

    return min(xCost, yCost);
}

// Incomplete function
int minCost(int N, int X, int Y, std::vector<int> &A)
{
    // TODO: implement this function
    x = X, y = Y;
    return f(A);
}

int main()
{
    // Test Case 1
    int N1 = 1, X1 = 1, Y1 = 10;
    std::vector<int> A1 = {1};
    std::cout << "Test Case 1: " << minCost(N1, X1, Y1, A1) << std::endl;

    // Test Case 2
    int N2 = 3, X2 = 3, Y2 = 2;
    std::vector<int> A2 = {1, 2, 3};
    std::cout << "Test Case 2: " << minCost(N2, X2, Y2, A2) << std::endl;

    // Test Case 3
    int N3 = 5, X3 = 2, Y3 = 5;
    std::vector<int> A3 = {1, 2, 3, 4, 5};
    std::cout << "Test Case 3: " << minCost(N3, X3, Y3, A3) << std::endl;

    return 0;
}