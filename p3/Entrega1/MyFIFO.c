#include <stdio.h>
#include <limits.h>
#include "MyFifo.h"



void MyFIFOInit(int size,struct MyFifo FIFO){
    // Initialize the FIFO
    for(int i=0; i<size; i++){
        FIFO.fifo[i] = 0;
    }
    FIFO.head = 0;
    FIFO.tail = 0;
}

int MyFIFOInsert(int value,struct MyFifo FIFO){
    // Add a value to the FIFO
    FIFO.fifo[FIFO.head] = value;
    if(FIFO.head == FIFO.tail){
        return full_fifo;
    }

    FIFO.head++;

    return 0;
    }
void MyFIFORemove(struct MyFifo FIFO){
    for(int i = 0; i < FIFO.head; i++){
        FIFO.fifo[i] = FIFO.fifo[i+1];
    }
    FIFO.head--;
}

int MyFIFOPeep(struct MyFifo FIFO){
    return FIFO.fifo[FIFO.head];
}

int MyFIFOSize(struct MyFifo FIFO){
    return FIFO.tail;
}
