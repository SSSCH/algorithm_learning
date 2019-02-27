//
// Created by SCH on 2019/2/25.
//

#include <assert.h>
#include <cstring>
#include "Solution.h"
#include <vector>
#include <string>
using std::vector;
using std::string;
vector<int> v(3, 7); //= vector<int> v{7, 7, 7}
string s = "sssccchhh";


void swap(int* nums, int j, int i){
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
    assert(numbers != NULL && rows > 0 && columns > 0);
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