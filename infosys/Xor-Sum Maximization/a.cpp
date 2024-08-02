#include <iostream>
#include <vector>

using namespace std;


// Function to be completed
int maximizeXorSum(int N, int K, std::vector<int>& A) {
    // Your code here
    // brute force approach
    int ans = 0;
    for(int x=0; x<=K; x++){
        int temp = 0;
        for(int i=0; i<N; i++){
            temp += x ^ A[i];
        }
        ans = max(ans, temp);
    }

    return ans;
}

int main() {
    // Test Case 1
    std::vector<int> A1 = {1, 2, 3};
    int N1 = 3, K1 = 3;
    std::cout << "Test Case 1: " << maximizeXorSum(N1, K1, A1) << std::endl;

    // Test Case 2
    std::vector<int> A2 = {4, 5, 6};
    int N2 = 3, K2 = 6;
    std::cout << "Test Case 2: " << maximizeXorSum(N2, K2, A2) << std::endl;

    // Test Case 3
    std::vector<int> A3 = {1, 1, 1};
    int N3 = 3, K3 = 1;
    std::cout << "Test Case 3: " << maximizeXorSum(N3, K3, A3) << std::endl;
    
    // Test Case 4
    std::vector<int> A4 = {989898};
    int N4 = 1, K4 = 0;
    std::cout << "Test Case 3: " << maximizeXorSum(N4, K4, A4) << std::endl;

    return 0;
}