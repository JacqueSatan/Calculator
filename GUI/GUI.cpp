#pragma once

#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <iostream>
#include <string>
#include <tchar.h>
#include <vector>
#include <Windows.h>

#include "GUI.h"

LRESULT WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		display = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			L"Edit",
			NULL,
			WS_CHILD | WS_VISIBLE | WS_TABSTOP,
			10, 10,
			180, 20,
			hWnd,
			NULL,
			(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
			NULL
		);

		for (size_t x = 0; x < buttonsText.size(); x++)
		{
			std::vector<const char*> row = buttonsText[x];
			for (size_t y = 0; y < row.size(); y++)
			{
				const char* button = row[y];
				HWND buttonWindow = CreateWindow(
					L"BUTTON",
					stringToTchar(button),
					WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
					10 + y * 45, 35 + x * 25,
					40, 20,
					hWnd,
					NULL,
					(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
					NULL
				);
				SendMessage(buttonWindow, WM_SETFONT, (LPARAM)GetStockObject(DEFAULT_GUI_FONT), true);
				if (std::strcmp(button, "C") == 0)
					buttons.Clear = buttonWindow;
				if (button == "(")
					buttons.OpenParenthese = buttonWindow;
				if (button == ")")
					buttons.CloseParenthese = buttonWindow;
				if (button == "AND")
					buttons.AND = buttonWindow;
				if (button == "NOT")
					buttons.NOT = buttonWindow;
				if (button == "<<")
					buttons.LeftShift = buttonWindow;
				if (button == ">>")
					buttons.RightShift = buttonWindow;
				if (button == "OR")
					buttons.OR = buttonWindow;
				if (button == "XOR")
					buttons.XOR = buttonWindow;
				if (button == "e")
					buttons.Euler = buttonWindow;
				if (button == "exp")
					buttons.Exponential = buttonWindow;
				if (button == "ln")
					buttons.NaturalLogartithm = buttonWindow;
				if (button == "log")
					buttons.Logarithm = buttonWindow;
				if (button == "rt")
					buttons.Root = buttonWindow;
				if (button == "sqrt")
					buttons.SquareRoot = buttonWindow;
				if (button == "cbrt")
					buttons.CubicRoot = buttonWindow;
				if (button == "^")
					buttons.Exponentiation = buttonWindow;
				if (button == "pi")
					buttons.Pi = buttonWindow;
				if (button == "0")
					buttons.zero = buttonWindow;
				if (button == "1")
					buttons.one = buttonWindow;
				if (button == "2")
					buttons.two = buttonWindow;
				if (button == "3")
					buttons.three = buttonWindow;
				if (button == "4")
					buttons.four = buttonWindow;
				if (button == "5")
					buttons.five = buttonWindow;
				if (button == "6")
					buttons.six = buttonWindow;
				if (button == "7")
					buttons.seven = buttonWindow;
				if (button == "8")
					buttons.eight = buttonWindow;
				if (button == "9")
					buttons.nine = buttonWindow;
				if (button == ".")
					buttons.Dot = buttonWindow;
				if (button == "*")
					buttons.Multiply = buttonWindow;
				if (button == "/")
					buttons.Divide = buttonWindow;
				if (button == "+")
					buttons.Add = buttonWindow;
				if (button == "-")
					buttons.Substract = buttonWindow;
				if (button == "=")
					buttons.Equal = buttonWindow;
				else
					MessageBox(hWnd, stringToTchar(button), L"ok", NULL);
			}
		}
		break;
	}
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		EndPaint(hWnd, &ps);
		break;
	}
	case WM_COMMAND:
	{
		if ((HWND)wParam == buttons.Clear)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.OpenParenthese)
			SetWindowText(display, L"(");
		if ((HWND)wParam == buttons.CloseParenthese)
			SetWindowText(display, L")");
		if ((HWND)wParam == buttons.AND)
			SetWindowText(display, L"AND");
		if ((HWND)wParam == buttons.NOT)
			SetWindowText(display, L"NOT");
		if ((HWND)wParam == buttons.LeftShift)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.RightShift)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.OR)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.XOR)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.Euler)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.Exponential)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.NaturalLogartithm)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.Logarithm)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.Root)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.SquareRoot)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.CubicRoot)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.Exponentiation)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.Pi)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.zero)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.one)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.two)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.three)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.four)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.five)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.six)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.seven)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.eight)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.nine)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.Dot)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.Multiply)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.Divide)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.Add)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.Substract)
			SetWindowText(display, L"");
		if ((HWND)wParam == buttons.Equal)
			SetWindowText(display, L"");
		else
			MessageBox(hWnd, L"non dsl lok", L"ereur", NULL);
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// Sp�cifie les param�tres de la fen�tre
	WNDCLASSEX wcex{
		sizeof(WNDCLASSEX),
		CS_HREDRAW | CS_VREDRAW,				// Style de la fen�tre. Permet de d�placer et de changer la taille de la fen�tre. https://docs.microsoft.com/en-us/windows/win32/winmsg/window-class-styles
		WndProc,								// Fonction appel�e lors de chaque �v�nement
		NULL,									// Octets � allouer en plus
		NULL,									// Idem, non n�cessaire
		hInstance,								// Instance de la fen�tre
		LoadIcon(hInstance, IDI_APPLICATION),	// Instance de l'ic�ne
		LoadCursor(NULL, IDC_ARROW),			// Instance du curseur
		(HBRUSH)(COLOR_WINDOW + 1),				// Sert � modifier la couleur du fond de la fen�tre
		NULL,									// Barre de menu par d�faut
		_T("MainWindow"),						// Nom de la classe de la fen�tre
		LoadIcon(hInstance, IDI_APPLICATION)
	};

	// Enregistre la structure cr��e aupr�s du syst�me d'exploitation
	if (!RegisterClassEx(&wcex))
	{
		// Affiche un message d'erreur si l'op�ration n'a pas r�ussi
		MessageBox(
			NULL,
			_T("La fen�tre n'a pas pu �tre enregistr�e."),
			_T("Erreur"),
			MB_ICONERROR
		);

		// Puis quitte l'application
		return 1;
	}

	HWND hWnd = CreateWindow(
		_T("MainWindow"),				// Nom de la classe de la fen�tre
		_T("Calculatrice"),				// Titre de la fen�tre
		WS_OVERLAPPEDWINDOW,			// Type de la fen�tre. Celui-ci regroupe les plus utilis�s
		CW_USEDEFAULT, CW_USEDEFAULT,	// Emplacement de la fen�tre
		4 * 45 + 40, 70 + 10 * 25,		// Taille de la fen�tre
		NULL,							// Parent
		NULL,							// Barre de menu
		hInstance,						// Instance de la fen�tre
		NULL
	);

	if (!hWnd)
	{
		MessageBox(
			NULL,
			_T("La fen�tre n'a pas pu �tre cr��e."),
			_T("Erreur"),
			MB_ICONERROR
		);

		return 1;
	}

	// Affiche la fen�tre
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// Attrape tous les �v�nements pour les traiter
	MSG msg;
	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

wchar_t* stringToTchar(const char* string)
{
	// https://docs.microsoft.com/en-us/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar
	int wcharSize = MultiByteToWideChar(
		CP_UTF8,		// Encodage
		NULL,			// Drapeaux, aucun utilis� ici
		string,	// Pointeur vers la string � convertir
		-1,				// -1 remplace la taille de la string, car elle se termine par le caract�re 0
		NULL,			// Premier appel, le wchar n'existe pas encore
		0);
	wchar_t* result = new wchar_t[wcharSize];
	MultiByteToWideChar(
		CP_UTF8,
		NULL,
		string,
		-1,
		result,
		wcharSize);
	return result;
}