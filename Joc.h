#pragma once

///////////////////////////////////////////////////////////////////////////
//Llibreria grafica
#include "lib/libreria.h"
///////////////////////////////////////////////////////////////////////////

#include <conio.h>      /* getch */ 
#include <stdio.h>      /* printf */
#include <time.h>       /* time */
#include <stdlib.h>


//========================================================================
// Mida Pantalla
const int MIDAX = 624;
const int MIDAY = 680;
const int CASELLES_X = 8;
const int CASELLES_Y = 8;

//========================================================================
// Fitxes
// Blanques parells, negres senars
const int REI_BLANC = 1;
const int REI_NEGRE = 2;
const int DAMA_BLANC = 3;
const int DAMA_NEGRE = 4;
const int TORRE_BLANC = 5;
const int TORRE_NEGRE = 6;
const int ALFIL_BLANC = 7;
const int ALFIL_NEGRE = 8;
const int CAVALL_BLANC = 9;
const int CAVALL_NEGRE = 10;
const int PEO_BLANC = 11;
const int PEO_NEGRE = 12;

//========================================================================
// Inici del taulell respecte la cantonada superior esquerre
const int INIPANTALLAX = 0;
const int INIPANTALLAY = 58;

//========================================================================
// Fi del taulell respecte la cantonada inferior dreta
const int FIPANTALLAX = 624;
const int FIPANTALLAY = 680;

const int MIDACASELLA = 78;

int aleatori(int min, int max, int pas);

void joc();

void getPosMatrix(int x, int y, int(&fila), int(&columna));
void pintaPecesTornNegre(int matriu[][CASELLES_Y], Sprite peça[]);
void pintaPeces(int matriu[][CASELLES_Y], Sprite peça[]);
void comprovaMoviment(int& fitxaOrigen, int matriu[][CASELLES_Y], bool& origen, int xMouse, int yMouse, int& xOrigen, int& yOrigen, struct T_SOUND* soFitxa, int& torn);

bool comprovaMovimentConcret(int& fitxaOrigen, int& xOrigen, int& yOrigen, int xDesti, int yDesti, int matriu[CASELLES_X][CASELLES_Y]);

/*----- END --------------*/



