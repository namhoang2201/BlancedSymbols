// Dinh nghia stack dung danh sach lien ket don
// Voi truong du lieu cua 1 nut la mot chuoi ky tu

// Dinh nghia 1 nut
typedef struct StackNodeHtml{
	char item[10];
	struct StackNodeHtml *next;
} StackNodeHtml;

// Dinh nghia stackHtml
typedef struct StackHtml{
	StackNodeHtml *top;
};

// Khoi tao stackHtml
StackHtml *stackHtmlConstruct(){
	StackHtml *s;
	s = (StackHtml*) malloc (sizeof(StackHtml));
	if(s==NULL){
//	No memory
		return NULL; 
	}
	s->top = NULL;
	return s;
}

// Kiem tra StackHtml rong
bool stackHtmlEmpty(StackHtml *s){
	return (s->top == NULL);
}

// Thong bao StackHtml tran
int stackHtmlFull(){
	printf("\n NO MEMORY! STACK IS FULL ");
	getch();
	return 1;
}

// Them phan tu vao StackHtml
int stackHtmlPush(StackHtml *s, char[] item){
	StackNodeHtml *node;
	node = (StackNodeHtml*) malloc (sizeof(StackNodeHtml));
	if(node == NULL){
		stackHtmlFull(s);
//		Tran stack, het bo nho
		return 1;
	}
	node->item = item;
	node->next = s->top;
	s->top = node;
	return 0;
}

// Loai bo va lay phan tu ra khoi StackHtml
char stackHtmlPop(StackHtml *s){
	char[] item;
	StackNodeHtml *node;
	if(stackHtmlEmpty(s)){
//		Empty stack, can't pop
	return 'a';
	}
	node = s->top;
	item = node->item;
	s->top = node->next;
	free(node);
	return item;
}

//	Tra ve gia tri phan tu o dinh ngan xep nhung khong lay ra
char topHtml(StackHtml *s){
	if(stackHtmlEmpty(s)){
		return 'a';
	}
	return s->top->item;
}

// Huy StackHtml
void stackHtmlDestroy(StackHtml *s){
	while(!stackHtmlEmpty(s)){
		stackHtmlPop(s);
	}
	free(s);
}

void dispHtml(StackHtml *s){
	StackNodeHtml *node;
	int ct = 0;
	char *m;
	printf("\n\n DANH SACH CAC PHAN TU CUA STACK \n\n");
	if(stackHtmlEmpty(s)){
		printf("\n\n EMPTY STACK ");
		getch();
	}else{
		node = s->top;
		do{
			m = node->item;
			printf("%s\t", m);
			ct++;
			if(ct % 9 == 0) printf("\n");
			node = node->next;
		}while(!(node == NULL));
		printf("\n");
	}
}





