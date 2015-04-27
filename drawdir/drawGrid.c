/*
 * draw the table ***with*** number inside!
 * @xiaofeng
 *
 */
#include<stdio.h>
#include "global.h"

void drawGrid(int a[][4]){
	int i, j;
	int locX = 5, locY = 3;
	int m=0, n=0;

	for(i=1; i<=17; i++){
		if((i-1)%4 == 0){
			for(j=1; j<=33; j++) putchar('*');
		}else{
			if(locY == i){
				m = (i-3)/4;		// Note: i-3
				n = 0;
				locX = 5;		// Note: locX == 5
				for(j=1; j<=33; j++){
					if((j-1)%8 == 0)
					      putchar('|');
					else if(locX == j){
					      printf("%d", a[m][n++]);
					      locX += 8;
					}else
					      putchar(' ');
				}

				locY += 4;
			}else{
				
				for(j=1; j<=33; j++){
					if((j-1)%8 == 0)
					      putchar('|');
					else
					      putchar(' ');
				}
			}
		}
		putchar('\n');
	}
	
}
