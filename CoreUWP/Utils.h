#pragma once

#include "pch.h"

namespace Calculatrice::Utils
{
	//	Retourne un vector constitu� de strings cr��s � partir d'une valeur string scind� en
	//	fonction de s�parateur(s). Cette fonction sera utilis�e pour s�parer les nombres des
	//	op�rateurs d'un calcul donn�.
	//
	//
	//	Params :
	//		string text					: String � scinder
	//		vector<string>	delimiters	: Liste de d�limiteurs
	std::vector<std::string> splitString(std::string text, std::vector<std::string> delimiters);

	//	Indique si un vector donn� contient ou non une certaine valeur.
	//
	//
	//	Params :
	//		vector<...> vector	: Vector � inspecter
	//		...	key				: Valeur � trouver
	template<class T>
	bool vectorIncludes(std::vector<T> vector, T key);

	//	Retourne l'index de la premi�re fois qu'une valeur appara�t dans un vector.
	//
	//
	//	Params :
	//		vector<...> vector	: Vector � inspecter
	//		... key				: Valeur � trouver
	template<class T>
	int firstIndexInVector(std::vector<T> vector, T key);

	//	Retourne une liste de tous les index d'une valeur dans un vector.
	//
	//
	//  Params :
	//		vector<string> vector	: Vector � inspecter
	//		string key				: Valeur � trouver
	std::vector<int> indexesInVector(std::vector<std::string> vector, std::string key);

	//	Permet d'encadrer des suites d'op�rations du m�me type entre parenth�ses.
	//		Exemple : 5+9*5*7 -> 5+(9*5*7)
	//
	//
	//	Params :
	//		vector<string> expression	: Expression � manipuler
	//		string operation			: Op�rations � encadrer
	std::vector<std::string> frameAlignedOperations(std::vector<std::string> expression, std::string operation);

	//	Retourne les index des parenth�ses ouvrantes et fermantes les plus int�rieures d'un expression.
	//
	//
	//  Params :
	//		vector<string> expression	: Expression � �valuer
	std::vector<int> findDeepestExpression(std::vector<std::string> exression);

	namespace Constants {
		//	D�limiteurs utilis�s pour s�rialiser les expressions.
		inline std::vector<std::string> delimiters = {
			"+", "-",
			"*", "/",
			"(", ")",
			"^",
			">", "<", "|", "\\", "&", "~",
		};

		//tex:
		//$$e=\frac{2+2}{\frac{2+3}{\frac{3+4}{\frac{4+5}{etc...}}}}$$
		inline double euler = 2.71828182845904523536028747135266249775724709369995957496696762772407663035354759457138217852516642742746;

		inline double pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480;
	}

	// Structure repr�sentant une erreur
	struct Error
	{
		std::string name;
		std::string description;
	};
}