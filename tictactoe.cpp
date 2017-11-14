//
// Created by Tristan Brindle on 14/11/2017.
//

#include "tictactoe.hpp"

namespace tictactoe {

std::ostream& operator<<(std::ostream& os, entry e)
{
    switch (e) {
    case entry::empty:
        return os << " ";
    case entry::nought:
        return os << "O";
    case entry::cross:
        return os << "X";
    }
}

board::board()
{
    array_.fill(entry::empty);
}

entry board::operator()(int row, int col) const
{
    if (row < 0 || row > 2) {
        throw std::out_of_range{
                "Row must be in the range 0-2, got " + std::to_string(row)};
    }
    if (col < 0 || col > 2) {
        throw std::out_of_range{
                "Column must be in the range 0-2, got " + std::to_string(col)};
    }

    return array_[row * 3 + col];
}

entry& board::operator()(int row, int col)
{
    if (row < 0 || row > 2) {
        throw std::out_of_range{
                "Row must be in the range 0-2, got " + std::to_string(row)};
    }
    if (col < 0 || col > 2) {
        throw std::out_of_range{
                "Column must be in the range 0-2, got " + std::to_string(col)};
    }

    return array_[row * 3 + col];
}

std::ostream& operator<<(std::ostream& os, const board& b)
{
    os << "\n";
    os << " " << b(0, 0) << " | " << b(0, 1) << " | " << b(0, 2) << "\n";
    os << "---+---+---\n";
    os << " " << b(1, 0) << " | " << b(1, 1) << " | " << b(1, 2) << "\n";
    os << "---+---+---\n";
    os << " " << b(2, 0) << " | " << b(2, 1) << " | " << b(2, 2) << "\n\n";
    return os;
}

bool check_winner(const board& b, entry e)
{
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (b(i, 0) == e &&
                b(i, 1) == e &&
                b(i, 2) == e) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (b(0, i) == e &&
                b(1, i) == e &&
                b(2, i) == e) {
            return true;
        }
    }

    // Check diagonals
    if (b(0, 0) == e && b(1, 1) == e && b(2, 2) == e) return true;
    if (b(0, 2) == e && b(1, 2) == e && b(2, 0) == e) return true;

    return false;
}

bool check_draw(const board& b)
{
    // A game is a draw if all cells in the board are non-empty, and nobody
    // has won
    for (const auto e : b) {
        if (e == entry::empty) {
            return false;
        }
    }
    return true;
}

}
