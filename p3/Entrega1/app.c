/**   \file app.c
 *    \brief test application
 *
 *    test application to convice the observer that the FIFO works 
 *    \author Vitor Silva,Tiago Pereira
 *    \date 13 March 2023
 *    \bug No known bugs.
 */
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
