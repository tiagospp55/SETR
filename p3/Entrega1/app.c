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
   int option = 0;
   int flag = 0;
   while(flag == 0){
      
   printf("Chose a option:\n1- Automatic Sequence\n2- Create a new fifo\n3- Insert a value\n4- Remove a value\n5- Print all the data\n6- Destroy the FIFO\n7- Exit\n ");
   struct MyFIFO fifo;
   scanf("%d", &option);
    
    while(option < 1 || option > 7) {
        printf("The option you entered is not one of the options\n");
        printf("Please enter a valid option: ");
        scanf("%d", &option);
        printf("\n");
    }

   int error[10]; // Só para mostrar o retorno dos valores de erro

   switch (option)
   {
   case 1:{
      printf("Iremos testar para uma FIFO de 5 posições\n");
      MyFIFOInit(&fifo, 5);
      for(int i = 0; i < 7; i++){
         error[i] = MyFIFOInsert(&fifo, i);
      }
      printf("A sexta e sétima inserção não vão funcionar, retornando o valor de erro 2\nValores de retorno:\n");
      for(int j = 0;  j < 7; j++){
         printf("%d ",error[j]);
      }
      printf("\nFicamos assim com os valores na FIFO de: \n");
      MyFIFOPrint(&fifo);
      printf("\nRemover 3 valores\n");
      MyFIFORemove(&fifo);
      MyFIFORemove(&fifo);
      MyFIFORemove(&fifo);
      printf("A head passou agora para: %d\n", fifo.head);
      printf("Temos assim %d valores dentro da FIFO\n", MyFIFOPeep(&fifo));
   
      MyFIFOPrint(&fifo);
      MyFIFOInsert(&fifo, 2);
      MyFIFOInsert(&fifo,5);
      MyFIFOPrint(&fifo);
      MyFIFORemove(&fifo);
      MyFIFORemove(&fifo);
      MyFIFOPrint(&fifo);
      
      break;
   }
   case 2:{
      printf("Qual o tamanho da FIFO que pretende criar?");
      int size;
      scanf("%d", &size);
      MyFIFOInit(&fifo, size);
      break;
   }  
   case 3:{
      if(fifo.size == 0){
         printf("Não existe FIFO criada, por favor crie uma\n");
         break;
      }
      int value;
      printf("Qual o valor que pretende inserir?");
      scanf("%d", &value);
      printf("\n");
      MyFIFOInsert(&fifo, value);
      break;
   }

   case 4:{
      if(fifo.size == 0){
         printf("Não existe FIFO criada, por favor crie uma\n");
         break;
      }
      MyFIFORemove(&fifo);
      break;
   }
   case 5:{
      if(fifo.size == 0){
         printf("Não existe FIFO criada, por favor crie uma\n");
         break;
      }
      MyFIFOPrint(&fifo);
      break;
   }
   case 6:{
      if(fifo.size == 0){
         printf("Não existe FIFO criada, por favor crie uma\n");
         break;
      }
      MyFIFODestroy(&fifo);
      break;
   }
   case 7:{
      flag = 1;
      break;
   }
   default:
      break;
   }
   
   }

}

//void MyFIFOInit(int size,struct MyFifo FIFO);

//int MyFIFOInsert(int value,struct MyFifo FIFO);

//void MyFIFORemove(struct MyFifo FIFO);

//int MyFIFOPeep(struct MyFifo FIFO);

//int MyFIFOSize(struct MyFifo FIFO);
