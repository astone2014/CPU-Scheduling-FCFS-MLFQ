#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

#include "windows.h"
#include "Header.h"

using namespace std;

CpuScheduler::CpuScheduler() {//constructor 
	head = NULL;
	curr = NULL;
	temp = NULL;
}
void CpuScheduler::addProcess(int addData[], char Name) {//add a process
	nodePtr n = new process;
	n->next = NULL;
	for (int i = 0; i < 20; i++) {
		n->queue[i] = addData[i];
	}
	n->Name = Name;
	n->Progress = 0;

	if (head != NULL) {
		curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = n;
	}
	else {
		head = n;
	}
}
void CpuScheduler::deleteProcess(int delData) {
	temp = head;
	temp1 = head;
	while (temp != NULL) {

	}
}

void CpuScheduler::MainRunner() {
	while (finishcount != 9) {
		while (finishcount != 9) {
			FindTail();
			FindTailIo();
			curr = head;
			PrintList();
			PrintIoList();
			PrintFinishedList();
			cout << "\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n\n\n";
			if (curr != NULL) {
				while (curr->queue[0] > 0) {
					--curr->queue[0];
					++clock;
					RunIo();
					CheckIo();
				}
			}
			else {
				while (head == NULL && finishcount != 9) {
					RunIo();
					CheckIo();
					++clock;
					if (finishcount == 8 && headIo->queue[0] == 0) {
						++finishcount;
						finished = finishedhead;
						while (finished->next != NULL) {
							finished = finished->next;
						}
						finished->next = headIo;
						headIo = NULL;
						tailIo = NULL;
					}
				}
			}
			SendToIo();
			//tail->next = curr; // move to the end of IO
			//tail->next->next = NULL; // remove
		}
	}
	if (finishcount == 9) {
		headIo = NULL;
		finished = finishedhead;
		while (finished != NULL) {
			finished->queue[0] = 0;
			finished = finished->next;
		}
		PrintList();
		PrintIoList();
		PrintFinishedList();
		cout << "\n\n -- FINISHED -- \n";
		cout << "Clock Time: " << clock << "\t Wait Time: " << waittime << endl;
	}
}

void CpuScheduler::CheckFinished() {
}
void CpuScheduler::CheckIo() {
	temp = headIo;
	moving = headIo;
	while (temp != NULL) {
		if (temp->queue[0] <= 0) {
			Shifter();
			if (headIo == temp) {
				if (head != NULL) {
					headIo = headIo->next;
					tail->next = temp;
					tail = tail->next;
					tail->next = NULL;
				}
				else {
					head = temp;
				}
			}
			else {
				if (head != NULL) {
					moving->next = temp->next;
					tail->next = temp;
					tail = tail->next;
					tail->next = NULL;
				}
				else if (head == NULL) {
					head = temp;
				}
			}
		}
		moving = temp;
		temp = temp->next;
	}
}

void CpuScheduler::RunIo() {
	temp = headIo;
	while (temp != NULL) {
		--temp->queue[0];
		temp = temp->next;
	}
}

void CpuScheduler::SendToIo() {
	temp = head;
	if (headIo == NULL) {
		headIo = temp;
	}
	else {
		if (temp != NULL) {
			if (temp->queue[0] == 0 && temp->queue[1] == 0) { // check for finished
				if (temp->next == NULL) {
					head = NULL;
				}
				cout << "FINISHED COUNT: " << finishcount;
				if (finishedhead == NULL) {
					finishedhead = temp;
				}
				else {
					finished = finishedhead;
					while (finished->next != NULL) {
						finished = finished->next;
					}
					finished->next = temp;
				}

				++finishcount;
			}
			else {
				tailIo->next = temp; // send a 0 burst to IO tail.
			}
		}
	}
	if (head != NULL) {
		head = head->next;
	}
	if (temp != NULL) {
		temp->next = NULL;
	}
	Shifter();
}

void CpuScheduler::FindTail() {
	temp = head;
	while (temp != NULL) {
		tail = temp;
		temp = temp->next;
	}
}

void CpuScheduler::FindTailIo() {
	temp = headIo;
	while (temp != NULL) {
		tailIo = temp;
		temp = temp->next;
	}
}

void CpuScheduler::Shifter() {
	if (temp != NULL) {
		for (int i = 0; i < 20; i++) {
			temp->queue[i] = temp->queue[i + 1];
		}
	}
}
void CpuScheduler::PrintList() {
	cout << "\n#" << printed << " Current Time: " << clock << endl;
	if (head != NULL) {
		curr = head;
		cout << "\nNow running:\tP" << curr->Name << "  |  Burst: " << curr->queue[0] << "  |  Head: " << head->Name << "  |  Tail: " << tail->Name;
		if (headIo != NULL) { cout << "    ||    IoHead: " << headIo->Name << "  |  IoTail: " << tailIo->Name; } cout << endl;
		temp = head;
		cout << "..................................................................................................\n";
		cout << "Ready Queue\tProcess\t\tBurst\n";
		while (temp != NULL) {
			cout << "\t\tP" << temp->Name << "\t\t[" << temp->queue[0] << "]\n";
			temp = temp->next;
		}
		cout << "...........................................................\n";
		++printed;
	}
	else {
		cout << "\nNow running:\tIO  |  Burst: NONE |  Head: NONE |  Tail: NONE\n";
		cout << "Ready Queue\tProcess\t\tBurst\n" << endl;
		cout << "\t\t[Empty]" << endl;
	}
}

void CpuScheduler::PrintIoList() {
	if (headIo != NULL) {
		temp = headIo;
		cout << "Now in I/O:   Process\t\tRemaining I/O time" << endl;
		while (temp != NULL) {
			cout << "\t\tP" << temp->Name << "\t\t[" << temp->queue[0] << "]\n";
			temp = temp->next;
		}
	}
	else {
		cout << "Now in I/O:\tProcess\tRemaining I/O time" << endl;
		cout << "\t\t[Empty]" << endl;
	}
}

void CpuScheduler::PrintFinishedList() {
	if (finishedhead != NULL) {
		temp = finishedhead;
		cout << "Finished:   Process\t\tRemaining I/O time" << endl;
		while (temp != NULL) {
			cout << "\t\tP" << temp->Name << "\t\t[" << temp->queue[0] << "]\n";
			temp = temp->next;
		}
	}
	else {
	}
}