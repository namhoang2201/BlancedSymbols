#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<locale.h>
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

bool isOpenTerm(char c){
	int i;
	for(i=0; i<3; i++){
		if(*(Terms[i])== c){
			return true;
		}
	}
	return false;	
}

bool matches(char x, char y){
	int i,j;
	for(i=0; i<3; i++){
		if((*(Terms[i])==x)&&(Terms[i][1])==y){
			return true;
		}
	}
	return false;
}

char *readFile(char *fileName) {
	char *locale = setlocale(LC_ALL, "en_US.utf8");
    FILE *file = fopen(fileName, "r");
    char *code;
    size_t n = 0;
    int c;

    if (file == NULL) return NULL; //could not open file
    fseek(file, 0, SEEK_END);
    long f_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    code = (char*)malloc(f_size);

    while ((c = fgetc(file)) != EOF) {
        code[n++] = (char)c;
    }

    code[n] = '\0';        

    return code;
}

bool isBalanced(char *xau){
//	Init a stack
	Stack* s = stackConstruct();
	int i;
	for(i=0; i< strlen(xau); i++){
		if(isTerm(xau[i])){
			if(isOpenTerm(xau[i])){
				stackPush(s, xau[i]);
			}else{
				if(matches(top(s), xau[i])){
					stackPop(s);
					continue;
				}else{
					return false;
				}
			}
		}
	}
	if(stackEmpty(s)){
		return true;
	}
	return false;
}

int main(){
	
	
	
}
