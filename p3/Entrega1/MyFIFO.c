
#include <stdio.h>
#include <stdlib.h>
#include "MyFifo.h"




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
    
    if(fifo->cnt == fifo->size) {
        printf("%d não foi inserido (tamanho máximo atingido)\n", value);
        return fifo_Full; 
    }
    fifo->data[fifo->tail] = value;
    if(fifo->tail == fifo->size) fifo->tail = 0;
    fifo->tail++;
    fifo->cnt++;
    printf("Inserir %d\n", value);
    return 0;
}


/**
 *
 * \brief Removes an element from the FIFO
*/
int MyFIFORemove(struct MyFIFO *fifo){
    printf("\nRemove %d", fifo->data[fifo->head]);
    if(fifo->cnt == 0) return fifo_Empty;
    if(fifo->head == fifo->size){
        fifo->head = 0;
    } 
    else{
        fifo->head++;
        fifo->cnt--;
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



void MyFIFOPrint(struct MyFIFO *fifo)
{
    if((fifo->cnt - fifo->head) < fifo->size){
        printf("eNTROU AQUI");
        for(int i = fifo->head; i < (fifo->head + fifo->cnt); i++){
            printf("%d ", fifo->data[i]);
        }
    }else{
        printf("eNTROU AQUI ASDASDASD");
        int res = 0;
        for(int i = fifo->head; i < fifo->size; i++){
            printf("%d ", fifo->data[i]);
            res++;
        }
        for(int i = 0; i <= (fifo->cnt - res); i++){ 
            printf("%d ", fifo->data[i]);
        }
    }

}

