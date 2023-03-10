#include <stdio.h>  
#include <limits.h>
#include "MyFifo.h"



void MyFIFOInit(int size,struct MyFifo FIFO){
    // Initialize the FIFO
    for(int i=0; i<size; i++){
        FIFO.fifo[i] = 0;
    }
    FIFO.Last_Pointer = 0;  // último a ser colocado 
    FIFO.First_Pointer = 0; // Primeiro a ser colocado 
}

int MyFIFOInsert(int value,struct MyFifo FIFO){
    // Add a value to the FIFO
    if(FIFO.Last_Pointer == INT_MAX && FIFO.First_Pointer == 0){
        return full_fifo;
    }
    else if (FIFO.Last_Pointer == INT_MAX && FIFO.First_Pointer != 0)
    {
        FIFO.First_Pointer = 0;
        FIFO.fifo[FIFO.Last_Pointer] = value;
        FIFO.Last_Pointer++;
    }
    else{
        FIFO.fifo[FIFO.Last_Pointer] = value;
        FIFO.Last_Pointer++;
    }

    return 0;
    }
    
void MyFIFORemove(struct MyFifo FIFO){

	if(FIFO.Last_Pointer == 0){
		return empty_fifo; 
	}else{

        FIFO.Last_Pointer--;
    }}

int MyFIFOPeep(struct MyFifo FIFO){
    return FIFO.fifo[FIFO.Last_Pointer];
}

int MyFIFOSize(struct MyFifo FIFO){
    return FIFO.First_Pointer;
}
