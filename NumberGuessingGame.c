#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(){
    printf("Welcome to the world of guessing numbers\n");

    int x,lower=1,upper=100,number,count=0,t=1;
    while(t==1){number = (rand() % (upper - lower + 1)) + lower;
    do{
        printf("Guess the number: ");
        scanf("%d",&x);
        if(x>number){
            printf("Try something smaller\n");
        }
        else if(x<number){
            printf("Try something bigger\n");
        }
        count++;
    }while(x!=number);

    if(x==number){
        printf("Congratulations , you guessed it right.\n");
        printf("You took a total of %d attempts for this.\n",count);
    }

    int score;
        if (count == 1) {
            score = 100;
            printf("Your score: %d points\n", score);
            printf("Perfect score\n");
        } else if (count <= 3) {
            score = 80;
            printf("Your score: %d points\n", score);
            printf("Good score\n");
        } else if (count <= 5) {
            score = 50;
            printf("Your score: %d points\n", score);
            printf("Average score\n");
        } else if (count <= 8) {
            score = 30;
            printf("Your score: %d points\n", score);
            printf("Below average score\n");
        } else {
            score = 0;
            printf("Your score: %d points\n", score);
            printf("No points for taking too many attempts\n");
        }

        printf("Want to replay?\n");
        printf("Press 1 for Yes and 0 for No\n");
        scanf("%d",&t);

        }

    return 0;
}
