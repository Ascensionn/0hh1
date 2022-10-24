#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"

 /**
 * --------------------------------------------------------
 * ---------- UTILITY FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == UNKNOWN) {
                counter++;
            }
        }
    }
    return counter;
}


/**
 * --------------------------------------------------------
 * --------- VALIDITY CHECKING FUNCTIONS ------------------
 * --------------------------------------------------------
 */

bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
    int size,
    int row,
    int color) {
    // using loop to check if there is three color in each row
    // beacuse we check next two rows and current raw so we use size - 2
    for (int n = 0; n < size - 2; n++) {
        if (board[row][n] == color &&
            board[row][n + 1] == color && board[row][n + 2] == color) {
            return false;
        }

    }
    return true;
}

bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
    int size,
    int col,
    int color) {
    // using loop to check if there is three color in each col
    // beacuse we check next two cols and current col so we use size - 2
    for (int n = 0; n < size - 2; n++) {
        if (board[n][col] == color &&
            board[n + 1][col] == color && board[n + 2][col] == color) {
            return false;
        }

    }
    return true;

}

bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        int color;
        // if any row or column in any color cannot be balanced,
        // the board is invalid
        if (!row_has_no_threes_of_color(board, size, i, color = 1) ||
            !col_has_no_threes_of_color(board, size, i, color = 1) ||
            !row_has_no_threes_of_color(board, size, i, color = 2) ||
            !col_has_no_threes_of_color(board, size, i, color = 2)) {
            return false;
        }


    }
    return true;
}

bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
    int size,
    int row1,
    int row2) {
    // use z to count the times
    // that row1 and row2 have the same color at the same position
    int z = 0;
    // make sure that they are completed
    for (int i = 0; i < size; i++) {
        if (board[row1][i] == UNKNOWN || board[row2][i] == UNKNOWN) {
            return true;
        }
    }

    for (int i = 0; i < size; i++) {
        if (board[row1][i] == board[row2][i]) {
            z++;
        }

    }

    if (z == size) {
        return false;
    }
    else {
        return true;
    }

}


bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
    int size,
    int col1,
    int col2) {
    // use z to count the times that row1 and row2 have the
    // same color
    int z = 0;
    // make sure that they are completed
    for (int i = 0; i < size; i++) {
        if (board[i][col1] == UNKNOWN || board[i][col2] == UNKNOWN) {
            return true;
        }
    }

    for (int i = 0; i < size; i++) {
        if (board[i][col1] == board[i][col2]) {
            z++;
        }

    }

    if (z == size) {
        return false;
    }
    else {
        return true;
    }


}

bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
    // using nested loop to check if there is duplicates in two rows
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (!rows_are_different(board, size, i, j)) {
                return false;
            }
        }
    }
    // using nested loop to check if there is duplicates in two cols
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (!cols_are_different(board, size, i, j)) {
                return false;
            }
        }
    }

    return true;
}



/**
 * --------------------------------------------------------
 * ---------- SOLVING FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
    int size,
    int row,
    bool announce) {
    bool isBlue = false;
    bool isRed = false;
    for (int i = 0; i < size - 2; i++) {
        // Testing to see if the board here is: XX-
        if (board[row][i] == board[row][i + 1] 
            && board[row][i + 2] == UNKNOWN) {
            if (board[row][i] == RED) {
                isRed = true;
            }
            else if (board[row][i] == BLUE) {
                isBlue = true;
            }
            if (isRed) {
                mark_square_as(board, size, row, i + 2, opposite_color(RED), announce);
            }
            else if (isBlue) {
                mark_square_as(board, size, row, i + 2, opposite_color(BLUE), announce);
            }
        }
        // Testing to see if the board here is: X-X
        else if (board[row][i] == board[row][i + 2] 
            && board[row][i + 1] == UNKNOWN) {
            if (board[row][i] == RED) {
                isRed = true;
            }
            else if (board[row][i] == BLUE) {
                isBlue = true;
            }
            if (isRed) {
                mark_square_as(board, size, row, i + 1, opposite_color(RED), announce);
            }
            else if (isBlue) {
                mark_square_as(board, size, row, i + 1, opposite_color(BLUE), announce);
            }
        }
        // Testing to see if the board here is: -XX
        else if (board[row][i + 1] == board[row][i + 2] 
            && board[row][i] == UNKNOWN) {
            if (board[row][i + 1] == RED) {
                isRed = true;
            }
            else if (board[row][i + 1] == BLUE) {
                isBlue = true;
            }
            if (isRed) {
                mark_square_as(board, size, row, i, opposite_color(RED), announce);
            }
            else if (isBlue) {
                mark_square_as(board, size, row, i, opposite_color(BLUE), announce);
            }
        }
        isRed = false;
        isBlue = false;
    }
    return;
}

void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
    int size,
    int col,
    bool announce) {
    bool isBlue = false;
    bool isRed = false;
    for (int i = 0; i < size - 2; i++) {
        /* Testing to see if the board here is:
         * X
         * X
         * -
         */
        if (board[i][col] == board[i + 1][col] 
            && board[i + 2][col] == UNKNOWN) {
            if (board[i][col] == RED) {
                isRed = true;
            }
            else if (board[i][col] == BLUE) {
                isBlue = true;
            }
            if (isRed) {
                mark_square_as(board, size, i + 2, col, opposite_color(RED), announce);
            }
            else if (isBlue) {
                mark_square_as(board, size, i + 2, col, opposite_color(BLUE), announce);
            }
        }
        /* Testing to see if the board here is:
         * X
         * -
         * X
         */
        else if (board[i][col] == board[i + 2][col] 
            && board[i + 1][col] == UNKNOWN) {
            if (board[i][col] == RED) {
                isRed = true;
            }
            else if (board[i][col] == BLUE) {
                isBlue = true;
            }
            if (isRed) {
                mark_square_as(board, size, i + 1, col, opposite_color(RED), announce);
            }
            else if (isBlue) {
                mark_square_as(board, size, i + 1, col, opposite_color(BLUE), announce);
            }
        }
        /* Testing to see if the board here is:
         * -
         * X
         * X
         */
        else if (board[i + 1][col] == board[i + 2][col] 
            && board[i][col] == UNKNOWN) {
            if (board[i + 1][col] == RED) {
                isRed = true;
            }
            else if (board[i + 1][col] == BLUE) {
                isBlue = true;
            }
            if (isRed) {
                mark_square_as(board, size, i, col, opposite_color(RED), announce);
            }
            else if (isBlue) {
                mark_square_as(board, size, i, col, opposite_color(BLUE), announce);
            }
        }
        isRed = false;
        isBlue = false;
    }
    return;
}


void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
    int size,
    int row,
    bool announce) {
    int blueCounter = 0;
    int redCounter = 0;
    int halfOfRow = size / 2;

    // Find out numbers of blues and reds
    for (int i = 0; i < size; i++) {
        if (board[row][i] == BLUE) {
            blueCounter++;
        }
        if (board[row][i] == RED) {
            redCounter++;
        }
    }
    // These two if statements make sure the correct colour gets
    // the equal amount as the other colour IF one of the counters
    // find out that its equal to half the row
    if (blueCounter == halfOfRow) {
        for (int i = 0; i < size; i++) {
            if (board[row][i] == UNKNOWN) {
                mark_square_as(board, size, row, i, opposite_color(BLUE), announce);
            }
        }
    }
    if (redCounter == halfOfRow) {
        for (int i = 0; i < size; i++) {
            if (board[row][i] == UNKNOWN) {
                mark_square_as(board, size, row, i, opposite_color(RED), announce);
            }
        }
    }
    return;
}

void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
    int size,
    int col,
    bool announce) {
    int blueCounter = 0;
    int redCounter = 0;
    int halfOfCol = size / 2;

    // Find out numbers of blues and reds
    for (int i = 0; i < size; i++) {
        if (board[i][col] == BLUE) {
            blueCounter++;
        }
        if (board[i][col] == RED) {
            redCounter++;
        }
    }
    // These two if statements make sure the correct colour gets
    // the equal amount as the other colour IF one of the counters
    // find out that its equal to half the row
    if (blueCounter == halfOfCol) {
        for (int i = 0; i < size; i++) {
            if (board[i][col] == UNKNOWN) {
                mark_square_as(board, size, i, col, opposite_color(BLUE), announce);
            }
        }
    }
    if (redCounter == halfOfCol) {
        for (int i = 0; i < size; i++) {
            if (board[i][col] == UNKNOWN) {
                mark_square_as(board, size, i, col, opposite_color(RED), announce);
            }
        }
    }
    return;
}

/**
 * --------------------------------------------------------
 * ---------- GAMEPLAY FUNCTIONS --------------------------
 * --------------------------------------------------------
 */

bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
    // check if the board is valid
    bool x = board_is_valid(board, size);
    // check if the board is completed
    int y = count_unknown_squares(board, size);
    if (x == 1 && y == 0) {
        return true;
    }
    else {
        return false;

    }
}

bool check_valid_input(int size, int row_input, char col_input,
    char color_char, int& row, int& col) {
    char Col = toupper(col_input);
    char Color = toupper(color_char);
    // using nested loops to check if the input meet the requirments
    if (row_input <= size && row_input > 0) {
        if (Color == UNKNOWN_LETTER || Color == RED_LETTER ||
            Color == BLUE_LETTER) {
            if (Col >= 'A' && Col <= ('A' + size - 1)) {
                row = row_input - 1;
                col = int(Col) - 65;
                return true;
            }
            else {
                cout << "Sorry, that's not a valid input.";
                return false;
            }

        }
        else {
            cout << "Sorry, that's not a valid input.";
            return false;
        }

    }
    else {
        cout << "Sorry, that's not a valid input.";
        return false;
    }
}

bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
    const int current_board[MAX_SIZE][MAX_SIZE],
    int size, int row, int col, int color) {
    // if it is unequal to 0，
    // means that it has original color
    if (original_board[row][col] != 0) {
        cout << "Sorry, original squares cannot be changed.";
        return false;
    }
    int board[MAX_SIZE][MAX_SIZE];
    copy_board(current_board, board, size);
    board[row][col] = color;

    if (!board_is_valid(board, size)) {
        cout << "Sorry, that move violates a rule.";
        return false;
    }

    return true;

}

