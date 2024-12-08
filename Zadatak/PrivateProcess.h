#pragma once
#include "Process.h"

/*
    Kreirati klasu PrivateProcess koja je javno izvedena iz klase Process, koja od privatnih atributa ima kod (char* code) 
    i od javnih metoda sadrži konstruktor koji postavlja sve atribute
*/

class PrivateProcess :
    public Process
{
private:
    char* _code;
public:
    PrivateProcess(int, const char*);
    void Start(const char*);
    void Stop();
};