/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

#pragma once
#include<iostream>
#include<time.h>
using namespace std;
__declspec( dllexport ) int Partition(int data[], int length, int start, int end);
void Swap(int *a,int  *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int RandomInRange(int start, int end) {
	if (end > start) {
		srand(time(NULL));
		return start + rand() % (end - start);
	}
	return start;
}
int Partition(int data[], int length, int start, int end) {
	if (data == NULL || length < 0 || start<0 || end>length)
		throw new  std::exception("Invalid Parameters");

	int index = RandomInRange(start, end);
	Swap(&data[index], &data[end]);
	int small = start - 1;
	for (index = start; index < end; index++) {
		if (data[index] < data[end]) {
			small++;
			if (small != index)
				Swap(&data[index], &data[small]);
		}
	}
	small++;
	Swap(&data[small], &data[end]);
	return small;
}
