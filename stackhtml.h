// Dinh nghia stack dung danh sach lien ket don
// Voi truong du lieu cua 1 nut la mot chuoi ky tu

typedef struct stackNodeHtml{
	char item[10];
	struct stackNodeHtml *next;
};

typedef struct stackHtml{
	stackNodeHtml *top;
};
