#include "PublicProcess.h"
#include <string.h>
#include <iostream>

/*
	Kod objekata ove klase parametar tip uvek ima vrednost 0. Prilikom startovanja procesa prosleđuje se kao parametar 
    funkcije Start ime korisnika koji startuje proces. Ako je ime korisnika koji inicira startovanje PublicProcess-a 
    (userName) različito od vrednosti creatorName, creatorName treba da uzme vrednost koju ima userName, dok proces, u 
    svakom slucaju, treba da pređe u stanje 1. 
*/

PublicProcess::PublicProcess(int password, const char* name) : Process(password) {
    _creatorName = new char[50];
    strcpy(_creatorName, name);
    _type = 0;
}
void PublicProcess::ReadProcess() {
    Process::ReadProcess();
    std::cout << "\tCreator name: " << _creatorName << std::endl;
}
void PublicProcess::Start(const char* parameter) {
    _state = 1;
    if (strcmp(parameter, _creatorName) != 0)
        strcpy(_creatorName, parameter);
}

void PublicProcess::Stop() {
    _state = 2;
}