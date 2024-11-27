#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void set_text_color(int hour) {
    if (hour >= 6 && hour < 12) {
        printf("\033[1;33m");
    } else if (hour >= 12 && hour < 18) {
        printf("\033[1;32m");
    } else {
        printf("\033[1;34m");
    }
}

void reset_text_color() {
    printf("\033[0m");
}

void stopwatch() {
    int running = 1;
    int seconds = 0;
    int minutes = 0;
    int hours = 0;
    char command;

    while (running) {
        clear_screen();
        printf("Stopwatch: %02d:%02d:%02d\n", hours, minutes, seconds);
        printf("Commands: [S] Start/Resume  [P] Pause  [R] Reset  [Q] Quit\n");
        sleep(1);

        if (kbhit()) {
            command = getchar();
            if (command == 'S' || command == 's') {
                while (!kbhit() || (command = getchar()) != 'P' && command != 'p' && command != 'Q' && command != 'q') {
                    sleep(1);
                    seconds++;
                    if (seconds == 60) {
                        seconds = 0;
                        minutes++;
                        if (minutes == 60) {
                            minutes = 0;
                            hours++;
                        }
                    }
                    clear_screen();
                    printf("Stopwatch: %02d:%02d:%02d\n", hours, minutes, seconds);
                    printf("Commands: [S] Start/Resume  [P] Pause  [R] Reset  [Q] Quit\n");
                }
                if (command == 'Q' || command == 'q') {
                    running = 0;
                } else if (command == 'R' || command == 'r') {
                    seconds = 0;
                    minutes = 0;
                    hours = 0;
                }
            } else if (command == 'Q' || command == 'q') {
                running = 0;
            } else if (command == 'R' || command == 'r') {
                seconds = 0;
                minutes = 0;
                hours = 0;
            }
        }
    }
}

void countdown_timer() {
    int hours, minutes, seconds, total_seconds;
    printf("Set timer (HH MM SS): ");
    scanf("%d %d %d", &hours, &minutes, &seconds);
    total_seconds = hours * 3600 + minutes * 60 + seconds;

    while (total_seconds > 0) {
        clear_screen();
        hours = total_seconds / 3600;
        minutes = (total_seconds % 3600) / 60;
        seconds = total_seconds % 60;
        printf("Countdown Timer: %02d:%02d:%02d\n", hours, minutes, seconds);
        sleep(1);
        total_seconds--;
    }

    clear_screen();
    printf("Countdown Timer: 00:00:00\n");
    printf("Time's up!\n");
    sleep(3);
}

int main() {
    int choice;
    int format;
    while (1) {
        clear_screen();
        printf("Choose an option: \n");
        printf("1. Clock\n");
        printf("2. Stopwatch\n");
        printf("3. Countdown Timer\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            break;
        }

        if (choice == 1) {
            clear_screen();
            printf("Choose the time format: \n");
            printf("1. 24 Hour format\n");
            printf("2. 12 Hour format (default)\n");
            printf("Make a choice(1/2): ");
            scanf("%d", &format);
            clear_screen();

            if (format != 1 && format != 2) {
                format = 2;
            }

            time_t raw_time, program_start_time;
            struct tm *current_time;
            char buffer[50];

            time(&program_start_time);

            while (1) {
                time(&raw_time);
                current_time = localtime(&raw_time);

                set_text_color(current_time->tm_hour);

                if (format == 1) {
                    strftime(buffer, sizeof(buffer), "%H:%M:%S", current_time);
                } else if (format == 2) {
                    strftime(buffer, sizeof(buffer), "%I:%M:%S %p", current_time);
                }
                printf("Current time: %s\n", buffer);

                strftime(buffer, sizeof(buffer), "%A : %B %d, %Y", current_time);
                printf("Current date: %s\n", buffer);

                time_t elapsed_time = raw_time - program_start_time;
                int hours = elapsed_time / 3600;
                int minutes = (elapsed_time % 3600) / 60;
                int seconds = elapsed_time % 60;
                printf("System Uptime: %02d:%02d:%02d\n", hours, minutes, seconds);

                reset_text_color();

                sleep(1);
                clear_screen();
            }
        } else if (choice == 2) {
            stopwatch();
        } else if (choice == 3) {
            countdown_timer();
        }
    }

    return 0;
}
