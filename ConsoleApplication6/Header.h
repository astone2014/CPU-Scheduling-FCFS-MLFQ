class CpuScheduler {
public:
	CpuScheduler();
	void addProcess(int addData[], char Name);
	void deleteProcess(int delData);
	void swapProcess(int delData);
	void MainRunner();
	void RunProcess();
	void RunIo();
	void FindTail();
	void FindTailIo();
	void CheckFinished();
	void Shifter();
	void CheckIo();
	void SendToIo();
	void Remover();
	void SendToRun();
	void PrintList();
	void PrintIoList();
	void PrintFinishedList();

	/*STATES
	waiting
	running
	blocked*/

private:
	typedef struct process {
		int Progress;
		int Burst;
		int Io;
		int queue[20];
		char Name;
		process *next;
	}*nodePtr;

	nodePtr head;
	nodePtr tail;
	nodePtr moving;
	nodePtr tailIo;
	nodePtr curr;
	nodePtr temp;
	nodePtr temp1;
	nodePtr temp2;
	nodePtr headIo;
	nodePtr currIo;
	nodePtr tempIo;
	nodePtr finished;
	nodePtr finishedhead;
	nodePtr finishedrunner;
	nodePtr remove;
	nodePtr check;

	int clock = 0;
	int printed = 1;
	int waittime = 0;
	int numinIo = 0;
	int finishcount = 0;
};