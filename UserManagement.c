#include <stdio.h>
#include <string.h>
#include <conio.h>

void maskPassword(char *password) {
    char ch;
    int i = 0;
    
    while ((ch = getch()) != '\r') {
        if (ch == 8) {
            if (i > 0) {
                i--;
                printf("\b \b"); 
            }
        } else {
            password[i++] = ch;
            printf("*"); 
        }
    }
    password[i] = '\0'; 
    printf("\n"); 
}

int main() {
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Exit\n");

    char name1[100] = "";
    char password1[100] = "";
    char name2[100];
    char password2[100];
    
    int registered = 0; 

    while (1) {
        printf("Select an option: ");
        int x;
        scanf("%d", &x);
        
        switch (x) {
            case 1: 
                printf("Register a new user.\n");
                printf("Enter Username: ");
                scanf("%s", name1);
                printf("Enter Password: ");
                maskPassword(password1);
                registered = 1;
                break;

            case 2:
                if (!registered) {
                    printf("You must register first!\n");
                    break;
                }

                printf("Enter Username: ");
                scanf("%s", name2);
                printf("Enter Password: ");
                maskPassword(password2);

                if (strcmp(name1, name2) == 0 && strcmp(password1, password2) == 0) {
                    printf("Login Successful! Welcome %s\n", name1);
                } else {
                    printf("Login Failed! Incorrect Username or Password.\n");
                }
                break;

            case 3:
                printf("Exiting Program!\n");
                return 0;

            default:
                printf("Invalid option! Please select a valid option.\n");
        }
    }

    return 0;
}
