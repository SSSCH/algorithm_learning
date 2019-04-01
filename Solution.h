//
// Created by SCH on 2019/2/25.
//
#include <stack>
#include <vector>
#include <list>
#include <bits/forward_list.h>
#include <cassert>

#ifndef ALGORITHM_LEARNING_SOLUTION_H

#define ALGORITHM_LEARNING_SOLUTION_H
using namespace std;
struct ListNode{
    int m_nKey;
    ListNode* M_pNext;
};
struct ComplexListNode{
    int m_nKey;
    ComplexListNode* M_pNext;
    ComplexListNode* M_pAny;
};
namespace MySolution{
    class Solution {
    public:
        /**
         * 3.数组中的重复数字。
         * @brief在一个长度为n的数组里，所有的数字都在0-n-1的范围内。数组中某些数字是重复的，
         * 但不知道有几个是重复的，也不知道每个数字重复了几次。找出数组中任意一个重复的数字。
         * @note:空间复杂度为o(1),时间复杂度为o(n);将数字放到对应下标的位置。，重复比较和交换过程，知道发现一个重复的数字。
         * @param,numbers:an arrary integers
         *@param,length: the length of arrary numbers
         *@param,duplication(output):the duplicated number in the arrary numbers
         *@return value : @true if the input is valid, and there are some duplication in the arrary numbers
         *otherwise false
         * */
        bool duplicate(int numbers[], int length, int* duplication);
        /**
            *4.二维数组中的查找
            * @brief:在一个二维数组中，每一行都按照从左到右递增，每一列按照从上倒下递增。完成一个函数，输入这样一个二维数组和一个整数，判断该数组是否有该整数。
            * @note:从可以减小数组范围的角度考虑，选择二维数组的右上角/坐下角作为起点，大于目标数则可以删去一行，小于目标数则可以删去一列。
            *parameters:@numbers:2d arrarys,@rows:hang,@columns:lie,target:the given numbers
            *retutn value:@true if the targets exist, otherwise not exist
         * */
        bool find_2dArrary(int* numbers, int rows, int columns, int target);
        /**
         * 5.替换空格
         * @brief:把字符串的每一个空格替换成“%20”。
         * @note:从时间复杂度和空间复杂度的优化考虑，先遍历字符串算出空格数，然后从后往前重置字符串。这样只需移动字符串一次。
         * @param:@string(input)
         * &return:the processed string
         * */
        char* submit_blank(char string[]);
        /***
         6.从尾到头打印链表
         @brief:输入链表头节点，从尾到头打印每个节点的值。
         @note:利用栈或者递归的方式（递归的本质就是栈）就能只遍历链表一次，就输出每个节点的值。
         @Parama:phead(input):链表头节点
         */
        void PrintListReversing_Iteratively(ListNode* phead);//迭代地，栈实现
        void PrintListReversing_Recursively(ListNode* phead);//递归地，递归实现
        /***
         * 10.斐波那契数列
         * f(0)= 0, f(1)= 1, f(n)=f(n-1)+f(n-2)
         * @brief:输入n，求斐波那契（Fibonacci）数列的第n项。
         * @note：递归和循环，递归的本质是把一个问题分解成两个或者多个小问题。如果多个小问题存在相互重叠的部分，就存在重复的计算。
         *        通常应用动态规划解决问题是我们都是用递归的思想分析问题，但递归也存在不足：因为其总是自下而上的循环来实现代码，所以递归分解的子问题中
         *        会存在大量的重复，如在feibonacci数列中求f（10）要先求f（9）和f（8），求f（9）要先求f（8）和f（7）...所以会有很多重复的节点。
         *        为了避免重复 计算，我们可以把已经得到的数列中间项保存起来，在下次需要计算的时候先查找一下，如果已经计算过来就不要重复计算了。
         * */
        long long Fibonacci_Recursively(unsigned int n);  //递归实现
        long long Fibonacci_Iteratively(unsigned int n); //循环实现
        /***
         * 10.1青蛙跳台阶，
         * @brief：一只青蛙一次可以跳上 1 级台阶，也可以跳上 2 级。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
         * @note：feibonacci的应用。
         * f(n)=f(n-1)+f(n-2),f(1)=1, f(2)=2
         * */
        long long JumpStep(unsigned int n);
        /***
         * 10.2变态跳台阶，
         * @brief：一只青蛙一次可以随意跳n级台阶，求它跳上一个n级台阶有多少种方法。
         * @note：f(n)=f(n-1)+...+f(1)。feibonacci的引申。
         *
         * */
        /**
         * 10.3矩形覆盖
         * @brief:使用8个2×1的小矩形无重叠 的覆盖一个2×8的大矩形都多少中方法
         * @note:逻辑原理同为10，10.1：fibonacci数列,实现同10.1
         * */
        long long JumpStepPlus_DynamicPlan(unsigned int n);
        long long JumpStepPlus_Math(unsigned int n);

        /**11.快速排序的递归实现与循环实现
         *@brief：快速排序的关键在于在数组中选择一个数字，接下来把数组中的数字分为两部分，比该数字小的移到数组的左边，比他大的数字移到数组右边。
         *@note:双指针；一个负责指向最后一个小于该目标数的指针，一个负责遍历。
         * */
         int _QuickSort(int data[], int lenth, int begin, int end);
         void QuickSort(int data[], int length, int begin, int end);
         /**12.旋转数组最小值。
          * @brief：把一个数组最开始的若干元素搬到数组的末尾，我们称之为旋转数组。输入一个递增的旋转数组，输出该数组的最小值。
          * @note：修改二分法实现 & 顺序查找实现
          * @param：input:@number,输入的旋转数组；@length，数组的长度
          * @return:output/return:最小值
          * */
        int MinNumberInRotateArrary(int RotatArrary[], int length);
        int MinNumberByOrder(int RotatArrary[], int length);

        /**13字符矩阵中的路径
         * @回溯算法
         * @input:matrix：字符数组
         * rows：列数
         * row：当前列坐标
         * cols：行数
         * col：当前行坐标
         * str：需要找到的路径
         * PathCharIdex:用于指示str的下标，表示当前正在 寻找哪个字母的路径
         * IsMarked：用于标记矩阵中的某一位是否已经走过，走过则为true，否则为false
         * @return:true:路径存在，otherwise not exist
         * */
        bool _FindPathInMatrix(char* matrix, int col, int cols, int row, int rows, char* str, int* PathCharIdex, bool *IsMarked);
        bool FindPathInMatrix(char* matrix, int cols, int rows, char* str);

        /**
         * 14.机器人运动范围
         * @题目描述：在m×n的方格中，机器人从坐标（0,0）开始移动，可上下左右动，但一个坐标只能走一次，而且不能进入坐标位数之和>k的格子。问：机器人能够到达多少个格子
         * @回溯算法
         * @input：rows:列数
         * row：当前列坐标
         * cols：行数
         * col：当前行坐标
         * k：限制值
         * IsMarked（两个作用合一）:1.用于标记某一位置是否走过，走过为true，否则false；2.同时也用于记录一共走过了多少格子，走过的就对应索引值+1，最后遍历chessboard得出到达的格子数
         * @output：机器人能够到达的格子数
         * */
        int DigitalSum(int number);
        void _RobotRunRange(int col, int cols, int row, int rows, int k, int* IsMarked);
        int RobotRunRange(int cols, int rows, int k);

        /**
         * 15.剪绳子
         * @题目描述：将长度为m的绳子减为任意n段，求各段长度乘积的最大值。（m>1，n>1为整数）
         * @动态规划，@贪婪算法
         *@input:@length:绳子长度
         *@return：各段长度乘积最大值
         * */
         //动态规划
        unsigned int CutRope_DynamicProgramming(int length);
        //贪婪算法
        unsigned int CutRope_GreedyAlgorthm(int length);

        /**16.二进制中1的个数
         * @位运算
         * @题目描述：输入一个整数，输出该二进制数中1的个数
         * @input:无符号整数
         * @return：1的个数
         * */
         //迭代，循环32次
         int Find_1_InNumber(unsigned int number);
         //迭代，多少个1就循环多少次
         int Find_1_InNumberX(unsigned int number);

         /**
          * 17.数值的整数次方值
          * @考察1.代码的规范性：书写清晰；命名规范；布局清晰2.代码的完整性：功能测试；边界测试；负面测试3.错误处理方法：返回值；全局变量；抛出异常
          * @input：底数&指数
          * @return：运算结果
          * */
          double Power(double Base, int Exponent);
          double PowerWithUnsignedExpenent(double Base, unsigned int Expenent);

          /**18.打印1-n位最大的整数
           * @解决大数问题：1.用字符串模拟数学加减2.字符串的表示
           * @input：位数n
           * @return：打印1-n位最大的整数
           * */
           bool IncreaseNumber(char* Number);
           void _PrintNmber(char* Number);
           void PrintNumber(int n);

           /**19.删除链表任意节点，o（1）时间
            * @input:@Head:链表头节点@ToBeDeleted：需要被删除的节点
            *@该算法会导致不能连续删除相邻的节点
            * */
            void DeletNode(ListNode** Head, ListNode* ToBeDeletde);

            /**20.删除链表重复的节点,且重复的节点是连续的
             * @input:@Head：链表头节点
             *@return:重复节点的个数
             * */
             int DeleteDumplicateNode(ListNode** Head);
             /**21.正则表达式的匹配
              * @三指针，两个用来匹配，一个用来循环
              * @input：@str：要匹配的字符串@tempstr：匹配的模板
              * @retrun:true if match success,otherwise is false
              * */
              bool RegularExpressionMatch(const char* str, const char* tempstr);

              /**22.字符串转数字
               * @功能考虑齐全
               * @ input：@str:字符串
               * @output:@number:匹配后的字符串
               * @return ：if match retrun true,otherwise return false
               * */
               bool StrToDigital(const char* str, double* number);

               /**22.调整数组，使得奇数在前，偶数在后
                * @breaf双指针,代码的可移植性/可扩展性/可重用性
                * @param：arrary数组，func函数指针，length数组长度
              * */
              static bool JudgeOdd(int number);
              void AdjustArary(int arrary[], int length, bool(*func)(int));
              /**23.链表倒数第k个节点
               *@brief双指针，鲁棒性
               * @param:Head链表头节点，k倒数第k个节点
               * @return倒数第k个节点的值
               * */
               int Find_K_InList(ListNode* Head, int k);

               /**24.判断一个链表中是否有环，如果有的话找出环的入口节点
                * @brief双指针的使用
                * @param:Head链表头节点
                * @return:if has ring, return ringNode
                * */
                ListNode* FindRingNode(ListNode* Head);
                /**25.反转链表并且输出反转后链表的头节点
                 * @brief1.三指针(迭代),2.递归：这边使用递归是十分巧妙的方法，首先利用递归走到链表的尾节点，然后再更新每个节点的pNext，从而实现链表的反转。而NewNext
                 * 的值在递归到末端并赋值后就没有发生改变。还有一点需要注意的是：最后递归出来时并不会设置原链表Head的pNext=null;所以可以索性一上来在递归至原链表尾部的过程中就把
                 * 所有节点的pNext=nullptr。
                 * @param Head,链表头节点
                 * @return 反转后链表头节点
                 * */
                ListNode* ReverseList_Recursively(ListNode* Head); //迭代实现
                ListNode* ReverseList_Iteratively(ListNode* Head); //递归实现
                /**26.合并两个递增的链表，合并后任然是递增的
                 * @brief:双指针
                 * @param:Head1
                 * @param:Head2
                 * @retrun:合并后的链表头节点
                 * */
                 ListNode* Merge2List(ListNode* Head1, ListNode* Head2);
                 /**27顺时针打印矩阵
                  * @brief:通过画图让抽象的问题具象化,迭代、递归都行
                  * @param：matrix输入矩阵
                  * @param:cols:矩阵的行数，rows：矩阵的列数
                  * @param:col：打印的起点行坐标，row：打印的起点的列坐标，colLimt:打印的行坐标的最大值，rowLimt：打印的列坐标的最大值
                  * @param：ret，输出顺时针打印的矩阵的头指针
                  * */
                 void PrintMatrixClockWise(int* Matrix,int cols,int rows, int* ret);
                 /**29.栈的压入和弹出 序列
                  * @brief:给出一个序列表示栈的 压入顺序，判断另一个序列是不是弹出顺序。
                  * @brief：举例，找规律,建立辅助栈，彻底明白栈的本质（filo）
                  * @param:list_push:压入序列，list_pop:弹出序列,length:序列长度
                  * @return:是的话返回true，否则返回false
                  * */
                 bool Judge_Match_Stcak(const int* list_push, const int* list_pop, const int length);
                 /**30.复杂链表的复制
                  * @brief:输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个指向链表中任意一个节点，包括null），返回赋值后的复杂链表的head
                  * @note：方法1：利用哈希表，o（n）/o(n);方法2：分治思想，不需要辅助空间，时间复杂度为o(n)
                  * @param:Head：原链表头节点
                  * @param:CloneHead:复制的复杂链表的头节点的指针。注意：返回值的类型是指针，所以传参类型是ComplexListNode**
                  * */
                  void DumplicateComplexList_HashMap(ComplexListNode* Head, ComplexListNode** CloneHead);
                  void DumplicateComplexList(ComplexListNode* Head, ComplexListNode** CloneHead);
    };
    /***
     * 9.用两个栈模拟队列
     * @brief:用两个栈实现队列，实现他的两个函数appendTail和deleteHead，分别完成队列尾部的插入节点和在队列头部删除节点的功能。
     * @note:类模板的编程，队列（先进先出）和栈（先进后出）的本质
     * */
    template<typename T>
    class CQueue {
    public:
        /**
         * 添加队列尾节点
         * @paramers:@node(input) 类型的引用
         * */
        void AppendTail(const T& node);
        /**
         * 删除隊列头节点
         * */
        void DeletHead();
        /**
         * 返回头节点
         * */
        T BOTTON();

    private:
        std::stack<T> stack_for_queuepush;
        std::stack<T> stack_for_queuepop;
    };
    /***template的定义和声明必须在同一个文件中***/
    template<typename T> void MySolution::CQueue<T>::AppendTail(const T& node) {
        stack_for_queuepush.push(node);
    }
    template<typename T> void MySolution::CQueue<T>::DeletHead() {

        if (stack_for_queuepop.empty() && (!stack_for_queuepush.empty())) {
            while (!stack_for_queuepush.empty()) {
                T& tmp = stack_for_queuepush.top();
                stack_for_queuepop.push(tmp);
                stack_for_queuepush.pop();
            }
        } else if(stack_for_queuepop.empty() && stack_for_queuepush.empty()) {
            throw std::exception();
        }
        stack_for_queuepop.top();
        stack_for_queuepop.pop();
    }
    template<typename T> T MySolution::CQueue<T>::BOTTON() {
        T ret;
        if (stack_for_queuepop.empty() && (!stack_for_queuepush.empty())) {
            while (!stack_for_queuepush.empty()) {
                T& tmp = stack_for_queuepush.top();
                stack_for_queuepop.push(tmp);
                stack_for_queuepush.pop();
            }
        } else if(stack_for_queuepop.empty() && stack_for_queuepush.empty()) {
            throw std::exception();
        }
        ret = stack_for_queuepop.top();
        return ret;
    }
    /**28.包含min函数的的栈。
 * 定义栈的数据节后，在该类型中实现一个能够找到栈的最小值的min函数，且调用min、push、pop的时间复杂度都为o（1）
 * @brief:类模板编程、辅助栈的构建,辅助栈的pop和push和数据栈的pop和push同进度
 *@brief:举例让抽象问题具体化
 * */
    template <typename T>
    class StackWithMin {
    public:
        //push
        void push(const T& element);
        //pop
        void pop();
        //min
        T min();

    private:
        stack<T> Data;
        stack<T> Min;

    };

    template <typename T> void MySolution::StackWithMin<T>::push(const T& element) {
        Data.push(element);
        if (Min.empty() || (element < Min.top())) {
            Min.push(element);
        } else {
            Min.push(Min.top());
        }
    }
    template <typename T> void MySolution::StackWithMin<T>::pop() {
        assert(Data.size() > 0 && Min.size() > 0);
        Data.pop();
        Min.pop();
    }
    template <typename T> T MySolution::StackWithMin<T>::min() {
        assert(Data.size() > 0 && Min.size() > 0);
        return Min.top();
    }
}



#endif //ALGORITHM_LEARNING_SOLUTION_H
