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
