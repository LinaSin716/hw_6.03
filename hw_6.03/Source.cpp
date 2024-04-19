#include <iostream>
#include <chrono>
#include<fstream>

#include <set>
#include <string>
#include <vector>


std::string Transform_str(std::string word); // преобразование слова(в нижний регистр + избавление от знаков)

int main() {
    std::ifstream file;
    file.open("text.txt");

    auto start = std::chrono::system_clock::now();
    std::vector<std::string> arr;
    std::string word;
    while (file >> word)
    {
        word = Transform_str(word);
        if (std::find(arr.begin(), arr.end(), word) == arr.end()) {
            arr.push_back(word);
        }
    }
    auto end = std::chrono::system_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "vector:\nsize = " << arr.size() << "\ntime = " << time.count() << "\n\n";

    file.close();

    //========================================================================================

    file.open("text.txt");

    start = std::chrono::system_clock::now();
    std::set<std::string> set;
    while (file >> word)
    {
        word = Transform_str(word);
        set.insert(word);
    }
    end = std::chrono::system_clock::now();
    time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "set:\nsize = " << set.size() << "\ntime = " << time.count() << "\n\n";

    file.close();

    return 0;
}

std::string Transform_str(std::string word) {
    std::string new_word = "";
    for (char& element : word)
    {
        if (isalpha(element) || element == '\'') {
            new_word += std::tolower(element);
        }
    }
    return new_word;
}
