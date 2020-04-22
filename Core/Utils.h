#pragma once

#include <string>
#include <vector>

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
	bool vectorIncludes(std::vector<int> vector, int key);
	bool vectorIncludes(std::vector<std::string> vector, std::string key);

	//	Retourne l'index de la premi�re fois qu'une valeur appara�t dans un vector.
	//
	//
	//	Params :
	//		vector<string> vector	: Vector � inspecter
	//		string key				: Valeur � trouver
	int firstIndexInVector(std::vector<std::string> vector, std::string key);

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
			"+", "-", "*", "/", "(", ")", "^"
		};
	}
}