#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void printSudoku(int grid[9][9])  //arranging the board grid
{
    system("cls"); //clear the screen of previous attempts and menu
 
    cout << "\t   ____   _    _   ____     ____    _   _   _    _ " << endl;
    cout << "\t  / ___| | |  | | |  _ \\   / __ \\  | | / / | |  | |" << endl;
    cout << "\t  \\___ \\ | |  | | | | \\ | | /  \\ | |  / /  | |  | |" << endl;
    cout << "\t   ___) || |__| | | |_/ | | \\__/ | |  \\ \\  | |__| |" << endl;
    cout << "\t  \\____/  \\____/  |____/   \\____/  |_| \\_\\  \\____/" << endl;
    cout << "\n \t*** Play by replacing zeros with numbers from 1-9 ***\n "<<endl;
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            cout << setw(2) << grid[row][col];  //output the default values 
            if ((col + 1) % 3 == 0 && col < 9 - 1)  //setting vertical grid lines
                cout << " |";
        }
        cout << endl;
        if ((row + 1) % 3 == 0 && row < 9 - 1)
            cout << " ------+-------+------" << endl;  //setting horizontal grid lines
    }
}

bool check(int board[9][9], int row, int col, int num)
{
    for (int i = 0; i < 9; i++)  //check that no matching numbers in row
        if (board[row][i] == num)
            return false;

    for (int i = 0; i < 9; i++)  //check that no matching numbers in column
        if (board[i][col] == num)
            return false;

    int boxRow = row - row % 3;  //define 'boxRow' and 'boxCol' so they come as multiples of 3 only
    int boxCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + boxRow][j + boxCol] == num)  //check that no matching numbers in 3x3 box
                return false;

    return true;
}

bool allFilled(int grid[9][9])  //check that all boxes are filled
{
    for (int row = 0; row < 9; row++)
        for (int col = 0; col < 9; col++)
            if (grid[row][col] == 0)
                return false;
    return true;
}

bool solution(int board[9][9], int row, int col)
{
    if (row == 9 - 1 && col == 9)  //runs the function until it is on the last box
        return true;  //if all cells are filled, the puzzle is considered solved

    if (col == 9)  //move to the next row if on the ninth column
    {
        row++;
        col = 0;
    }
    if (board[row][col] != 0)  //0 indicates empty cells, checks if all cells are filled
        return solution(board, row, col + 1);

    for (int num = 1; num <= 9; num++)  //number in cell must be from 1-9 
    {
        if (check(board, row, col, num))
        {
            board[row][col] = num;
            if (solution(board, row, col + 1))
                return true;
            board[row][col] = 0;
        }
    }
    return false;
}

void letsPlay(int board[9][9]) {
    int row, col, num;
    while (true) {
        printSudoku(board);
        cout << endl << endl;
        cout << "Having trouble? Enter a negative digit at 'Enter number' to view the solution." << endl;
        cout << "Enter the row number: ";  //choose the row to select a box
        cin >> row;
        cout << "Enter the column number: ";  //choose the column to select a box
        cin >> col;
        cout << "Enter number: ";  //enter a number at the selected box
        cin >> num;

        if (num <= -1)  //if any number less than 0
        {
            solution(board, 0, 0);  //calls the solution
            printSudoku(board);  //calls the grid
            cout << endl;
            cout << "Try it on your own next time!" << endl;
            return;
        }
        if (allFilled(board))  //checks if all boxes are filled
            break;
        row -= 1;  //row decrement
        col -= 1;  //column decrement
        if (!check(board, row, col, num))  //if the number is repeated in a row, column, or 3x3 grid
        {
            cout << "You've already tried this number!";
            //-----put a prompt here
           
            continue;
        }
        board[row][col] = num;
    }

    bool solved = true;  //check if the values entered are correct 
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)  //checks that no boxes in grid are 0
            {
                solved = false;
                break;
            }
        }
    }

    if (solved) {
        cout << "Congratulations! You solved the Sudoku! " << endl;
        printSudoku(board);
    }
    else {
        cout << "Your answer was wrong.\nHere's the solution" << endl;
        solution(board, 0, 0);
        cout << "Better luck next time!" << endl;
    }

}

int main() {
    int board[9][9] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},  //default values at start
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
    while (true)
    {
        int menu;
        cout << "\t   ____   _    _   ____     ____    _   _   _    _ " << endl;
        cout << "\t  / ___| | |  | | |  _ \\   / __ \\  | | / / | |  | |" << endl;
        cout << "\t  \\___ \\ | |  | | | | \\ | | /  \\ | |  / /  | |  | |" << endl;
        cout << "\t   ___) || |__| | | |_/ | | \\__/ | |  \\ \\  | |__| |" << endl;
        cout << "\t  \\____/  \\____/  |____/   \\____/  |_| \\_\\  \\____/" << endl;
        cout << "\n \t*** Play by replacing zeros with numbers from 1-9 ***\n " << endl;
          
            //displaying menu with options for player       
            cout << "\t\t\t=====MENU=====" << endl;
            cout << "\n\tEnter a number to proceed\n";
            cout << "\t[1] Let's Play!" << endl;
            cout << "\t[2] Check the solution?" << endl;
            cout << "\t[3] Exit Menu" << endl;
            cout << "\t[4] Reset the board?" << endl;
            cout << "\n\tWhat would you like to do? \n\t";
                cin >> menu;
            cout << endl;

            switch (menu) {
            case 1:
                 letsPlay(board);  //call the letsPlay function to start playing
                 break;
            case 2:
                if (solution(board, 0, 0))
                  {
                    cout << "The solution is: " << endl;
                    cout << endl << endl;
                    for (int row = 0; row < 9; row++) 
                    {
                        for (int col = 0; col < 9; col++)
                        {
                            cout << setw(2) << board[row][col];  //use board instead of grid here
                            if ((col + 1) % 3 == 0 && col < 9 - 1)
                                cout << " |";
                        }
                        cout << endl;
                        if ((row + 1) % 3 == 0 && row < 9 - 1)
                            cout << " ------+-------+------" << endl;
                    }
                    cout << endl;
                    cout << "Better luck next time!" << endl;
                }
                else
                    cout << "Invalid Start Board" << endl;
                break;
            case 3:
                exit(0);
            case 4:
                system("cls");
                return main();
            default:
                cout << "Not a valid Menu choice!" << endl;
            }
    }
}