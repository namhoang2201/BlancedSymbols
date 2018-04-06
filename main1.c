#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "stack.h"

char Terms[3][2] = {{'(',')'},{'[',']'},{'{','}'}};

_Bool isTerm(char c){
	int i,j;
	for(i=0; i<3; i++){
		for(j=0; j<2; j++){
				if(Terms[i][j] ==c ){
				return 1;
			}
		}
	}
	return 0;
};

_Bool isOpenTerm(){
	
}

_Bool matches(char x, char y){
	
}

_Bool isBalanced(char xau){
	
}
int main(){
	
	
	
}
