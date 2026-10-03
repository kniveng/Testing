#include "cprocessing.h"
#include "mainmenu.h"
#include "game.h"
#include "utils.h"

CP_Font myFont;

void Main_Menu_Init(void)
{
    myFont = CP_Font_Load("Assets/Exo2-Regular.ttf");
}

void Main_Menu_Update(void)
{
    CP_Graphics_ClearBackground(CP_Color_Create(128, 128, 128, 255));

    CP_Settings_Fill(CP_Color_Create(255, 125, 125, 255));
    CP_Graphics_DrawRect(800.0f, 250.0f, 300.0f, 200.0f);
    CP_Graphics_DrawRect(800.0f, 650.0f, 300.0f, 200.0f);

    CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
    CP_Settings_TextSize(70.0f);
    CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
    CP_Font_DrawText("Play", 800.0f, 250.0f);
    CP_Font_DrawText("Exit", 800.0f, 650.0f);

    if (CP_Input_MouseClicked())
    {
        float mouseX = CP_Input_GetMouseX();
        float mouseY = CP_Input_GetMouseY();

        if (IsAreaClicked(800.0f, 250.0f, 300.0f, 200.0f, mouseX, mouseY))
        {
            CP_Engine_SetNextGameState(Game_Init, Game_Update, Game_Exit);
        }

        if (IsAreaClicked(800.0f, 650.0f, 300.0f, 200.0f, mouseX, mouseY))
        {
            CP_Engine_Terminate();
        }
    }
}

void Main_Menu_Exit(void)
{

}