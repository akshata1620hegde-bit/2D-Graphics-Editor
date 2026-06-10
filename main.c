#include <stdio.h>
#include "graphics.h"

int main()
{
    char canvas[ROWS][COLS];
    int choice;

    initializeCanvas(canvas);

    do
    {
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Display Picture\n");
        printf("6. Clear Picture\n");
        printf("7. Delete Rectangle\n");
        printf("8. Modify Rectangle\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            drawRectangle(canvas, 2, 2, 10, 5);
            break;

        case 2:
            drawLine(canvas, 10, 2, 10, 20);
            break;

        case 3:
            drawTriangle(canvas, 5, 25, 6);
            break;

        case 4:
            drawCircle(canvas, 10, 30, 4);
            break;

        case 5:
            displayCanvas(canvas);
            break;

        case 6:
            initializeCanvas(canvas);
            printf("Picture cleared!\n");
            break;

        case 7:
            deleteRectangle(canvas, 2, 2, 10, 5);
            printf("Rectangle deleted!\n");
            break;

        case 8:
            modifyRectangle(canvas,
                            2, 2, 10, 5,
                            8, 8, 12, 4);
            printf("Rectangle modified!\n");
            break;

        case 9:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 9);

    return 0;
}