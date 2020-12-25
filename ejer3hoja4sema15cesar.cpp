#include "stdafx.h"
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include <Windows.h>
#include <iomanip>
using namespace std;
using namespace System;

#define n 15
#define m 15
using namespace std;
using namespace System;

int mapa1[n][m] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,3,0,0,0,0,0,0,0,0,0,0,0,2,1},
	{1,0,0,0,0,1,1,1,1,1,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,0,0,0,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,1,1,1,1,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};


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
	int X = 5, Y = 4;
	char Tecla;
	Console::SetCursorPosition(X, Y);
	Console::ForegroundColor = ConsoleColor::Black;
	Console::BackgroundColor = ConsoleColor::White;
	cout << "+";
	bool direccion = true;
	int j = 3;
	while (1)
	{
		while (!_kbhit())
		{

			Console::SetCursorPosition(j, 2);
			cout << char(215);
			Sleep(300);
			Console::SetCursorPosition(j, 2);
			cout << " ";
			if (direccion == true)
				j++;
			else
				j--;
			if (Matriz[2][j] == 2)
				direccion = false;
			if (Matriz[2][j] == 3)
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

	}
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
	MuestraMapa(Matriz);
	Juego(Matriz);

	Nivel = 2;
	AsignarMatriz(&Nivel, Matriz);
	MuestraMapa(Matriz);
	Juego(Matriz);
	_getch;
}