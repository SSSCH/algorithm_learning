//
// Created by SCH on 2019/2/25.
//

#include <assert.h>
#include <cstring>
#include "Solution.h"
#include <string>
#include <stack>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <array>
using std::vector;
using std::string;
vector<int> v(3, 7); //= vector<int> v{7, 7, 7}
string s = "sssccchhh";

void Swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void swap(int nums[], int j, int i){
    assert(nums);
    int tmp = nums[j];
    nums[j] = nums[i];
    nums[i] = tmp;
}
//o(n)/0(1)
bool MySolution::Solution::duplicate(int *numbers, int length, int *duplication) {
    assert(numbers && length > 0);
    for (int i = 0; i < length; i++) {
        if(numbers[i] > length)
            return false;
    }
    for (int j = 0; j < length; ++j) {
        while (numbers[j] != j) {
            if (numbers[j] == numbers[numbers[j]]) {
                duplication[0] = numbers[j];
                return true;
            }
            swap(numbers, j, numbers[j]);
        }
    }
    return false;
}
//二维数组的传参方式：int numbers[][10], int (*numbers)[10], int** numbers, 或者将其降维成一维数组
bool MySolution::Solution::find_2dArrary(int *numbers, int rows, int columns, int target) {
    assert(numbers != nullptr && rows > 0 && columns > 0);
    int row = 0;
    int column = columns - 1;
    while(column >= 0 && row <= (rows-1)){
        if(numbers[row*columns + column] > target) column--;
        else if(numbers[row*columns + column] < target) row++;
        else return true;
    }
    return false;
}

char* MySolution::Solution::submit_blank(char string[]) {
    assert(string);
    size_t blank = 0;
    size_t originlenth = 0;
    size_t newlenth = 0;
    originlenth = strlen(string);
    for (int i = 0; i < originlenth; ++i) {
        if (string[i] == ' ') blank++;
    }
    newlenth = originlenth + blank*2;
    //string = (char*)realloc(string, blank*2);
    while (originlenth != newlenth) {
        if (string[originlenth] != ' ') {
            string[newlenth] = string[originlenth];
            newlenth--;

        } else {
            string[newlenth--] = '0';
            string[newlenth--] = '2';
            string[newlenth--] = '%';
        }
        originlenth --;
    }
    return string;
}
//用栈实现
void MySolution::Solution::PrintListReversing_Iteratively(ListNode* phead) {
    std::stack<ListNode*> ListStack;
    ListNode* tmp = phead;
    //遍历链表，入栈
    while (tmp != nullptr) {
          ListStack.push(tmp);
          tmp = tmp->M_pNext;
    }
    //出栈，打印
    while (!ListStack.empty()) {
        printf("%d\t", ListStack.top()->m_nKey);
        ListStack.pop();
    }
    printf("\n");
}
//递归实现，递归的本质就是一个栈结构
void MySolution::Solution::PrintListReversing_Recursively(ListNode *phead) {
    if (phead != nullptr) {
        if (phead->M_pNext != nullptr) {
            PrintListReversing_Recursively(phead->M_pNext);
        }
        printf("%d\t", phead->m_nKey);
    }
}
//递归实现
long long MySolution::Solution::Fibonacci_Recursively(unsigned int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n > 1) {
        return (Fibonacci_Recursively(n - 1) + Fibonacci_Recursively(n - 2));
    }
}
//迭代，循环实现
long long MySolution::Solution::Fibonacci_Iteratively(unsigned int n) {
    long long FibonacciMinusOne = 1;
    long long FibonacciMinusTwo = 0;
    long long TmpTarget = 1;
    for (int i = 2; i <= n; ++i) {
        TmpTarget = FibonacciMinusOne + FibonacciMinusTwo;
        FibonacciMinusTwo = FibonacciMinusOne;
        FibonacciMinusOne = TmpTarget;

    }
    return TmpTarget;
}
//f(n)=f(n-1)+f(n-2)
long long MySolution::Solution::JumpStep(unsigned int n) {
    long long FibonacciMinusOne = 2;
    long long FibonacciMinusTwo = 1;
    long long TmpTarget = 3;
    if (n == 1) return FibonacciMinusTwo;
    if (n == 2) return FibonacciMinusOne;
    for (int i = 3; i <= n ; ++i) {
        TmpTarget = FibonacciMinusOne + FibonacciMinusTwo;
        FibonacciMinusTwo = FibonacciMinusOne;
        FibonacciMinusOne = TmpTarget;
    }
    return TmpTarget;
};
//f(n)=f(n-1)+...+f(0) ==f(n)=2f(n-1)
long long MySolution::Solution::JumpStepPlus_DynamicPlan(unsigned int n) {
    long long tmp = 2;
    long long TmpTarget = 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    for (int i = 3; i <= n; ++i) {
        TmpTarget = 2*tmp;
        tmp = TmpTarget;
    }
    return TmpTarget;
}
/**
 * c++中math.h的pow返回类型是double,so,自己寫一個*/
long long Math_pow(unsigned m, unsigned int n){
    assert(n>=1);
    long long TmpTarget = 1;
    for (int i = 1; i <=n; ++i) {
        TmpTarget *= m;
    }
    return TmpTarget;
}
long long MySolution::Solution::JumpStepPlus_Math(unsigned int n) {
    assert(n>=1);
    return Math_pow(2, n-1);
}

int RandomInRange(int n, int m){
    assert(n>=0 && m>=0 && m >= n);
    return (rand()%(m-n+1)+n);
}
int MySolution::Solution::_QuickSort(int data[], int length, int begin, int end) {
    //int index = RandomInRange(begin, end); //index range: [begin, end]
    int index = RandomInRange(begin, end); //也可以不用生成随机数，直接取中值（begin+end）/2也行， 类似二分法（二分排序？）
    Swap(&data[index], &data[end]);
    int SmallIndex = begin -1;
    for (int i = begin; i < end; ++i) {
        if (data[i] < data[end]) {
            SmallIndex++;
            if (SmallIndex != i) {
                Swap(&data[SmallIndex], &data[i]);
            }
        }
    }
    SmallIndex++;
    swap(data, SmallIndex, end);
    return SmallIndex;
}
void MySolution::Solution::QuickSort(int data[], int length, int begin, int end) {
    assert(length >= 0 && begin >= 0 && end >= begin);
    if (begin == end) {
        return;
    }
    int index = _QuickSort(data, end-begin+1, begin, end);
    if(index > begin) {
        /**特別注意：index>begin 这边不能有等号，否则循环永远无法结束，最终导致程序栈溢出，下面也是
         * */
        QuickSort(data, end-begin+1, begin, index-1);
    }
    if (index < end) {
        QuickSort(data, end-begin+1, index+1, end);
    }
}

int MySolution::Solution::MinNumberInRotateArrary(int *RotatArrary, int length) {
    assert(RotatArrary != nullptr && length > 0);
    int begin = 0;
    int end = length -1;
    int mid = 0;
    while (begin != (end - 1)) {
        mid = (begin + end)/2;
        if (RotatArrary[mid] == RotatArrary[begin] && RotatArrary[mid] == RotatArrary[end]) { //特殊情况：『1，1，1，1，0，1，1』,此时只能用顺序查找
            return MinNumberByOrder(RotatArrary, length);
        }
        if (RotatArrary[mid] >= RotatArrary[begin]) {
            begin = mid;
        }
        if (RotatArrary[mid] <= RotatArrary[end]) {
            end = mid;
        }
    }
    return RotatArrary[end];
}
int MySolution::Solution::MinNumberByOrder(int *RotatArrary, int length) {
    int* arrary = RotatArrary;
    int result = arrary[0];
    for (int i = 1; i < length; ++i) {
        if (result > arrary[i]) {
            result = arrary[i];
        }
    }
    return result;
}

bool MySolution::Solution::_FindPathInMatrix(char *matrix, int col, int cols, int row, int rows, char *str, int*PathCharIndex, bool *IsMarked) {
    if (str[*PathCharIndex] == '\0') {  //路径找完了
        return true;
    }
    if (col >= 0 && col < cols && row >= 0 && row < rows && matrix[col*rows + row] == str[*PathCharIndex] && !IsMarked[col*rows + row]) {
        IsMarked[col*rows + row] = true;  //标记该位置已经走过
        (*PathCharIndex)++;  //指向下一个字符
        if (!_FindPathInMatrix(matrix, col-1, cols, row, rows, str, PathCharIndex, IsMarked) && //up
            !_FindPathInMatrix(matrix, col+1, cols, row, rows, str, PathCharIndex, IsMarked) &&  //down
            !_FindPathInMatrix(matrix, col, cols, row-1, rows, str, PathCharIndex, IsMarked) && //left
            !_FindPathInMatrix(matrix, col, cols, row+1, rows, str, PathCharIndex, IsMarked) ) {//right
                IsMarked[col*rows + row] = false; //此路不通，撤回标记
                (*PathCharIndex)--;  //字符路径撤回
                return false;
        }else{
            return true;
        }
    }
    return false;
}
bool MySolution::Solution::FindPathInMatrix(char *matrix, int cols, int rows, char *str) {
    assert(matrix != nullptr && rows >= 1 && cols >= 1  && str != nullptr);
    int col = 0;
    int row = 0;
    bool *IsMarked = new bool[cols*rows];//标记某点是否已经走过（不能往回走）
    for (int i = 0; i < cols*rows; ++i) {
        IsMarked[i] = false;
    }
    int index = 0;
    for (col = 0; col < cols; ++col) {
        for (row = 0; row < rows; ++row) {
            if(_FindPathInMatrix(matrix, col, cols, row, rows, str, &index, IsMarked))
                return true;
        }
    }
    delete[](IsMarked);
    return false;
}

int MySolution::Solution::DigitalSum(int number) {
    int ret =0;
    while (number != 0) {
        ret +=number%10;
        number = number/10;
    }
    return ret;
}

void MySolution::Solution::_RobotRunRange(int col, int cols, int row, int rows, int k, int *IsMarked) {
    assert(IsMarked != nullptr);
    if (col >=0 && col < cols && row >= 0 && row < rows && (DigitalSum(row) + DigitalSum(col)) <= k && IsMarked[col*rows + row] == 0) {
        IsMarked[col*rows + row] = 1;
        _RobotRunRange(col - 1, cols , row, rows, k, IsMarked); //up
        _RobotRunRange(col + 1, cols , row, rows, k, IsMarked); //down
        _RobotRunRange(col, cols , row - 1, rows, k, IsMarked); //left
        _RobotRunRange(col, cols , row + 1, rows, k, IsMarked); //right
    }
    return ;
}
int MySolution::Solution::RobotRunRange(int cols, int rows, int k) {
    assert(cols > 0 && rows > 0);
    int isMarked[cols*rows];
    int col = 0;
    int row = 0;
    int ret = 0;
    for (int i = 0; i < cols*rows; ++i) {
        isMarked[i] = 0;
    }

    _RobotRunRange(col, cols, row, rows, k, isMarked);  //相比于14题矩阵中的路径，14题中的路径起点是要自己找的，而这边是固定的从（0，0）开始
                                                                    //所以，无需循环

    for (int j = 0; j < cols*rows; ++j) {
        //if (isMarked[j] != 0) ret++;
        ret+=isMarked[j];
    }
    return ret;
}

unsigned int MySolution::Solution::CutRope_DynamicProgramming(int length) {
    assert(length > 1);
    unsigned int Rope[length - 1];
    for (int i = 0; i <length-1 ; ++i) {
        Rope[i] = 0;
    }
    unsigned int max = 0;
    Rope[1] = 1;
    Rope[2] = 2;
    Rope[3] = 3;
    switch (length) {
        case 2:return 1;
        case 3:return 2;
        default:
            for (int j = 4; j <= length; ++j) {  //自下而上将子问题的最优解储存在Rope[]中
                for (int i = 1; i <= length/2; ++i) {
                     Rope[j] = Rope[i]*Rope[j-i];
                    if (max < Rope[j]) max = Rope[j];
                }
                Rope[j] = max;
                max = 0;
            }
            return Rope[length];
    }

}
unsigned int MySolution::Solution::CutRope_GreedyAlgorthm(int length) {
    assert(length > 1);
    unsigned int timeOf3 = 0;
    switch (length) {
        case 2:return 1;
        case 3:return 2;
        case 4:return 4;
        default:
            timeOf3 = (unsigned int)length/3;
            switch (length%3) {
                case 0:
                    return ((unsigned int)pow(3,timeOf3)); //pow()用于求指数
                case 1:
                    return ((unsigned int)pow(3,timeOf3-1)*2*2);
                case 2:
                    return ((unsigned int)pow(3,timeOf3)*2*1);
                default:
                    return 0;
            }
    }
}

int MySolution::Solution::Find_1_InNumber(unsigned int number) {
    int ret =0;
    unsigned int tmpForCmp = 1;
    for (int i = 0; i <=31; ++i) {
        if (number & tmpForCmp) {
            ret++;
        }
        tmpForCmp <<=1;
    }
    return ret;
}
int MySolution::Solution::Find_1_InNumberX(unsigned int number) {
    int count = 0;
    while (number != 0) {
        count++;
        number = number & (number - 1);
    }
    return count;
}
double  MySolution::Solution::Power(double Base, int Exponent) {
    if (Base==0 || Exponent==0) {
        return 1.0;
    }
    if(Exponent < 0){
        double result = PowerWithUnsignedExpenent(Base, (unsigned int)(-Exponent));
        return 1.0/result;
    } else {
        double result = PowerWithUnsignedExpenent(Base, (unsigned int)Exponent);
        return result;
    }
}
double  MySolution::Solution::PowerWithUnsignedExpenent(double Base, unsigned int Expenent) {
    double result = 1;
    if (Expenent == 1) {
        return Base;
    }
    if (Expenent == 0) {
        return 1;
    }
    result = PowerWithUnsignedExpenent(Base, Expenent >> 1);
    result *= result;
    if (Expenent & 0x1) { //判断奇偶性
        result *= Base;
    }
    return result;
}
bool MySolution::Solution::IncreaseNumber(char *Number) {
    bool IsLegalNumber = false;
    int strlength = (int)strlen(Number);
    for (int i = strlength - 1; i >=0 ; --i) {    //循环的意义是用于进位，当第n位需要进位时说明已经到达n位的最大数
        Number[i] += 1;
        if (Number[i] == 10 + '0') {
            Number[i] = '0';
        } else{
            IsLegalNumber = true;
            break;
        }
    }
    return IsLegalNumber;
}
void MySolution::Solution::_PrintNmber(char *Number) {
    for (int i = 0; i < strlen(Number); ++i) {
        if (Number[i] != '0'){
            Number +=i;  //注意，这边Number的增加只是传参过来的拷贝值，实际的Number不受影响；若想实际的Number也增加的话应该传char**
            break;
        }
    }
    printf("%s\t", Number);
}
void MySolution::Solution::PrintNumber(int n) {
    assert(n > 0);
    char* Number = new char[n+1];
    memset(Number, '0', n);
    Number[n] = '\0';
    while (IncreaseNumber(Number)) {
        _PrintNmber(Number);
    }
    printf("\n");
}
void MySolution::Solution::DeletNode(ListNode **Head, ListNode *ToBeDeletde) {
    assert(Head != nullptr && ToBeDeletde != nullptr && *Head != nullptr);
    ListNode* tmp = ToBeDeletde->M_pNext;

    if (ToBeDeletde->M_pNext != nullptr) {
        ToBeDeletde->m_nKey = ToBeDeletde->M_pNext->m_nKey;
        ToBeDeletde->M_pNext = ToBeDeletde->M_pNext->M_pNext;
    } else if (*Head == ToBeDeletde) { delete *Head; }
    else {
        ListNode* target = *Head;
        while (target->M_pNext != ToBeDeletde) {
            target = target->M_pNext;
        }
        target->M_pNext = nullptr;
        delete ToBeDeletde;
    }
    delete tmp;
}
int MySolution::Solution::DeleteDumplicateNode(ListNode **Head) {
    assert(Head != nullptr && *Head != nullptr);
    int DumplicateCount = 0;
    ListNode* IndexNode = *Head;
    ListNode* PreNode = *Head;
    while (IndexNode->M_pNext != nullptr) {
        if (IndexNode->m_nKey == IndexNode->M_pNext->m_nKey) {
            DumplicateCount++;
            while (IndexNode->M_pNext != nullptr &&(IndexNode->m_nKey == IndexNode->M_pNext->m_nKey)) {
                ListNode* tmpNode = IndexNode;
                IndexNode = IndexNode->M_pNext;
                delete tmpNode;
                tmpNode = nullptr;
            }
            PreNode->M_pNext = IndexNode->M_pNext;
            if (IndexNode->M_pNext != nullptr) {
                ListNode* tmpNode = IndexNode;
                IndexNode = IndexNode->M_pNext;
                delete tmpNode;
                tmpNode = nullptr;
            } else {
                delete IndexNode;
                IndexNode = nullptr;
                return DumplicateCount;
            }
        } else {
            PreNode = IndexNode;
            IndexNode = IndexNode->M_pNext;
        }
    }
    return DumplicateCount;
}
bool MySolution::Solution::RegularExpressionMatch(const char *str, const char *tempstr) {
    assert(str != nullptr && tempstr != nullptr);
    int IndexForErgodic = 0; //用于循环
    int IndexFOrMatch = 0;  //指向str将要对比的第一个指针
    int IndexForTemp = 0;   //指向tempstr将要对比的第一个指针
    while (tempstr[IndexForErgodic] != '\0') {
        if (tempstr[IndexForErgodic] == '.') {
            for (IndexForTemp; IndexForErgodic>IndexForTemp; ++IndexForTemp) {
                if (str[IndexFOrMatch] != tempstr[IndexForTemp]) return false;
                else IndexFOrMatch++;
            }
            IndexFOrMatch++;
            IndexForTemp++;
        }
        else if (tempstr[IndexForErgodic] == '*') {
            for (IndexForTemp; (IndexForErgodic-IndexForTemp) > 1; ++IndexForTemp) {
                if (str[IndexFOrMatch] != tempstr[IndexForTemp]) return false;
                else IndexFOrMatch++;
            }
            while (str[IndexFOrMatch] == tempstr[IndexForErgodic - 1]) {
                IndexFOrMatch++;
            }
            IndexForTemp+=2;
        }

        IndexForErgodic++;

    }
    for (IndexForTemp; IndexForTemp <= IndexForErgodic; ++IndexForTemp) {
        if (str[IndexFOrMatch] != tempstr[IndexForTemp]) return false;
        else IndexFOrMatch++;
    }
    return true;
}