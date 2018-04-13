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
	int n;
	printf("\nCHUONG TRINH KIEM TRA SU CAN BANG BIEU TUONG (DAU NGOAC HOAC CAC THE HTML)");
	do{
		printf("\n---------------------------------------------------------------------");
		printf("\n\nMoi ban chon chuc nang: 1, 2, 3 hoac 4");
		printf("\n\t1. Kiem tra su can bang chuoi dau ngoac don.");
		printf("\n\t2. Kiem tra su can bang dau ngoac trong ma nguon C++.");
		printf("\n\t3. Kiem tra su can bang cua cac the trong ma nguon HTML.");
		printf("\n\t4. Ket thuc !\n");
		scanf("%d", &n);
		switch(n){
			case 1: printf("\n\tKiem tra su can bang chuoi dau ngoac don: ");
					char *fileName = "chuoingoacdon.txt";
					printf("\n\tFile dau ngoac don co ten: %s", fileName);
					printf("\n\tNoi dung cua file la: ");
					printf("\n\t%s", readFile(fileName));
					if(isBalanced(readFile(fileName))){
						printf("\n\tChuoi ngoac don la CAN BANG !");
					}else{
						printf("\n\tChuoi ngoac don la KHONG CAN BANG !");
					}
					break;
			case 2: printf("\n\tKiem tra su can bang dau ngoac trong ma nguon C++: ");
					char *fileName1 = "chuoingoacdon.txt";
					printf("\n\tFile dau ngoac don co ten: %s", fileName1);
					printf("\n\tNoi dung cua file la: ");
					printf("\n\t%s", readFile(fileName1));
					if(isBalanced(readFile(fileName1))){
						printf("\n\tChuoi ngoac don la CAN BANG !");
					}else{
						printf("\n\tChuoi ngoac don la KHONG CAN BANG !");
					}
					break;
			case 3: printf("\n\tKiem tra su can bang cua cac the trong ma nguon HTML: ");
					break;
			case 4: return 1;
		}
	}while(n!=4);
	
}
