#pragma once
#include "Process.h"
#include <string.h>

/*
    Kreirati klasu PublicProcess koja je javno izvedena iz klase Process, koja od privatnih atributa sadrži ime korisnika 
    koji ih je kreirao (char* creatorName). Od javnih metoda sadrži: 
	    • konstruktor koji postavlja sve atribute. 
    Kod objekata ove klase parametar tip uvek ima vrednost 0. Prilikom startovanja procesa prosleđuje se kao parametar 
    funkcije Start ime korisnika koji startuje proces. Ako je ime korisnika koji inicira startovanje PublicProcess-a 
    (userName) različito od vrednosti creatorName, creatorName treba da uzme vrednost koju ima userName, dok proces, u 
    svakom slucaju, treba da pređe u stanje 1. 

*/

class PublicProcess :
    public Process
{
private:
    char* _creatorName;
public:
    PublicProcess(int, const char*);
    void Start(const char*);
    void Stop();
    void SetCreatorName(char* name) { strcpy(_creatorName, name); }
    char* GetName() const { return _creatorName; }
};

