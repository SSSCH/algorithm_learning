//
// Created by SCH on 2019/2/25.
//
#include <stack>
#include <vector>
#ifndef ALGORITHM_LEARNING_SOLUTION_H

#define ALGORITHM_LEARNING_SOLUTION_H
using namespace std;
struct ListNode{
    int m_nKey;
    ListNode* M_pNext;
};
namespace MySolution{
    class Solution {
    public:
        /**
         * 3.数组中的重复数字
        Parameters:
        @numbers:an arrary integers
        @length: the length of arrary numbers
        @duplication(output):the duplicated number in the arrary numbers
        @return value : @true if the input is valid, and there are some duplication in the arrary numbers
        otherwise false
         * */
        bool duplicate(int numbers[], int length, int* duplication);
        /**
            4.二维数组中的查找
            parameters:
            @numbers:2d arrarys,@rows:hang,@columns:lie
            target:the given numbers
            retutn value:@true if the targets exist, otherwise not exist
         * */
        bool find_2dArrary(int* numbers, int rows, int columns, int target);
        /**
         * 5.替换空格
         * parameters:@string(input)
         * return:the processed string
         * */
        char* submit_blank(char string[]);
        /***
         6.从尾到头打印链表
         Parameters:@phead(input):链表头节点
         */
        void PrintListReversing_Iteratively(ListNode* phead);//迭代地，栈实现
        void PrintListReversing_Recursively(ListNode* phead);//递归地，递归实现
        /***
         * 10.斐波那契数列
         * f(0)= 0, f(1)= 1, f(n)=f(n-1)+f(n-2)*/
        long long Fibonacci_Recursively(unsigned int n);  //递归实现
        long long Fibonacci_Iteratively(unsigned int n); //循环实现
        /***
         * 10.1青蛙跳台阶，一只青蛙一次可以跳上 1 级台阶，也可以跳上 2 级。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
         * f(n)=f(n-1)+f(n-2),f(1)=1, f(2)=2
         * */
        long long JumpStep(unsigned int n);
        /***
         * 10.2变态跳台阶，一只青蛙一次可以随意跳n级台阶，求它跳上一个n级台阶有多少种方法。
         * f(n)=f(n-1)+...+f(1)
         * */
        /**
         * 10.3矩形覆盖，逻辑原理同为10，10.1：fibonacci数列,实现同10.1
         * */
        long long JumpStepPlus_DynamicPlan(unsigned int n);
        long long JumpStepPlus_Math(unsigned int n);

        /**11.快速排序的递归实现与循环实现
         *
         * */
         int _QuickSort(int data[], int lenth, int begin, int end);
         void QuickSort(int data[], int length, int begin, int end);
         /**12.旋转数组最小值
          * @修改二分法实现 & 顺序查找实现
          * @input:@number,输入的旋转数组；@length，数组的长度
          * @output/return:最小值
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
    };

    /***
     * 9.用两个栈模拟队列
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
}



#endif //ALGORITHM_LEARNING_SOLUTION_H
