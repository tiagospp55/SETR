#include <stdio.h>
#include <stdlib.h>
#include "MyFifo.h"

void MyFIFOInit(struct MyFIFO *fifo,int size){   
    fifo->data = (int*) malloc(size * sizeof(int));
    fifo->head = 0;
    fifo->tail = 0;
    fifo->cnt = 0;
    fifo->size = size;
}

int MyFIFOInsert(struct MyFIFO *fifo,int value){
     printf("insert\n");
    if(fifo->cnt == fifo->size) {
        return fifo_Full; // Se tiver o máximo elementos do array circular
        printf("Não inserido (tamanho máximo atingido)");
    }
    fifo->data[fifo->tail] = value;
    if(fifo->tail == fifo->size) fifo->tail = 0;
    fifo->tail++;
    fifo->cnt++;
   
    return 0;
}

int MyFIFORemove(struct MyFIFO *fifo){
    printf("remove\n");
    if(fifo->cnt == 0) return fifo_Empty;
    if(fifo->head == fifo->size){
        fifo->head = 0;
    } 
    else{
        fifo->head++;
        fifo->cnt--;
        printf(" cnt depois remove %d\n", fifo->cnt);
    }
    
    return 0;

}

int MyFIFOPeep(struct MyFIFO *fifo){
    return fifo->data[fifo->head];
}

int MyFIFOSize(struct MyFIFO *fifo){
    return fifo->cnt;
}

void MyFIFODestroy(struct MyFIFO *fifo){
    free(fifo->data);
    free(fifo);
}


