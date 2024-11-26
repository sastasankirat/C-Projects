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

int main(){
    int format;
    printf("Choose the time format: \n");
    printf("1. 24 Hour format\n");
    printf("2. 12 Hour format (default)\n");
    printf("Make a choice(1/2): ");
    scanf("%d", &format);
    clear_screen();
    time_t raw_time;
    struct tm*current_time;
    char buffer[50];

    if(format!=1&&format!=2){format = 2;}
    while (1) {
    time(&raw_time);
    current_time = localtime(&raw_time);
    if(format == 1){
        strftime(buffer,sizeof(buffer),"%H:%M:%S",current_time);
        }
    else if(format == 2){
        strftime(buffer,sizeof(buffer),"%I:%M:%S %p",current_time);
    }

    printf("Current time: %s\n", buffer);

    strftime(buffer,sizeof(buffer),"%A : %B,%d,%Y",current_time);
    printf("Current date: %s\n", buffer);
    sleep(1);
    clear_screen();
    }

    return 0;
}