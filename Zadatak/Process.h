#pragma once

/*
	Kreirati klasu Process koja od zaštićenih atributa sadrži šifru (int), stanje (int, može da uzme vrednosti 0 – kreiran,
	1 – startovan i 2 - zaustavljen) i tip (int) a od javnih funkcija sadrži: 
		• funkciju koja vraća šifru, 
		• funkciju koja vraća stanje, 
		• funkciju za prikaz šifre, stanja i tipa procesa, 
		• čistu virtuelnu funkciju za startovanje procesa koja kao parametar ima jedan niz 
		  karaktera - void Start(char* parameter), 
		• čistu virtuelnu funkciju za zaustavljanje procesa – void Stop(). 
	Nakon kreiranja objekta tipa Process, objekat je u stanju 0. U stanje 1 prelazi nakon što se startuje pozivom 
	odgovarajuće funkcije, a u stanje 2 nakon što se pozove funkcija za njegovo zaustavljanje. 
*/
class Process
{
protected:
	int _password;
	int _state;
	int _type;

public:
	Process(int);
	~Process();
	int GetPassword() const;
	int GetState() const;
	virtual void ReadProcess();
	virtual void Start(const char* parameter) = 0;
	virtual void Stop() = 0;
	void UnconditionalStart();
};

