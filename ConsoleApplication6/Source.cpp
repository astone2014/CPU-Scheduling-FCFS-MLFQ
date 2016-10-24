//FCFS Austen Stone
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "Header.h";
using namespace std;

int processes[9][20] = { { 12, 44, 10, 52, 15, 21, 11, 42, 9, 31, 10, 77, 11 },
{ 18, 32, 17, 42, 16, 27, 7, 41, 17, 33, 11, 43, 12, 32, 14 },
{ 21, 24, 15, 27, 5, 28, 9, 26, 11, 49, 14, 55, 8 },
{ 5, 35, 4, 41, 6, 45, 8, 51, 4, 61, 3, 54, 6, 61, 5 },
{ 4, 41, 6, 26, 5, 38, 4, 33, 5, 37, 14, 28, 7, 18, 12, 33, 15 },
{ 7, 33, 5, 31, 6, 32, 5, 41, 4, 42, 7, 39, 6, 33, 5 },
{ 22, 38, 7, 41, 5, 29, 24, 26, 4, 32, 3, 22, 6, 26, 6, 36, 5 },
{ 25, 21, 20, 33, 16, 41, 7, 21, 14, 23, 15, 31, 4, 32, 3, 32, 5, 41, 4 },
{ 3, 37, 14, 41, 8, 30, 4, 19, 7, 33, 5, 18, 4, 26, 5, 31, 16 } };

int p1[30] = { 12, 44, 10, 52, 15, 21, 11, 42, 9, 31, 10, 77, 11 };
int p2[30] = { 18, 32, 17, 42, 16, 27, 7, 41, 17, 33, 11, 43, 12, 32, 14 };
int p3[30] = { 21, 24, 15, 27, 5, 28, 9, 26, 11, 49, 14, 55, 8 };
int p4[30] = { 5, 35, 4, 41, 6, 45, 8, 51, 4, 61, 3, 54, 6, 61, 5 };
int p5[30] = { 4, 41, 6, 26, 5, 38, 4, 33, 5, 37, 14, 28, 7, 18, 12, 33, 15 };
int p6[30] = { 7, 33, 5, 31, 6, 32, 5, 41, 4, 42, 7, 39, 6, 33, 5 };
int p7[30] = { 22, 38, 7, 41, 5, 29, 24, 26, 4, 32, 3, 22, 6, 26, 6, 36, 5 };
int p8[30] = { 25, 21, 20, 33, 16, 41, 7, 21, 14, 23, 15, 31, 4, 32, 3, 32, 5, 41, 4 };
int p9[30] = { 3, 37, 14, 41, 8, 30, 4, 19, 7, 33, 5, 18, 4, 26, 5, 31, 16 };
void loopit();

int main(int argc, char** argv) {
	CpuScheduler runit;
	loopit();
	return 0;
}

void loopit() {
	CpuScheduler runit;

	runit.addProcess(p1, 'p1');
	runit.addProcess(p2, 'p2');
	runit.addProcess(p3, 'p3');
	runit.addProcess(p4, 'p4');
	runit.addProcess(p5, 'p5');
	runit.addProcess(p6, 'p6');
	runit.addProcess(p7, 'p7');
	runit.addProcess(p8, 'p8');
	runit.addProcess(p9, 'p9');
	runit.MainRunner();
}

/*CPU SCHEDULING CALCULATIONS
cpu utalization
turnaround time
waiting time
response time*/

