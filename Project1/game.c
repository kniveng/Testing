#include "cprocessing.h"
#include "game.h"
#include "mainmenu.h"
#include "utils.h"

CP_Vector Blueposition;
CP_Vector BluevelocityW;
CP_Vector BluevelocityA;
CP_Vector BluevelocityS;
CP_Vector BluevelocityD;

float redX = 400.0f;
float redY = 450.0f;
float greenX = 1200.0f;
float greenY = 450.0f;
float recLength = 1300.0f;

int showRect1 = 1;
int showRect2 = 1;
int showRect3 = 1;
int showRect4 = 1;
int showRect5 = 1;
int showRect6 = 1;
int showRect7 = 1;
int showRect8 = 1;
int showRect9 = 1;
int showRect10 = 1;

void Game_Init(void)
{
	BluevelocityW = CP_Vector_Set(0.0f, -7.0f);
	BluevelocityA = CP_Vector_Set(-7.0f, 0.0f);
	BluevelocityS = CP_Vector_Set(0.0f, 7.0f);
	BluevelocityD = CP_Vector_Set(7.0f, 0.0f);

	float redX = 400.0f;
float redY = 450.0f;
float greenX = 1200.0f;
float greenY = 450.0f;
float recLength = 1300.0f;

int showRect1 = 1;
int showRect2 = 1;
int showRect3 = 1;
int showRect4 = 1;
int showRect5 = 1;
int showRect6 = 1;
int showRect7 = 1;
int showRect8 = 1;
int showRect9 = 1;
int showRect10 = 1;
}


void Game_Update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 255));

	CP_Settings_Fill(CP_Color_Create(255, 127, 127, 255));
	CP_Graphics_DrawCircle(redX, redY, 400.0f);

	CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
	CP_Graphics_DrawCircle(greenX, greenY, 400.0f);

	CP_Settings_Fill(CP_Color_Create(0, 0, 255, 255));
	CP_Graphics_DrawCircle(Blueposition.x + 800.0f, Blueposition.y + 450.0f, 100.0f);

	if (CP_Input_KeyDown(KEY_W))
	{
		Blueposition = CP_Vector_Add(Blueposition, BluevelocityW);
	}
	if (CP_Input_KeyDown(KEY_A))
	{
		Blueposition = CP_Vector_Add(Blueposition, BluevelocityA);
	}
	if (CP_Input_KeyDown(KEY_S))
	{
		Blueposition = CP_Vector_Add(Blueposition, BluevelocityS);
	}
	if (CP_Input_KeyDown(KEY_D))
	{
		Blueposition = CP_Vector_Add(Blueposition, BluevelocityD);
	}
	CP_Settings_Fill(CP_Color_Create(139, 0, 0, 255));
	CP_Graphics_DrawRect(150.0f, 50.0f, 1300.0f, 50.0f);

	CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
	CP_Settings_RectMode(CP_POSITION_CORNER);
	CP_Graphics_DrawRect(150.0f, 50.0f, recLength, 50.0f);

	if (showRect1) {
		CP_Graphics_DrawRect(150.0f, 150.0f, 76.0f, 50.0f);
	}
	if (showRect2) {
		CP_Graphics_DrawRect(286.0f, 150.0f, 76.0f, 50.0f);
	}
	if (showRect3) {
		CP_Graphics_DrawRect(422.0f, 150.0f, 76.0f, 50.0f);

	}
	if (showRect4) {
		CP_Graphics_DrawRect(558.0f, 150.0f, 76.0f, 50.0f);

	}
	if (showRect5) {
		CP_Graphics_DrawRect(694.0f, 150.0f, 76.0f, 50.0f);

	}
	if (showRect6) {
		CP_Graphics_DrawRect(830.0f, 150.0f, 76.0f, 50.0f);

	}
	if (showRect7) {
		CP_Graphics_DrawRect(966.0f, 150.0f, 76.0f, 50.0f);

	}
	if (showRect8) {
		CP_Graphics_DrawRect(1102.0f, 150.0f, 76.0f, 50.0f);

	}
	if (showRect9) {
		CP_Graphics_DrawRect(1238.0f, 150.0f, 76.0f, 50.0f);

	}
	if (showRect10) {
		CP_Graphics_DrawRect(1374.0f, 150.0f, 76.0f, 50.0f);
	}

	float blueX = Blueposition.x + 800.0f;
	float blueY = Blueposition.y + 450.0f;
	if (AreCirclesIntersecting(blueX, blueY, 50.0f, redX, redY, 200.0f)) 
	{
		if (recLength > 0) {
			recLength -= 5;
		}
		else {
			recLength -= 0;
		}

		if (recLength <= 1170.0f) {
			showRect10 = 0;
		}
		if (recLength <= 1040.0f) {
			showRect9 = 0;
		}
		if (recLength <= 910.0f) {
			showRect8 = 0;
		}
		if (recLength <= 780.0f) {
			showRect7 = 0;
		}
		if (recLength <= 650.0f) {
			showRect6 = 0;
		}
		if (recLength <= 520.0f) {
			showRect5 = 0;
		}
		if (recLength <= 390.0f) {
			showRect4 = 0;
		}
		if (recLength <= 260.0f) {
			showRect3 = 0;
		}
		if (recLength <= 130.0f) {
			showRect2 = 0;
		}
		if (recLength <= 0.0f) {
			showRect1 = 0;
		}

	}
	if (AreCirclesIntersecting(blueX, blueY, 50.0f, greenX, greenY, 200.0f))
	{
		if (recLength <= 1300.0f) {
			recLength += 5;
		}
		else {
			recLength += 0;
		}
		if (recLength >= 1170.0f) {
			showRect10 = 1;
		}
		if (recLength >= 1040.0f) {
			showRect9 = 1;
		}
		if (recLength >= 910.0f) {
			showRect8 = 1;
		}
		if (recLength >= 780.0f) {
			showRect7 = 1;
		}
		if (recLength >= 650.0f) {
			showRect6 = 1;
		}
		if (recLength >= 520.0f) {
			showRect5 = 1;
		}
		if (recLength >= 390.0f) {
			showRect4 = 1;
		}
		if (recLength >= 260.0f) {
			showRect3 = 1;
		}
		if (recLength >= 130.0f) {
			showRect2 = 1;
		}
		if (recLength >= 0.0f) {
			showRect1 = 1;
		}
	}
	if (CP_Input_KeyTriggered(KEY_Q)) {
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
	}
}

void Game_Exit(void)
{

}