//
// Created by En on 2022/10/28.
//
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 6
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
int main()
{
    int old_board[SIZE + 2][SIZE + 2] = {0}; //从计算机存储的角度——拉平数组，可直接这么写（相当于一维数组）
    for (int row = 0; row < SIZE + 2; row++)
    {
        for (int col = 0; col < SIZE + 2; col++)
        {
            if (row == 0 || row == SIZE + 1 || col == 0 || col == SIZE + 1)
            {
                old_board[row][col] = 0;
            }
            else
            {
                old_board[row][col] = board[row - 1][col - 1];
            }
        }
    }
    // Linux/Unix清屏：system("clear");
    // for wins: #include <conio.h>:clrscr()
    for (int row = 1; row <= SIZE; row++)
    {
        for (int col = 1; col <= SIZE; col++)
        {
            printf("%c", old_board[row][col] ? '*' : ' ');
        }
        printf("\n");
    }
    int next_board[SIZE + 2][SIZE + 2] = {0};
    for (int round = 1; round <= 10; round++)
    {
        for (int row = 1; row <= SIZE; row++)
        {
            for (int col = 1; col <= SIZE; col++)
            {
                int neighbors =
                        old_board[row - 1][col - 1] +
                        old_board[row - 1][col] +
                        old_board[row - 1][col + 1] +
                        old_board[row][col - 1] +
                        old_board[row][col + 1] +
                        old_board[row + 1][col - 1] +
                        old_board[row + 1][col] +
                        old_board[row + 1][col + 1];
                if (old_board[row][col])
                {
                    next_board[row][col] = (neighbors == 2 || neighbors == 3);
                }
                else
                {
                    next_board[row][col] = (neighbors == 3);
                }
            }
        }
        // sleep(seconds:1)  for Linux/Unix #include<unistd.h>
        // for wins: #include<windows.h>:Sleep(ms)
        Sleep(1000);
        system("cls");
        for (int row = 1; row <= SIZE; row++)
        {
            for (int col = 1; col <= SIZE; col++)
            {
                printf("%c", next_board[row][col] ? '*' : ' ');
            }
            printf("\n");
        }
        Sleep(1000);

        for (int row = 1; row <= SIZE; row++)
        {
            for (int col = 1; col <= SIZE; col++)
            {
                old_board[row][col] = next_board[row][col];
            }
        }
    }
    return 0;
}