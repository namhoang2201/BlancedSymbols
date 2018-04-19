// Dinh nghia stack dung danh sach lien ket don
// Voi truong du lieu cua 1 nut la mot chuoi ky tu

// Dinh nghia 1 nut
typedef struct StackNodeHtml{
	char item[10];
	struct StackNodeHtml *next;
};

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





