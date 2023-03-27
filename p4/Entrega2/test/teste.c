#include <unity.h>
#include "cmdproc.h"

extern char cmdString[MAX_CMDSTRING_SIZE];
extern unsigned char cmdStringLen = 0; 

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
	TEST_ASSERT_EQUAL_INT(0, cmdStringLen);
}
void test_newCmdChar(void)
{
	

	resetCmdString();
	TEST_ASSERT_INT(0, newCmdChar('a'));
	TEST_ASSERT_CHAR('a', cmdString[0]);
	TEST_ASSERT_INT(0, newCmdChar('b'));
	TEST_ASSERT_CHAR('b', cmdString[1]);
	TEST_ASSERT_INT(0, newCmdChar('c'));
	TEST_ASSERT_CHAR('c', cmdString[2]);
	TEST_ASSERT_INT(0, newCmdChar('d'));
	TEST_ASSERT_CHAR('d', cmdString[3]);
	TEST_ASSERT_INT(0, newCmdChar('e'));
	TEST_ASSERT_CHAR('e', cmdString[4]);
	TEST_ASSERT_INT(0, newCmdChar('f'));
	TEST_ASSERT_CHAR('f', cmdString[5]);
	TEST_ASSERT_INT(0, newCmdChar('g'));
	TEST_ASSERT_CHAR('g', cmdString[6]);
	TEST_ASSERT_INT(0,newCmdChar('h'));
	TEST_ASSERT_CHAR('h', cmdString[7]);
	TEST_ASSERT_INT(0,newCmdChar('i'));
	TEST_ASSERT_CHAR('i', cmdString[8]);
	TEST_ASSERT_INT(0, newCmdChar('j'));
	TEST_ASSERT_CHAR('j', cmdString[9]);
	TEST_ASSERT_INT(INVALID_STRING, newCmdChar('k'));
}

void test_cmdProcessor(void)
{
	resetCmdString();
	TEST_ASSERT_INT(INVALID_STRING,cmdProcessor());

	//Caso funcional para a instrução P
	newCmdChar('#');  //Verificar se o primeiro caracter é #
	newCmdChar('P');
	newCmdChar('1');
	newCmdChar('2');
	newCmdChar('3');
	newCmdChar((unsigned char)('P'+'1'+'2'+'3'));
	newCmdChar('!');  //Verificar se o ultimo caracter é !
	TEST_ASSERT_EQUAL_INT(0,cmdProcessor());



	resetCmdString();
	//Caso funcional para a instrução S
	newCmdChar('#'); // Detetado
	newCmdChar('S');
	newCmdChar('!');
	TEST_ASSERT_EQUAL_INT(0,cmdProcessor());
	resetCmdString();

	//Caso não funcional para instruções não existentes
	newCmdChar('#'); //Verificar se o primeiro caracter é #
	newCmdChar('D'); 
	newCmdChar('!'); //Verificar se o ultimo caracter é !
	TEST_ASSERT_EQUAL_INT(INVALID_STRING,cmdProcessor());
	resetCmdString();
	
//Casos em que o terminador não aparece

	
}
void test_MyVectorLib_Len_RightSize(void)
{
	
}

int main(void)
{
	UNITY_BEGIN();
	
	RUN_TEST(test_resetCmd_String);
	RUN_TEST(test_newCmdChar);
	RUN_TEST(test_cmdProcessor);
		
	return UNITY_END();
}