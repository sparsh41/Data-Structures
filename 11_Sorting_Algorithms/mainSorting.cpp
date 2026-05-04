#include "Sorting.hpp"
#include <vector>
#include <string>
#include <ctime>

template <typename T>
void print(const std::vector<T>& v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}


int main() {
    std::vector<std::string> strings {"xyz", "abc", "re", "the", "start", "hash", "graph", "dog", "cat"};
    std::vector<int> ints {43, 2, -2, 94, 934};

    Sorting::quickSort(strings);
    //Sorting::mergeSort(ints);

    // print(strings);
    // print(ints);

    std::cout << strings[5] + strings[4] << std::endl;

    // srand(time(0));
    // std::vector<int> ints2;
    // for (int i = 0; i < 1000000; i++) {
    //     ints2.push_back(rand() % 120);
    // }

    // Sorting::mergeSort(ints2);

    return 0;
}