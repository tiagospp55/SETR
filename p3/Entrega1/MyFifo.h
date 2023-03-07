#include <stdio.h>
#include <limits.h>

struct MyFifo
{
    int fifo[INT_MAX];
    int size_index = 0; //Tamanho da Fifo
    int pointer_index = 0; // Pointer para a última posição utilizada
};


void MyFIFOInit(int size,MyFifo FIFO){
    // Initialize the FIFO
    for(int i=0; i<size; i++){
        FIFO.fifo[i] = 0;
    }

}

void MyFIFOInsert(int value,MyFifo FIFO){
    // Add a value to the FIFO
    FIFO.fifo[FIFO.pointer_index] = value;
    FIFO.pointer_index++;
}



