#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "stack.h"

char Terms[3][2] = {{'(',')'},{'[',']'},{'{','}'}};

bool isTerm(char c){
	int i,j;
	for(i=0; i<3; i++){
		for(j=0; j<2; j++){
				if(Terms[i][j] ==c ){
				return true;
			}
		}
	}
	return false;
};

bool isOpenTerm(){
	int i;
	for(i=0; i<3; i++){
		if(*(Terms[i])== c){
			return true;
		}
	}
	return false;	
}

bool matches(char x, char y){
	
}

bool isBalanced(char xau){
	
}
int main(){
	
	
	
}
