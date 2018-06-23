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

// 面试题21：调整数组顺序使奇数位于偶数前面
// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
// 奇数位于数组的前半部分，所有偶数位于数组的后半部分。
//牛客网加强版 调整奇偶顺序但是奇数和奇数，偶数和偶数的相对顺序不变

#include <cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void Reorder(int *pData, unsigned int length, bool(*func)(int));
bool isEven(int n);

// ====================方法一====================
void ReorderOddEven_1(int *pData, unsigned int length)
{
    //if (pData == 0 || length <= 0) return;
    //int first = 0, last = length - 1;
    //while (first < last) {
    //    while (*(pData + first) % 2 == 1 && first < last) first++;
    //    while (*(pData + last) % 2 == 0 && first < last) last--;
    //   // cout << "*(pData + first)=" << *(pData + first) << "      *(pData + last)=" << *(pData + last) << endl;
    //    if (*(pData + first) % 2 == 0 && *(pData + last) % 2 == 1) {
    //        int temp = *(pData + first);
    //        *(pData + first) = *(pData + last);
    //        *(pData + last) = temp;
    //    }
    //}
    if (pData == nullptr || length == 0) return;
    int *pleft = pData;
    int *pright = (pData + length - 1);
    while (pleft<pright)
    {
        while (pleft < pright && *pleft % 2 == 1) pleft++;
        while (pleft < pright && *pright % 2 == 0) pright--;
        if (pleft < pright) {
            int temp = *pleft;
            *pleft = *pright;
            *pright = temp;
        }
    }
    return;
}

// ====================方法二====================
void Reorder(int *pData, unsigned int length,bool (*func)(int))// 函数指针
{ 
	if (pData == NULL || length == 0) return;
	int *pBegin = pData;
	int *pEnd = pData + length - 1;
    //int count = 0;
	while (pBegin < pEnd) {
		while (pBegin < pEnd &&  !func(*pBegin)) { //!!!Bug 1 是!func（*pBegin)而不是isEven
			pBegin++;
            cout << "寻找偶数" << *pBegin << endl;
		}
		while (pBegin < pEnd && func(*pEnd)) {
			pEnd--;
            cout << "寻找奇数" << *pEnd << endl;
		}
        // cout << "pBegin=" << *pBegin << "   pEnd=" << *pEnd << endl;
        
          
		if (pBegin < pEnd) {
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;

          /*  cout << "交换完的数组为：";
            for (int i = 0; i < length; i++) {
                cout << *pData + i << "  ";
            }
            cout << endl;*/
		}
	}
    return;
}

bool isEven(int n) {
    //cout << "call the isEven function in number:" << n << endl;
    return (n % 2 == 0);
    // return (n & 1 == 0);  //!!!Bug 2 不能用n&1=0
}
void ReorderOddEven_2(int *pData, unsigned int length)
{
	Reorder(pData, length, isEven);
}
//
////======================方法三=====================
////想法，只能顺序调整，从左到右，遇到第一个偶数从它的右边开始寻找直到找到第一个奇数，然后将奇数和偶数调换位置
////再从刚才的偶数右边开始寻找第二个偶数，进行同样的操作，直到完成所有偶数的寻找

//void Reorder3(int *pData, unsigned int length, bool(*func)(int))// 函数指针
//{
//    if (pData == NULL || length == 0) return;
//    int *pBegin = pData;
//    int *pEnd = pData + length - 1;
//
//    while (pBegin < pEnd) {
//        while (pBegin < pEnd && !func(*pBegin)) {
//            pBegin++;
//        }
//        int *pSecond = pBegin + 1;
//
//        while (pSecond< pEnd && func(*pSecond)) {
//            pSecond++;
//        }
//        if (pBegin < pEnd) {
//            int temp = *pBegin;
//            *pBegin = *pSecond;
//            *pSecond = temp;
//        }
//        pBegin++;
//    }
//}
//
//bool isEven3(int n) {
//    return (n & 0x1 == 0);
//}
//void ReorderOddEven_3(int *pData, unsigned int length)
//{
//    Reorder3(pData, length, isEven3);
//}

// ====================测试代码====================
void PrintArray(int numbers[], int length)
{
	if (length < 0)
		return;

	for (int i = 0; i < length; ++i)
		printf("%d\t", numbers[i]);

	printf("\n");
}

void Test(char* testName, int numbers[], int length)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	int* copy = new int[length];
	for (int i = 0; i < length; ++i)
	{
		copy[i] = numbers[i];
	}
    int *copy2 = new int[length];
    for (int i = 0; i < length; i++) {
        copy2[i] = numbers[i];
    }
	printf("Test for solution 1:\n");
	PrintArray(numbers, length);
	ReorderOddEven_1(numbers, length);
	PrintArray(numbers, length);

	printf("Test for solution 2:\n");
	PrintArray(copy, length);
	ReorderOddEven_2(copy, length);
	PrintArray(copy, length);

    //printf("Test for solution 3:\n");
    //cout << "Original:" << endl;
    //PrintArray(copy, length);
    //ReorderOddEven_3(copy, length);
    //cout << "Sorted:" << endl;
    //PrintArray(copy, length);

	delete[] copy;
}

void Test1()
{
	int numbers[] = { 1, 2, 3, 4, 5, 6, 7 };
	Test("Test1", numbers, sizeof(numbers) / sizeof(int));
}

void Test2()
{
	int numbers[] = { 2, 4, 6, 1, 3, 5, 7 };
	Test("Test2", numbers, sizeof(numbers) / sizeof(int));
}

void Test3()
{
	int numbers[] = { 1, 3, 5, 7, 2, 4, 6 };
	Test("Test3", numbers, sizeof(numbers) / sizeof(int));
}

void Test4()
{
	int numbers[] = { 1 };
	Test("Test4", numbers, sizeof(numbers) / sizeof(int));
}

void Test5()
{
	int numbers[] = { 2 };
	Test("Test5", numbers, sizeof(numbers) / sizeof(int));
}

void Test6()
{
	Test("Test6", nullptr, 0);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
    //int num[10] = { 4,5,6,1,2,3,7,8,9,0 };
    //vector<int> v1 (&num[0], &num[7]);
    //cout << v1.front() << endl; 
    return 0;;

}

//#include<iostream>
//using namespace std;
//void main() {
//	unsigned int a = 4;
//	if (int(a & 0x1) == 1) cout << "Odd";
//	if (int(a & 0x1) == 0) cout << "Even";
//}
