#include <stdio.h>
#include <string.h>
#include <conio.h>

#define MAX_USERS 10

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

    char names[MAX_USERS][100];
    char passwords[MAX_USERS][100];
    int registered = 0; 
    int userCount = 0;

    while (1) {
        printf("Select an option: ");
        int x;
        scanf("%d", &x);
        
        switch (x) {
            case 1:
                if (userCount >= MAX_USERS) {
                    printf("Maximum user limit reached!\n");
                    break;
                }

                printf("Register a new user.\n");
                printf("Enter Username: ");
                scanf("%s", names[userCount]);
                printf("Enter Password: ");
                maskPassword(passwords[userCount]);
                userCount++;
                registered = 1;
                break;

            case 2:
                if (!registered) {
                    printf("You must register first!\n");
                    break;
                }

                char name2[100];
                char password2[100];
                printf("Enter Username: ");
                scanf("%s", name2);
                printf("Enter Password: ");
                maskPassword(password2);

                int loginSuccess = 0;
                for (int i = 0; i < userCount; i++) {
                    if (strcmp(names[i], name2) == 0 && strcmp(passwords[i], password2) == 0) {
                        printf("Login Successful! Welcome %s\n", names[i]);
                        loginSuccess = 1;
                        break;
                    }
                }

                if (!loginSuccess) {
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
