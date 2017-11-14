
#include "tictactoe.hpp"

#include <iostream>

void read_names(std::array<tictactoe::player, 2>& players)
{
    std::cout << "Player 1, please enter your name:\n";
    std::cin >> players[0].name;
    std::cout << "Hello " << players[0].name << "!\n";
    std::cout << "Player 2, please enter your name:\n";
    std::cin >> players[1].name;
    std::cout << "Hello " << players[1].name << "!\n";
}

tictactoe::entry get_p1_token()
{
    while (true) {
        std::cout << "Player 1, please choose a token (enter O or X):\n";
        char c;
        std::cin >> c;
        switch (c) {
        case 'O':
            return tictactoe::entry::nought;
        case 'X':
            return tictactoe::entry::cross;
        default:
            continue;
        }
    }
}

enum class game_result {
    player1_win = 0,
    player2_win = 1,
    draw = 2
};

game_result run_game(std::array<tictactoe::player, 2>& players, int starting_player) {

    tictactoe::board board{};

    int current_player = starting_player;

    while (true) {
        while (true) {
            std::cout << board;
            std::cout << players[current_player].name << ", it's your turn\n";

            int row_num = -1;
            int col_num = -1;

            while (row_num < 0 || row_num > 2) {
                std::cout << "Enter row number [0 - 2]:\n";
                std::cin >> row_num;
            }

            while (col_num < 0 || col_num > 2) {
                std::cout << "Enter column number [0 - 2]:\n";
                std::cin >> col_num;
            }

            if (board(row_num, col_num) == tictactoe::entry::empty) {
                board(row_num, col_num) = players[current_player].token;
                break;
            }
            else {
                std::cout << "I'm sorry, that square is taken. Try again\n";
            }
        }

        if (tictactoe::check_winner(board, players[current_player].token)) {
            std::cout << "Congratulations " << players[current_player].name << ", you've won!\n";
            return static_cast<game_result>(current_player);
        }

        if (tictactoe::check_draw(board)) {
            std::cout << "The game has ended in a draw, try again next time\n";
            return game_result::draw;
        }

        current_player = (++current_player) % 2;
    }
}

int main()
{
    std::array<tictactoe::player, 2> players;

    read_names(players);
    players[0].token = get_p1_token();
    if (players[0].token == tictactoe::entry::nought) {
        players[1].token = tictactoe::entry::cross;
    } else {
        players[1].token = tictactoe::entry::nought;
    }

    bool quit = false;
    int next_starter = 0;

    while (!quit) {
        const auto res = run_game(players, next_starter);

        switch (res) {
        case game_result::player1_win:
            players[0].score += 2;
            break;
        case game_result::player2_win:
            players[1].score += 2;
            break;
        case game_result::draw:
            players[0].score += 1;
            players[1].score += 1;
            break;
        }

        std::cout << "Current scores:\n";
        std::cout << players[0].name << ": " << players[0].score << '\n';
        std::cout << players[1].name << ": " << players[1].score << '\n';

        bool chosen = false;
        while (!chosen) {
            std::cout << "Do you wish to play again? [Y/N]:?";
            char c;
            std::cin >> c;

            switch (c) {
            case 'y':
            case 'Y':
                chosen = true;
                break;
            case 'n':
            case 'N':
                chosen = true;
                quit = true;
                break;
            default:
                continue;
            }
        }

        next_starter = (++next_starter) % 2;
    }

    if (players[0].score > players[1].score) {
        std::cout << "Congratulations " << players[0].name << ", you win!!";
    } else if (players[1].score > players[0].score) {
        std::cout << "Congratulations " << players[1].name << ", you win!!";
    } else {
        std::cout << "The match ended in a draw, play again soon!\n";
    }
}