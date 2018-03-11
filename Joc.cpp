#include "Joc.h"


void getPosMatrix(int x, int y, int(&fila), int(&columna))
{
	if ((x >= INIPANTALLAX) && (y >= INIPANTALLAY))
	{
		columna = (x - INIPANTALLAX) / MIDACASELLA;
		fila = (y - INIPANTALLAY) / MIDACASELLA;
		columna = columna + 1;
		fila = fila + 1;
	}
	else
	{
		columna = 0;
		fila = 0;
	}
	printf("Columna Fila %d %d \n", fila, columna);
}

bool movimentAlfil(int matriu[][8], int yOrigen, int xOrigen, int yDesti, int xDesti)
{
	bool moviment = false;
	int offSetAlfil[4][2] = { {1,1},{1,-1},{-1,1},{-1,-1} };
	int i = 0;
	int auxX;
	int auxY;
	while(!moviment && i<4)
	{
		int j = 1;
		bool maxim = false;
		while(!moviment && !maxim)
		{
			auxX = xOrigen + j*offSetAlfil[i][0];
			auxY = yOrigen + j*offSetAlfil[i][1];
			if (auxX > 8 || auxY > 8)
				maxim = true;
			else
			{
				if (auxX==xDesti && auxY==yDesti)
					moviment = true;
				else
				{
					if (matriu[auxX-1][auxY-1] != 0)
						maxim = true;
					else
						j++;
				}
			}
		}
		i++;
	}
	return moviment;
}
bool movimentTorre(int matriu[][8], int yOrigen, int xOrigen, int yDesti, int xDesti)
{
	bool moviment = false;
	int offSetTorre[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
	int i = 0;
	int auxX;
	int auxY;
	while (!moviment && i<4)
	{
		int j = 1;
		bool maxim = false;
		while (!moviment && !maxim)
		{
			auxX = xOrigen + j*offSetTorre[i][0];
			auxY = yOrigen + j*offSetTorre[i][1];
			if (auxX > 8 || auxY > 8)
				maxim = true;
			else
			{
				if (auxX == xDesti && auxY == yDesti)
					moviment = true;
				else
				{
					if (matriu[auxX - 1][auxY - 1] != 0)
						maxim = true;
					else
						j++;
				}
			}
		}
		i++;
	}
	return moviment;
}
bool movimentDama(int matriu[][8], int yOrigen, int xOrigen, int yDesti, int xDesti)
{
	bool moviment = false;
	int offSetDama[8][2] = { { 1,1 },{ 1,-1 },{ -1,1 },{ -1,-1 },{ 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
	int i = 0;
	int auxX;
	int auxY;
	while (!moviment && i<8)
	{
		int j = 1;
		bool maxim = false;
		while (!moviment && !maxim)
		{
			auxX = xOrigen + j*offSetDama[i][0];
			auxY = yOrigen + j*offSetDama[i][1];
			if (auxX > 8 || auxY > 8)
				maxim = true;
			else
			{
				if (auxX == xDesti && auxY == yDesti)
					moviment = true;
				else
				{
					if (matriu[auxX - 1][auxY - 1] != 0)
						maxim = true;
					else
						j++;
				}
			}
		}
		i++;
	}
	return moviment;
}
bool movimentValid(int matriu[][8], int yOrigen, int xOrigen, int yDesti, int xDesti)
{
	bool moviment = true;
	switch (matriu[xOrigen - 1][yOrigen - 1])
	{
	case REI_BLANC:
		break;
	case REI_NEGRE:
		break;
	case DAMA_BLANC:
		moviment = movimentDama(matriu, yOrigen, xOrigen, yDesti, xDesti);
		break;
	case DAMA_NEGRE:
		moviment = movimentDama(matriu, yOrigen, xOrigen, yDesti, xDesti);
		break;
	case TORRE_BLANC:
		moviment = movimentTorre(matriu, yOrigen, xOrigen, yDesti, xDesti);
		break;
	case TORRE_NEGRE:
		moviment = movimentTorre(matriu, yOrigen, xOrigen, yDesti, xDesti);
		break;
	case CAVALL_BLANC:
		break;
	case CAVALL_NEGRE:
		break;
	case ALFIL_BLANC:
		moviment = movimentAlfil(matriu, yOrigen, xOrigen, yDesti, xDesti);
		break;
	case ALFIL_NEGRE:
		moviment = movimentAlfil(matriu, yOrigen, xOrigen, yDesti, xDesti);
		break;
	case PEO_BLANC:
		break;
	case PEO_NEGRE:
		break;
	}
	return moviment;
}
void pintaPeces(int matriu[][CASELLES_Y], Sprite peça[])
{
	for (int i = 0; i < CASELLES_X; i++)
	{
		for (int j = 0; j < CASELLES_Y; j++)
		{
			switch (matriu[i][j])
			{
			case REI_BLANC:
				peça[REI_BLANC - 1].draw(INIPANTALLAX + j* MIDACASELLA, INIPANTALLAY + i * MIDACASELLA);
				break;
			case REI_NEGRE:
				peça[REI_NEGRE - 1].draw(INIPANTALLAX + j* MIDACASELLA, INIPANTALLAY + i * MIDACASELLA);
				break;
			case DAMA_BLANC:
				peça[DAMA_BLANC - 1].draw(INIPANTALLAX + j* MIDACASELLA, INIPANTALLAY + i * MIDACASELLA);
				break;
			case DAMA_NEGRE:
				peça[DAMA_NEGRE - 1].draw(INIPANTALLAX + j* MIDACASELLA, INIPANTALLAY + i * MIDACASELLA);
				break;
			case TORRE_BLANC:
				peça[TORRE_BLANC - 1].draw(INIPANTALLAX + j* MIDACASELLA, INIPANTALLAY + i * MIDACASELLA);
				break;
			case TORRE_NEGRE:
				peça[TORRE_NEGRE - 1].draw(INIPANTALLAX + j* MIDACASELLA, INIPANTALLAY + i * MIDACASELLA);
				break;
			case CAVALL_BLANC:
				peça[CAVALL_BLANC - 1].draw(INIPANTALLAX + j* MIDACASELLA, INIPANTALLAY + i * MIDACASELLA);
				break;
			case CAVALL_NEGRE:
				peça[CAVALL_NEGRE - 1].draw(INIPANTALLAX + j* MIDACASELLA, INIPANTALLAY + i * MIDACASELLA);
				break;
			case ALFIL_BLANC:
				peça[ALFIL_BLANC - 1].draw(INIPANTALLAX + j* MIDACASELLA, INIPANTALLAY + i * MIDACASELLA);
				break;
			case ALFIL_NEGRE:
				peça[ALFIL_NEGRE - 1].draw(INIPANTALLAX + j* MIDACASELLA, INIPANTALLAY + i * MIDACASELLA);
				break;
			case PEO_BLANC:
				peça[PEO_BLANC - 1].draw(INIPANTALLAX + j* MIDACASELLA, INIPANTALLAY + i * MIDACASELLA);
				break;
			case PEO_NEGRE:
				peça[PEO_NEGRE - 1].draw(INIPANTALLAX + j* MIDACASELLA, INIPANTALLAY + i * MIDACASELLA);
				break;
			}
		}
	}
}

void comprovaMoviment(int& fitxaOrigen, int matriu[][CASELLES_Y], bool& origen, int xMouse, int yMouse, int& xOrigen, int& yOrigen, struct T_SOUND* soFitxa, int& torn, struct T_SOUND* menjarFitxa)
{
	int xDesti = 0;
	int yDesti = 0;
	if (origen)
	{
		getPosMatrix(xMouse, yMouse, xDesti, yDesti);
		if (((xDesti != xOrigen) || (yDesti != yOrigen)) && ((matriu[xDesti - 1][yDesti - 1] == 0) || ((matriu[xDesti - 1][yDesti - 1] % 2) != (fitxaOrigen % 2))))
		{
			if (movimentValid(matriu, yOrigen, xOrigen, yDesti, xDesti))
			{
				Sound_Stop(menjarFitxa);
				Sound_Stop(soFitxa);
				if (matriu[xDesti - 1][yDesti - 1] != 0)
					Sound_Play(menjarFitxa, PLAY_THEN_STOP_AT_END);
				else
					Sound_Play(soFitxa, PLAY_THEN_STOP_AT_END);
				matriu[xDesti - 1][yDesti - 1] = fitxaOrigen;
				matriu[xOrigen - 1][yOrigen - 1] = 0;
				origen = false;
				torn++;
			}
		}
	}
	else
	{
		getPosMatrix(xMouse, yMouse, xOrigen, yOrigen);
		if ((matriu[xOrigen - 1][yOrigen - 1] != 0) && (matriu[xOrigen - 1][yOrigen - 1]%2==torn%2) )
		{
			origen = true;
			fitxaOrigen = matriu[xOrigen - 1][yOrigen - 1];
		}
	}
}


void inicialitzaPeces(Sprite peça[])
{
	peça[REI_BLANC - 1].create("data/rei_blanc.png");
	peça[REI_NEGRE - 1].create("data/rei_negre.png");
	peça[CAVALL_BLANC - 1].create("data/cavall_blanc.png");
	peça[CAVALL_NEGRE - 1].create("data/cavall_negre.png");
	peça[ALFIL_BLANC - 1].create("data/alfil_blanc.png");
	peça[ALFIL_NEGRE - 1].create("data/alfil_negre.png");
	peça[DAMA_BLANC - 1].create("data/dama_blanc.png");
	peça[DAMA_NEGRE - 1].create("data/dama_negre.png");
	peça[PEO_BLANC - 1].create("data/peo_blanc.png");
	peça[PEO_NEGRE - 1].create("data/peo_negre.png");
	peça[TORRE_BLANC - 1].create("data/torre_blanc.png");
	peça[TORRE_NEGRE - 1].create("data/torre_negre.png");
}

//-----------------------------------------
// joc: porta el control de tot el joc
//-----------------------------------------
void joc()
{
	// ********************************************
	// Inicialització de la part gràfica del joc
	// *******************************************
	//Inicialitza Part grafica
	Screen jocLib(MIDAX, MIDAY);

	//Mostrem finestra
	jocLib.show();
	//Inicialitzem el tauler
	Sprite fons;
	fons.create("data/tauler.png");
	//Inicialitzem les peces 
	Sprite peça[12];
	inicialitzaPeces(peça);

	
	
	//Iniciallitzem el so
	Sound_Init();
	struct T_SOUND* soFitxa;
	soFitxa = Sound_LoadSound("data/fitxa.ogg");
	struct T_SOUND* menjarFitxa;
	menjarFitxa = Sound_LoadSound("data/menjar_fitxa.ogg");
	struct T_SOUND* musica;
	//musica de fons--Oltremare, Ludovico Einaudi
	musica=Sound_LoadMusic("data/oltremare.ogg", PLAY_FROM_DISK_STREAM);

	int matriu[CASELLES_X][CASELLES_Y] = { {TORRE_NEGRE ,CAVALL_NEGRE,ALFIL_NEGRE,DAMA_NEGRE,REI_NEGRE,ALFIL_NEGRE,CAVALL_NEGRE,TORRE_NEGRE },
		{PEO_NEGRE,PEO_NEGRE,PEO_NEGRE,PEO_NEGRE,PEO_NEGRE,PEO_NEGRE,PEO_NEGRE,PEO_NEGRE } ,
			{ 0,0,0,0,0,0,0,0 } ,{ 0,0,0,0,0,0,0,0 } ,{ 0,0,0,0,0,0,0,0 } ,{ 0,0,0,0,0,0,0,0 } ,
			{ PEO_BLANC,PEO_BLANC,PEO_BLANC,PEO_BLANC,PEO_BLANC,PEO_BLANC,PEO_BLANC,PEO_BLANC } ,
			{ TORRE_BLANC,CAVALL_BLANC,ALFIL_BLANC,DAMA_BLANC,REI_BLANC,ALFIL_BLANC,CAVALL_BLANC,TORRE_BLANC } };

	// Variables d'ajuda per agafar posició ratolí
	int xMouse = 0;
	int yMouse = 0;
	int xOrigen = 0;
	int yOrigen = 0;
	int torn = 1;
	int fitxaOrigen;
	bool origen = false;
	do
	{

		jocLib.processEvents();
		if (Mouse_getButLeft())
		{
			xMouse = Mouse_getX();
			yMouse = Mouse_getY();
			comprovaMoviment(fitxaOrigen, matriu, origen, xMouse, yMouse, xOrigen, yOrigen, soFitxa,torn,menjarFitxa);


			// AFEGIR CODI: Agafar posició de la casella on s'ha clicat
			// S'haurà de controlar si el clic correspon a la casella origen o
			// a la casella final del moviment

			// AFEGIR CODI: Si ja hem clicat origen i destí,
			// fer comprovació que el moviment sigui correcte i, si ho ´es
			// fer el moviment

		}


		fons.draw(0, 0);
		pintaPeces(matriu, peça);


		// Actualitza la pantalla
		jocLib.update();

		// ***********************************************************************
		// Sortim del bucle si pressionem ESC
		// ***********************************************************************
	} while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));

}