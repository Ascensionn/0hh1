/**
 * ohhi.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1
 *
 * Yanbo Zhai    Tian Jian He
 * zhaiyanb
 * andyhe
 *
 * This project  is an application to read, check, solve,
 * and play basic instances of 0h h1, a Sudoku-like puzzle game.
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();
void test_row_has_no_threes_of_color();
void test_cols_are_different();
void test_board_has_no_duplicates();
void test_solve_balance_row();
void test_solve_three_in_a_row();
void test_solve_three_in_a_column();
void test_check_valid_input();


void startTests() {
    test_count_unknown_squares();
    test_row_has_no_threes_of_color();
    test_cols_are_different();
    test_board_has_no_duplicates();
    test_solve_balance_row();
    test_solve_three_in_a_row();
    test_solve_three_in_a_column();
    test_check_valid_input();

    // add your calls to test functions here
}


void test_count_unknown_squares() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = { "XOXO",
                             "--OO",
                             "---X",
                             "--O-" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << count_unknown_squares(board, size_1) << endl;
    // test case 2
    string test_board_2[] = { "-O-O",
                             "--O-",
                             "---X",
                             "--O-" };
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << count_unknown_squares(board, size_2) << endl;
}

void test_row_has_no_threes_of_color() {
    int board[MAX_SIZE][MAX_SIZE];
    // test case 1
    string test_board_1[] = { "XOXO",
                             "--OO",
                             "XX-X",
                             "--O-" };
    int size_1 = 4;
    int row_1 = 2;
    read_board_from_string(board, test_board_1, size_1);
    cout << row_has_no_threes_of_color(board,
        size_1,
        row_1,
        RED) << endl;

    // test case 2
    string test_board_2[] = { "XOXO",
                             "--OO",
                             "---X",
                             "--O-" };
    int size_2 = 4;
    int row_2 = 0;
    read_board_from_string(board, test_board_2, size_2);
    cout << row_has_no_threes_of_color(board,
        size_2,
        row_2,
        RED) << endl;

    // test case 3
    string test_board_3[] = { "-OOO",
                             "--OO",
                             "---X",
                             "--O-" };
    int size_3 = 4;
    int row_3 = 0;
    read_board_from_string(board, test_board_3, size_3);
    cout << row_has_no_threes_of_color(board,
        size_3,
        row_3,
        BLUE) << endl;

    // test case 4
    string test_board_4[] = { "XXX-",
                             "--OO",
                             "---X",
                             "--O-" };
    int size_4 = 4;
    int row_4 = 0;
    read_board_from_string(board, test_board_4, size_2);
    cout << row_has_no_threes_of_color(board,
        size_4,
        row_4,
        RED) << endl;



}

void test_cols_are_different() {
    int board[MAX_SIZE][MAX_SIZE];
    string test_board_1[] = { "XOXO",
                             "XOXO",
                             "O-O-",
                             "O-O-" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << cols_are_different(board,
        size_1,
        0,
        2) << endl;

    string test_board_2[] = { "XOXO",
                             "-OO-",
                             "---O",
                             "-XOX" };
    int size_2 = 4;

    read_board_from_string(board, test_board_2, size_2);
    cout << cols_are_different(board,
        size_2,
        3,
        1) << endl;


    string test_board_3[] = { "-OO-",
                             "-XX-",
                             "-OO-",
                             "-XX-" };
    int size_3 = 4;

    read_board_from_string(board, test_board_3, size_3);
    cout << cols_are_different(board,
        size_3,
        2,
        1) << endl;

    string test_board_4[] = { "XX-O",
                             "XXOO",
                             "O--O",
                             "--O-" };
    int size_4 = 4;

    read_board_from_string(board, test_board_4, size_4);
    cout << cols_are_different(board,
        size_2,
        0,
        1) << endl;

    string test_board_5[] = { "--XX",
                             "--OO",
                             "--XX",
                             "--OO" };
    int size_5 = 4;

    read_board_from_string(board, test_board_5, size_5);
    cout << cols_are_different(board,
        size_5,
        2,
        3) << endl;

    string test_board_6[] = { "-OO-",
                             "-OO-",
                             "-XX-",
                             "-XX-" };
    int size_6 = 4;

    read_board_from_string(board, test_board_6, size_6);
    cout << cols_are_different(board,
        size_6,
        2,
        1) << endl;

}

void test_board_has_no_duplicates() {
    int board[MAX_SIZE][MAX_SIZE];
    string test_board_1[] = { "XOXO",
                             "XOXO",
                             "---O",
                             "--O-" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_has_no_duplicates(board, size_1) << endl;
    string test_board_2[] = { "XXOO",
                             "XXOO",
                             "----",
                             "----" };
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << board_has_no_duplicates(board, size_2) << endl;

    string test_board_3[] = { "O--X",
                             "XXOO",
                             "XXOO",
                             "--O-" };
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << board_has_no_duplicates(board, size_3) << endl;

    string test_board_4[] = { "X--O",
                             "OOXX",
                             "OOXX",
                             "--O-" };
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << board_has_no_duplicates(board, size_4) << endl;

    string test_board_5[] = { "X--O",
                             "O--X",
                             "OO--",
                             "--O-" };
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << board_has_no_duplicates(board, size_5) << endl;

    string test_board_6[] = { "----",
                             "----",
                             "----",
                             "----" };
    int size_6 = 4;
    read_board_from_string(board, test_board_6, size_6);
    cout << board_has_no_duplicates(board, size_6) << endl;

    string test_board_7[] = { "----",
                             "--O-",
                             "----",
                             "X---" };
    int size_7 = 4;
    read_board_from_string(board, test_board_7, size_7);
    cout << board_has_no_duplicates(board, size_7) << endl;

}
void test_solve_balance_row() {
    cout << "Testing solve_balance_row() function" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    string test_board_1[] = { "XOXO",
                             "--OO",
                             "---X",
                             "--O-" };
    int size_1 = 4;
    int row_1 = 1;

    read_board_from_string(board, test_board_1, size_1);
    solve_balance_row(board,
        size_1,
        row_1,
        1);

    string test_board_2[] = { "----",
                             "-X-X",
                             "---X",
                             "--O-" };
    int size_2 = 4;
    int row_2 = 1;

    read_board_from_string(board, test_board_2, size_2);
    solve_balance_row(board,
        size_2,
        row_2,
        1);

    string test_board_3[] = { "----",
                             "--XX",
                             "-X-X",
                             "-OO-" };
    int size_3 = 4;
    int row_3 = 3;

    read_board_from_string(board, test_board_3, size_3);
    solve_balance_row(board,
        size_3,
        row_3,
        1);

    string test_board_4[] = { "----",
                             "--XX",
                             "-OO-",
                             "-X-X" };
    int size_4 = 4;
    int row_4 = 3;

    read_board_from_string(board, test_board_4, size_4);
    solve_balance_row(board,
        size_4,
        row_4,
        1);

    string test_board_5[] = { "----",
                             "-X-X",
                             "---X",
                             "--O-" };
    int size_5 = 4;
    int row_5 = 2;

    read_board_from_string(board, test_board_5, size_5);
    solve_balance_row(board,
        size_5,
        row_5,
        1);
    cout << "Expecting nothing to be marked" << endl;

    string test_board_6[] = { "----",
                             "-X-X",
                             "---X",
                             "--O-" };
    int size_6 = 4;
    int row_6 = 0;

    read_board_from_string(board, test_board_6, size_6);
    solve_balance_row(board,
        size_6,
        row_6,
        1);
    cout << "Expecting nothing to be marked" << endl;

    cout << "End of solve_balance_row() function" << endl;
}

void test_solve_three_in_a_row() {
    int board[MAX_SIZE][MAX_SIZE];
    string test_board_1[] = { "X-XO",
                             "--OO",
                             "---X",
                             "--O-" };
    int size_1 = 4;
    int row_1 = 0;
    read_board_from_string(board, test_board_1, size_1);
    solve_three_in_a_row(board,
        size_1,
        row_1,
        1);

    string test_board_2[] = { "X-XO",
                             "--OO",
                             "O-OX",
                             "----" };
    int size_2 = 4;
    int row_2 = 2;
    read_board_from_string(board, test_board_2, size_2);
    solve_three_in_a_row(board,
        size_2,
        row_2,
        1);


    string test_board_3[] = { "X-XO",
                             "--OO",
                             "---X",
                             "-XX-" };
    int size_3 = 4;
    int row_3 = 3;
    read_board_from_string(board, test_board_3, size_3);
    solve_three_in_a_row(board,
        size_3,
        row_3,
        1);

}
void test_solve_three_in_a_column() {
    int board[MAX_SIZE][MAX_SIZE];
    string test_board_1[] = { "XOXO",
                             "--XO",
                             "X--X",
                             "O-O-" };
    int size_1 = 4;
    int col_1 = 0;
    read_board_from_string(board, test_board_1, size_1);
    solve_three_in_a_column(board,
        size_1,
        col_1,
        1);




    string test_board_2[] = { "O-XO",
                             "--XO",
                             "O--X",
                             "X-O-" };
    int size_2 = 4;
    int col_2 = 0;
    read_board_from_string(board, test_board_2, size_2);
    solve_three_in_a_column(board,
        size_2,
        col_2,
        1);



    string test_board_3[] = { "--XO",
                             "O-XO",
                             "O--X",
                             "--O-" };
    int size_3 = 4;
    int col_3 = 0;
    read_board_from_string(board, test_board_3, size_3);
    solve_three_in_a_column(board,
        size_3,
        col_3,
        1);
}

void test_check_valid_input() {

    int size_1 = 4;
    int row_input_1 = 4;
    char col_input_1 = 'b';
    char color_char_1 = 'X';
    int row = 0;
    int col = 0;
    cout << check_valid_input(size_1, row_input_1, col_input_1,
        color_char_1, row, col);


    int size_2 = 6;
    int row_input_2 = 4;
    char col_input_2 = 'z';
    char color_char_2 = 'O';
    cout << check_valid_input(size_2, row_input_2, col_input_2,
        color_char_2, row, col);


    int size_3 = 4;
    int row_input_3 = 1;
    char col_input_3 = 'b';
    char color_char_3 = 'X';

    cout << check_valid_input(size_3, row_input_3, col_input_3,
        color_char_3, row, col);



    int size_4 = 2;
    int row_input_4 = 2;
    char col_input_4 = 'f';
    char color_char_4 = 'X';
    cout << check_valid_input(size_4, row_input_4, col_input_4,
        color_char_4, row, col);



    int size_5 = 8;
    int row_input_5 = 4;
    char col_input_5 = 'b';
    char color_char_5 = 'w';
    cout << check_valid_input(size_5, row_input_5, col_input_5,
        color_char_5, row, col);

    int size_6 = 3;
    int row_input_6 = 4;
    char col_input_6 = 'b';
    char color_char_6 = 'w';
    cout << check_valid_input(size_6, row_input_6, col_input_6,
        color_char_6, row, col);

    int size_7 = 3;
    int row_input_7 = 1;
    char col_input_7 = 'b';
    char color_char_7 = 'X';
    cout << check_valid_input(size_7, row_input_7, col_input_7,
        color_char_7, row, col);

}