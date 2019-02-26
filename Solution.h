//
// Created by SCH on 2019/2/25.
//

#ifndef ALGORITHM_LEARNING_SOLUTION_H

#define ALGORITHM_LEARNING_SOLUTION_H
namespace MySolution{
    class Solution {
    public:
        //Parameters:
        //@numbers:an arrary integers
        // @length: the length of arrary numbers
        // @duplication(output):the duplicated number in the arrary numbers
        //Teturn value : @true if the input is valid, and there are some duplication in the arrary numbers
        //otherwise false
        bool duplicate(int numbers[], int length, int* duplication);
        //parameters:
        //@numbers:2d arrarys,@rows:hang,@columns:lie
        //target:the given numbers
        //retutn value:@true if the targets exist, otherwise not exist
        bool find_2dArrary(int* numbers, int rows, int columns, int target);
    };
}



#endif //ALGORITHM_LEARNING_SOLUTION_H
