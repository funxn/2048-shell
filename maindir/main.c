#include<stdio.h>
#include"global.h"
#include"proto.h"


int main(){
	int i, j;
	int temp =1;
	int a[4][4]={2,2,2,2,4,4,2,2,8,8,8,4,0,2,2,0};
	drawGrid(a);
	changeState(a);
	return 0;
}
