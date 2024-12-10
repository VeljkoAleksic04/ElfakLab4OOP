#pragma once
/*
	Na programskom jeziku C++ kreirati klasu ProcessQueue koja od privatnih atributa sadrži maksimalni broj elemenata po 
	nizu i dva niza pointera na objekte klase Process. Jedan niz predstavlja aktivne procese a drugi procese na čekanju
	Klasa sadrži i sledeće javne funkcije:
	• konstruktor koji postavlja broj elemenata nizova i zauzima potreban prostor u memoriji,
	• destruktor,
	• funkciju za dodavanje pointera na tip Process u specificirani niz ako u njemu postoji slobodno mesto,
	• funkciju koja iz nizova izbacuje sve procese u stanju 2,
	• funkciju koja startuje sve procese iz oba niza koji su stanju 0,
	• funkciju koja zaustavlja sve procese iz oba niza koji su u stanju 1,
	• operatorsku funkciju + koja spaja dva objekta tipa ProcessQueue u jedan,
	• funkciju koja prikazuje sadržaj oba niza.

*/
#include "Process.h"
class ProcessQueue
{
private:
	int _maxElements;
	Process** _activeProcesses;
	Process** _pendingProcesses;
	int _cntActive;
	int _cntPending;
public:
	ProcessQueue(int);
	~ProcessQueue();
	void AddProcess(Process*, int);
	void RemoveState2();
	void ActivateProcesses();
	void StopProcesses();
	ProcessQueue operator+(const ProcessQueue&);
	void PrintProcessQueue();
};

