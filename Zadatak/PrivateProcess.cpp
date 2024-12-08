#include "PrivateProcess.h"
#include <string.h>
#include <iostream>
/*
	Kod objekata ove klase parametar tip uvek ima vrednost 1. Ove procese može da startuje samo korisnik koji zna 
	njihov kod i koji prosleđuje kod kao parametar funkcije za startovanje, a mogu da pređu u stanje 2 samo ako se 
	trenutno nalaze u stanju 1
*/

PrivateProcess::PrivateProcess(int password, const char* code) : Process(password), _code(new char[10]) {
	_type = 1;
	strcpy(_code, code);
}
void PrivateProcess::Start(const char* parameter) {
	if (!strcmp(parameter, _code))
		_state = 1;
	else std::cout << "\nProcess activating failed...\n";
}
void PrivateProcess:: Stop() {
	if (_state == 1)
		_state = 2;
	else std::cout << "\nUnable to stop process...\n";
}