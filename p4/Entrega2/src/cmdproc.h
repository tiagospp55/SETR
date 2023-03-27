#ifndef __CMD_PROC_H_
#define __CMD_PROC_H_
#define INVALID_STRING -1
#define INVALID_COMAND -2
#define CS_ERROR -3
#define INVALID_FORMAT -4
/* Some defines */
/* Other defines should be return codes of the functions */
/* E.g. #define CMD_EMPTY_STRING -1                      */
#define MAX_CMDSTRING_SIZE 10 /* Maximum size of the command string */ 
#define SOF_SYM '#'	          /* Start of Frame Symbol */
#define EOF_SYM '!'           /* End of Frame Symbol */

/* Function prototypes */
int cmdProcessor(void);
int newCmdChar(unsigned char newChar);
void resetCmdString(void);

#endif

