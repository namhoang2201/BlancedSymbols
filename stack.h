// Dinh nghia stack dung danh sach lien ket don
// Dinh nghia 1 nut
typedef struct StackNode{
	char item;
	struct StackNode *next;
}StackNode;

// Dinh nghia Stack
typedef struct Stack{
	StackNode *top;
}Stack;

// Khoi tao stack
Stack *stackConstruct(){
	Stack *s;
	s = (Stack*) malloc (sizeof(Stack));
	if(s==NULL){
//		No memory
		return NULL; 
	}
	s->top = NULL;
	return s;
}

// Kiem tra stack rong
bool stackEmpty(Stack *s){
	return (s->top == NULL);
}

// Thong bao stack tran
int stackFull(Stack *s){
	printf("\n NO MEMORY! STACK IS FULL ");
	getch();
	return 1;
}

// Dua ra cac phan tu cua ngan xep
void disp(Stack *s){
	StackNode *node;
	int ct = 0;
	char m;
	printf("\n\n DANH SACH CAC PHAN TU CUA STACK \n\n");
	if(stackEmpty(s)){
		printf("\n\n EMPTY STACK ");
		getch();
	}else{
		node = s->top;
		do{
			m = node->item;
			printf("%c", m);
			ct++;
			if(ct % 9 == 0) printf("\n");
			node = node->next;
		}while(!(node == NULL));
		printf("\n");
	}
}

// Them phan tu vao stack
int stackPush(Stack *s, char item){
	StackNode *node;
	node = (StackNode*) malloc (sizeof(StackNode));
	if(node == NULL){
		stackFull(s);
//		Tran stack, het bo nho
		return 1;
	}
	node->item = item;
	node->next = s->top;
	s->top = node;
	return 0;
}

// Loai bo va lay phan tu ra khoi stack
char stackPop(Stack *s){
	char item;
	StackNode *node;
	if(stackEmpty(s)){
//		Empty stack, can't pop
	return 'a';
	}
	node = s->top;
	item = node->item;
	s->top = node->next;
	free(node);
	return item;
}

//		Tra ve gia tri phan tu o dinh ngan xep nhung khong lay ra
char top(Stack *s){
	if(stackEmpty(s)){
		return 'a';
	}
	return s->top->item;
}

// Huy stack
void stackDestroy(Stack *s){
	while(!stackEmpty(s)){
		stackPop(s);
	}
	free(s);
}
