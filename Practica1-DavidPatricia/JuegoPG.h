//#pragma once
#ifndef H_JuegoPG_H
#define H_JuegoPG_H
#include <SDL.h>
#include <vector>
//#include "ObjetoJuego.h"
#include "EstadoJuego.h"
#include "TexturasSDL.h"
#include "Sound_SDL.h"
#include "checkML.h"
#include <stack>

enum Texturas_t{TFondo, TGlobo, TMariposa, TPremio, TBoton};
//enum Estado {EMENU, EJUEGO, EGAMEOVER, EPAUSA};

class JuegoPG{
public:
	JuegoPG();
	~JuegoPG();
	void run();

	////////////Para la practica 2///////////////////////////
	//Este metodo  guarda el nombre de cada archivo de textura
	std::vector<std::string> archText;//
	TexturasSDL* getTextura(Texturas_t et) const { return pTexturaG[et]; };//
	SDL_Renderer* getRender() const{ return pRender; };//
	//Este va definido en el cpp
	void getMousePos(int & mpx, int & mpy) const;//
	//void newBaja(ObjetoJuego* po);///
	//void newPuntos(ObjetoJuego* po);///
	//void newPremio(ObjetoJuego* po);///
	void initMedia();//
	void freeMedia();//
	void changeState(EstadoJuego* newSt);
	void pushState(EstadoJuego* newState);
	void popState();
	void onExit();//SETSALIR
	//Para obtener el ancho de la pantalla
	int getWindowWidth()const { return SCREEN_WIDTH; };
	void muestraMensaje(std::string info, std::string boton);//
	int getPuntos()const { return puntuacion; };
	Sound_SDL* getSound()const{ return sonido; };
	TexturasSDL* getPuntosText(){ return pTexturaG[0]; };
	EstadoJuego* getState(){ return pilaEstados.top(); };

private:
	std::stack<EstadoJuego*> pilaEstados;
	//int numGlobos = 6;///
	const int SCREEN_WIDTH = 640;//   //Screen dimension
	const int SCREEN_HEIGHT = 480;//  //Screen dimension
	SDL_Renderer* pRender;//
	SDL_Window* pWindow;//
	SDL_Rect* fRect; //Este será el rectangulo de fondo de la textura IGUAL ES BORRABLE
	//std::vector<ObjetoJuego*> pObjetos;///
	std::vector<TexturasSDL*> pTexturaG;//
	Sound_SDL* sonido;//
	int mouseX;//
	int mouseY;//

	bool error, exit;
	int puntuacion;
	//bool gameOver();///*/
	bool initSDL();//
	void closeSDL();//
	/*bool initGlobos();///
	void freeGlobos();///
	void render() const;///
	void onClick();///
	void update();///*/
	void handle_event();//
	void initMusic();//
	void closeMusic();//

	void rellenaArch();//
};

#endif