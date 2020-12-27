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

void Juego(int **Matriz, int vida)
{
	int X = 5, Y = 4;


	char Tecla;

	Console::SetCursorPosition(X, Y);
	Console::ForegroundColor = ConsoleColor::Black;
	Console::BackgroundColor = ConsoleColor::White;
	cout << "+";
	bool direccion = true;
	int xe = 1;
	int ye = 2;
	while (1)
	{
		while (!kbhit())
		{
			
			Console::SetCursorPosition(xe, ye);
			cout << char(215);
			Sleep(300);
			Console::SetCursorPosition(xe, ye);
			cout << " ";
			if (direccion == true)
				xe++;
			else
				xe--;
			if (Matriz[ye][xe] == 2)
				direccion = false;
			if (Matriz[ye][xe] == 3)
				direccion = true;
		}

		Tecla = _getch();
		Console::SetCursorPosition(X, Y);
		cout << " ";
		if (Tecla == 72) //arriba
		{
			Y--;
			if (Matriz[Y][X] == 1)
				Y++;
		}
		if (Tecla == 80) //abajo
		{
			Y++;
			if (Matriz[Y][X] == 1)
				Y--;
		}
		if (Tecla == 75) // izquierda
		{
			X--;
			if (Matriz[Y][X] == 1)
				X++;
		}
		if (Tecla == 77) //derecha
		{
			X++;
			if (Matriz[Y][X] == 1)
				X--;
		}
		if (X == 8 && Y == 8)
			break;
		Console::SetCursorPosition(X, Y);
		cout << "+";

		if (X == xe && Y == 2)
		{
			vida--;
			DibujarVida(vida);
			if (vida == 0)
				Perdiste();
			
		
		}
	}
}
int main()
{
	int vida = 3;

	int **Matriz;
	int Nivel;
	Matriz = new int *[n];
	for (int i = 0; i < n; i++)
		Matriz[i] = new int[m];

	Nivel = 1;
	AsignarMatriz(&Nivel, Matriz);
	DibujarVida(vida);
	MuestraMapa(Matriz);
	Juego(Matriz, vida);

	Nivel = 2;
	AsignarMatriz(&Nivel, Matriz);
	MuestraMapa(Matriz);
	Juego(Matriz, vida);
	_getch;
}