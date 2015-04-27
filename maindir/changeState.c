#include<stdio.h>
#include<stdlib.h>
#include"global.h"
#include"proto.h"

void up_state(int (*str)[4]);
void down_state(int (*str)[4]);
void left_state(int (*str)[4]);
void right_state(int (*str)[4]);

int changeState(int (*a)[4]){
	int key='s';
	fflush(stdin);
	while((key=getchar())!=EOF && key != QUIT){
		switch(key){
			case KEY_UP: up_state(a);
				     break;
			case KEY_DOWN: down_state(a);
				     break;
			case KEY_LEFT: left_state(a);
				     break;
			case KEY_RIGHT: right_state(a);
				     break;
			default:
				     break;
		}
		fflush(stdin);
		if(key != '\n'){
			randomGen(a);			// 产生随机的'2'
			drawGrid(a);			// 重新绘制表格
		}
	}


	return 1;
}

// 注意: 这里普遍使用直接数作为"参数" , 将使得程序的易扩展性不好哦
void right_state(int (*a)[4]){
	int i=0, j=3;
	int k;					// 不能用冒泡
	putchar('\n');
	for(i=0; i<4; i++){
		for(j=3; j>=1; j--){
			for(k=j-1; k>=0; k--)
				if(a[i][j] == a[i][k]){
					a[i][j] += a[i][k];
					a[i][k] = 0;
					break;	// break不可少
				}
			
		}
	}
	for(i=0; i<4; i++){
		for(j=3; j>=1; j--){		// 注意: 这里是j=2
			if(a[i][j] == 0){
				for(k=j-1; k>=0; k--)
					if(a[i][k] != 0){
						a[i][j] = a[i][k];
						a[i][k] = 0;
						break;	// break不可少
					}
				//j = k;	// ERR: 这里要把j=k括进来
			}
		}
	}
	putchar('\n');
}

void left_state(int (*a)[4]){
	int i=0, j=0;
	int k;					// 不能用冒泡
	for(i=0; i<4; i++){
		for(j=0; j<=2; j++){
			for(k=j+1; k<4; k++){
				if(a[i][j] == a[i][k]){
					a[i][j] += a[i][k];
					a[i][k] = 0;
					break;
				}
			}
		}
	}
	for(i=0; i<4; i++){
		for(j=0; j<=2; j++){		// 注意: 这里是j=2
			if(a[i][j] == 0){
				for(k=j+1; k<4 ; k++)
					if(a[i][k] != 0){
						a[i][j] = a[i][k];
						a[i][k] = 0;
						break;
					}
				//j = k;
			}
		}
	}
}
void down_state(int (*a)[4]){
	int i=0, j=3;
	int k;					// 不能用冒泡
	for(i=0; i<4; i++){
		for(j=3; j>=1; j--){
			for(k=j-1; k>=0; k--){
				if(a[j][i] == a[k][i]){
					a[j][i] += a[k][i];
					a[k][i] = 0;
					break;
				}
			}
		}
	}
	for(i=0; i<4; i++){
		for(j=3; j>=1; j--){		// 注意: 这里是j=2
			if(a[j][i] == 0)
				for(k=j-1; k>=0; k--)
					if(a[k][i] != 0){
						a[j][i] = a[k][i];
						a[k][i] = 0;
						break;
					}
		}
	}
}
void up_state(int (*a)[4]){
	int i=0, j=0;
	int k;					// 不能用冒泡
	for(i=0; i<4; i++){
		for(j=0; j<3; j++){
			for(k=j+1; k<4; k++){
				if(a[j][i] == a[k][i]){
					a[j][i] += a[k][i];
					a[k][i] = 0;
					break;
				}
			}
		}
	}
	for(i=0; i<4; i++){
		for(j=0; j<3; j++){		// 注意: 这里是j=2
			if(a[j][i] == 0)
				for(k=j+1; k<4 ; k++)
					if(a[k][i] != 0){
						a[j][i] = a[k][i];
						a[k][i] = 0;
						break;
					}
		}
	}
}
