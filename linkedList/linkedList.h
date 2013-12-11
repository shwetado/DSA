typedef struct Node{
	void* data;
	struct Node* prev;
	struct Node* next;
} Node;

typedef struct {
	struct Node* head;
	struct Node* end;
	int length;
} List;

typedef char String[256];

List* create();
int insert(List* list,int index, void* data);