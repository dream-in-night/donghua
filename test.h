#include <iostream>
#include<vector>
#include <math.h>
#include<stdio.h>
using namespace std;
int n, p, k;
vector<int> num,numtemp;
void Calc(int i, int sum, int level,vector<int> temp) {           //参数 i sum	level temp
	sum += pow(i, k);						//       sum = i 的 k 次幂
	temp.push_back(i);						//		把i压入temp数组
	if (p - temp.size() > n - sum)			//	如果 p-temp.size > n - sum ，则返回
		return;									
	if (sum > n)							//  如果 sum > n	则返回
		return;
	if (level == 0) {						//  若  level = 0 
		if (sum == n) {						//		若 sum = n ==================================================================================================================================
			int flag = false;				//		|	初始定义flag为假                                                         																|
			if (num.size() == 0)			//		|		如果num是空数组                                                         															|
				flag = true;				//		|			flag为真                                                         																|
			else {							//		|		如果num不是空数组------------------------------                          															|
				for (int j = p-1; j >=0; j--) {//	|		|	对比num[j]和temp[j]                        |                                 													|
					if (num[j] > temp[j]) {		//	|		|		如果num[j]大，那么flag为假，break      |                               														|
						flag = false;			//  |       |                                              |						                      										|			
						break;					//	|		|											   |																					|	
					}							//	|		|											   |																					|
					else if (num[j] < temp[j]) {//	|		|-------如果temp[j]大，那么flag为真，break-----|																					|
						flag = true;			//	|																																			|
						break;					//	|																																			|
					}							//	|																																			|
				}								//	|																																			|
			}									//	|																																			|
			if (flag == true) {				    //  如果 flag为真，即num是空数组，或者num不是空数组但num[j] < temp[j] ，清除num , 将 temp[j]压入num数组，返回====================================
				num.clear();				//
				for (int j = 0; j < p; j++)	//
					num.push_back(temp[j]);	//
			}								//
		}									//
		return;								// 返回
	}																										
	else {									// 否则，即level 不为0,递归调用calc
		for (int j = 1; j <= i; j++) {
			
			Calc(j, sum, level - 1, temp);
		}
	}
}
int main(void) {
	cin >> n >> p >> k;
	int breakpoint = pow(n, 1.0 / k);
	/*if (p > breakpoint) {
		if (n == p) {
			cout << n << " =";
			for (int i = 0; i < p; i++) {
				cout << " " << "1" << "^" << k;
				if (i != p - 1)
					cout << " +";
			}		
		}
		else {
			cout << "Impossible";
		}
		return 0;
	}*/
	int cnt = 0;
	for (int i = 1; i <= breakpoint; i++) {
		if (cnt == 2)
			break;
		if (!num.empty())
			cnt++;// 
		numtemp.clear();
		Calc(i, 0, p-1, numtemp);
	}
	if (num.size() == 0) {	
		cout << "Impossible";
	}
	else {
		cout << n << " =";
		for (int i = 0; i < num.size(); i++) {
		//	cout << " " << num[i] << "^" << k;
			printf(" %d^%d", num[i], k);
			if (i != num.size() - 1)
				printf(" +");
				//cout << " +";
		}
	}

	return 0;
}

