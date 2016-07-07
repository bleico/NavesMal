#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

void gotoxy(int x, int y)
{
	handle_t hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD  dwPos;
	dwPos.X = 40;
	dwPos.Y = 15;
	SetConsoleCursorPosition(hCon, dwPos);

}

void OcultarCursor ()
{
	handle_t hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2;
	cci.bVisible = FALSE ;

	SetConsoleCursorInfo(hCon , &cci);
}

void pintar_limites()
{
	for (int i = 2 ; i<78; i++)
	{
		gotoxy(i,3);  printf ("%c",205);
		gotoxy(i,33); printf ("%c",205);
	}
	for (int i = 3 ; i<33 ;i++)
	{
		gotoxy(2,i);  printf ("%c",186);
		gotoxy(77,i); printf ("%c",186);
	}
	gotoxy(2,3); printf ("%c",201);
	gotoxy(2,33); printf ("%c",200);
	gotoxy(77,3); printf ("%c",187);
	gotoxy(77,33); printf ("%c",188);
}

class NAVE
{
	int x,y;
public:
	NAVE(int _x, int _y):x(_x),y(_y){}
	void pintar();
	void borrar();
	void mover();
};

void NAVE ::pintar()
{
	gotoxy(x,y);   printf("  %c",30);
	gotoxy(x,y+1); printf(" %c%c%c",40,207,41);
	gotoxy(x,y+2); printf("%c%c %c%c",30,190,190,30);
}

void NAVE::borrar()
{
	gotoxy(x,y);   printf("     ");
	gotoxy(x,y+1); printf("     ");
	gotoxy(x,y+2); printf("     ");
}

void NAVE::mover()
{
	if (kbhit())
		{
			char tecla = getch();
			borrar();
			if (tecla == IZQUIERDA)x--;
			if (tecla == DERECHA)x++;
			if (tecla == ARRIBA)y--;
			if (tecla == ABAJO)y++;
			pintar();
		}
}

int main()
{
	OcultarCursor ();
	pintar_limites();
	NAVE N (7,7);
	N.pintar();

	bool game_over = false;
	while (!game_over)
	{
		N.mover();
		Sleep(30);
	}

	return 0;

}
