#include <stdio.h>
#include <stdlib.h>

struct MyFIFO{
    int *data;
    int head;
    int tail;
    int cnt; 
    int size;
};

struct MyFIFO* MyFIFOInit(int size){   
    struct MyFIFO *fifo = (struct MyFIFO*) malloc(sizeof(fifo));
    fifo->data = (int*) malloc(size * sizeof(int));
    fifo->head = 0;
    fifo->tail = 0;
    fifo->cnt = 0;
    fifo->size = 0;
    return fifo;
    }

int MyFIFOInsert(struct *fifo,int value){
    if(fifo->cnt == fifo->size) return fifo_Full; // Se tiver o máximo elementos do array circular
    fifo->data[fifo->tail] = value;
    if(fifo->tail == fifo->size) fifo->tail = 0;
    fifo->count++;
    return 0;
}

int MyFIFORemove(struct *fifo){
    if(fifo->cnt = 0) return fifo_Empty
    if(fifo->head == fifo->size){
        fifo->head = 0;
    } 
    else{
        fifo->head++:
    }

    return 0;

}

int MyFIFOPeep(struct MyFIFO *fifo){
    return fifo->data[fifo->head];
}

int MyFIFOSize(struct MyFIFO *fifo){
    return fifo->size;
}

void MyFIFODestroy(struct FIFO *fifo){
    free(fifo->data);
    free(fifo);
}


