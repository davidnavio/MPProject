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

bool movimientoAlfil(int xorigen, int yorigen, int xfinal, int yfinal)
{
	bool moviment = false;


	return moviment;
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



	Sprite fons;
	fons.create("data/tauler.png");
	Sprite reiBlanc;
	reiBlanc.create("data/rei_blanc.png");
	Sprite reiNegre;
	reiNegre.create("data/rei_negre.png");
	Sprite cavallBlanc;
	cavallBlanc.create("data/cavall_blanc.png");
	Sprite cavallNegre;
	cavallNegre.create("data/cavall_negre.png");

	int matriu[8][8] = { {CAVALL_BLANC ,CAVALL_NEGRE,REI_BLANC,REI_NEGRE,0,0,0,0 },{ 0,0,0,0,0,0,0,0 } ,{ 0,0,0,0,0,0,0,0 } ,{ 0,0,0,0,0,0,0,0 } ,{ 0,0,0,0,0,0,0,0 } ,{ 0,0,0,0,0,0,0,0 } ,{ 0,0,0,0,0,0,0,0 } ,{ 0,0,0,0,0,0,0,0 } };

	// Variables d'ajuda per agafar posició ratolí
	int xMouse = 0;
	int yMouse = 0;
	int xorigen = 0;
	int yorigen = 0;
	int xdesti = 0;
	int ydesti = 0;
	int fitxa;
	bool origen = false;
	do
	{

		jocLib.processEvents();
		if (Mouse_getButLeft())
		{
			xMouse = Mouse_getX();
			yMouse = Mouse_getY();
			if (origen)
			{
				getPosMatrix(xMouse, yMouse, xdesti, ydesti);
				if ((xdesti != xorigen) || (ydesti != yorigen))
				{
					matriu[xdesti - 1][ydesti - 1] = fitxa;
					matriu[xorigen - 1][yorigen - 1] = 0;
					origen = false;
				}
			}
			else
			{
				getPosMatrix(xMouse, yMouse, xorigen, yorigen);
				if (matriu[xorigen - 1][yorigen - 1] != 0)
				{
					origen = true;
					fitxa = matriu[xorigen - 1][yorigen - 1];
				}

			}


			// AFEGIR CODI: Agafar posició de la casella on s'ha clicat
			// S'haurà de controlar si el clic correspon a la casella origen o
			// a la casella final del moviment

			// AFEGIR CODI: Si ja hem clicat origen i destí,
			// fer comprovació que el moviment sigui correcte i, si ho ´es
			// fer el moviment

		}


		fons.draw(0, 0);

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (matriu[i][j] == CAVALL_BLANC)
					cavallBlanc.draw(INIPANTALLAX + j* MIDACASELLA, INIPANTALLAY + i * MIDACASELLA);
				if (matriu[i][j] == CAVALL_NEGRE)
					cavallNegre.draw(INIPANTALLAX + j* MIDACASELLA, INIPANTALLAY + i * MIDACASELLA);
				if (matriu[i][j] == REI_BLANC)
					reiBlanc.draw(INIPANTALLAX + j* MIDACASELLA, INIPANTALLAY + i * MIDACASELLA);
				if (matriu[i][j] == REI_NEGRE)
					reiNegre.draw(INIPANTALLAX + j* MIDACASELLA, INIPANTALLAY + i * MIDACASELLA);
			}
		}

		// Actualitza la pantalla
		jocLib.update();

		// ***********************************************************************
		// Sortim del bucle si pressionem ESC
		// ***********************************************************************
	} while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));

}