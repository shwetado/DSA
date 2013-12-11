typedef char String[256];

typedef struct {
	String pName;
	int priority;
	int pTime;
} Process;

Process* createProcess(String pName,int pTime,int priority);