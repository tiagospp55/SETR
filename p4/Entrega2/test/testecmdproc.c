#include <unity.h>
#include "cmdproc.h"

extern char cmdString[MAX_CMDSTRING_SIZE];
extern unsigned char cmdStringLen; 

void setUp(void)
{
	return;
}
void tearDown(void)
{
	return;
}

void test_resetCmd_String(void){
	resetCmdString();
	TEST_ASSERT_EQUAL_INT(INVALID_STRING, cmdProcessor());
	TEST_ASSERT_EQUAL_INT(0,cmdStringLen);


}
void test_newCmdChar(void)
{
	/*Perguntar qual é a melhor forma de testar*/
	char cmdStringCorrect[] = {'a','b','c','d','e','f','g','h','i','j'};
	resetCmdString();
	TEST_ASSERT_EQUAL_INT(0, newCmdChar('a'));
	TEST_ASSERT_EQUAL_CHAR('a', cmdString[0]);
	TEST_ASSERT_EQUAL_INT(0, newCmdChar('b'));
	TEST_ASSERT_EQUAL_INT(0, newCmdChar('c'));
	TEST_ASSERT_EQUAL_INT(0, newCmdChar('d'));
	TEST_ASSERT_EQUAL_INT(0, newCmdChar('e'));
	TEST_ASSERT_EQUAL_INT(0, newCmdChar('f'));
	TEST_ASSERT_EQUAL_INT(0, newCmdChar('g'));
	TEST_ASSERT_EQUAL_INT(0,newCmdChar('h'));
	TEST_ASSERT_EQUAL_INT(0,newCmdChar('i'));
	TEST_ASSERT_EQUAL_INT(0, newCmdChar('j'));
	TEST_ASSERT_EQUAL_INT_MESSAGE(INVALID_STRING, newCmdChar('k'), "Tem que dar o valor de erro -1");
	TEST_ASSERT_EQUAL_CHAR_ARRAY_MESSAGE(cmdStringCorrect,cmdString, MAX_CMDSTRING_SIZE, "Os chars nao estao a ser colocados corretamente");
	resetCmdString();
	
}

void test_cmdProcessor_Correct(void)
{
	resetCmdString();
	TEST_ASSERT_EQUAL_INT_MESSAGE(INVALID_STRING,cmdProcessor(), "cmdStrLen tem que ser 0");

	/*Caso funcional para a instrução P*/
	newCmdChar('#');  /*Verificar se o primeiro caracter é # */
	newCmdChar('P');
	newCmdChar('1');
	newCmdChar('2');
	newCmdChar('3');
	newCmdChar((unsigned char)('P'+'1'+'2'+'3'));
	newCmdChar('!');  /*Verificar se o ultimo caracter é !*/
	TEST_ASSERT_EQUAL_INT_MESSAGE(0,cmdProcessor(), "Caso funcional para o comando P não está a funcionar");
	


	resetCmdString();
	/* Caso funcional para a instrução S */
 	newCmdChar('#'); /*Detetado*/
	newCmdChar('S');
	newCmdChar('!');
	TEST_ASSERT_EQUAL_INT_MESSAGE(0,cmdProcessor(), "Caso funcional para o comando S não está a funcionar");
	resetCmdString();

	
}


void test_cmdProcessor_Fail(void){
	/*Caso não funcional para instruções não existentes */
	newCmdChar('#'); 
	newCmdChar('D'); 
	newCmdChar('!');
	TEST_ASSERT_EQUAL_INT_MESSAGE(INVALID_COMMAND,cmdProcessor(), "Falha a detetar os casos não funcionais para instruções não existentes ");

	resetCmdString();
	
	newCmdChar('+');
	newCmdChar('S'); 
	newCmdChar('!');
	TEST_ASSERT_EQUAL_INT_MESSAGE(INVALID_FORMAT,cmdProcessor(), "Falha a detetar os casos em que o incializador não é # no comando S");
	resetCmdString();
	newCmdChar('+');
	newCmdChar('P'); 
	newCmdChar('!');
	TEST_ASSERT_EQUAL_INT_MESSAGE(INVALID_FORMAT,cmdProcessor(), "Falha a detetar os casos em que o inicializador nao e # no comando P");
	resetCmdString();

	newCmdChar('#');  
	newCmdChar('P');
	newCmdChar('1');
	newCmdChar('2');
	newCmdChar('3');
	newCmdChar((unsigned char)('P'+'1'+'2'+'3'));
	newCmdChar('a');
	TEST_ASSERT_EQUAL_INT_MESSAGE(INVALID_COMMAND,cmdProcessor(), "Falha a detetar os casos em que nao tem o finalizador ! no comando P");
	resetCmdString();
	
	newCmdChar('#'); /*Detetado*/
	newCmdChar('S');
	newCmdChar('+');
	TEST_ASSERT_EQUAL_INT_MESSAGE(INVALID_COMMAND,cmdProcessor(), "Falha a detetar os casos em que nao tem o finalizador ! no comando S");
	resetCmdString();
}


int main(void)
{
	UNITY_BEGIN();
	
	RUN_TEST(test_resetCmd_String);
	RUN_TEST(test_newCmdChar);
	RUN_TEST(test_cmdProcessor_Correct);
	RUN_TEST(test_cmdProcessor_Fail);
		
	return UNITY_END();
}