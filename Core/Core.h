#pragma once

#include <string>
#include <vector>

namespace Calculatrice::Core {
	std::vector<std::string> parse(std::string rawExpression);

	//	Cette fonction sert � g�nerer une liste de strings compr�hensible par le programme � partir d'une
	//		expression sous la forme d'une variable string.
	//	Elle s'occupe de placer des parenth�ses l� o� elles sont n�cessaires pour que les lois de priorit�s
	//		de calcul soient respect�es, et transforme aussi les soustraction en additions, pour respecter
	//		les lois de distributivit�.
	//
	//
	//	Params :
	//		string rawExpression	: Expression � s�rialiser
	//
	//
	//	Exemple d'utilisation :
	//		Pour s�rialiser "5+3-5*8*9"
	//		Calculatrice::Core::serialize("5+3-5*8*9");
	std::vector<std::string> serialize(std::string rawExpression);
	
	//	Surcharge de la fonction suivante. Permet de simplifier son utilisation.
	//
	//
	//	Params :
	//		string rawExpression	: Expression � r�soudre
	//
	//
	//	Exemple d'utilisation :
	//		Pour r�soudre 5+3*8*9
	//		Calculatrice::Core::solve("5+3*8*9");
	double solve(std::string rawExpression);

	//	Cette fonction sert � r�soudre une expression faite d'op�rations simples.
	//
	//
	//	Params :
	//		vector<string> expression	: Expression � r�soudre
	//
	//
	//	Exemple d'utilisation :
	//		Pour r�soudre 5+3*8*9
	//		Calculatrice::Core::solve(Calculatrice::Core::serialize("5+3*8*9"));
	double solve(std::vector<std::string> expression);
}