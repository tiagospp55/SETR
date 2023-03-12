#include <stdio.h>
#include "MyFifo.h"

int main(void){
    struct MyFifo FIFO;

    MyFIFOInit(100,FIFO);

    for(int i = 0; i < 5; i++){
        int value = random();
        MyFIFOInsert(value, FIFO);
    }

    

}

//void MyFIFOInit(int size,struct MyFifo FIFO);

//int MyFIFOInsert(int value,struct MyFifo FIFO);

//void MyFIFORemove(struct MyFifo FIFO);

//int MyFIFOPeep(struct MyFifo FIFO);

//int MyFIFOSize(struct MyFifo FIFO);
