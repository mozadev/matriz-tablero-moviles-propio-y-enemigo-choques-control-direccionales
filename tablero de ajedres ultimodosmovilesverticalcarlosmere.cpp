#include "stdafx.h"
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include <Windows.h>
#include <iomanip>

#define n 15
#define m 15

using namespace std;
using namespace System;

int vida = 3;

int mapa1[n][m] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,3,0,0,0,0,0,0,0,0,0,0,0,2,1 },
	{ 1,0,0,0,0,1,1,1,1,1,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,0,0,0,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,1,1,1,1,1,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
};

void DibujarVida(int vida)
{

	Console::SetCursorPosition(70, 0);
	cout << "          ";
	Console::SetCursorPosition(70, 0);
	cout << "Vidas: ";
	for (int i = 0; i < vida; i++)
	{
		cout << char(64);
	}
}

void Perdiste()
{
	Console::Clear();
	Console::SetCursorPosition(35, 12);
	cout << "PERDISTE";
	_getch();
}


void AsignarMatriz(int *Nivel, int **Matriz)
{
	if (*Nivel == 1)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				Matriz[i][j] = mapa1[i][j];

}
void MuestraMapa(int **Matriz)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			Console::SetCursorPosition(j, i);
			Console::BackgroundColor = ConsoleColor::White;
			if (Matriz[i][j] == 0)
				cout << " ";
			if (Matriz[i][j] == 1)
			{
				Console::ForegroundColor = ConsoleColor::Black;
				cout << char(219);
			}
		}
}

void Juego(int **Matriz)

{
	int x, y;
	int dx, dy, vida;
	vida = 3;
	x = 2; y = 2;
	dx = dy = 0;

	int xE, yE, dyE;
	xE = 10; yE = 10; dyE = 1;
	char tecla;
	int xE2, yE2, dyE2;
	xE2 = 3; yE2 = 3; dyE2 = 1;
	
	DibujarVida(vida);
	while (1)
	{
		dx = dy = 0;
		Console::CursorVisible = false;
		Console::SetCursorPosition(xE, yE);
		cout << " ";
		Console::CursorVisible = false;
		Console::SetCursorPosition(xE2, yE2);
		cout << " ";
		if (kbhit())
		{
			Console::SetCursorPosition(x, y);
			cout << " ";
			tecla = getch();
			switch (tecla)
			{
			case 'W':
				dy = -1;
				break;
			case 'S':
				dy = 1;
				break;
			case 'D':
				dx = 1;
				break;
			case 'A':
				dx = -1;
				break;
			}
			x = x + dx;
			y = y + dy;
		}

		if (x == xE && y == yE)
		{
			vida--;
			if (vida == 0)
				Perdiste();
			DibujarVida(vida);
			x = 2; y = 2;
		}
		if (x == xE2 && y == yE2)
		{
			vida--;
			if (vida == 0)
				Perdiste();
			DibujarVida(vida);
			x = 2; y = 2;
		}

		Console::SetCursorPosition(x, y);
		cout << "*";


		if (yE + dyE >= 14 || yE + dyE <= 0)
			dyE = dyE*-1;
		yE += dyE;
		if (yE2 + dyE2 >= 14 || yE2 + dyE2 <= 0)
			dyE2 = dyE2*-1;
		yE2 += dyE2;

		Console::SetCursorPosition(xE, yE);
		cout << char(219);
		Sleep(100);

		Console::SetCursorPosition(xE2, yE2);
		cout << char(219);
		Sleep(100);

	}
	_getch();
	

}




int main()
{


	int **Matriz;
	int Nivel;
	Matriz = new int *[n];
	for (int i = 0; i < n; i++)
		Matriz[i] = new int[m];

	Nivel = 1;
	AsignarMatriz(&Nivel, Matriz);
	DibujarVida(vida);
	MuestraMapa(Matriz);
	Juego(Matriz);

	Nivel = 2;
	AsignarMatriz(&Nivel, Matriz);
	MuestraMapa(Matriz);
	Juego(Matriz);
	_getch;
}