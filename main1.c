#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdbool.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"
#include "stackHtml.h"

char Terms[3][2] = {{'(',')'},{'[',']'},{'{','}'}};

char *htmlTags1[35] = { "<html>", "<head>", "<body>", "<title>", "<h1>", "<h2>", "<h3>", "<h4>", "<h5>", "<h6>", "<ul>", "<ol>", "<li>", 
						"<dl>", "<dt>", "<table>", "<td>", "<tr>", "<th>", "<form>", "<strong>", "<div>", "<textarea>", "<span>", "<pre>",
						"<em>", "<frameset>", "<dd>", "<script>", "<b>", "<i>", "<fieldset>", "<font>", "<sub>", "<sup>" };
char *htmlTags2[35] = { "</html>", "</head>", "</body>", "</title>", "</h1>", "</h2>", "</h3>", "</h4>", "</h5>", "</h6>", "</ul>", "</ol>", "</li>", 
						"</dl>", "</dt>", "</table>", "</td>", "</tr>", "</th>", "</form>", "</strong>", "</div>", "</textarea>", "</span>", "</pre>",
						"</em>", "</frameset>", "</dd>", "</script>", "</b>", "</i>", "</fieldset>", "</font>", "</sub>", "</sup>" };

// Kiem tra mot ki tu co phai la khoang trang khong
int isWhitespace(int ch) {
	return (ch == ' ') || (ch == '\n') || (ch == '\t');
}

// Doc tung tu mot, dau vao la con tro code toi mang cac ki tu, tra ve dia chi cua tu luu vao con tro word
char *readWord(char *code, char *word){
	int ch, pos = 0;
	ch = *code;
	// Bo qua cac ki tu la khoang trang	
	while(isWhitespace(ch)){
		code++;
		ch = *code;
	}
	
	// Gap cac ki tu khac khoang trang thi luu vao mot tu, con tro word la dia chi cua mang chua tu
	while(!isWhitespace(ch) && (ch != EOF)){
		if(pos < 20){
			word[pos] = (char) ch;
			pos++;
			code++;
		}
		ch = *code;
	}
	word[pos]= '\0';
	return word;
}

//Kiem tra xem tu dua vao co phai la the HTML hay khong ?
bool isHtmlTag(char *word){
	int i;
	for(i = 0; i< 35; i++){
		if((strcmp(word , htmlTags1[i]) == 0) || (strcmp(word , htmlTags2[i]) == 0)){
				return true;
		}
	}
	return false;
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

// Kiem tra xem tu dua vao co phai la the mo HTML hay khong ?
bool isOpenHtmlTag(char *word){
	int i;
	for(i=0; i<35; i++){
		if(strcmp(word, htmlTags1[i]) == 0){
			return true;
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

// Kiem tra xem 2 tu dua vao co phai la mot cap the HTML tuong ung cua nhau hay khong (bao gom the mo va the dong tuong ung)
bool htmlMatches(char *word1, char *word2){
	int i;
	for(i = 0; i< 35; i++){
		if((strcmp(word1, htmlTags1[i]) == 0) && (strcmp(word2, htmlTags2[i]) == 0)){
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

// Kiem tra xem file HTML dua vao co can bang cac the HTML hay khong ?
bool isHtmlBalanced(char *fileName){
	// Khoi tao 1 StackHtml
	StackHtml* s = stackHtmlConstruct();
	// Doc file html va luu tat ca noi dung vao 1 mang ky tu, tro boi con tro code
	char* code = readFile(fileName);
	// Duyet cac tu trong mang tu trich ra tu van ban txt, tu dau den cuoi, lay ra tung tu mot
	// Doc tung tu mot
	while(*code != '\0'){
		// Cap phat bo nho de luu moi tu
		char *word = (char*) malloc (20*sizeof(char));
		// Luu tu vao word
		word = readWord( code, word);
		// Kiem tra xem tu dua vao co phai la the HTML khong ?, neu dung thi day vao StackHtml
		if(isHtmlTag(word)){
			if(isOpenHtmlTag(word)){
				stackHtmlPush(s, word);
				dispHtml(s);
				printf("\n");
			}else{
				// Nguoc lai, tu dua vao la the dong => lay ra ptu o dinh stack va kiem tra xem
				// no va phan tu dang xet co phai la 1 cap cua nhau hay khong ?
				if(htmlMatches(topHtml(s), word)){
					// Neu dung la 1 cap tuong ung, loai bo ptu o dinh stack va tiep tuc vong lap
					stackHtmlPop(s);
				}else{
					// Nguoc lai, neu phat hien khong phai la 1 cap tuong ung cua nhau thi tra ve false luon !
					return false;
				}
			}
		}
		
		code = code + strlen(word) + 1;
		free(word);
	}
	
	// Sau cung, kiem tra StackHtml co rong hay khong ? Neu rong thi tra ve true, tuc la cang bang the HTML
	if(stackHtmlEmpty(s)){
		return true;
	}
	
	return false;
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
				disp(s);
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
					printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
					printf("\n\t%s", readFile(fileName));
					printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
					if(isBalanced(readFile(fileName))){
						printf("\n\tChuoi ngoac don la CAN BANG !");
					}else{
						printf("\n\tChuoi ngoac don la KHONG CAN BANG !");
					}
					break;
			case 2: printf("\n\tKiem tra su can bang dau ngoac trong ma nguon C++: ");
					char *fileName1 = "cplusplus";
					printf("\n\tFile C++ co ten: %s", fileName1);
					printf("\n\tNoi dung cua file la: ");
					printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
					printf("\n%s", readFile(fileName1));
					printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
					if(isBalanced(readFile(fileName1))){
						printf("\n\tFile C++ CAN BANG ngoac don !");
					}else{
						printf("\n\tFile C++ KHONG CAN BANG ngoac don !");
					}
					break;
			case 3: printf("\n\tKiem tra su can bang cua cac the trong ma nguon HTML: ");
					char *fileName2 = "namhoang.html";
					printf("\n\tFile HTML co ten: %s", fileName2);
					printf("\n\tNoi dung cua file la: ");
					printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
					printf("\n%s", readFile(fileName2));
					printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
					bool canbang =	isHtmlBalanced(fileName2);
					if(canbang == true){
						printf("File %s CAN BANG the HTML", fileName2);
					}else{
						printf("File %s KHONG CAN BANG the HTML", fileName2);
					}
			
					break;
			case 4: return 1;
		}
	}while(n!=4);
	
}
