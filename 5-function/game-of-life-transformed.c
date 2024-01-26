//
// Created by En on 2022/10/29.
//
// Run it with "Terminal"
//

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 6
//int Func[void](函数不接受任何参数时，函数声明要加void,函数定义与实现时可加可不加)
int board[SIZE][SIZE] = {
        {0},
        {0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 1, 1, 0},
        {0}};
//指定法初始化数组
// int board[SIZE][SIZE] = {
//    [1][1] = 1, [1][2] = 1,
//    [2][1] = 1, [2][2] = 1,
//    [3][3] = 1, [3][4] = 1
//};

// extended_board as a parameter
// ----------
// int arr[]
// 1D array: arr[5]: address of the first element + 5 * (sizeof int)
// 2D array: array of arrays
// arr[1][3]: address of the first element +
//            1 * (sizeof a row = number of elements in a row * (sizeof int)) +
//            3 * (sizeof int)
//0: ------
//1: ------
//2: ------
void ExtendBoard(const int origin_board[][SIZE],
                 int extended_board[][SIZE + 2]);
void PrintExtendedBoard(const int extended_board[][SIZE + 2]);
void GenerateNewBoard(const int old_board[][SIZE + 2],
                      int new_board[][SIZE + 2]);
void CopyExtendedBoard(const int src_board[][SIZE + 2],
                       int dest_board[][SIZE + 2]);
void SleepAndClear(int sec);

int main() {
    const int board[SIZE][SIZE] = {
            {0},
            {0, 1, 1, 0, 0, 0},
            {0, 1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1, 0},
            {0, 0, 0, 1, 1, 0},
            {0}
    };

    int old_board[SIZE + 2][SIZE + 2] = {0};
    ExtendBoard(board, old_board);
    PrintExtendedBoard(old_board);
//  SleepAndClear(1);

    int new_board[SIZE + 2][SIZE + 2] = {0};
    for (int round = 0; round < 10; round++) {
        GenerateNewBoard(old_board, new_board);
        SleepAndClear(1000);
        PrintExtendedBoard(new_board);
        CopyExtendedBoard(new_board, old_board);
    }

    return 0;
}

void ExtendBoard(const int origin_board[][SIZE],
                 int extended_board[][SIZE + 2]) {
    for (int row = 0; row < SIZE + 2; row++) {
        for (int col = 0; col < SIZE + 2; col++) {
            if (row == 0 || row == SIZE + 1 || col == 0 || col == SIZE + 1) {
                extended_board[row][col] = 0;
            } else {
                extended_board[row][col] = origin_board[row - 1][col - 1];
            }
        }
    }
}

void PrintExtendedBoard(const int extended_board[][SIZE + 2]) {
    for (int row = 1; row <= SIZE; row++) {
        for (int col = 1; col <= SIZE; col++) {
            printf("%c ", extended_board[row][col] ? '*' : ' ');
        }
        printf("\n");
    }
}

void GenerateNewBoard(const int old_board[][SIZE + 2],
                      int new_board[][SIZE + 2]) {
    for (int row = 1; row <= SIZE; row++) {
        for (int col = 1; col <= SIZE; col++) {
            // count the number of neighbours of old_board[row][col]
            int neighbours =
                    old_board[row - 1][col - 1] +
                    old_board[row - 1][col] +
                    old_board[row - 1][col + 1] +
                    old_board[row][col - 1] +
                    old_board[row][col + 1] +
                    old_board[row + 1][col - 1] +
                    old_board[row + 1][col] +
                    old_board[row + 1][col + 1];

            // evaluate the new board
            if (old_board[row][col]) {  // old_board[row][col] is alive
                new_board[row][col] = (neighbours == 2 || neighbours == 3);
            } else {  // old_board[row][col] is dead
                new_board[row][col] = (neighbours == 3);
            }
        }
    }
}

void CopyExtendedBoard(const int src_board[][SIZE + 2],
                       int dest_board[][SIZE + 2]) {
    for (int row = 1; row <= SIZE; row++) {
        for (int col = 1; col <= SIZE; col++) {
            dest_board[row][col] = src_board[row][col];
        }
    }
}

void SleepAndClear(int sec) {
    Sleep(sec);
    system("cls");
}