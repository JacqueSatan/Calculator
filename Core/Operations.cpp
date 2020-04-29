#include <math.h>
#include "Utils.h"

namespace Calculatrice::Operations {
	double exponential(double number)
	{
		return pow(Calculatrice::Utils::Constants::euler, number);
	}

	double exponentiation(double firstMember, double secondMember)
	{
		//tex:
		//$$b = e^{\ln{b}}$$
		//$$b^x = e^{x\cdot \ln{b}}$$

		// Si le premier membre est n�gatif
		if (firstMember < 0)
			if (fmod(secondMember, 2) == 0) // Si l'exposant est pair
				return exponential(secondMember * log(-firstMember));
			else // Sinon
				return -exponential(secondMember * log(-firstMember));
		else
			return exp(secondMember * log(firstMember));
	}

	double division(double dividende, double divisor, int precision)
	{
		// Indique si le r�sultat est n�gatif
		bool negative = false;

		// Si le dividende est n�gatif, negative est invers�
		if (dividende < 0)
		{
			negative = !negative;
			dividende = -dividende;
		}
		// Si le diviseur est n�gatif, negative est invers�
		if (divisor < 0)
		{
			negative = !negative;
			divisor = -divisor;
		}

		// Est divis� par 10 � chaque it�ration, indique o� le r�sultat obtenu durant une de celles-ci doit �tre plac� dans le quotient
		long long position = 0;
		// R�sultat de la division
		double quotient{};
		// Reste de la division
		double reste = dividende;
		// S'ex�cute "precision" fois, indique le nombre de chiffres apr�s la virgule � calculer
		for (int iterations = 0; iterations <= precision && reste != 0; iterations++)
		{
			// Nombre par lequel on multiplie le diviseur pour obtenir le reste
			double i{};
			// Calcule la table de multiplication du diviseur pour trouver le r�sultat le plus �lev� qui soit inf�rieur ou �gal au dividende
			while (divisor * (i + 1) <= reste)
				i++;
			// On ajoute i au quotient, multipli� par sa position
			quotient += i * pow(10, -position++);
			// Le reste est calcul�
			reste -= (i * divisor);
			// Puis multipli� par 10
			reste *= 10;
		}

		return negative ? -quotient : quotient;
	}

	double root(double number, double root)
	{
		//tex:
		//$$\sqrt[n]{x}=x^{\frac{1}{n}}$$
		if (number < 0) throw(Calculatrice::Utils::Error{ "Erreur racine", "Le programme n'est pas encore capable d'utiliser cette fonction pour des nombres n�gatifs" });
		return exponentiation(number, 1. / root);
	}
}