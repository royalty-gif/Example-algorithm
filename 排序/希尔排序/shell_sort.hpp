/*
 *  基本思想：
 *  1. 把记录按下标的一定增量分组，对每组使用直接插入排序算法排序；
 *  2. 随着增量逐渐减少，每组包含的关键词越来越多，当增量减至 1 时，整个文件恰被分成一组，算法便终止
 *  3. 该方法实质上是一种分组插入方法
 *  @note：希尔排序(Shell's Sort)是插入排序的一种又称“缩小增量排序”（Diminishing Increment Sort），是直接插入排序算法的一种更高效的改进版本
 *  @note：希尔排序是非稳定排序算法
 */

#include <iostream>

#pragma once

class Sort {
public:
    template<typename T>
    static void shellSort(T array[], int len, bool min2Max = true) {
        int d = len;

        do {
            d = d / 3 + 1;

            for(int i = d; i < len; i += d) {
                int k = i;
                T e = array[i];

                for(int j = i-1; (j >= 0) && (min2Max ? (array[j] > e) : (array[j] < e)); j--) {
                    array[j+1] = array[j];
                    k = j;
                }

                if(k != i) {
                    array[k] = e;
                }
            }
        } while(d > 1);
    }
private:
    Sort() = default;
    Sort(const Sort&) = default;
    Sort& operator = (const Sort&) = default;
};

