#include <iostream>
#include "Solution.h"

#define EXPECT_EQ(expect, actual, object_format)   EXPECT_EQ_BASE((expect==actual), expect, actual, object_format)
#define EXPECT_EQ_BASE(equality, expect, actual, object_format) \
                                do{  \
                                test_count ++; \
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

void test_solution(){
    test_duplicate();
}

int main() {
    /*string s1, s2;
    cin >> s1 >> s2;
    cout << s1 << s2<< endl;*/
    test_solution();
    printf("test count:%d, test pass count:%d, pass rate: %3.2f%%\n", test_count/2, test_parse_count/2, test_parse_count*100.0/test_count);
    // std::cout << "test count:"<< test_count << ",test_parse_count:" << test_parse_count << ",success_rate:" << test_parse_count*1.000/test_count << std::endl;
    return 0;
}