#include "JuegoPG.h"
#include <iostream>
#include <typeinfo>
#include "GlobosPG.h"
#include "Mariposa.h"
#include "Premio.h"
#include "GloboA.h"
#include "MenuPG.h"

JuegoPG::JuegoPG()
{
	srand(SDL_GetTicks());
	initSDL();
	rellenaArch();
	initMedia();
	//initGlobos();
	//puntuacion = 0;
	error = false;
	exit = false;
	mouseX = 0;
	mouseY = 0;
}


JuegoPG::~JuegoPG()
{
	//freeGlobos();
	freeMedia();
	closeSDL();
}

void JuegoPG::getMousePos(int & mpx, int & mpy)const{
	mpx = mouseX;
	mpy = mouseY;
}

/*void JuegoPG::newBaja(ObjetoJuego* po){
	if (typeid(*po) == typeid(GlobosPG) || typeid(*po) == typeid(GloboA)) {
		--numGlobos;
	}
	else if (typeid(*po) == typeid(Premio)) {
		sonido->playEffect();
	}
}

void JuegoPG::newPuntos(ObjetoJuego* po) {
	sonido->playEffect();
	puntuacion += dynamic_cast<ObjetoPG*>(po)->puntos;
}

void JuegoPG::newPremio(ObjetoJuego* po) {
	pObjetos.emplace_back(new Premio(rand() % 720, rand() % 480, this));
	dynamic_cast<Premio*>(pObjetos[pObjetos.size() - 1])->reiniciarP();
}*/

//Inicializa las texturas, la musica y la fuente
void JuegoPG::initMedia() {
	TexturasSDL::loadFuente("..\\fonts\\MONOFONT.TTF", 12);

	pTexturaG.emplace_back(new TexturasSDL());
	pTexturaG[0]->load(pRender, archText[TFondo]);
	pTexturaG.emplace_back(new TexturasSDL());
	pTexturaG[1]->load(pRender, archText[TGlobo]);
	pTexturaG.emplace_back(new TexturasSDL());
	pTexturaG[2]->load(pRender, archText[TMariposa]);
	pTexturaG.emplace_back(new TexturasSDL());
	pTexturaG[3]->load(pRender, archText[TPremio]);
	pTexturaG.emplace_back(new TexturasSDL());

	//Creamos un SDL_Rect para pasarselo después al render (para el fondo)
	fRect = new SDL_Rect();
	fRect->h = SCREEN_HEIGHT;
	fRect->w = SCREEN_WIDTH;
	fRect->x = 0;
	fRect->y = 0;

	initMusic();

}

//Libera lo creado en initMedia()
void JuegoPG::freeMedia() {
	closeMusic();
	delete fRect;
	fRect = nullptr;
	for (int n = 0; n < pTexturaG.size(); n++) {
		delete pTexturaG[n];
		pTexturaG[n] = nullptr;
	}
	TexturasSDL::closeFuente();
}

//Metodo auxiliar que rellena el vector de archivos de texturas
void JuegoPG::rellenaArch() {
	archText.push_back("..\\bmps\\fondo.png");
	archText.push_back("..\\bmps\\Globo.png");
	archText.push_back("..\\bmps\\Mariposa.png");
	archText.push_back("..\\bmps\\Doritos.png");
}

//Invoca una ventana(info) con un boton(boton)
void JuegoPG::muestraMensaje(std::string info, std::string boton) {
	//SDL_DisplayMode dm;
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, info.c_str(), boton.c_str(), nullptr);
}

void JuegoPG::initMusic() {
	sonido = new Sound_SDL("..\\sounds\\AllStar.wav", "..\\sounds\\Hitmarker.wav");
}

void JuegoPG::closeMusic(){
	Sound_SDL::close();
	delete sonido;
}

//Este metodo da valor al pRender y al pWindow
bool JuegoPG::initSDL() {

	bool success = true; //Initialization flag

	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "SDL could not initialize! \nSDL_Error: " << SDL_GetError() << '\n';
		success = false;
	}
	else {
		//Create window: SDL_CreateWindow("SDL Hello World", posX, posY, width, height, SDL_WINDOW_SHOWN);
		pWindow = SDL_CreateWindow("GloboJuego", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (pWindow == nullptr){
			std::cout << "Window could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
			success = false;
		}
		else {
			//Get window surface:
			pRender = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
			if (pRender == nullptr){
				std::cout << "Renderer could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
				success = false;
			}
		}
	}
	return success;
}

void JuegoPG::closeSDL() {
	SDL_DestroyRenderer(pRender);
	pRender = nullptr;
	SDL_DestroyWindow(pWindow);
	pWindow = nullptr;
	SDL_Quit();
}

/*bool JuegoPG::initGlobos(){
	bool success = true;
	//Creo un int que me servirá para almacenar el aleatorio
	int r;

	for (int n = 0; n < numGlobos; ++n){
		//Aquí lanzo la moneda y creo uno de los dos globos
		r = rand() % 2;
		if (r==1)
			pObjetos.emplace_back(new GlobosPG(rand() % 720, rand() % 480, this));
		else
			pObjetos.emplace_back(new GloboA(rand() % 720, rand() % 480, this));
	}
	pObjetos.emplace_back(new Mariposa(rand() % 720, rand() % 480, this));
	pObjetos.emplace_back(new Mariposa(rand() % 720, rand() % 480, this));
	//pObjetos.emplace_back(new Premio(rand() % 720, rand() % 480, this));
	return success;
}

void JuegoPG::freeGlobos() {
	for (int n = 0; n < pObjetos.size(); ++n){
		delete pObjetos[n];
		pObjetos[n] = nullptr;
	}
}*/

//HABRIA QUE CAMBIARLO
void JuegoPG::run() {
	if (!error) {
		Uint32 MSxUpdate = 500;
		std::cout << "PLAY \n";
		Uint32 lastUpdate = SDL_GetTicks();
		muestraMensaje("PLAY", "Ready?");//SE BORRARIA
		pilaEstados.push(new MenuPG(this));
		sonido->playMusic();
		handle_event();
		while (!exit && !error && numGlobos>0) {
			if (SDL_GetTicks() - lastUpdate >= MSxUpdate){ // while(elapsed >= MSxUpdate)
				update();
				lastUpdate = SDL_GetTicks();
			}
			render();
			onClick();
			handle_event();
		}

		if (exit) std::cout << "EXIT \n";
		else std::cout << "Has obtenido " << puntuacion << " puntos\n";
		std::string puntos = std::to_string(puntuacion);
		muestraMensaje("ENHORABUENA", "Has obtenido " + puntos);
		sonido->close();
		SDL_Delay(1000); //cin.get();
	}
}

void JuegoPG::onExit() {
	exit = true;
}

/*
bool JuegoPG::gameOver(){
	return numGlobos <= 0;
}*/

void JuegoPG::handle_event(){
	SDL_Event e;
	if (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) onExit();
		else if (e.type == SDL_MOUSEBUTTONUP) {
			if (e.button.button == SDL_BUTTON_LEFT) {
				std::cout << "CLICK \n";
				mouseX = e.button.x;
				mouseY = e.button.y;
			}
		}
	}
}

/*void JuegoPG::render()const{
	SDL_RenderClear(pRender);
	pTexturaG[TFondo]->draw(pRender, *fRect, nullptr);

	for each (ObjetoJuego* g in pObjetos)
	{
		g->draw();
	}
	std::string puntos = std::to_string(puntuacion);
	pTexturaG[pTexturaG.size()-1]->renderText(pRender, puntos);
	SDL_RenderPresent(pRender);
}*/

/*void JuegoPG::update() {
	for each (ObjetoJuego* g in pObjetos)
	{
		g->update();
	}
}*/

/*void JuegoPG::onClick(){
	bool click = false;
	int i = 0;
	while (!click && i<pObjetos.size()){
		if (pObjetos[i]->onClick()) {
			click = true;
		}
		i++;
	}
}*/