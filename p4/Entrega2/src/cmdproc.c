/* ***************************************************** */
/* SETR 22/23, Paulo Pedreiras                           */
/* Base code for Unit Testing                            */
/*    Simple example of command processor                */
/*    Note that there are several simplifications        */
/*    E.g. Kp, Ti and Td usually are not integer values  */
/*    Code can (and should) be improved. E.g. error      */ 
/*        codes are "magic numbers" in the middle of the */
/*        code instead of being (defined) text literals  */
/* ***************************************************** */

/**   \file cmdproc.c
 *    \brief functions to create the PID controller
 *
 *    \author Vitor Silva,Tiago Pereira
 *    \date 28 March 2023
 *    \bug 
 *    \version 1.0
 */

#include <stdio.h>

#include "cmdproc.h"

/* PID parameters */
/* Note that in a real application these vars would be extern */
char Kp, Ti, Td;

/* Process variables */ 
/* Note that in a real application these vars would be extern */
int setpoint, output, error; 

/* Internal variables */
/**
 *   \var cmdString 
 *   \brief String to put chrs of the PID controller
*/
char cmdString[MAX_CMDSTRING_SIZE];
/**
 *   \var cmdStringLen
 *   \brief Length of string
 */
unsigned char cmdStringLen = 0; 

/* ************************************************************ */
/* Processes the the chars received so far looking for commands */
/* Returns:                                                     */
/*  	 0: if a valid command was found and executed           */
/* 	-1: if empty string or incomplete command found             */
/* 	-2: if an invalid command was found                         */
/* 	-3: if a CS error is detected (command not executed)        */
/* 	-4: if string format is wrong                               */
/* ************************************************************ */

/**
 *
 * \brief Processes the the chars received so far looking for commands
 * 
 * 
 * \param[out]  return 0 if a valid command was found and executed 
 * -
 * -1: if empty string or incomplete command found 
 * -
 * -2: if an invalid command was found 
 * - 
 * -3: if a CS error is detected (command not executed) 
 * -
 * -4: if string format is wrong               
*/
int cmdProcessor(void)
{
	int i;
	
	/* Detect empty cmd string */
	if(cmdStringLen == 0)
		return INVALID_STRING; 
	
	/* Find index of SOF */
	for(i=0; i < cmdStringLen; i++) {
		if(cmdString[i] == SOF_SYM) {
			break;
		}
	}
	
	/* If a SOF was found look for commands */
	if(i < cmdStringLen ) {
		if(cmdString[i+1] == 'P' && cmdString[i+6] == '!') { /* P command detected */
			Kp = cmdString[i+2];
			Ti = cmdString[i+3];
			Td = cmdString[i+4];
			resetCmdString();
			return 0;
		}
		
		if(cmdString[i+1] == 'S'  && cmdString[i+2] == '!') { /* S command detected */
			printf("Setpoint = %d, Output = %d, Error = %d \n", setpoint, output, error);
			resetCmdString();
			return 0;
		}		
		return INVALID_COMMAND;
	}
	/* cmd string not null and SOF not found */
	return INVALID_FORMAT;

}

/* ******************************** */
/* Adds a char to the cmd string 	*/
/* Returns: 				        */
/*  	 0: if success 		        */
/* 		-1: if cmd string full 	    */
/* ******************************** */
/**
 *
 * \brief Adds a char to the cmd string
 * 
 * \param[in] void char to put in string
 * \param[out]  return 0 if success
 *  -
 * -1 if cmd string full                 
*/
int newCmdChar(unsigned char newChar)
{
	/* If cmd string not full add char to it */
	if (cmdStringLen < MAX_CMDSTRING_SIZE) {
		cmdString[cmdStringLen] = newChar;
		cmdStringLen +=1;
		return 0;		
	}
	
	/* If cmd string full return error */
	return INVALID_STRING;
}

/* ************************** */
/* Resets the commanbd string */  
/* ************************** */

/**
 *
 * \brief Reset the command string
 *                 
*/
void resetCmdString(void)
{
	cmdStringLen = 0;		
	return;
}
