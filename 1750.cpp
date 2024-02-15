#include <iostream>
#include <unordered_set>
#include <string>

bool same_character_type(const std::string& string1, const std::string& string2) {
    // Convert strings to sets of characters
    std::unordered_set<char> set1(string1.begin(), string1.end());
    std::unordered_set<char> set2(string2.begin(), string2.end());
    
    // Check if the sets have only one element, meaning they contain the same type of character
    return set1.size() == 1 && set2.size() == 1;
}

int main() {
    std::string a = "aaaaaaaaaaaaaaaaa";
    std::string b = "aa";

    if (same_character_type(a, b)) {
        std::cout << "Both strings contain only the same type of character." << std::endl;
    } else {
        std::cout << "Strings contain different types of characters." << std::endl;
    }

    return 0;
}
