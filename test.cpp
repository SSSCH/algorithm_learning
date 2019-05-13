#include <iostream>
#include <memory.h>
#include <math.h>
#include "Solution.h"
#define EXPTCT_EQ_STRING(expect, actual, length)  do{ \
    test_count ++;\
    if(sizeof(expect) == (length+1) && memcmp(expect, actual, length) == 0) {\
        test_parse_count++;} \
    else {\
        fprintf(stderr, "%s%d, expect: %s, actual: %s\n", __FILE__, __LINE__, expect, actual);}\
}while(0)
#define EXPTCT_EQ_DATA(expect, actual, length)  do{ \
    test_count ++;\
    if((sizeof(expect)/sizeof(int)) == (length) && (memcmp(expect, actual, (length-1)*sizeof(int)) == 0)) {\
        test_parse_count++;} \
    else {\
        fprintf(stderr, "%s%d\n", __FILE__, __LINE__);\
        fprintf(stderr, "expect is:\n");\
        for(int i =0; i < length; i++){\
            fprintf(stderr, "%d\t", expect[i]);\
        }\
        fprintf(stderr, "\n");\
        fprintf(stderr, "actual is:\n");\
        for(int i =0; i < length; i++){\
            fprintf(stderr, "%d\t", actual[i]);\
        }\
        fprintf(stderr, "\n");\
    }\
}while(0)

#define EXPECT_EQ(expect, actual, object_format)   EXPECT_EQ_BASE((expect==actual), expect, actual, object_format)
#define EXPECT_EQ_BASE(equality, expect, actual, object_format) \
                                do{  \
                                test_count++; \
                                if(!equality){ \
                                fprintf(stderr, "%s%d, expect: " object_format ", actual:" object_format "\n", __FILE__, __LINE__, expect, actual); \
                                } \
                                else \
                                test_parse_count++; \
                                }while(0) \

static int test_count = 0;
static int test_parse_count = 0;
MySolution::Solution solution;

using namespace std;
using namespace MySolution;
void test_duplicate(){
   int numbers[] = {3, 5, 4 ,3, 2, 1};
   int duplication[] = { 0 };
   EXPECT_EQ(true, solution.duplicate(numbers, 6, duplication), "%d");
   EXPECT_EQ(3, *duplication, "%d");
}
void test_find2dArrary(){
    int numbers[] =    {1,3,5,7,9,
                        2,4,6,8,10,
                        3,5,7,9,11,
                        4,6,8,10,12,
                        5,7,9,11,13,};
    EXPECT_EQ(true, solution.find_2dArrary(numbers, 5, 5, 4), "%d");
}
void test_SubmitBlank(){
    char string[27] = " hello world  ! ";
    EXPTCT_EQ_STRING("%20hello%20world%20%20!%20", solution.submit_blank(string), 26);
}
void test_PrintListReversingly_Iteratively(){
    ListNode head; head.m_nKey = 1;
    ListNode second; second.m_nKey = 2;
    ListNode third; third.m_nKey = 3;
    ListNode forth; forth.m_nKey = 4;
    ListNode fifth; fifth.m_nKey = 5;
    ListNode sixth; sixth.m_nKey = 6;
    head.M_pNext = &second;
    second.M_pNext = &third;
    third.M_pNext = &forth;
    forth.M_pNext = &fifth;
    fifth.M_pNext = &sixth;
    sixth.M_pNext = nullptr;
    solution.PrintListReversing_Iteratively(&head);
    solution.PrintListReversing_Recursively(&head);
}
void test_2stack_simulate_queue(){
    MySolution::CQueue<int> myQueue;
    for (int i = 0; i < 7 ; ++i) {
        myQueue.AppendTail(i);
        std::cout << "head is: " << myQueue.BOTTON() << "\t" << std::endl;
        myQueue.DeletHead();
    }

}
void test_Fibonacci(){
    EXPECT_EQ(solution.Fibonacci_Recursively(3), solution.Fibonacci_Iteratively(3), "%lld");
    EXPECT_EQ(solution.Fibonacci_Recursively(5), solution.Fibonacci_Iteratively(5), "%lld");
    //EXPECT_EQ(solution.Fibonacci_Recursively(50), solution.Fibonacci_Iteratively(50), "%lld");  //此时，递归的效率已经十分的低，速度太慢了
    EXPECT_EQ(solution.JumpStep(1)+solution.JumpStep(2), solution.JumpStep(3), "%lld");
    EXPECT_EQ(solution.JumpStep(7)+solution.JumpStep(8), solution.JumpStep(9), "%lld");
    EXPECT_EQ(solution.JumpStepPlus_Math(17), solution.JumpStepPlus_DynamicPlan(17),"%lld");
}
void test_quick_sort(){
    int data2[] = {1,2};
    int data1[16] = {-1, 27, 4, 44, 2, 5, 17, 8, 3, 7, 10, 15,25, 20, -30, 50};
    int data_sorted1[16] = {-30,-1, 2, 3, 4, 5, 7, 8, 10, 15, 17, 20, 25, 27, 44, 50};
    solution.QuickSort(data1, 16, 0, 15);
    solution.QuickSort(data2, 2 ,0, 1);
    EXPTCT_EQ_DATA(data_sorted1, data1, 16);
    EXPTCT_EQ_DATA(data2, data2, 2);
}
void test_MinNumberInRotatArrary(){
    int rotatArrary1[] = {14,14,15,16,17,18,19,20,22,23,24,25,26,29,33,34,3,4,5,6,7,8,9,10,11,12,13};
    int rotatArrary2[] = {1};
    int rotatArrary3[] = {1,1,1,1,0,1,1};
    int rotatArrary4[] = {1,2,3,4,5,6,7,8,9};
    EXPECT_EQ(3, solution.MinNumberInRotateArrary(rotatArrary1, (sizeof(rotatArrary1)/ sizeof(int))), "%d");
    EXPECT_EQ(1, solution.MinNumberInRotateArrary(rotatArrary2, (sizeof(rotatArrary2)/ sizeof(int))), "%d");
    EXPECT_EQ(0, solution.MinNumberInRotateArrary(rotatArrary3, (sizeof(rotatArrary3)/ sizeof(int))), "%d");
    EXPECT_EQ(1, solution.MinNumberInRotateArrary(rotatArrary4, (sizeof(rotatArrary4)/ sizeof(int))), "%d");
}
void test_Find_Matrix_Path(){
    char matrix[] = {"wqioeurgss" //10*4
                     "kjgvbsdvas"
                     "wuierfvhss"
                     "klvaskvasf"};
    char matrix1[] = {"asshjasldfasd"};
    char matrix2[] = {"ssssssssssss"};
    char* str1 = "qjkwuierskv";
    char* str2 = "assh";
    char* str3 = "wieuof";
    char* str4 = "sss";
    EXPECT_EQ(true, solution.FindPathInMatrix(matrix, 4, 10 , str1), "%d");
    EXPECT_EQ(true, solution.FindPathInMatrix(matrix, 4, 10 , str2), "%d");
    EXPECT_EQ(true, solution.FindPathInMatrix(matrix, 4, 10 , str4), "%d");
    EXPECT_EQ(false, solution.FindPathInMatrix(matrix, 4, 10 , str3), "%d");
    EXPECT_EQ(false, solution.FindPathInMatrix(matrix, 4, 10 , str3), "%d");
    EXPECT_EQ(true, solution.FindPathInMatrix(matrix1, 1, 13 , str2), "%d");
    EXPECT_EQ(false, solution.FindPathInMatrix(matrix1, 1, 13 , str1), "%d");
    EXPECT_EQ(true, solution.FindPathInMatrix(matrix2, 12, 1 , str4), "%d");
    EXPECT_EQ(false, solution.FindPathInMatrix(matrix2, 12, 1 , str3), "%d");
}
void test_RobotRunRange(){
    EXPECT_EQ(7, solution.DigitalSum(7),"%d");
    EXPECT_EQ(8, solution.DigitalSum(1052), "%d");
    EXPECT_EQ(6, solution.RobotRunRange(10, 10, 2), "%d");
    EXPECT_EQ(3, solution.RobotRunRange(1, 10, 2), "%d");
    EXPECT_EQ(3, solution.RobotRunRange(10, 1, 2), "%d");
    EXPECT_EQ(99, solution.RobotRunRange(10, 10, 17), "%d");
    EXPECT_EQ(10, solution.RobotRunRange(11, 11, 3), "%d");
}
void test_CutRope(){
    EXPECT_EQ(1, solution.CutRope_DynamicProgramming(2), "%d");
    EXPECT_EQ(2, solution.CutRope_GreedyAlgorthm(3), "%d");
    EXPECT_EQ(36, solution.CutRope_DynamicProgramming(10), "%d");
    EXPECT_EQ(36, solution.CutRope_GreedyAlgorthm(10), "%d");
    EXPECT_EQ(243, solution.CutRope_DynamicProgramming(15), "%d");
    EXPECT_EQ(243, solution.CutRope_GreedyAlgorthm(15), "%d");
}
void test_Find1InNumber(){
    EXPECT_EQ(0, solution.Find_1_InNumber(0), "%d");
    EXPECT_EQ(1, solution.Find_1_InNumber(1), "%d");
    EXPECT_EQ(8,solution.Find_1_InNumber(0b11101010010101),"%d");
    EXPECT_EQ(0, solution.Find_1_InNumberX(0), "%d");
    EXPECT_EQ(1, solution.Find_1_InNumberX(1), "%d");
    EXPECT_EQ(10,solution.Find_1_InNumberX(0b1110101001010111),"%d");
    EXPECT_EQ(31, solution.Find_1_InNumberX(0x7fffffff), "%d");
    EXPECT_EQ(32, solution.Find_1_InNumberX(0xffffffff), "%d");
    EXPECT_EQ(1,solution.Find_1_InNumberX(0x80000000),"%d");
    EXPECT_EQ(31, solution.Find_1_InNumber(0x7fffffff), "%d");
    EXPECT_EQ(32, solution.Find_1_InNumber(0xffffffff), "%d");
    EXPECT_EQ(1,solution.Find_1_InNumber(0x80000000), "%d");
    printf("有符号数：-1=0x%x,\t无符号数：0x7fffffff=%u,\t0xffffffff=%u\n", -1, 0x7fffffff, 0xffffffff);
}
void test_Power(){
    EXPECT_EQ(1, solution.Power(0.0, 0), "%f");
    EXPECT_EQ(1, solution.Power(78.0, 0), "%f");
    EXPECT_EQ(pow(2.0, -8), solution.Power(2.0, -8), "%f");
    EXPECT_EQ(pow(-13, 9), solution.Power(-13, 9), "%f");
    EXPECT_EQ(pow(12, 8), solution.Power(12, 8), "%f");
}
void test_PrintNumber(){
    //solution.PrintNumber(0);
    solution.PrintNumber(2);
    //solution.PrintNumber(4);

}
void test_DeleteNode(){
    ListNode* Head = new ListNode;
    ListNode* first = new ListNode;first->m_nKey = 1;
    ListNode* second = new ListNode;second->m_nKey = 2;
    ListNode* third = new ListNode;third->m_nKey = 3;
    ListNode* forth = new ListNode;forth->m_nKey = 4;
    ListNode* fifth = new ListNode;fifth->m_nKey = 5;
    ListNode* sixth = new ListNode;sixth->m_nKey = 6;
    Head->M_pNext = first;
    first->M_pNext = second;
    second->M_pNext = third;
    third->M_pNext = forth;
    forth->M_pNext = fifth;
    fifth->M_pNext = sixth;
    sixth->M_pNext = nullptr;
    solution.DeletNode(&Head, first);
    EXPECT_EQ(2, Head->M_pNext->m_nKey, "%d");
    solution.DeletNode(&Head, fifth);
    EXPECT_EQ(6, forth->M_pNext->m_nKey, "%d");
    /*solution.DeletNode(&Head, sixth);  //不能连续删除相邻的节点
    EXPECT_EQ(nullptr, fifth->M_pNext, "s");*/
}
void test_DeleteDumplicateNode(){
    ListNode* Head = new ListNode;Head->m_nKey = NULL;
    ListNode* first = new ListNode;first->m_nKey = 1;
    ListNode* second = new ListNode;second->m_nKey = 2;
    ListNode* third = new ListNode;third->m_nKey = 2;
    ListNode* forth = new ListNode;forth->m_nKey = 2;
    ListNode* fifth = new ListNode;fifth->m_nKey = 3;
    ListNode* sixth = new ListNode;sixth->m_nKey = 3;
    Head->M_pNext = first;
    first->M_pNext = second;
    second->M_pNext = third;
    third->M_pNext = forth;
    forth->M_pNext = fifth;
    fifth->M_pNext = sixth;
    sixth->M_pNext = nullptr;
    int ret = solution.DeleteDumplicateNode(&Head);  //注意这边不要直接把DeketeDumplicateNode写入EXPECT_EQ,
                                                     // 因为当expect！=actual时，fprintf会再次打印actual。
                                                     // 若直接写入函数，相当于再执行一次，此时执行的输入已经没有重复的值了，必然返回0！
    EXPECT_EQ(2, ret, "%d");
}
void test_RegularExpressionMtach(){
    const char* str1 = "gg";
    const char* str2 = "gfff";
    const char* str3 = "ffxgggg";
    const char* str4 = "fgg";
    const char* str5 = "xggg";
    const char* str6 = "fhaksdfh";
    const char* str7 = "abcdefgt";
    const char* tempstr1 = ".f*g";
    const char* tempstr2 = ".f*";
    const char* tempstr3 = "f*.ggf*.g";
    const char* tempstr4 = "f*gg";
    const char* tempstr5 = ".ggg";
    const char* tempstr6 = "........";
    const char* tempstr7 = "abcdefg";
    bool ret1 = solution.RegularExpressionMatch(str1, tempstr1);
    bool ret2 = solution.RegularExpressionMatch(str2, tempstr2);
    bool ret3 = solution.RegularExpressionMatch(str3, tempstr3);
    bool ret4 = solution.RegularExpressionMatch(str4, tempstr4);
    bool ret5 = solution.RegularExpressionMatch(str5, tempstr5);
    bool ret6 = solution.RegularExpressionMatch(str6, tempstr6);
    bool ret7 = solution.RegularExpressionMatch(str7, tempstr7);
    EXPECT_EQ(true, ret1, "%d");
    EXPECT_EQ(true, ret2, "%d");
    EXPECT_EQ(true, ret3, "%d");
    EXPECT_EQ(true, ret4, "%d");
    EXPECT_EQ(true, ret5, "%d");
    EXPECT_EQ(true, ret6, "%d");
    EXPECT_EQ(false, ret7, "%d");
}
void test_StrToDigital(){
    double number = 0;
    solution.StrToDigital("123", &number);
    EXPECT_EQ(123, number, "%d");
    solution.StrToDigital("1.245235", &number);
    EXPECT_EQ(1.245235, number, "%d");
    solution.StrToDigital("0.1e+4", &number);
    EXPECT_EQ(0.1e+4, number, "%d");
    solution.StrToDigital("0.1E-4", &number);
    EXPECT_EQ(0.1E-4, number, "%d");
    EXPECT_EQ(true, solution.StrToDigital("0123", &number), "%d");
    EXPECT_EQ(false, solution.StrToDigital("0.e.2", &number), "%d");
    EXPECT_EQ(false, solution.StrToDigital("0..e", &number), "%d");
    EXPECT_EQ(false, solution.StrToDigital("0.e5.2", &number), "%d");
    EXPECT_EQ(false, solution.StrToDigital("0.e", &number), "%d");
    EXPECT_EQ(false, solution.StrToDigital("0e", &number), "%d");
    EXPECT_EQ(false, solution.StrToDigital("23awef12", &number), "%d");
    EXPECT_EQ(true, solution.StrToDigital("-0234", &number), "%d");
    //EXPECT_EQ(false, solution.StrToDigital("e+79797941234124123424123413465", &number), "%d");//to large

}
void test_AdjustArrary(){
    int arrary1[] = {1,2,3,4,5,6,7,8,9};
    const int AdjustedArraty1[] = {1,9,3,7,5,6,4,8,2};
    int arrary2[] = {2,4,6,8,10};
    const int AdjustedArraty2[] = {2,4,6,8,10};
    int arrary3[] = {1,3,5,7,9};
    const int AdjustedArraty3[] = {1,3,5,7,9};
    int arrary4[] = {1};
    const int AdjustedArraty4[] = {1};
    int arrary5[] = {1,4,6,7,3,6,2,8,9,10};
    const int AdjustedArraty5[] = {1,9,3,7,6,6,2,8,4,10};
    solution.AdjustArary(arrary1, 9,MySolution::Solution::JudgeOdd);
    EXPTCT_EQ_DATA(AdjustedArraty1, arrary1, 9);

    solution.AdjustArary(arrary2, 5, MySolution::Solution::JudgeOdd);
    EXPTCT_EQ_DATA(AdjustedArraty2, arrary2, 5);

    solution.AdjustArary(arrary3, 5, MySolution::Solution::JudgeOdd);
    EXPTCT_EQ_DATA(AdjustedArraty3, arrary3, 5);

    solution.AdjustArary(arrary4, 1, MySolution::Solution::JudgeOdd);
    EXPTCT_EQ_DATA(AdjustedArraty4, arrary4, 1);

    solution.AdjustArary(arrary5, 10, MySolution::Solution::JudgeOdd);
    EXPTCT_EQ_DATA(AdjustedArraty5, arrary5, 10);

}
void test_findKinList(){
    ListNode* Head = new ListNode;Head->m_nKey = NULL;
    ListNode* first = new ListNode;first->m_nKey = 1;
    ListNode* second = new ListNode;second->m_nKey = 2;
    ListNode* third = new ListNode;third->m_nKey = 3;
    ListNode* forth = new ListNode;forth->m_nKey = 4;
    ListNode* fifth = new ListNode;fifth->m_nKey = 5;
    ListNode* sixth = new ListNode;sixth->m_nKey = 6;
    Head->M_pNext = first;
    first->M_pNext = second;
    second->M_pNext = third;
    third->M_pNext = forth;
    forth->M_pNext = fifth;
    fifth->M_pNext = sixth;
    sixth->M_pNext = nullptr;
    EXPECT_EQ(6, solution.Find_K_InList(Head, 1), "%d");
    EXPECT_EQ(5, solution.Find_K_InList(Head, 2), "%d");
    EXPECT_EQ(4, solution.Find_K_InList(Head, 3), "%d");
    EXPECT_EQ(3, solution.Find_K_InList(Head, 4), "%d");
    EXPECT_EQ(2, solution.Find_K_InList(Head, 5), "%d");
    EXPECT_EQ(1, solution.Find_K_InList(Head, 6), "%d");
    EXPECT_EQ(-1, solution.Find_K_InList(Head, 7), "%d");
    EXPECT_EQ(-1, solution.Find_K_InList(Head, 8), "%d");

}
void test_FindRingNode(){
    //forward_list<int> list1 = {1,2,3,4,5,6,7,8,9};
    ListNode* Head = new ListNode;Head->m_nKey = NULL;
    ListNode* first = new ListNode;first->m_nKey = 1;
    ListNode* second = new ListNode;second->m_nKey = 2;
    ListNode* third = new ListNode;third->m_nKey = 3;
    ListNode* forth = new ListNode;forth->m_nKey = 4;
    ListNode* fifth = new ListNode;fifth->m_nKey = 5;
    ListNode* sixth = new ListNode;sixth->m_nKey = 6;
    Head->M_pNext = first;
    first->M_pNext = second;
    second->M_pNext = third;
    third->M_pNext = forth;
    forth->M_pNext = fifth;
    fifth->M_pNext = sixth;
    sixth->M_pNext = fifth;
    EXPECT_EQ(fifth->m_nKey, solution.FindRingNode(Head)->m_nKey, "%d");
}
void test_ReverseList(){
    ListNode* Head = new ListNode;Head->m_nKey = NULL;
    ListNode* first = new ListNode;first->m_nKey = 1;
    ListNode* second = new ListNode;second->m_nKey = 3;
    ListNode* third = new ListNode;third->m_nKey = 5;
    ListNode* forth = new ListNode;forth->m_nKey = 7;
    ListNode* fifth = new ListNode;fifth->m_nKey = 9;
    ListNode* sixth = new ListNode;sixth->m_nKey = 11;
    Head->M_pNext = first;
    first->M_pNext = second;
    second->M_pNext = third;
    third->M_pNext = forth;
    forth->M_pNext = fifth;
    forth->M_pNext = fifth;
    fifth->M_pNext = sixth;
    sixth->M_pNext = nullptr;
    EXPECT_EQ(sixth, solution.ReverseList_Recursively(Head), "%d");
    EXPECT_EQ(Head, solution.ReverseList_Iteratively(sixth), "%d");
    ListNode* newHead = Head;
    printf("25.after 2times Reversed List is : \n");
    while (newHead->M_pNext != nullptr) {
        printf("%d\t", newHead->m_nKey);
        newHead = newHead->M_pNext;
    }
    printf("%d\n", newHead->m_nKey);
}
void test_Merge2List(){
    ListNode* Head1 = new ListNode;Head1->m_nKey = 1;
    ListNode* first1 = new ListNode;first1->m_nKey = 2;
    ListNode* second1 = new ListNode;second1->m_nKey = 3;
    ListNode* third1 = new ListNode;third1->m_nKey = 4;
    ListNode* forth1 = new ListNode;forth1->m_nKey = 5;
    ListNode* fifth1 = new ListNode;fifth1->m_nKey = 6;
    ListNode* sixth1 = new ListNode;sixth1->m_nKey = 7;
    Head1->M_pNext = first1;
    first1->M_pNext = second1;
    second1->M_pNext = third1;
    third1->M_pNext = forth1;
    forth1->M_pNext = fifth1;
    forth1->M_pNext = fifth1;
    fifth1->M_pNext = sixth1;
    sixth1->M_pNext = nullptr;

    ListNode* Head = new ListNode;Head->m_nKey = 1;
    ListNode* first = new ListNode;first->m_nKey = 2;
    ListNode* second = new ListNode;second->m_nKey = 3;
    ListNode* third = new ListNode;third->m_nKey = 4;
    ListNode* forth = new ListNode;forth->m_nKey = 5;
    ListNode* fifth = new ListNode;fifth->m_nKey = 6;
    ListNode* sixth = new ListNode;sixth->m_nKey = 7;
    Head->M_pNext = first;
    first->M_pNext = second;
    second->M_pNext = third;
    third->M_pNext = forth;
    forth->M_pNext = fifth;
    forth->M_pNext = fifth;
    fifth->M_pNext = sixth;
    sixth->M_pNext = nullptr;
    ListNode* NewHead = solution.Merge2List(Head, Head1);
    printf("26.after Merged List is : \n");
    while (NewHead->M_pNext != nullptr) {
        printf("%d\t", NewHead->m_nKey);
        NewHead = NewHead->M_pNext;
    }
    printf("%d\n", NewHead->m_nKey);
}
void test_PrintMatrixClockWise(){
    int matrix[] = {1,2,3,4,5,
                    6,7,8,9,10,
                    11,12,13,14,15,
                    16,17,18,19,20,
                    21,22,23,24,25};
    int matrix1[] = {1,2,3,4,5,10,15,20,25,24,23,22,21,	16,11,6,7,8,9,14,19,18,17,12,13};
    int* ret = (int*)calloc(25, 4);
    solution.PrintMatrixClockWise(matrix, 5, 5, ret);
    EXPTCT_EQ_DATA(matrix1, ret, 25);
    free(ret);
}
void test_StackWithMin(){
    StackWithMin<int> mystack;
    mystack.push(7);                    //7
    EXPECT_EQ(7, mystack.min(), "%d");

    mystack.push(3);                    //7，3
    EXPECT_EQ(3, mystack.min(), "%d");

    mystack.push(4);                    //7，3，4
    mystack.push(4);                    //7，3，4，4
    EXPECT_EQ(3, mystack.min(), "%d");

    mystack.push(1);                    //7，3，4，4，1
    EXPECT_EQ(1, mystack.min(), "%d");

    mystack.push(5);                    //7，3，4，4，1，5
    EXPECT_EQ(1, mystack.min(), "%d");
    mystack.pop();                      //7，3，4，4，1
    mystack.pop();                        //7，3，4，4
    EXPECT_EQ(3, mystack.min(), "%d");
    mystack.pop();                      //7，3，4
    mystack.pop();                      //7，3
    mystack.pop();                      //7
    EXPECT_EQ(7, mystack.min(), "%d");
    mystack.pop();


}
void test_Judge_Match_Stack(){
    int list_push[] = {1,2,3,4,5,6};
    int list_pop1[] = {6,5,4,3,2,1};
    int list_pop2[] = {5,4,3,2,1,6};
    int list_pop3[] = {4,6,5,3,2,1};

    int list_pop4[] = {6,5,4,3,1,2};
    int list_pop5[] = {6,4,3,2,1,5};
    int list_pop6[] = {4,3,2,6,1,5};
    int list_pop7[] = {5,6,4,2,1,3};
    int list_pop8[] = {4,3,6,5,1,2};
    EXPECT_EQ(true, solution.Judge_Match_Stcak(list_push, list_pop1, 6), "%d");
    EXPECT_EQ(true, solution.Judge_Match_Stcak(list_push, list_pop2, 6), "%d");
    EXPECT_EQ(true, solution.Judge_Match_Stcak(list_push, list_pop3, 6), "%d");

    EXPECT_EQ(false, solution.Judge_Match_Stcak(list_push, list_pop4, 6), "%d");
    EXPECT_EQ(false, solution.Judge_Match_Stcak(list_push, list_pop5, 6), "%d");
    EXPECT_EQ(false, solution.Judge_Match_Stcak(list_push, list_pop6, 6), "%d");
    EXPECT_EQ(false, solution.Judge_Match_Stcak(list_push, list_pop7, 6), "%d");
    EXPECT_EQ(false, solution.Judge_Match_Stcak(list_push, list_pop8, 6), "%d");

}
void test_EQ_ComplexList(ComplexListNode* actual, ComplexListNode* expect){
  test_count ++;
  ComplexListNode* oldHead = expect;
  ComplexListNode* cloneHead = actual;
  bool IsDumplicateSuccess = false;
  while(actual != nullptr && expect != nullptr){
    if(((expect->m_nKey) == (actual->m_nKey)) && ((expect->M_pAny == nullptr && actual->M_pAny == nullptr) ||((expect->M_pAny->m_nKey) == (actual->M_pAny->m_nKey)))){
      expect = expect->M_pNext;
      actual = actual->M_pNext;
    }else{
      IsDumplicateSuccess = false;
      break;
    }
  }
  IsDumplicateSuccess = (expect == nullptr) && (actual == nullptr);
  if(!IsDumplicateSuccess){
    fprintf(stderr, "%s%d\n", __FILE__, __LINE__);
    fprintf(stderr, "key for old ComplexList:\n");
    while(oldHead != nullptr){
      fprintf(stderr, "%d,", oldHead->m_nKey);
      if (oldHead->M_pAny != nullptr) {
        fprintf(stderr, "%d\t", oldHead->M_pAny->m_nKey);
      }else fprintf_s(stderr, "\t");
      oldHead = oldHead->M_pNext;
    }
    fprintf(stderr, "\n");
    fprintf(stderr, "key for clone ComplexList:\n");
    while(cloneHead != nullptr){
      fprintf(stderr, "%d,", cloneHead->m_nKey);
      if (cloneHead->M_pAny != nullptr) {
        fprintf(stderr, "%d\t", cloneHead->M_pAny->m_nKey);
      }else fprintf_s(stderr, "\t");
      cloneHead = cloneHead->M_pNext;
    }
    fprintf(stderr, "\n");
  }else test_parse_count++;
}
void test_DumplicateComplexList(){
  auto Head = new ComplexListNode;
  auto first = new ComplexListNode;
  auto second = new ComplexListNode;
  auto third = new ComplexListNode;
  auto forth = new ComplexListNode;
  auto fifth = new ComplexListNode;
  auto sixth = new ComplexListNode;
    Head->m_nKey = 1;
    Head->M_pNext = first;
    Head->M_pAny = second;
    first->m_nKey = 3;
    first->M_pNext = second;
    first->M_pAny = third;
    second->m_nKey = 5;
    second->M_pNext = third;
    second->M_pAny = forth;
    third->m_nKey = 3;
    third->M_pNext = forth;
    third->M_pAny = fifth;
    forth->m_nKey = 4;
    forth->M_pNext = fifth;
    forth->M_pAny = nullptr;
    fifth->m_nKey = 1;
    fifth->M_pNext = sixth;
    fifth->M_pAny = first;
    sixth->m_nKey = 5;
    sixth->M_pNext = nullptr;
    sixth->M_pAny = second;
    ComplexListNode* CloneHead = nullptr;
    ComplexListNode* CloneHead1 = nullptr;
    solution.DumplicateComplexList_HashMap(Head, &CloneHead);
    solution.DumplicateComplexList(Head, &CloneHead1);
    test_EQ_ComplexList(CloneHead, Head);
    test_EQ_ComplexList(CloneHead1, Head);
}
void test_string_arrange(){
  char string1[]= {'a','b','c','\0'};

  solution.StringArrange(string1);
}
void test_find_MoreThanHalf_Number(){
    int number1[] = {7,7,7,4,7,6,7,7,9};
    int number2[] = {1,3,7,4,7,6,5,7,9};
    int ret = 0;
    EXPECT_EQ(true, solution.MoreThanHalfNumber(number1, &ret, 9), "%s");
    EXPECT_EQ(false, solution.MoreThanHalfNumber(number2, &ret, 9), "%s");
    EXPECT_EQ(7, ret, "%d");
}
void test_PrintLittle_k_Number(){
  int number1[] = {2,5,7,6,4,2,8,7,4};
  solution.PrintLittle_k_Number_Partition(number1, 1, 9);
  solution.PrintLittle_k_Number_Partition(number1, 2, 9);
  solution.PrintLittle_k_Number_Partition(number1, 3, 9);
  solution.PrintLittle_k_Number_Partition(number1, 4, 9);
  solution.PrintLittle_k_Number_Partition(number1, 5, 9);
  solution.PrintLittle_k_Number_UseSpace(number1, 6, 9);
  solution.PrintLittle_k_Number_UseSpace(number1, 7, 9);
  solution.PrintLittle_k_Number_UseSpace(number1, 8, 9);
  solution.PrintLittle_k_Number_UseSpace(number1, 9, 9);

}
void test_find_biggest_Sumof_SubArrary(){
  int arrary1[] = {1,-2,3,10,-4,7,2,-5};
  int arrary2[] = {-2,4,-9,10,2,-1,7,2,-5};
  int arrary3[] = {-2,-4,-9,-10,-2,-1,-7,-2,-5};
  int arrary4[] = {1,1,1,1,1,1,1,1,1};
  EXPECT_EQ(18, solution.FindBiggestSumOfSubArrary(arrary1, 8),"%d");
  EXPECT_EQ(20, solution.FindBiggestSumOfSubArrary(arrary2, 9),"%d");
  EXPECT_EQ(-1, solution.FindBiggestSumOfSubArrary(arrary3, 9),"%d");
  EXPECT_EQ(9, solution.FindBiggestSumOfSubArrary(arrary4, 9),"%d");
}
void test_count_digital_one(){
  EXPECT_EQ(5, solution.CountDigitalOne(12), "%d");
  EXPECT_EQ(16, solution.CountDigitalOne(51), "%d");
  EXPECT_EQ(20, solution.CountDigitalOne(98), "%d");
  EXPECT_EQ(57, solution.CountDigitalOne(123), "%d");
}
void test_digital_at_index(){
    EXPECT_EQ(0, solution.DigitalAtIndex(0), "%d");
    EXPECT_EQ(5, solution.DigitalAtIndex(5), "%d");
    EXPECT_EQ(4, solution.DigitalAtIndex(19), "%d");
    EXPECT_EQ(1, solution.DigitalAtIndex(20), "%d");
    EXPECT_EQ(9, solution.DigitalAtIndex(249), "%d");
    EXPECT_EQ(6, solution.DigitalAtIndex(5459), "%d");
    EXPECT_EQ(1, solution.DigitalAtIndex(55575), "%d");

}
void  test_sort_mostlittle_number(){
  vector<int> numbers1 = {3,32,321};
  vector<int> numbers2 = {12,352,121,35431,0};
  vector<int> numbers3 = {13,342,1321,78,7812};
  EXPTCT_EQ_STRING("321323", solution.SortMostLittleNumber(numbers1).c_str(), 6);
  EXPTCT_EQ_STRING("01211235235431", solution.SortMostLittleNumber(numbers2).c_str(), 14);
  EXPTCT_EQ_STRING("131321342781278", solution.SortMostLittleNumber(numbers3).c_str(), 15);
}
void test_translate_number_to_string(){
  const long long number1(12258);
  const long long number2(123123321457);
  const long long number3(159674546);
  EXPECT_EQ(5, solution.TranslateNumberToString(number1), "%d");
  EXPECT_EQ(27, solution.TranslateNumberToString(number2), "%d");
  EXPECT_EQ(2, solution.TranslateNumberToString(number3), "%d");
}
void test_gift_max_value(){
  const int board[] ={1,10,3,8,
                12,2,9,6,
                5,7,4,11,
                3,7,16,0};
    const int board1[] ={1,10,3,8,
                         2,10,10,6};
    const int board2[] ={1,7,9,8,
                         2,2,9,6,
                         5,7,8,1,
                         3,7,9,0};
    const int board3[] ={1,1,
                         10,2,
                         10,10,
                         3,0};
  EXPECT_EQ(48, solution.GiftMaxValue(board, 4, 4), "%d");
  EXPECT_EQ(37, solution.GiftMaxValue(board1, 2, 4), "%d");
  EXPECT_EQ(43, solution.GiftMaxValue(board2, 4, 4), "%d");
  EXPECT_EQ(48, solution.GiftMaxValue(board, 4, 4), "%d");
  EXPECT_EQ(31, solution.GiftMaxValue(board, 4, 2), "%d");
}
void test_longest_string_without_duplication(){
  const string str1("arabcracfd");
  const string str2("aaaaaaa");
  const string str3("weoinmvhgbiuoeg");
  const string str4("qwoxzcvnawterpeoitngxfbns");
  EXPECT_EQ(5, solution.LongestStringWithoutDuplication(str1).size(), "%d");
  EXPECT_EQ(1, solution.LongestStringWithoutDuplication(str2).size(), "%d");
  EXPECT_EQ(10, solution.LongestStringWithoutDuplication(str3).size(), "%d");
  EXPECT_EQ(12, solution.LongestStringWithoutDuplication(str4).size(), "%d");
}
void test_ugly_number(){
  EXPECT_EQ(1, solution.UglyNumber(1), "%lld");
  EXPECT_EQ(2, solution.UglyNumber(2), "%lld");
  EXPECT_EQ(3, solution.UglyNumber(3), "%lld");
  EXPECT_EQ(4, solution.UglyNumber(4), "%lld");
  EXPECT_EQ(5, solution.UglyNumber(5), "%lld");
  EXPECT_EQ(6, solution.UglyNumber(6), "%lld");
  EXPECT_EQ(8, solution.UglyNumber(7), "%lld");
  EXPECT_EQ(9, solution.UglyNumber(8), "%lld");
  EXPECT_EQ(10, solution.UglyNumber(9), "%lld");
  EXPECT_EQ(51018336, solution.UglyNumber(999), "%lld");
  EXPECT_EQ(58385852050781250, solution.UglyNumber(8899), "%llu");
  EXPECT_EQ(2433151904186341120, solution.UglyNumber(168899), "%llu");
}
void test_find_first_unique_char(){
    string str("abaccdeff");
    string str1;
    string str2("aabbccddeeff");
    string str3("aderredacyucuyj");
    EXPECT_EQ('b', solution.FirstUniqueChar(str), "%a");
    EXPECT_EQ('\0', solution.FirstUniqueChar(str1), "%a");
    EXPECT_EQ('\0', solution.FirstUniqueChar(str2), "%a");
    EXPECT_EQ('j', solution.FirstUniqueChar(str3), "%c");
}
void test_inverse_pairs(){
  vector<int> nums1 = {7,5,6,4};
  vector<int> nums2;
  vector<int> nums3 = {7,5};
  vector<int> nums4 = {1,2,3,4,5,6,7,0};
  EXPECT_EQ(5, solution.InversePairs(nums1), "%d");
  EXPECT_EQ(0, solution.InversePairs(nums2), "%d");
  EXPECT_EQ(1, solution.InversePairs(nums3), "%d");
  EXPECT_EQ(7, solution.InversePairs(nums4), "%d");
}
void test_find_first_public_node(){
  ListNode* Head1 = new ListNode;
  ListNode* first1 = new ListNode;first1->m_nKey = 1;
  ListNode* second1 = new ListNode;second1->m_nKey = 2;
  ListNode* third = new ListNode;third->m_nKey = 3;
  ListNode* forth = new ListNode;forth->m_nKey = 4;
  ListNode* fifth = new ListNode;fifth->m_nKey = 5;
  ListNode* sixth = new ListNode;sixth->m_nKey = 6;
  Head1->M_pNext = first1;
  first1->M_pNext = second1;
  second1->M_pNext = third;
  third->M_pNext = forth;
  forth->M_pNext = fifth;
  fifth->M_pNext = sixth;
  sixth->M_pNext = nullptr;

  ListNode* Head2 = new ListNode;
  ListNode* first2 = new ListNode;first2->m_nKey = 1;
  ListNode* second2 = new ListNode;second2->m_nKey = 2;
  ListNode* third2 = new ListNode;third2->m_nKey = 3;
  ListNode* forth2 = new ListNode;forth2->m_nKey = 4;
  ListNode* fifth2 = new ListNode;fifth2->m_nKey = 5;
  ListNode* sixth2 = new ListNode;sixth2->m_nKey = 6;
  Head2->M_pNext = first2;
  first2->M_pNext = second2;
  second2->M_pNext = third2;
  third2->M_pNext = forth2;
  forth2->M_pNext = fifth2;
  fifth2->M_pNext = sixth2;
  sixth2->M_pNext = third;
  //存在公共节点
  EXPECT_EQ(third, solution.FindFirstPublicNode(Head1, Head2), "%d");

  auto Head3 = new ListNode;
  ListNode *Head5 = nullptr;
  //传入空指针
  EXPECT_EQ(nullptr, solution.FindFirstPublicNode(Head3, Head5), "%d");

  ListNode* Head4 = new ListNode;
  ListNode* first4 = new ListNode;first4->m_nKey = 1;
  ListNode* second4 = new ListNode;second4->m_nKey = 2;
  ListNode* third4 = new ListNode;third4->m_nKey = 3;
  ListNode* forth4 = new ListNode;forth4->m_nKey = 4;
  ListNode* fifth4 = new ListNode;fifth4->m_nKey = 5;
  ListNode* sixth4 = new ListNode;sixth4->m_nKey = 6;
  Head4->M_pNext = first4;
  first4->M_pNext = second4;
  second4->M_pNext = third4;
  third4->M_pNext = forth4;
  forth4->M_pNext = fifth4;
  fifth4->M_pNext = sixth4;
  sixth4->M_pNext = nullptr;
  //咩有公共节点
  EXPECT_EQ(nullptr, solution.FindFirstPublicNode(Head1, Head4), "%d");
}
void test_times_of_number(){
    int num1[] = {1,2,2,2,2,2,4,5,6,7,8,9,10};
    EXPECT_EQ(1,solution.TimesOfNumber(num1, 13, 1), "%d");
    EXPECT_EQ(5,solution.TimesOfNumber(num1, 13, 2), "%d");
    EXPECT_EQ(0,solution.TimesOfNumber(num1, 13, 3), "%d");
    EXPECT_EQ(1,solution.TimesOfNumber(num1, 13, 4), "%d");
    EXPECT_EQ(1,solution.TimesOfNumber(num1, 13, 5), "%d");
    EXPECT_EQ(1,solution.TimesOfNumber(num1, 13, 6), "%d");
    EXPECT_EQ(1,solution.TimesOfNumber(num1, 13, 7), "%d");
    EXPECT_EQ(1,solution.TimesOfNumber(num1, 13, 8), "%d");
    EXPECT_EQ(1,solution.TimesOfNumber(num1, 13, 9), "%d");
    EXPECT_EQ(1,solution.TimesOfNumber(num1, 13, 10), "%d");
}
void test_find_nums_appear_once(){
  vector<int> nums = {1,2,4,6,8,1,2,6,9,8}; //4,9
  vector<int> nums1 = {21,21,2123,2123,3345,3345,467,467,5897,5897,6123,756,821,821,93,93}; //6123,756
  vector<int> nums2 = {22,33,77,88,99,22,77,99,88,33,234,234}; //234,556
  int num1 = -1;
  int num2 = -1;
  solution.FindNumsAppearOnce(nums, &num1, &num2);
  EXPECT_EQ(9, num1, "%d");
  EXPECT_EQ(4, num2, "%d");
  solution.FindNumsAppearOnce(nums1, &num1, &num2);
  EXPECT_EQ(6123, num1, "%d");
  EXPECT_EQ(756, num2, "%d");
  solution.FindNumsAppearOnce(nums2, &num1, &num2);
  EXPECT_EQ(-1, num1, "%d");
  EXPECT_EQ(-1, num2, "%d");
}
void test_find_nums_sum_of_s(){
  int nums1[] = {1,2,3,4,5,6,7,9,12,16,18,20};
  int num1,num2;
  EXPECT_EQ(true, solution.FindNumsSumOfS(nums1, 12, &num1, &num2, 17), "%d");
  EXPECT_EQ(1, num1, "%d");
  EXPECT_EQ(16, num2, "%d");
}
void test_find_sequence_sum(){
  int nums1[] = {1,2,3,4,5,6,7,9,12,16,18,20};
  vector<vector<int>> result;
  EXPECT_EQ(true, solution.FindSequenceSum(nums1, 12, result, 18), "%d");
  cout << "47.1和为s的连续正数序列:" << endl;
  for (auto &nums : result) {
    for ( auto &nums1 : nums) {
      cout << nums1 << "\t";
    }
    cout << endl;
  }
  EXPECT_EQ(false, solution.FindSequenceSum(nums1, 12, result, 0), "%d");
  EXPECT_EQ(false, solution.FindSequenceSum(nums1, 12, result, 200), "%d");
  EXPECT_EQ(true, solution.FindSequenceSum(nums1, 12, result, 38), "%d");
}
void test_reverse_string(){
    const string str("You are so beautiful!");
    string dest;
    solution.ReverseString(str, dest);
    EXPTCT_EQ_STRING("beautiful! so are You", dest.c_str(), dest.size());
}
void test_max_num_of_sliding_window(){
  const vector<int> nums1 = {2,3,4,2,6,2,5,1};
  const vector<int> nums2;
  vector<int> ret;
  solution.MaxNumOfSlidingWindow(nums1, 3, ret);
  ret = solution.MaxInSlidingWindow(nums1, 2);
  cout << "49.滑动窗口的大小：" << endl;
  cout << "一共有"<< ret.size()<<"个滑动窗口"<<endl;
  cout << "他们的最大值分别是：";
  for(const auto &max : ret){
    cout << nums1[max] << "\t";
  }
  cout << endl;
}
void test_dice_sum(){
  map<int, double> ret;
  ret = solution.ProbabilitySumOfDice(12);
  //6n-n + 1 =  ret.size();所以，n= (ret.size()-1)/5
  cout << "50." << (ret.size()-1)/5 << "个骰子的点数出现的概率分别是：" << endl;
  double r =0;
  for (const auto &ele : ret) {
    cout << "和为" << ele.first << "的概率为：" << ele.second << endl;
    r+=ele.second;
  }
  printf("总概率为：%3.2f%%", r);
}
void test_is_continous(){
  int num1[] = {1, 5, 3, 2, 4};
  int num2[] = {5, 7, 9, 0, 10};
  int num4[] = {5, 7, 9, 0, 8,10};
  int num3[] = {5, 7, 8, 0, 8};
  int num5[] = {0, 0, 0, 0, 8};
  EXPECT_EQ(true, solution.ISContinous(num1, 5), "%d");
  EXPECT_EQ(false, solution.ISContinous(num2, 5), "%d");
  EXPECT_EQ(false, solution.ISContinous(num3, 5), "%d");
  //EXPECT_EQ(false, solution.ISContinous(num4, 6), "%d");
  EXPECT_EQ(true, solution.ISContinous(num5, 5), "%d");
}
void test_JosephRing(){
  EXPECT_EQ(4, solution.LastRemaining(5, 1), "%d");
  EXPECT_EQ(2, solution.LastRemaining(5, 2), "%d");
  EXPECT_EQ(3, solution.LastRemaining(5, 3), "%d");
  EXPECT_EQ(0, solution.LastRemaining(5, 4), "%d");
  EXPECT_EQ(1, solution.LastRemaining(5, 5), "%d");
}
void test_max_profit(){
  int price[] = {23,45,12,55,67,78,34,15,77,90,55,30};
  EXPECT_EQ(78,solution.MaxProfit(price, 12), "%d");
}
void test_sum_of_n(){
  EXPECT_EQ(solution.SumOfX(100), solution.SumOfN(100), "%lld");
}
void test_addition_without_arithmetic(){
  EXPECT_EQ(solution.AdditionWithoutArithemticRecursively(45, 55), solution.AdditionWithoutArithmetic(45, 55), "%d");
  EXPECT_EQ(solution.AdditionWithoutArithemticRecursively(45234, 12345), solution.AdditionWithoutArithmetic(45234, 12345), "%d");
  EXPECT_EQ(solution.AdditionWithoutArithemticRecursively(515, 4455), solution.AdditionWithoutArithmetic(515, 4455), "%d");
  EXPECT_EQ(solution.AdditionWithoutArithemticRecursively(1524, 242), solution.AdditionWithoutArithmetic(1524, 242), "%d");
}
void test_construct_multiply_arrary(){
  vector<int> A = {2,2,2,2,2};
  auto ret = solution.ConstructMultiplyArrary(A);
  cout << "56.test construct multiply arrary:" << "arrary size :" << ret.size() << endl;
  for (const auto &num : ret) {
    cout << num << "\t";
  }
  cout << endl;
}
void test_solution(){
//    test_duplicate();
//    test_find2dArrary();
//    test_SubmitBlank();
//    test_PrintListReversingly_Iteratively();
//    test_2stack_simulate_queue();
//    test_Fibonacci();
//    test_quick_sort();
//    test_MinNumberInRotatArrary();
//    test_Find_Matrix_Path();
//    test_RobotRunRange();
//    test_CutRope();
//    test_Find1InNumber();
//    test_Power();
//    test_PrintNumber();
//    test_DeleteNode();
//    test_DeleteDumplicateNode();
//    test_RegularExpressionMtach();
//    test_StrToDigital();
//    test_AdjustArrary();
//    test_findKinList();
//    test_FindRingNode();
//    test_ReverseList();
//    test_Merge2List();
//    test_PrintMatrixClockWise();
//    test_StackWithMin();
//    test_Judge_Match_Stack();
//    test_DumplicateComplexList();
//    test_string_arrange();
//    test_find_MoreThanHalf_Number();
//    test_PrintLittle_k_Number();
//    test_find_biggest_Sumof_SubArrary();
//    test_count_digital_one();
//    test_digital_at_index();
//    test_sort_mostlittle_number();
//    test_translate_number_to_string();
//    test_gift_max_value();
//    test_longest_string_without_duplication();
//    test_ugly_number();
//    test_find_first_unique_char();
//    test_inverse_pairs();
//    test_find_first_public_node();
//    test_times_of_number();
//    test_find_nums_appear_once();
//    test_find_nums_sum_of_s();
//    test_find_sequence_sum();
//    test_reverse_string();
//    test_max_num_of_sliding_window();
//    test_dice_sum();
//    test_is_continous();
//    test_JosephRing();
//    test_max_profit();
//    test_sum_of_n();
//    test_addition_without_arithmetic();
//    test_construct_multiply_arrary();
}

int main() {
    /*string s1, s2;
    cin >> s1 >> s2;
    cout << s1 << s2<< endl;*/
    test_solution();
    printf("test count:%d, test pass count:%d, pass rate: %3.2f%%\n", test_count, test_parse_count, test_parse_count*100.0/test_count);
    // std::cout << "test count:"<< test_count << ",test_parse_count:" << test_parse_count << ",success_rate:" << test_parse_count*1.000/test_count << std::endl;
    return 0;
}