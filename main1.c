#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<locale.h>
#include<stdlib.h>
#include "stack.h"

char Terms[3][2] = {{'(',')'},{'[',']'},{'{','}'}};
char **HtmlTags = {{'<html>','</html>'}, {'<head>','</head>'}, {'<body>','</body>'}, {'<title>','</title>'},
		{'<h1>','</h1>'}, {'<h2>','</h2>'}, {'<h3>','</h3>'}, {'<h4>','</h4>'}, {'<h5>','</h5>'}, {'<h6>','</h6>'},
		{'<ul>','</ul>'}, {'<ol>','</ol>'}, {'<li>','</li>'}, {'<dl>','</dl>'}, {'<dt>','</dt>'}, {'<table>','</table>'},
		{'<td>','</td>'}, {'<tr>','</tr>'},{'<th>','</th>'}, {'<form>','</form>'}, {'<strong>','</strong>'},
		{'<div>','</div>'}, {'<textarea>','</textarea>'}, {'<span>','</span>'}, {'<pre>','</pre>'}, {'<em>','</em>'},
		{'<frameset>','</frameset>'}, {'<dd>','</dd>'}, {'<script>','</script>'}, {'<b>','</b>'}, {'<i>','</i>'},
		{'<fieldset>','</fieldset>'}, {'<font>','</font>'}, {'<sub>','</sub>'}, {'<sup>','</sup>'} };

// Kiem tra mot ki tu co phai la khoang trang khong
int IsWhitespace(int ch) {
	return (ch == ' ') || (ch == '\n') || (ch == '\t');
}

// Doc tung tu mot, dau vao la con tro code toi mang cac ki tu
char *readWord(char *code, int* i, char *word){
	int ch, pos = 0;
	ch = code[*i];
// Bo qua cac ki tu la khoang trang	
	while(IsWhitespace(ch)){
		(*i)++;
		ch = code[*i];
	}
	
// Gap cac ki tu khac khoang trang thi luu vao mot tu, con tro word la dia chi cua mang chua tu
	while(!IsWhitespace(ch) && (ch != EOF)){
		if(pos < 20){
			word[pos] = (char) ch;
			pos++;
			(*i)++;
		}
		ch = code[*i];
	}
	word[pos]= '\0';
	return word;
}

// Kiem tra xem ky tu c dua vao co phai la dau ngoac hay khong ?
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
}

// Kiem tra xem ky tu c dua vao co phai la ky tu mo ngoac hay khong ?
bool isOpenTerm(char c){
	int i;
	for(i=0; i<3; i++){
		if(*(Terms[i])== c){
			return true;
		}
	}
	return false;	
}

// Kiem tra xem 2 ki tu dua vao co phai la mot cap tuong ung cua nhau trong mang Terms duoc dinh nghia o tren hay khong ?
bool matches(char x, char y){
	int i,j;
	for(i=0; i<3; i++){
		if((*(Terms[i])==x)&&(Terms[i][1])==y){
			return true;
		}
	}
	return false;
}

// Doc tung ki tu cua 1 file tu dau den cuoi roi sao chep vao mot mang ten la code, tra ve dia chi cua mang code
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

// Kiem tra xem xau dua vao co can bang ngoac hay khong ?
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
					char *fileName1 = "cplusplus.cpp";
					printf("\n\tFile C++ co ten: %s", fileName1);
					printf("\n\tNoi dung cua file la: ");
					printf("\n%s", readFile(fileName1));
					if(isBalanced(readFile(fileName1))){
						printf("\n\tFile C++ CAN BANG ngoac don !");
					}else{
						printf("\n\tFile C++ KHONG CAN BANG ngoac don !");
					}
					break;
			case 3: printf("\n\tKiem tra su can bang cua cac the trong ma nguon HTML: ");
					
			
					break;
			case 4: return 1;
		}
	}while(n!=4);
	
}
