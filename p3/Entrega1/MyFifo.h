#include <stdio.h>
#include <limits.h>
#define fifo_Empty 1
#define fifo_Full 2

struct MyFIFO{
    int *data;
    int head;
    int tail;
    int cnt; 
    int size;
};


void MyFIFOInit(struct MyFIFO *fifo,int size);

int MyFIFOInsert(struct MyFIFO *fifo,int value);

int MyFIFORemove(struct MyFIFO *fifo);

int MyFIFOPeep(struct MyFIFO *fifo);

int MyFIFOSize(struct MyFIFO *fifo);

void MyFIFODestroy(struct MyFIFO *fifo);

void MyFIFOPrint(struct MyFIFO *fifo);