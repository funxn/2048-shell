#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void randomGen(int (*a)[4]){
	int i=0;
	int flag=0;
	int m=0, n=0;
	int rand_num;

	srand(time(NULL));
	rand_num = rand()%16 + 1;

	/* 验证是不是满了, 如果是则直接返回 */
	for(m=0; m<4; m++)
	      for(n=0; n<4; n++)
		    if(a[m][n]==0)
			  flag=1;
	if(flag == 0)
	      return; 

	/* 否则, 产生一随机数 */
	while(i < rand_num){
		m++;
		for(n=0; n<4; n++){
			if(a[m%4][n] == 0){
				i++;

				if(i >= rand_num){
					a[m%4][n] = 2;
					break;
				}
			}
		}
	}
}
