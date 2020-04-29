#pragma once

namespace Calculatrice::Operations {
	// Fonction exponentielle
	// exponential(5) correspond �
	//tex:
	//$$\exp{5}$$
	double exponential(double number);

	// Calculer une puissance d'un nombre
	// exponentiation(5, 10) correspond �
	//tex:
	//$$5^{10}$$
	double exponentiation(double firstMember, double secondMember);

	// R�soud une division comme une division euclidienne.
	// Cependant, la pr�cision des variables double en c++ font que le r�sultat est inexact
	// Le param�tre precision correspond au nombre de chiffres apr�s la virgule � calculer
	double division(double dividende, double divisor, int precision);

	// Calcule la racine d'un nombre
	double root(double number, double root);
}