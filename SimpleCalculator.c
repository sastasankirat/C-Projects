#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x, y, d;
    printf("Welcome to Simple Calculator\n");

    printf("Enter first number: ");
    scanf("%f", &x);

    printf("Choose one of the following options: \n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Power\n");
    printf("7. Exit\n");

    do
    {
        printf("Now, enter the number of your choice (eg: 1 for 'Add'): ");
        scanf("%f", &d);
        switch ((int)d)
        {
        case 1:
        {
            printf("Enter next number: ");
            scanf("%f", &y);
            float sum = x + y;
            printf("Sum: %.2f\n", sum);
            x = sum;
            break;
        }
        case 2:
        {
            printf("Enter next number: ");
            scanf("%f", &y);
            float difference = x - y;
            printf("Difference: %.2f\n", difference);
            x = difference;
            break;
        }
        case 3:
        {
            printf("Enter next number: ");
            scanf("%f", &y);
            float product = x * y;
            printf("Product: %.2f\n", product);
            x = product;
            break;
        }
        case 4:
        {
            printf("Enter next number: ");
            scanf("%f", &y);
            if (y == 0)
            {
                printf("Error: Division by zero is not allowed.\n");
            }
            else
            {
                float ratio = x / y;
                printf("Division: %.2f\n", ratio);
                x = ratio;
            }
            break;
        }
        case 5:
        {
            printf("Enter next number: ");
            scanf("%f", &y);
            if (y != 0)
            {
                int modulus = (int)x % (int)y;
                printf("Modulus: %d\n", modulus);
                x = modulus;
            }
            else
            {
                printf("Error: Modulus by zero is not allowed.\n");
            }
            break;
        }
        case 6:
        {
            printf("Enter next number: ");
            scanf("%f", &y);
            double power = pow(x, y);
            printf("Power: %.2f\n", power);
            x = power;
            break;
        }
        case 7:
            printf("Exiting the calculator. Goodbye!\n");
            break;
        default:
            printf("Invalid input\n");
        }
    } while ((int)d != 7);

    return 0;
}
