#include "ProcessQueue.h"
#include "Process.h"
#include <iostream>

ProcessQueue::ProcessQueue(int maxElements) : _maxElements(maxElements), _activeProcesses(new Process*[maxElements]), _pendingProcesses(new Process*[maxElements]), _cntActive(0), _cntPending(0) {
	for (int i = 0; i < maxElements; i++) {
		_activeProcesses[i] = nullptr;
		_pendingProcesses[i] = nullptr;
	}
}

ProcessQueue::~ProcessQueue() {
	for (int i = 0; i < _maxElements; i++) {
		delete _activeProcesses[i];
		delete _pendingProcesses[i];
	}
	delete[] _activeProcesses;
	delete[] _pendingProcesses;
	_activeProcesses = nullptr;
	_pendingProcesses = nullptr;
	_maxElements = 0;
}

/*Active has values 0 or 1. 1 is active, 0 is pending*/
void ProcessQueue::AddProcess(Process* process, int active) { //Da li ovo ovako treba da se izvede? Da li treba da se doda
	if (active) {
		if (_cntActive < _maxElements) {
			_activeProcesses[_cntActive++] = process;
		}
	}
	else {
		if (_cntActive < _maxElements) {
			_pendingProcesses[_cntPending++] = process;
		}
	}
}
void ProcessQueue::RemoveState2() {
	for (int i = 0; i < _cntActive; i++)
	{
		if (_activeProcesses[i]->GetState() == 2) {
			for (int j = i; j < _cntActive - 1; j++)
				_activeProcesses[j] = _activeProcesses[j + 1];
			_activeProcesses[_cntActive - 1] = nullptr;
			_cntActive--;
		}
	}
	for (int i = 0; i < _cntPending; i++) {
		if (_pendingProcesses[i]->GetState() == 2) {
			for (int j = i; j < _cntPending; j++)
				_pendingProcesses[j] = _pendingProcesses[j + 1];
			_pendingProcesses[_cntPending - 1] = nullptr;
			_cntPending--;
		}
	}
}
void ProcessQueue::ActivateProcesses() { //Da li ovo treba drugacije da se uradi?
	/*for (int i = 0; i < _cntActive; i++)
	{
		if (_activeProcesses[i]->GetState() == 0) {
			_activeProcesses[i]->Start(startParameter);
		}
	}
	for (int i = 0; i < _cntPending; i++)
	{
		if (_pendingProcesses[i]->GetState() == 0)
			_pendingProcesses[i]->Start(startParameter);
	}*/

	int veci = _cntActive > _cntPending ? _cntActive : _cntPending;
	int i = 0;
	while (i < veci) {
		if (i < _cntActive) {
			if (_activeProcesses[i]->GetState() == 0)
				_activeProcesses[i]->UnconditionalStart();
		}
		if (i < _cntPending) {
			if (_pendingProcesses[i]->GetState() == 0)
				_pendingProcesses[i]->UnconditionalStart();
		}
		i++;
	}
	//_activeProcesses[i]->GetPassword() - cemu sluzi ova funkcija ako se nigde ne koristi?
}
void ProcessQueue::StopProcesses() {
	int veci = _cntActive > _cntPending ? _cntActive : _cntPending;
	int i = 0;
	while (i < veci) {
		if (i < _cntActive) {
			if (_activeProcesses[i]->GetState() == 1)
				_activeProcesses[i]->Stop();
		}
		if (i < _cntPending) {
			if (_pendingProcesses[i]->GetState() == 1)
				_pendingProcesses[i]->Stop();
		}
		i++;
	}
}
ProcessQueue ProcessQueue::operator+(ProcessQueue& pQueue) {
	ProcessQueue pq(_maxElements + pQueue._maxElements);
	int processCntActive = _cntActive, processCntPending = _cntPending;

	processCntActive += pQueue._cntActive;
	processCntPending += pQueue._cntPending;
	for (int i = 0; i < _cntActive; i++) {
		pq._activeProcesses[i] = _activeProcesses[i];
		pq._cntActive++;
	}
	for (int i = _cntActive; i < processCntActive; i++) {
		pq._activeProcesses[i] = pQueue._activeProcesses[i-_cntActive];
		pq._cntActive++;
	}
	pq._activeProcesses[pq._cntActive - 1] = nullptr;

	for (int i = 0; i < _cntPending; i++) {
		pq._pendingProcesses[i] = _pendingProcesses[i];
		pq._cntPending++;
	}
	for (int i = _cntPending; i < processCntPending; i++) {
		pq._pendingProcesses[i] = pQueue._pendingProcesses[i-_cntPending];
		pq._cntPending++;
	}
	pq._pendingProcesses[pq._cntActive - 1] = nullptr;
	return pq;
}
void ProcessQueue::PrintProcessQueue() {
	std::cout << "Active processes: \n";
	for (int i = 0; i < _cntActive; i++)
		_activeProcesses[i]->ReadProcess();

	std::cout << "\nPending processes: \n";
	for (int i = 0; i < _cntPending; i++)
		_pendingProcesses[i]->ReadProcess();
}
