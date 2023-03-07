#include <stdio.h>
#include <limits.h>
#define full_fifo 1
#define empty_fifo 2
struct MyFifo
{
    int fifo[INT_MAX];
    int tail = 0; // Tamanho da Fifo
    int head = 0; // Pointer para a última posição utilizada
};

void MyFIFOInit(int size,struct MyFifo FIFO);

void MyFIFOInsert(int value,struct MyFifo FIFO);

void MyFIFORemove(struct MyFifo FIFO);

int MyFIFOPeep(struct MyFifo FIFO);

int MyFIFOSize(struct MyFifo FIFO);


