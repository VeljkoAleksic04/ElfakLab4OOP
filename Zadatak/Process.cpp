#include "Process.h"
#include <iostream>
/*
	Nakon kreiranja objekta tipa Process, objekat je u stanju 0. U stanje 1 prelazi nakon što se startuje pozivom
	odgovarajuće funkcije, a u stanje 2 nakon što se pozove funkcija za njegovo zaustavljanje.
*/

Process::Process(int password) : _state(0), _password(password) {}
Process::~Process() {
	_password = 0;
	_state = 0;
	_type = 0;
}
int Process::GetPassword() const { return this->_password; }
int Process::GetState() const { return this->_state; }
void Process::ReadProcess() { std::cout << "Sifra: " << _password << "\tStanje: " << _state << "\tTip procesa: " << _type; }
void Process::UnconditionalStart() { _state = 1; }