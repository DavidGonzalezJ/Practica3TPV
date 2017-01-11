//Práctica 2
//Autores: Patricia Cabrero y David González
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif
#include "SDL.h"
#include "JuegoPG.h"
#include <iostream>


int main(int argc, char* args[]) {  // SDL require esta cabecera 
	system("chcp 1252");
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	JuegoPG* partida = new JuegoPG();
	//Valora si hay errores dentro del run
	partida->run();
	delete partida;
	//system("PAUSE");
	//_CrtDumpMemoryLeaks();
	return 0;
}