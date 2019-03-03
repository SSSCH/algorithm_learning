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
void test_solution(){
    test_duplicate();
    test_find2dArrary();
    test_SubmitBlank();
    test_PrintListReversingly_Iteratively();
    test_2stack_simulate_queue();
    test_Fibonacci();
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