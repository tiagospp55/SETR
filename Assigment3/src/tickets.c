#include "tickets.h"
#define ERROR -1
unsigned int credit = 0;
unsigned int movieIndex = 0;
unsigned int coinValue[] = {1,2,5,10};
unsigned char movies[] = {'A','A','A','B','B'};
unsigned int sessions[] = {'19','21','22','19','20'};
unsigned int ticketPrice[] = {10,10,10,10,10};
unsigned char state = IDLE;

int insertCoin(int coinIndex){
    if(coinIndex < 0 || coinIndex > 3){
        return ERROR;
    }
    credit += coinValue[coinIndex];
    return credit;
}

int browseMovies(int up_down){
    if(up_down != 1 && up_down != -1){
        return movieIndex;
    }
    movieIndex++;
    printk("Movie %c, %dH00 session, EUR %d \n", &movies[movieIndex], &sessions[movieIndex], &ticketPrice[movieIndex]0);
    return movieIndex
}

int selectMovie(int movieIndex){
    if(movieIndex < 0 && movieIndex > 5){
        return ERROR;
    }
    if(credit < ticketPrice[movieIndex]){
        printk("Not Enough Credit");
        return CREDIT_STATE;
    }
    credit -= ticketPrice[movieIndex];
    printk("You just spend %d, now you have %d", &ticketPrice[MovieIndex],&credit);
    return IDLE_STATE;
}

void returnCredits(){
	printk("%d EUR retorned",&credit);
	credit = 0;
}

void resetAll(void){
    credit = 0;
    movieIndex = 0;
}

