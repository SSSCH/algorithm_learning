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
#include <errno.h>
#include <map>
#include <queue>
#define ISDIGITAL(ch) ('0' <= (ch) && (ch) <= '9')
#define ISDIGITAL1T9(ch) ('1' <= (ch) && (ch) <= '9')
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
    assert(m >= n);
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
    result = PowerWithUnsignedExpenent(Base, Expenent >> 1); //>> 1:除以2
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
        if (Number[i] != '0'){  //从第一个非0的数字开始打印
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
    ListNode* IndexNode = *Head; //索引节点
    ListNode* PreNode = *Head;  //保存索引节点的前一个节点
    while (IndexNode->M_pNext != nullptr) {
      //判断是否重复
        if (IndexNode->m_nKey == IndexNode->M_pNext->m_nKey) {
            DumplicateCount++; //重复节点计数
            //删除重复节点
            while (IndexNode->M_pNext != nullptr &&(IndexNode->m_nKey == IndexNode->M_pNext->m_nKey)) {
                ListNode* tmpNode = IndexNode;
                IndexNode = IndexNode->M_pNext;
                delete tmpNode;
                tmpNode = nullptr;
            }
            PreNode->M_pNext = IndexNode->M_pNext;
          //重复节点还剩一个，把它删了，此时重复节点不是最后一个节点
            if (IndexNode->M_pNext != nullptr) {
                ListNode* tmpNode = IndexNode;
                IndexNode = IndexNode->M_pNext;
                delete tmpNode;
                tmpNode = nullptr;
            } else { //重复节点是最后一个节点
                delete IndexNode;
                IndexNode = nullptr;
                return DumplicateCount;
            }
        } else { //不重复
            PreNode = IndexNode;
            IndexNode = IndexNode->M_pNext;
        }
    }
    return DumplicateCount;
}
bool MySolution::Solution::RegularExpressionMatch(const char *str, const char *tempstr) {
    assert(str != nullptr && tempstr != nullptr);
    int IndexForErgodic = 0; //用于索引/遍历
    int IndexFOrMatch = 0;  //指向str将要对比的第一个指针
    int IndexForTemp = 0;   //指向tempstr将要对比的第一个指针
    while (tempstr[IndexForErgodic] != '\0') {
      //匹配“.”
        if (tempstr[IndexForErgodic] == '.') {
            for (IndexForTemp; IndexForErgodic>IndexForTemp; ++IndexForTemp) {
                if (str[IndexFOrMatch] != tempstr[IndexForTemp]) return false;
                else IndexFOrMatch++;
            }
            IndexFOrMatch++;
            IndexForTemp++;
        }
        //匹配“*”
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
    //模板的索引指针匹配完毕，将剩余的部分一一对比
    for (IndexForTemp; IndexForTemp <= IndexForErgodic; ++IndexForTemp) {
        if (str[IndexFOrMatch] != tempstr[IndexForTemp]) return false;
        else IndexFOrMatch++;
    }
  return true;
}

bool MySolution::Solution::StrToDigital(const char *str, double *number) {
    assert(str != nullptr && number != nullptr);
    int DocNumber = 0;
    bool IsEAppeared =false;
    for (int i = 0; str[i] != '\0' ; ++i) {
        if (!ISDIGITAL(str[i])) {
            switch (str[i]) {
                case '+':
                    if (i == 0 || str[i - 1] == 'e' || str[i - 1] == 'E') break;
                    else return false;
                case '-':
                    if (i == 0 || str[i - 1] == 'e' || str[i - 1] == 'E') break;
                    else return false;
                case 'e':
                    IsEAppeared = true;
                    if (ISDIGITAL(str[i-1]) && (str[i+1] != '\0')) break;
                    else return false;
                case 'E':
                  IsEAppeared = true;
                  if (ISDIGITAL(str[i-1]) && (str[i+1] != '\0')) break;
                  else return false;
                case '.':
                    DocNumber++;
                    if ((DocNumber>1) && IsEAppeared) return false;
                    else break;
                default:
                    return false;
            }
        }
    }
    errno = 0;
    *number = strtod(str, nullptr);
    if (errno) {
        printf("errno:%d\n", errno);
        return false;
    }
    return true;
}
//判断是否为奇数
bool MySolution::Solution::JudgeOdd(int number) {
    return (number & 1) == 1;
}
void MySolution::Solution::AdjustArary(int arrary[], int length, bool (*func)(int) ) {
    assert(arrary != nullptr && func != nullptr);
    int IndexFront = 0;
    int IndexBack = length - 1;

    while (IndexFront < IndexBack) {
        //奇偶
        if (func(arrary[IndexFront]) && (!func(arrary[IndexBack]))) {
            IndexFront++;
            IndexBack--;
        }
        //偶奇
        else if ((!func(arrary[IndexFront])) && func(arrary[IndexBack])) {
            int tmp = arrary[IndexFront];
            arrary[IndexFront] = arrary[IndexBack];
            arrary[IndexBack] = tmp;
            IndexFront++;
            IndexBack--;
        }
        //偶偶
        else if((!func(arrary[IndexFront])) && (!func(arrary[IndexBack]))){
            IndexBack--;
        }
        //奇奇
        else {
            IndexFront++;
        }
    }
}
int MySolution::Solution::Find_K_InList(ListNode *Head, int k) {
    assert(Head != nullptr && k > 0);
    ListNode* TmpNode = Head;
    ListNode* KNode = Head;
    int Index_1 = 0;
    while (TmpNode->M_pNext != nullptr) {
      //TmpNode先走k-1步
        if (Index_1 != k-1) {
            Index_1++;
        } else {
            KNode = KNode->M_pNext;
        }
        TmpNode = TmpNode->M_pNext;
    }
    //链表不足k个节点时报错，即KNode没动
    if (KNode != Head) {
        return KNode->m_nKey;
    } else {
        fprintf(stderr, "k = %d is not exist !!\n",k);
        return -1;
    }
}
ListNode* MySolution::Solution::FindRingNode(ListNode *Head) {
    if (Head == nullptr) return nullptr;
    ListNode* Index1 = Head;
    ListNode* Index2 = Head;
    int RingNodeNumber = 0;
    //第一步：判断是否有环，利用双指针确定是否有环
    while ((Index2->M_pNext != nullptr) && (Index2->M_pNext->M_pNext != nullptr) && (Index1->M_pNext != Index2->M_pNext->M_pNext)) {
        Index2 = Index2->M_pNext->M_pNext;
        Index1 = Index1->M_pNext;
    }
    //没环
    if ((Index2->M_pNext == nullptr) || (Index2->M_pNext->M_pNext == nullptr)) return nullptr;
        //第二步：如果有环，确定环内节点的数目n，利用双指针确定环内节点数目
    else {//有环，也可以就用一个指针确定环内节点数
        Index1 = Index1->M_pNext;
        Index2 = Index2->M_pNext->M_pNext;
        do {
            Index2 = Index2->M_pNext->M_pNext;
            Index1 = Index1->M_pNext;
            RingNodeNumber++;
        } while (Index1 != Index2);
    }
    //第三步：找到环的头节点，利用双指针找到头节点
    Index1 = Head;
    Index2 = Head;
    for (int i = 0; i < RingNodeNumber ; ++i) {
        Index2 = Index2->M_pNext;
    }
    while (Index1 != Index2) {
        Index1 = Index1->M_pNext;
        Index2 = Index2->M_pNext;
    }
    return Index1;
}

ListNode* MySolution::Solution::ReverseList_Recursively(ListNode *Head) {//迭代
    assert(Head != nullptr);
    ListNode* NewHead = nullptr; //用于保存新的头节点
    ListNode* FrontNode = nullptr;
    ListNode* TargetNode = Head;
    while (TargetNode != nullptr) {
        ListNode* TmpNextNode = TargetNode->M_pNext;
        if (TmpNextNode == nullptr) NewHead = TargetNode;
        TargetNode->M_pNext = FrontNode;
        FrontNode = TargetNode;
        TargetNode = TmpNextNode;
    }
    return NewHead;
}
ListNode* MySolution::Solution::ReverseList_Iteratively(ListNode *Head) { //递归
    if (Head->M_pNext == nullptr || Head == nullptr) return Head;
    ListNode* TmpNext = Head->M_pNext;
    Head->M_pNext = nullptr;   //如果不加的话反转后的链表为0，1，3，5，7，9，11，9，11，9，11，9....即存在环节点(原Head->M_pNext 没有指向null)。
    ListNode* NewHead = ReverseList_Iteratively(TmpNext);
    //递归出来后要干的事：反转链表
    TmpNext->M_pNext  = Head;
    return  NewHead;
}

ListNode* MySolution::Solution::Merge2List(ListNode *Head1, ListNode *Head2) {
    assert(Head1 != nullptr && Head2 != nullptr);
    ListNode* NewHead = nullptr;
    ListNode* NewHeadNode = nullptr;
    ListNode* IndexNode = nullptr;
    if (Head1->m_nKey <= Head2->m_nKey) {
        NewHeadNode = Head1;
        NewHead = Head1;
        IndexNode = Head2;
    } else {
        NewHeadNode = Head2;
        NewHead = Head2;
        IndexNode = Head1;
    }
    while (IndexNode != nullptr) {
        while (!((NewHeadNode->M_pNext == nullptr) || (IndexNode->m_nKey <= NewHeadNode->M_pNext->m_nKey))) {
            NewHeadNode = NewHeadNode->M_pNext;
        }
        ListNode* NextNewNode = NewHeadNode->M_pNext;
        ListNode* NextIndexNode = IndexNode->M_pNext;
        NewHeadNode->M_pNext = IndexNode;
        IndexNode->M_pNext = NextNewNode;
        IndexNode = NextIndexNode;
        NewHeadNode = NewHeadNode->M_pNext;
    }
    //forLiChenXi();
    return NewHead;
}
//Matrix, cols,rows,ret不会在递归中改变
void _PrintMatrixClockWise(int* Matrix, int col, int row, int cols, int rows, int colLimt, int rowLinmt, int* ret, int index){
    //递归结束的条件：打印到矩阵的最后一圈
    if(colLimt >= col && rowLinmt >= row && index < cols*rows) {
        int sideMin = col;   //行列的最小边界
        while (row < rowLinmt) {
            ret[index] = Matrix[col*rows + row];
            index++;  //保存结果的指针
            row++;
        }
        row--;  //while中多加了一次row
        col++;  //往下拐，行+1
        while (col < colLimt) {
            ret[index] = Matrix[col*rows + row];
            index++;
            col++;
        }
        col--;   //while中多加了一次行col
        row--;  //往左拐，列-1
        while (row >= sideMin) {
            ret[index] = Matrix[col*rows + row];
            index++;
            row--;
        }
        row++;
        col--;  //往上拐，行-1
        while (col > sideMin) {
            ret[index] = Matrix[col*rows + row];
            index++;
            col--;
        }
        col++;
        row++; //往右拐，列+1

        colLimt--;  //最大行数-1
        rowLinmt--;  //最大列数-1
        _PrintMatrixClockWise(Matrix, col, row, cols, rows, colLimt, rowLinmt, ret, index);
    } else return ;
}
void MySolution::Solution::PrintMatrixClockWise(int *Matrix, int cols, int rows, int *ret) {
    assert(Matrix != nullptr && cols > 0 && rows > 0&& ret != nullptr);
    int index = 0;
    int col = 0;
    int row = 0;
    int colLimt = cols;
    int rowLimt = rows;
    _PrintMatrixClockWise(Matrix, col, row, cols, rows, colLimt, rowLimt, ret, index);
}
bool MySolution::Solution::Judge_Match_Stcak(const int* list_push, const int* list_pop, const int length) {
    assert((length > 0) && (list_pop != nullptr) && (list_push != nullptr));
    int index = 0;
    stack<int> tmp;
    for (int i = 0; i < length; ++i) {
        if (tmp.empty() || list_pop[i] != tmp.top()) {
            do {
                if (index == length) return false;
                tmp.push(list_push[index]);
                index++;
            } while (list_pop[i] != tmp.top());
            tmp.pop();
        } else tmp.pop();
    }
    return true;
}
void MySolution::Solution::DumplicateComplexList_HashMap(ComplexListNode *Head, ComplexListNode **CloneHead) {
  assert(Head != nullptr && CloneHead != nullptr);
  map<ComplexListNode*, ComplexListNode*> TmpMap;
  auto tmpNode = Head;
  *CloneHead = new ComplexListNode;
  auto cloneNode = *CloneHead;
    //第一步：将Head的pNext进行复制，并且建立pAny的哈希表。
    while (tmpNode != nullptr) {
      cloneNode->m_nKey = tmpNode->m_nKey;
      if (tmpNode->M_pNext != nullptr) {
        cloneNode->M_pNext = new ComplexListNode;
      } else {
        cloneNode->M_pNext = nullptr;
      }
      TmpMap[tmpNode] = cloneNode;
      cloneNode = cloneNode->M_pNext;
      tmpNode = tmpNode->M_pNext;
    }
    //第二步：复制pAny
    tmpNode = Head;
    cloneNode = *CloneHead;
  while (tmpNode != nullptr) {
    cloneNode->M_pAny = TmpMap[tmpNode->M_pAny];
    cloneNode = cloneNode->M_pNext;
    tmpNode = tmpNode->M_pNext;
  }
}
void MySolution::Solution::DumplicateComplexList(ComplexListNode *Head, ComplexListNode **CloneHead) {
  assert(Head != nullptr && CloneHead != nullptr);
  auto oldNode = Head;
  //第一步：复制pNext并将其接在原链表被复制的节点后面。
  while (oldNode != nullptr) {
    auto cloneNode = new ComplexListNode;
    cloneNode->m_nKey = oldNode->m_nKey;
    cloneNode->M_pNext = oldNode->M_pNext;
    oldNode->M_pNext = cloneNode;
    oldNode = cloneNode->M_pNext;
  }
  *CloneHead  = Head->M_pNext;
  oldNode = Head;
  //第二步：复制pAny
  while (oldNode != nullptr) {
    oldNode->M_pNext->M_pAny = oldNode->M_pAny;
    oldNode = oldNode->M_pNext->M_pNext;
  }
  //第三步：将复制链表拆下来
  oldNode = Head;
  while (oldNode->M_pNext->M_pNext != nullptr) {
    ComplexListNode *tmp = oldNode->M_pNext;
    oldNode->M_pNext = oldNode->M_pNext->M_pNext;
    tmp->M_pNext = oldNode->M_pNext->M_pNext;
    oldNode = oldNode->M_pNext;

  }
  oldNode->M_pNext = nullptr;
}
void MySolution::Solution::_StringArrange(char *pStr, char *pBegin) {
  if (*pBegin == '\0') {
    printf("%s\t", pStr);
  } else {
      for (char* Index = pBegin; *Index != '\0'; Index++) {
          char tmp = *Index;
          *Index = *pBegin;
          *pBegin = tmp;
          _StringArrange(pStr, pBegin+1);
          tmp = *Index;
          *Index = *pBegin;
          *pBegin = tmp;
      }
  }

}
void MySolution::Solution::StringArrange(char* pStr) {
    assert(pStr != nullptr);
    char* pBegin = pStr;
    cout<< "after string arrange:"<< endl;
    _StringArrange(pStr, pBegin);
    cout << endl;
}
bool MySolution::Solution::MoreThanHalfNumber(int *Number, int *targetNumber, int length) {
  assert(Number != nullptr && targetNumber != nullptr && length > 0);
  int MaxSize = 0;
  int MaxNumber = 0;
  map<int, int> m_map;
  for (int i = 0; i < length ; ++i) {
    ++m_map[Number[i]];
  }
  for (const auto &number : m_map) {
    if (number.second > MaxSize) {
      MaxNumber = number.first;
      MaxSize = number.second;
    }
  }
  if (MaxSize > length/2) {
    *targetNumber = MaxNumber;
    return true;
  } else return false;
}
int partition(int* number, int begin, int end){
    int big = begin ; //数组分界线指针,指向排序后random右边的数
    int random = RandomInRange(begin, end); //生成begin-end间的随机数
    swap(number, random, end);
    for (int i = begin; i < end; ++i) {
        if (number[i] < number[end]) {
            if (i != big) {
                swap(number, big, i);
            }
            big++;
        }
    }
    swap(number, big, end);
    return big;
}
void MySolution::Solution::PrintLittle_k_Number_Partition(int *number, int k, int length) {
  assert((number != nullptr) && (length > 0) && (k > 0) && (length >=k));
  int begin = 0;
  int end = length - 1;
  int target = 0;
    target = partition(number, begin, end);
    while (target != (k-1)) {  //注意是k-1，不是k，target对应的是下标
        if (target > k) {
            end = target - 1;
            target = partition(number, begin,end);
        } else if (target < k) {
            begin = target + 1;
            target = partition(number, begin, end);
        } else break;
    }
    printf("33.最小的%d个数为：\n",k);
    for (int i = 0; i < k; ++i) {
        printf("%d\t", number[i]);
    }
    printf("\n");
}
void MySolution::Solution::PrintLittle_k_Number_UseSpace(int *number, int k, int length) {
    assert(number != nullptr && k > 0 && length >0 && length >= k);
    priority_queue<int,vector<int>,less<int> > myqueue;
    for (int i = 0; i < k; ++i) {
        myqueue.push(number[i]);
    }
    for (int j = k; j < length; ++j) {
        if (myqueue.top() > number[j]) {
            myqueue.pop();
            myqueue.push(number[j]);
        }
    }
    printf("33.最小的%d个数为：\n",k);
    for (int i = 0; i < k; ++i) {
        printf("%d\t", myqueue.top());
        myqueue.pop();
    }
    printf("\n");
}
int MySolution::Solution::FindBiggestSumOfSubArrary(int *arrary, int length) {
  assert(arrary != nullptr && length > 0);
  int nCurrentSum = arrary[0];
  int BiggestSum = nCurrentSum;
  //f(i)为以下标i为最后元素的子数组的最大和
  //f(i) = {f(i-1) + number[i]  //f(i-1) >=0
  //       {number[i]  //f(i-1) < 0
  for (int j = 1; j < length; ++j) {
    if (nCurrentSum > 0) {
      nCurrentSum = nCurrentSum + arrary[j];
    } else {
      nCurrentSum = arrary[j];
    }
    if (nCurrentSum > BiggestSum) BiggestSum = nCurrentSum;
  }
  return BiggestSum;
}
int MySolution::Solution::CountDigitalOne(int n) {
  int cnt = 0;
  for (long long i = 1; i <= n; i*=10) {
    int a = n/i, b = n%i;
    cnt += (a+8)/10*i +(a%10 == 1)*(b+1);//之所以补8，是因为当i位为0，则a/10==(a+8)/10，当百位>=2，补8会产生进位位，效果等同于(a/10+1)
  }
  return cnt;
}