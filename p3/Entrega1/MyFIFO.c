
#include <stdio.h>
#include <stdlib.h>
#include "MyFifo.h"



struct MyFIFO{
    int *data;
    int head;
    int tail;
    int cnt; 
    int size;
};
/**
 *
 * \brief init the module
*/
void MyFIFOInit(struct MyFIFO *fifo,int size){   
    fifo->data = (int*) malloc(size * sizeof(int));
    fifo->head = 0;
    fifo->tail = 0;
    fifo->cnt = 0;
    fifo->size = size;
}


/**
 *
 * \brief adds an element to the FIFO
*/
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


/**
 *
 * \brief Removes an element from the FIFO
*/
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
/**
 *
 * \brief Return the oldest element on the FIFO,but does not remove
*/


int MyFIFOPeep(struct MyFIFO *fifo){
    return fifo->data[fifo->head];
}

/**
 *
 * \brief Returns the number of elements of the FIFO
*/
int MyFIFOSize(struct MyFIFO *fifo){
    return fifo->cnt;
}


/**
 *
 * \brief Destroy the FIFO
*/

void MyFIFODestroy(struct MyFIFO *fifo){
    free(fifo->data);
    free(fifo);
}




