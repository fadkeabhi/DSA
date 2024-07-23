#include <iostream>
#include <map>

int main() {
    // Create a map with key-value pairs of type int and string
    std::map<int, std::string> myMap;

    // Add elements to the map
    myMap[1] = "Apple";
    myMap[2] = "Banana";
    myMap[3] = "Orange";

    // Iterate over the map using an iterator
    for (auto it = myMap.begin(); it != myMap.end(); it++) {
        int key = it->first;
        std::string value = it->second;
        std::cout << "Key: " << key << ", Value: " << value << std::endl;
    }

    auto it = myMap.begin();
    auto next = ++it;
    --it;
    std::cout<<it->first;
    std::cout<<next->first;


    return 0;
}