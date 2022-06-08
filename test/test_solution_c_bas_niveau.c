//
// Created by Hadrien on 2022-06-01.
//
//#include "test_solution_c_bas_niveau.h"
#include "unity/unity.h"
#include <string.h>
#include "../src/solution_c_bas_niveau.h"

void setUp(){

}

void tearDown(){

};

/**
 * Test function
 */
void test_strLenght(){
    char* testString = "Hello Word";
    size_t leng = strlen(testString);
    TEST_ASSERT_EQUAL_UINT(10, leng);
}

void test_strCopy(){
    char* testString = "Hello Word";
    char testCpyString[20];
    char *firstCharCpyString = NULL;
    firstCharCpyString = strcpy(testCpyString, testString);
    TEST_ASSERT_EQUAL_PTR(testCpyString, firstCharCpyString);
    TEST_ASSERT_EQUAL_STRING(testString, testCpyString);
}

void test_strReverse(){
    char* testString = "Hello Word";
    int testStringLgt = strlen(testString);
    char testRevertString[20];
    char *firstCharRevertString;
    strcpy(testRevertString, testString);
    firstCharRevertString = strreverse(testRevertString);
    TEST_ASSERT_EQUAL_PTR(testRevertString, firstCharRevertString);
    for (int i = 0; i < testStringLgt; i++){
        TEST_ASSERT_EQUAL_CHAR(testString[testStringLgt - i - 1], testRevertString[i]);
    }
}

void test_longToDec(){
    char* testString1 = "10";
    //char* testString2 = "-13";
    char* testString3 = "4294967295";
    //char* testString4 = "-9223372036854775808";
    char* testString5 = "0";
    char stringBuffer[13];

    TEST_ASSERT_EQUAL_STRING(testString1, longtodec((unsigned int)10, stringBuffer));
    //TEST_ASSERT_EQUAL_STRING(testString2, longtodec((long)-13, stringBuffer));
    TEST_ASSERT_EQUAL_STRING(testString3, longtodec((unsigned int)4294967295, stringBuffer));
    //TEST_ASSERT_EQUAL_STRING(testString4, longtodec((long)-9223372036854775807, stringBuffer));
    TEST_ASSERT_EQUAL_STRING(testString5, longtodec((unsigned int)0, stringBuffer));
}


/**
 * Main
 */
int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_strLenght);
    RUN_TEST(test_strCopy);
    RUN_TEST(test_strReverse);
    RUN_TEST(test_longToDec);
    //RUN_TEST(test_function_should_doBlahAndBlah);
    //RUN_TEST(test_function_should_doAlsoDoBlah);
    return UNITY_END();
}
