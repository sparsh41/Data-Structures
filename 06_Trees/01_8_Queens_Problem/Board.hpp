#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <string>

class Board {
public:
    Board();

    void print() const;
    void place_queens();
    void place_queens_all(); // 92 unique solutions

private:
    bool check_place(const int row, const int col) const;
    void place_queens_helper(int row, int col, int queens_placed, bool& finished);
    void place_queens_all_helper(int row, int col, int queens_placed, int& sol);
    
    std::vector<std::string> board;
    unsigned board_size;
};

#endif