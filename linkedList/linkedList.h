typedef struct Node{
	void* data;
	struct Node* prev;
	struct Node* next;
} Node;

typedef struct {
	struct Node* head;
	int length;
} List;

typedef char String[256];

List* create();
Node* createNode(Node *prev, Node *next);
int insert(List* list,int index, void* data);
int deleteNode(List* list,int index);