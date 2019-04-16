//
// Created by SCH on 2019/2/25.
//
#include <stack>
#include <vector>
#include <list>
#include <bits/forward_list.h>
#include <cassert>
#include <string>

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
         * 10.1青蛙跳台阶
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
         * @brief：判断一个矩阵中是否包含在一条某字符串所有的字符的路径。路径可以从矩阵任意一格开始，每一步可以在矩阵中
         * 上、下、左、右移动一格。如果一条路径经过了矩阵中的某一格，那么该路径就不能再次进入该格子。
         * @note：回溯算法；回溯算法是蛮力法的升级版，它从解决问题的每一步的所有可能选项里系统地选择出一个可行的解决办法。
         * 回溯法适合解决由多个步骤组成的问题，且每一个步骤都包含多个选项。
         * @param:matrix：字符数组
         * @param:rows：列数
         * @param:row：当前列坐标
         * @param:cols：行数
         * @param:col：当前行坐标
         * @param:str：需要找到的路径
         * @param:PathCharIdex:用于指示str的下标，表示当前正在 寻找哪个字母的路径
         * @param:IsMarked：用于标记矩阵中的某一位是否已经走过，走过则为true，否则为false
         * @return:true:路径存在，otherwise not exist
         * */
        bool _FindPathInMatrix(char* matrix, int col, int cols, int row, int rows, char* str, int* PathCharIdex, bool *IsMarked);
        bool FindPathInMatrix(char* matrix, int cols, int rows, char* str);

        /**
         * 14.机器人运动范围
         * @brief：在m×n的方格中，机器人从坐标（0,0）开始移动，可上下左右动，但一个坐标只能走一次，
         * 而且不能进入坐标位数之和>k的格子。问：机器人能够到达多少个格子.如k=18时，能进（35，37），因为3+5+3+7=18.
         * @note:回溯算法
         * @param:rows:列数
         * @param:row：当前列坐标
         * @param:cols：行数
         * @param:col：当前行坐标
         * @param:k：限制值
         * @param:IsMarked（两个作用合一）:1.用于标记某一位置是否走过，走过为true，否则false；2.同时也用于记录一共走过了多少格子，走过的就对应索引值+1，最后遍历chessboard得出到达的格子数
         * @return：机器人能够到达的格子数
         * */
        int DigitalSum(int number); //数字各位之和
        void _RobotRunRange(int col, int cols, int row, int rows, int k, int* IsMarked);
        int RobotRunRange(int cols, int rows, int k);

        /**
         * 15.剪绳子
         * @brief：将长度为m的绳子减为任意n段，求各段长度乘积的最大值。（m>1，n>1为整数）
         * @note:动态规划.通常求一个问题的最优解（最大值或者最小值），且该问题能够分解成若干个子问题，子问题之间
         * 还有重叠的更小的子问题时，就可以考虑用动态规划解决。
         * @note:贪婪算法：每一步都做出一个贪婪的最优选择，基于这个选择，我们能够得到最优解。
         * @note:需要我们将一个具体的场景抽象成一个能够用动态规划或者贪婪算法解决的模型。
         * 关键是要具备从上到下分析问题、从下到上解决问题的能力，以及扎实的数学基本功。
         *@param:length:绳子长度
         *@return：各段长度乘积最大值
         * */
         //动态规划
        unsigned int CutRope_DynamicProgramming(int length);
        //贪婪算法
        unsigned int CutRope_GreedyAlgorthm(int length);

        /**16.二进制中1的个数
         * @brief：输入一个整数，输出该二进制数中1的个数
         * @note:位运算
         * @note：统计二进制数中1的个数可以解决很多问题。如：判断一个整数是不是2的整数次方（二进制数只有一个1）；输入两个数m和n，
         * 计算需要改变m的二进制表示中的多少位才能得到n（先异或，在求1的个数）。
         * @note：编程语言、数据结构（数组、字符串、堆、栈、队列、链表、树等等）、算法（查找、排序、动态规划、回溯法、贪婪算法、时间/空间复杂度）
         * @param:number:无符号整数
         * @return：1的个数
         * */
         //迭代，循环32次。不能右移，负数会补位。
         int Find_1_InNumber(unsigned int number);
         //迭代，多少个1就循环多少次
         int Find_1_InNumberX(unsigned int number);

         /**
          * 17.数值的整数次方值
          * @brief:实现库函数:数值的整数次方值。
          * @note：普通做法是进行(Expenent-1)次乘法。更好的方法是可以利用动态规划思想：求Expenent/2的指数值。即利用公式：
          * a^n = {a^n-2 * a^n-2 //n为偶数
          *       {a^n-2 * a^n-2 * a  //n为奇数
          * @note:高质量代码三要素：
          * 1.代码的规范性：书写清晰；布局清晰；命名合理；
          * 2.代码的完整性：功能测试；边界测试；负面测试；
          * 3.错误处理方法：返回值；全局变量；抛出异常
          * @param：base:底数,exponent:指数
          * @return：运算结果
          * */
          double Power(double Base, int Exponent);
          double PowerWithUnsignedExpenent(double Base, unsigned int Expenent);

          /**18.打印1-n位最大的整数
           * @brief:输入数字n，按顺序打印出从1到n位的最大十进制数。如：n=2,打印1，2，3.。。。99
           * @note:解决大数问题：1.用字符串模拟数学加减 2.字符串的表示
           * @note:遵循单一职责原则，一个模块只负责一个功能。IncreaseNumber（）负责生成模拟加减的字符串；_printNumber负责打印该字符串。
           * @param：n:最大的位数n
           * @param：Number:用于存放字符串的数组
           * */
           bool IncreaseNumber(char* Number);
           void _PrintNmber(char* Number);
           void PrintNumber(int n);

           /**19.删除链表任意节点，o（1）时间
            * @brief：最直接的方法是遍历链表，找到要删除的节点的前一个节点和后一个节点。这样时间复杂度为o（n）
            * @note：通过节点替换（覆盖），来实现删除节点
            * @note：o(1)方法有个问题：无法再删除已经删除了的节点的下一个节点，即（不能删除两个相邻的节点）
            * @param:Head:链表头节点
            * @param:ToBeDeleted：需要被删除的节点
            * */
            void DeletNode(ListNode** Head, ListNode* ToBeDeletde);

            /**20.删除链表重复的节点
             * @brief:在一个排序链表中，存在连续的重复节点，删除链表中重复的节点。
             * @note：考察对链表的理解和编程能力，重复节点可能出现在链表头、中间、尾部位置，也可能没有重复节点。
             * 如何删除重复节点（如何重置删除重复节点后的链表，即需要（双指针）保存一个PreNode（非重复节点指针）和一个IndexNode（索引指针））
             *@param:Head：链表头节点
             *@return:重复节点的个数
             * */
             int DeleteDumplicateNode(ListNode** Head);

             /**21.正则表达式的匹配
              * @brief:实现一个函数，用于匹配包含“*”和“.”的正则表达式。模式中的“.”可以匹配任意一个字符，而“*”匹配表示
              * 它前面的字符可以出现任意次数（含0次）。
              * @note：三指针，两个用来匹配，一个用来循环
              * @note：可以用有限状态机来建模
              * @param：str：要匹配的字符串
              * @param：tempstr：匹配的模板
              * @retrun:true if match success,otherwise is false
              * */
              bool RegularExpressionMatch(const char* str, const char* tempstr);
              /**22.表示数值的字符串
               * @brief:实现一个函数，判断一个字符串是否能够表示数值（包括整数和小数）。如“+122”，“-123”，“5e2”，“-1E-19”
               * 都是正确的。但“12e”，“1a3.14”，“1.2.3”，“-+2”，“12e+5.4”都不是。
               * @note：就是josn的数字的解析，字符串编程能力。需要注意的就是要考虑各种情况。
               * @param:str:字符串
               * @param:number:匹配后输出的字符串
               * @return ：if match retrun true,otherwise return false
               * */
               bool StrToDigital(const char* str, double* number);

               /**22.调整数组，使得奇数在前，偶数在后
                * @brief:输入一个整数数组，实现一个函数来调整该数组中的数字的顺序，使得奇数在前偶数在后。
                * @note：双指针,一头一尾。代码的可移植性/可扩展性/可重用性，单一职责原则。
                * @param：输入arrary:数组
                * @param:func:函数指针，代码可重用的关键，是一个一元谓词。
                * @param:length数组长度（无法判断数组的长度，只能从外部传入）。
              * */
              static bool JudgeOdd(int number);
              void AdjustArary(int arrary[], int length, bool(*func)(int));
              /**23.链表倒数第k个节点
               *@brief:输入一个链表，输入该链表的倒数第k个节点。从1开始计数，即链表的尾节点是倒数第一个节点。
               *@note：双指针，倒数第k个节点就是顺数第n-k+1个节点。想象一下：
               *一个长度为 n 的链表，我们要求倒数第k个节点，关键在于知道顺数时其前面的n-k+1个节点。
               * 可以用一个指针，先走k-1个节点，这样它和另一个从头开始动的节点之间的距离永远是k-1；在先行的指针运动到尾部时：
               * 另一个节点就运动到了n-k+1的位置，即倒数第k个节点。
               *@note：同样的双指针思路，还可以求链表的中间节点，1/3处、1/4处（若是存在）...等等求相对位置的节点。
               *@param:Head：链表头节点
               *@param：k：倒数第k个节点
               *@return：倒数第k个节点的值
               * */
               int Find_K_InList(ListNode* Head, int k);

               /**24.链表中环的入口节点
                * @brief：如果一个链表中包含环，如何找出环的入口节点？
                * @note：双指针的应用。
                * @note：需要解决两个问题：1.如何确定一个链表中包含环？2.如何找到入口节点
                * 1.双指针，一快一慢，如果能相遇说明有环。2.如果环中有n个节点，可以让快指针先走n步，最终相遇时就会在入口节点，那么如何确定n？
                *只要确定有环后，从相遇点再跑一圈计数就行了。
                * @param:Head链表头节点
                * @return:if has ring, return ringNode，otherwise return nullptr.
                * */
                ListNode* FindRingNode(ListNode* Head);
                /**25.反转链表并且输出反转后链表的头节点
                 * @brief:定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
                 * @note：1.三指针(迭代),分别保存迭代时的currentNode、preNode、NextNode。
                 * @note:2.递归：这边使用递归是十分巧妙的方法，首先利用递归走到链表的尾节点，然后再更新每个节点的pNext，从而实现链表的反转。而NewNext
                 * 的值在递归到末端并赋值后就没有发生改变。还有一点需要注意的是：最后递归出来时并不会设置原链表Head的pNext=null;所以可以索性一上来在递归至原链表尾部的过程中就把
                 * 所有节点的pNext=nullptr。
                 * @note：3.利用栈，也是递归的本质。
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
                  /**31.字符串的排列
                   * @brief:输入一个字符串，输出该字符串的所有排列组合。
                   * @note:全排列/生成字典；可用递归/迭代/回溯法解决.
                   * @note:对于那些按照一定要求摆放数字或者字母的题目，我们可以先求出全排列，然后一一判断每个排列是否满足要求。
                   * @param:pStr:整个字符串的第一个字符
                   * @param:pBegin:指向执行排列操作的字符串的第一个字符
                   * */
                   //递归法
                  void _StringArrange(char* pStr, char* pBegin);
                  void StringArrange(char* pStr);
                  /**32.数组中出现次数过半的数字
                   * @brief：判断一个数组中是否有出现次数过半的数字，如果有则找出这个数字
                   * @note:判断多种方法的时间复杂度&空间复杂度
                   * @note:解法1：基于Partition函数的时间复杂度为o（n）的算法，基于快排算法的思想，找出中位数。
                   * @note：解法2：利用HashMap，空间换时间，空间复杂度为o（n），时间复杂度为o（n）？。
                   * @param:Number:输入的数组
                   * @param:targetNumer:过半的数字
                   * @return: 如果存在则返回true，否则返回false
                   * */
                   bool MoreThanHalfNumber(int Number[], int* targetNumber, int length);
                   /**33.最小的k个数
                    * @brief:输入n个整数，找出其中最小的k个数。
                    * @note: 最优解法和32题相同，利用partition（隔断）函数，基于快速排列算法思想（类似二分法），找到分界点k即可。
                    * 此时时间复杂度o（n），没有用额外空间。
                    * @note:利用一个存储量为k的临时空间，先将数组前四个元素塞进去，然后遍历数组，比容器中最大值小的就替换进去。
                    * 此算法和partition的解法时间复杂度相同，但空间复杂度为o（n）。但优点是：在处理海量数据存在优势。
                    * @param:number:输入数组
                    * @param:length：数组长度
                    * @param:k
                    * */
                    void PrintLittle_k_Number_Partition(int number[], int length, int k);
                    void PrintLittle_k_Number_UseSpace(int number[], int length, int k);
                    /**34.连续子数组的最大和
                     * @brief:输入一个整形数组，数组里面有正数也有 负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
                     * 要求时间复杂度为o(n).如：输入数组为{1,-2,3,10,-4,7,2,-5},和最大子数组为{3,10,-4,7,2},输出和为18.
                     * @note：动态规划思想：用函数f(i)表示以第i个数字结尾的所有子数组中的最大和，那么,我们可以用如下递归公式求f(i)：
                     * f(i) = {f(i-1) + number[i]  //i >= 1 && f(i-1) > 0
                     *        {number[i]          //i >= 1 && f(i-1) <= 0
                     * @param：arrary:输入数组
                     * @param：length：数组长度
                     * @return: 子数组最大和
                     * */
                     int FindBiggestSumOfSubArrary(int* arrary, int length);
                     /**35.1-n中1出现的次数
                      *@brief:输入一个整数n，求该整数的十进制表示中1出现的次数。
                      *@note1:数学之美算法：a=n/i,b=n%i;
                      * 如果要计算百位上1出现的次数，它要受到3方面的影响：百位上的数字，百位以下（低位）的数字，百位以上（高位）的数字。
                       * 比如a=314,b=56:
                       * 当a的各位>1时（也就是n的百位），百位为1的数总共出现了(a/10+1)*100次;
                       * 当a的个位为1的时候，百位为1的数总共出现了(a/10)*100+(b+1); 100-199，1100-1199，...30100-30199,31100-311b
                       * 当a的个位为0的时候，百位为1的数出现了(a/10)*100次；
                       * 因此可以根据a的个位是否为1分成2中情况计算；
                      *@note2：《编程之美》上这样说:
                       *设N = abcde ,其中abcde分别为十进制中各位上的数字。
                       *如果要计算百位上1出现的次数，它要受到3方面的影响：百位上的数字，百位以下（低位）的数字，百位以上（高位）的数字。
                       *如果百位上数字为0，百位上可能出现1的次数由更高位决定。比如：12013，则可以知道百位出现1的情况可能是：
                       * 100~199，1100~1199,2100~2199，，...，11100~11199，一共1200个。
                       * 可以看出是由更高位数字（12）决定，并且等于更高位数字（12）乘以 当前位数（100）。注意：高位数字不包括当前位
                       *如果百位上数字为1，百位上可能出现1的次数不仅受更高位影响还受低位影响。比如：12113，则可以知道百位受高位影响出现的情况是：
                       * 100~199，1100~1199,2100~2199，，....，11100~11199，一共1200个。和上面情况一样，并且等于更高位数字（12）乘以 当前位数（100）。
                       * 但同时它还受低位影响，百位出现1的情况是：12100~12113,一共14个，等于低位数字（13）+1。 注意：低位数字不包括当前数字
                       *如果百位上数字大于1（2~9），则百位上出现1的情况仅由更高位决定，比如12213，则百位出现1的情况是：
                       * 100~199,1100~1199，2100~2199，...，11100~11199,12100~12199,一共有1300个，并且等于更高位数字+1（12+1）乘以当前位数（100）
                      *@param:n:输入的整数
                      *@return: 整数中1出现的次数
                      * */
                      int CountDigitalOne(int n);
                      /**36.数字序列中的某一位数字
                       * @brief:数字以0123456789101112131415...的格式序列化到一个字符序列中。
                       * 在这个序列中，第五位（从0开始计数）是5，第19位是4.写一个函数，求任意第n位对应的数字。
                       * @note:序列和数字的关系10×1+90×2+900×3+9000×4...
                       * @note：先确定该序列所在数的位数和值，再缺点该序列是数字的第几位
                       * @param:n：输入序列值
                       * @retrun: 该序列所在的数字
                       * */
                      int DigitalAtIndex(int n);
                      /**37.把数组排列成最小的数
                       * @brief:输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接处的所有数字中最小的一个。
                       * 例如：输入{3,32,321},则打印出321323
                       * @note：
                       * @param:
                       * @return:
                       * */
                       string SortMostLittleNumber(vector<int> numbers);

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
