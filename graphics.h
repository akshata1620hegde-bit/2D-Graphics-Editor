#ifndef GRAPHICS_H
#define GRAPHICS_H

#define ROWS 20
#define COLS 40

void initializeCanvas(char canvas[ROWS][COLS]);
void displayCanvas(char canvas[ROWS][COLS]);

void drawRectangle(char canvas[ROWS][COLS],
                   int row, int col,
                   int width, int height);

void drawLine(char canvas[ROWS][COLS],
              int row1, int col1,
              int row2, int col2);

void drawTriangle(char canvas[ROWS][COLS],
                  int row, int col,
                  int height);

void drawCircle(char canvas[ROWS][COLS],
                int centerRow,
                int centerCol,
                int radius);

#endif
