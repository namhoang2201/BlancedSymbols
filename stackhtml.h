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


