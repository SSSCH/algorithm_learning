//
// Created by SCH on 2019/2/25.
//
#include <stack>

#ifndef ALGORITHM_LEARNING_SOLUTION_H

#define ALGORITHM_LEARNING_SOLUTION_H
struct ListNode{
    int m_nKey;
    ListNode* M_pNext;
};
namespace MySolution{
    class Solution {
    public:
        //3.数组中的重复数字
        //Parameters:
        //@numbers:an arrary integers
        // @length: the length of arrary numbers
        // @duplication(output):the duplicated number in the arrary numbers
        //Teturn value : @true if the input is valid, and there are some duplication in the arrary numbers
        //otherwise false
        bool duplicate(int numbers[], int length, int* duplication);
        //4.二维数组中的查找
        //parameters:
        //@numbers:2d arrarys,@rows:hang,@columns:lie
        //target:the given numbers
        //retutn value:@true if the targets exist, otherwise not exist
        bool find_2dArrary(int* numbers, int rows, int columns, int target);
        /*
         * 5.替换空格
         * parameters:@string(input)
         * return:the processed string
         * */
        char* submit_blank(char string[]);
        /*
         * 6.从尾到头打印链表
         *Parameters:@phead(input):链表头节点
         *
         * */
        void PrintListReversing_Iteratively(ListNode* phead);//迭代地，栈实现
        void PrintListReversing_Recursively(ListNode* phead);//递归地，递归实现
    };
    template<typename T>
    class CQueue {
    public:
        /*添加队列尾节点
         * @paramers:@node(input) 类型的引用
         * */
        void AppendTail(const T& node);
        /*
         * 删除隊列头节点
         * */
        void DeletHead();
        /*返回头节点
         * */
        T BOTTON();

    private:
        std::stack<T> stack_for_queuepush;
        std::stack<T> stack_for_queuepop;
    };
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
            throw new std::exception();
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
            throw new std::exception();
        }
        ret = stack_for_queuepop.top();
        return ret;
    }
}



#endif //ALGORITHM_LEARNING_SOLUTION_H
