#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "../../raygui.h"
#include "math.h"

const int screenWidth = 400;
const int screenHeight = 400;

bool aIsActive = false;
bool bIsActive = false;
bool cIsActive = false;

float xvertex, yvertex, root1, root2, a, b, c;

char aChar[8];
char bChar[8];
char cChar[8];

char Root1Char[10];
char Root2Char[10];

char YVertexChar[10];
char XVertexChar[10];

void DrawCalc();
void UpdateCalc();

void CalculateRoots(float a, float b, float c, float& root1, float& root2);
void CalculateVertex(float a, float b, float& yvertex, float& xvertex);

int main(){
    InitWindow(screenWidth, screenHeight, "simple quad calc");
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        UpdateCalc();
        DrawCalc();
    }
}

void DrawCalc()
{
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawFPS(0, 0);
        DrawText("x^2", 270, 22, 18, RED);
        DrawText("x", 270, 62, 18, RED);
        DrawText("positive root", 270, 183, 18, RED);
        DrawText("negative root", 270, 224, 18, RED);
        DrawText("y vertex", 270, 263, 18, RED);
        DrawText("x vertex", 270, 304, 18, RED);
    EndDrawing();
}

void UpdateCalc()
{

    a = atof(aChar);
    b = atof(bChar);
    c = atof(cChar);
    
    Rectangle aRec = {143, 20, 120, 30};
    if(CheckCollisionPointRec(GetMousePosition(), aRec)){
        aIsActive = true;
        bIsActive = false;
        cIsActive = false;
    }

    Rectangle bRec = {143, 60, 120, 30};
    if(CheckCollisionPointRec(GetMousePosition(), bRec)){
        aIsActive = false;
        bIsActive = true;
        cIsActive = false;
    }

    Rectangle cRec = {143, 100, 120, 30};
    if(CheckCollisionPointRec(GetMousePosition(), cRec)){
        aIsActive = false;
        bIsActive = false;
        cIsActive = true;
    }

    GuiTextBox(aRec, aChar, 8, aIsActive);
    GuiTextBox(bRec, bChar, 8, bIsActive);
    GuiTextBox(cRec, cChar, 8, cIsActive);

    Rectangle CalculateRec = {130, 140, 150, 30};
    if(CheckCollisionPointRec(GetMousePosition(), CalculateRec)){
        aIsActive = false;
        bIsActive = false;
        cIsActive = false;
    }

    if(GuiButton(CalculateRec, "Calculate")){
        CalculateRoots(a, b, c, root1, root2);
        CalculateVertex(a, b, yvertex, xvertex);
        sprintf(Root1Char, "%f", root1);
        sprintf(Root2Char, "%f", root2);

        sprintf(XVertexChar, "%f", xvertex);
        sprintf(YVertexChar, "%f", yvertex);
    }

    Rectangle Root1Rec = {143, 180, 120, 30};
    GuiTextBox(Root1Rec, Root1Char, 10, false);
    Rectangle Root2Rec = {143, 220, 120, 30};
    GuiTextBox(Root2Rec, Root2Char, 10, false);

    Rectangle YVertexRec = {143, 260, 120, 30};
    GuiTextBox(YVertexRec, YVertexChar, 10, false);
    Rectangle XVertexRec = {143, 300, 120, 30};
    GuiTextBox(XVertexRec, XVertexChar, 10, false);
}

void CalculateRoots(float a, float b, float c, float &root1, float &root2)
{
    float discriminator = pow(b, 2) - 4*a*c;
    if(discriminator >= 0){
        root1 = (-b + sqrt(discriminator)) / 2*a;
        root2 = (-b - sqrt(discriminator)) / 2*a;
    }
}

void CalculateVertex(float a, float b, float &yvertex, float &xvertex)
{
    float discriminator = pow(b, 2) - 4*a*c;
    // if(discriminator >= 0){
    yvertex = -(discriminator) / 4*a;
    // }
    xvertex = -b/2*a;
}
