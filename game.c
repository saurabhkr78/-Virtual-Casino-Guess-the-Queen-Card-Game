#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int cash=100;
 void play(int bet){
    // char* c=(char*)malloc(100*sizeof(char));
    // c[0]='J';c[1]='Q';c[2]='K';
    char c[3]={'J','Q','K'};
    printf("Suffling Virtual Card....\n");
    
    //seeding random number generator
    srand(time(NULL));
    for(int i=0;i<5;i++){
        int x=rand()%3;
        int y=rand()%3;
        //swap character at position at x and y
        int temp=c[x];
        c[x]=c[y];
        c[y]=temp;
    }
    int guessNumber;
        printf("Guess Position of Queen Card whether it is at 1,2,3\n");
        scanf("%d",&guessNumber);
        if(c[guessNumber-1]=='Q')
        {
        cash+=3*bet;
        printf("Woohoo!You Win ;)\nResult=%c %c %cTotal Cash=%d\n",c[0],c[1],c[2],cash);
        }
        else
        {
        cash-=3*bet; 
        printf("Alas!You lost :(\nResult=%c %c %c \nTotal Cash=%d\n",c[0],c[1],c[2],cash);
        }
        
    // free(c);    
    }
 

int main(){
    printf("Welcome To Virtual Casino\n");
    int bet;
    while(cash>0){
    printf("Enter Your Betting amount? $");
    scanf("%d",&bet);
    if(bet==0||bet>cash)
    break;
    
    play(bet);
    }
    
}