#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x, y;
    int choice;

    printf("Welcome to Simple Calculator\n");

    while (1)
    {
        printf("Enter first number: ");
        scanf("%f", &x);

        printf("Choose one of the following options: \n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Power\n");
        printf("7. Clear current calculation (reset to new first number)\n");
        printf("8. Exit\n");

        while (1)
        {
            printf("Now, enter the number of your choice (1-8): ");
            if (scanf("%d", &choice) != 1)
            {
                printf("Invalid choice. Please enter a number between 1 and 8.\n");
                while(getchar() != '\n');
                continue;
            }

            switch (choice)
            {
            case 1:
                printf("Enter next number: ");
                scanf("%f", &y);
                x = x + y;
                printf("Sum: %.2f\n", x);
                break;

            case 2:
                printf("Enter next number: ");
                scanf("%f", &y);
                x = x - y;
                printf("Difference: %.2f\n", x);
                break;

            case 3:
                printf("Enter next number: ");
                scanf("%f", &y);
                x = x * y;
                printf("Product: %.2f\n", x);
                break;

            case 4:
                printf("Enter next number: ");
                scanf("%f", &y);
                if (y == 0)
                {
                    printf("Error: Division by zero is not allowed.\n");
                }
                else
                {
                    x = x / y;
                    printf("Division result: %.2f\n", x);
                }
                break;

            case 5:
                printf("Enter next number (integer only): ");
                scanf("%f", &y);
                if ((int)y != y)
                {
                    printf("Error: Modulus only works with integers.\n");
                }
                else if (y == 0)
                {
                    printf("Error: Modulus by zero is not allowed.\n");
                }
                else
                {
                    int result = (int)x % (int)y;
                    printf("Modulus result: %d\n", result);
                    x = result;
                }
                break;

            case 6:
                printf("Enter next number: ");
                scanf("%f", &y);
                x = pow(x, y);
                printf("Power result: %.2f\n", x);
                break;

            case 7:
                printf("Enter a new first number: ");
                scanf("%f", &x);
                printf("Current calculation reset. New first number set.\n");
                break;

            case 8:
                printf("Exiting the calculator. Goodbye!\n");
                return 0;

            default:
                printf("Invalid input. Please select a valid operation (1-8).\n");
            }

            char continue_choice;
            printf("Do you want to perform another operation on the current result? (y/n): ");
            while (getchar() != '\n');
            scanf("%c", &continue_choice);
            if (continue_choice != 'y' && continue_choice != 'Y')
            {
                break;
            }
        }
    }

    return 0;
}


