#include <iostream>
#include "Process.h"
#include "PublicProcess.h"
#include "PrivateProcess.h"
#include "ProcessQueue.h"
using namespace std;

void main() {
	Process* pup1 = new PublicProcess(123, "name1");
	Process* pup2 = new PublicProcess(987, "name2");
	Process* pup3 = new	PublicProcess(654, "name3");
	Process* pup4 = new PublicProcess(687841, "John Lennon");
	Process* pup5 = new PublicProcess(57489, "Tom Hegen");

	Process* prp1 = new PrivateProcess(1234, "code1");
	Process* prp2 = new PrivateProcess(9876, "code2");
	Process* prp3 = new PrivateProcess(19168, "code3");
	Process* prp4 = new PrivateProcess(11111, "Vito Corleone");

	ProcessQueue* pq1 = new ProcessQueue(10);
	ProcessQueue* pq2 = new ProcessQueue(10);

	cout << "Public processes: \n";
	pup1->Start("name1");
	pup2->Start("Tom Hegen");
	pup1->ReadProcess();
	pup2->ReadProcess();
	cout << endl;
	pup1->Stop();
	pup1->ReadProcess();
	pup2->ReadProcess();
	pup1->Start("Michael Corleone");
	cout << endl;
	pup1->ReadProcess();
	pup2->ReadProcess();

	cout << "\nPrivate processes: \n";
	prp1->Start("code1");
	prp2->Start("code2");
	prp1->ReadProcess();
	prp2->ReadProcess();
	prp1->Stop();
	prp2->Stop();
	prp1->ReadProcess();
	prp2->ReadProcess();
	prp3->Start("code4");
	prp3->Stop();
	prp1->ReadProcess();
	prp2->ReadProcess();
	cout << endl;
	pq1->AddProcess(pup1, 1);
	pq1->AddProcess(prp1, 1);
	pq1->AddProcess(pup5, 1);
	pq1->AddProcess(pup2, 0);
	pq1->AddProcess(prp3, 0);
	pq1->AddProcess(pup4, 0);

	pq2->AddProcess(pup1, 1);
	pq2->AddProcess(prp2, 0);
	pq2->AddProcess(prp3, 1);
	pq2->AddProcess(prp4, 0);
	pq2->AddProcess(prp1, 0);
	pq2->AddProcess(pup2, 0);
	pq2->AddProcess(pup5, 1);
	pq2->AddProcess(pup3, 0);
	cout << endl;
	cout << "\nProcess queue 1\n";
	pq1->PrintProcessQueue();
	cout << "\nProcess queue 2\n";
	pq2->PrintProcessQueue();
	cout << endl; 
	pq1->ActivateProcesses();
	cout << "\nProcess queue 1\n";
	pq1->PrintProcessQueue();
	cout << "\nProcess queue 2\n";
	pq2->PrintProcessQueue();

	pq1->RemoveState2();
	cout << endl; 
	cout << "\nProcess queue 1\n";
	pq1->PrintProcessQueue();
	cout << "\nProcess queue 2\n";
	pq2->PrintProcessQueue();
	cout << endl; 

	ProcessQueue pq3 = *pq1 + *pq2;
	cout << endl << "Process Queue 3: " << endl;
	pq3.PrintProcessQueue();

	delete pup1;
	delete pup2;
	delete pup3;
	delete pup4;
	delete pup5;

	delete prp1;
	delete prp2;
	delete prp3;
	delete prp4;

	delete pq1;
	delete pq2;
}