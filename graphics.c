#include <stdio.h>
#include <math.h>
#include "graphics.h"

void initializeCanvas(char canvas[ROWS][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas(char canvas[ROWS][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}
void drawRectangle(char canvas[ROWS][COLS],
                   int row, int col,
                   int width, int height)
{
    int i, j;

    for (i = row; i < row + height && i < ROWS; i++)
    {
        for (j = col; j < col + width && j < COLS; j++)
        {
            canvas[i][j] = '*';
        }
    }
}
void drawLine(char canvas[ROWS][COLS],
              int row1, int col1,
              int row2, int col2)
{
    int i;

    if (row1 == row2)
    {
        for (i = col1; i <= col2 && i < COLS; i++)
        {
            canvas[row1][i] = '*';
        }
    }

    else if (col1 == col2)
    {
        for (i = row1; i <= row2 && i < ROWS; i++)
        {
            canvas[i][col1] = '*';
        }
    }
}
void drawTriangle(char canvas[ROWS][COLS],
                  int row, int col,
                  int height)
{
    int i, j;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (row + i < ROWS && col + j < COLS)
            {
                canvas[row + i][col + j] = '*';
            }
        }
    }
}

void drawCircle(char canvas[ROWS][COLS],
                int centerRow,
                int centerCol,
                int radius)
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            int dx = i - centerRow;
            int dy = j - centerCol;

            if (dx * dx + dy * dy <= radius * radius)
            {
                canvas[i][j] = '*';
            }
        }
    }
}
void deleteRectangle(char canvas[ROWS][COLS],
                     int row, int col,
                     int width, int height)
{
    int i, j;

    for (i = row; i < row + height && i < ROWS; i++)
    {
        for (j = col; j < col + width && j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}
void modifyRectangle(char canvas[ROWS][COLS],
                     int oldRow, int oldCol,
                     int oldWidth, int oldHeight,
                     int newRow, int newCol,
                     int newWidth, int newHeight)
{
    deleteRectangle(canvas,
                    oldRow, oldCol,
                    oldWidth, oldHeight);

    drawRectangle(canvas,
                  newRow, newCol,
                  newWidth, newHeight);
}