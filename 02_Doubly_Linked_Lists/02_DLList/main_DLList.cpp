#include "DLList.hpp"
#include "DLList.cpp"

using namespace std;


int main() {
    DLList<char> list;

    list.push_front('a');
    list.push_front('b');
    list.push_front('c');

    // Print List
    list.print_list();

    return 0;
}