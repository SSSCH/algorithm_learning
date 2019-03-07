#include <iostream>
#include <memory.h>

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
    if((sizeof(expect)/4) == (length) && memcmp(expect, actual, length-1) == 0) {\
        test_parse_count++;} \
    else {\
        fprintf(stderr, "%s%d\n", __FILE__, __LINE__);\
        for(int i =0; i < length; i++){\
            fprintf(stderr, "%d\t", actual[i]);\
        }\
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

void test_solution(){
    test_duplicate();
    test_find2dArrary();
    test_SubmitBlank();
    test_PrintListReversingly_Iteratively();
    test_2stack_simulate_queue();
    test_Fibonacci();
    test_quick_sort();
    test_MinNumberInRotatArrary();
    test_Find_Matrix_Path();
    test_RobotRunRange();
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