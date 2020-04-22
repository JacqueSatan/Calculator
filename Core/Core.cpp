#include "Core.h"
#include "Utils.h"

namespace Calculatrice::Core {
	std::vector<std::string> serialize(std::string rawExpression)
	{
		// S�pare les nombres des symboles
		std::vector<std::string> expression = Calculatrice::Utils::splitString(rawExpression, Calculatrice::Utils::Constants::delimiters);
		// Supprime les �l�ments vides de l'expression
		while (Calculatrice::Utils::vectorIncludes(expression, ""))
			expression.erase(expression.begin() + Calculatrice::Utils::firstIndexInVector(expression, ""));

		// Sert � respecter les lois de distributivit�.
		// Remplace toutes les soustractions par des additions du nombre oppos�.
		while (Calculatrice::Utils::vectorIncludes(expression, "-"))
		{
			int index = Calculatrice::Utils::firstIndexInVector(expression, "-");
			expression[index] = "+";
			// static_cast<size_t>(index) sert � considerer index comme une variable sur 8 octets plutot que 4.
			// Cela permet d'�viter des erreurs sur les tr�s (tr�s) grandes op�rations, et le compilateur
			//		consid�re �a comme une erreur.
			expression[static_cast<size_t>(index) + 1] = "-" + expression[static_cast<size_t>(index) + 1];
		}

		// Sert � respecter les lois de priorit�s de calcul.
		// Encadre de parenth�ses les op�rations qui se suivent.
		expression = Calculatrice::Utils::frameAlignedOperations(expression, "^");
		expression = Calculatrice::Utils::frameAlignedOperations(expression, "*");
		expression = Calculatrice::Utils::frameAlignedOperations(expression, "/");

		return expression;
	}

	double solve(std::string rawExpression) { return solve(serialize(rawExpression)); }

	double solve(std::vector<std::string> expression)
	{
		// Retourne l'expression si elle ne comporte plus qu'un seul membre.
		if (expression.size() == 1) return std::stod(expression[0]);

		// Calcule en premier les calculs entre parenth�ses.
		while (Calculatrice::Utils::vectorIncludes(expression, "("))
		{
			// Expression entre les parenth�ses les plus int�rieures.
			std::vector<std::string> deepestExpression{};
			// Nouvelle expression, dont l'expression la plus int�rieure � �t� r�solue.
			std::vector<std::string> newExpression{};
			// index des parenth�ses de l'expression la plus int�rieure.
			std::vector<int> bounds = Calculatrice::Utils::findDeepestExpression(expression);

			// Assigne l'expression la plus int�rieure � son vector.
			std::copy(expression.begin() + bounds[0] + 1, expression.begin() + bounds[1], std::back_inserter(deepestExpression));
			// Ajoute la premi�re partie de l'expression au vector de la nouvelle expression.
			std::copy(expression.begin(), expression.begin() + bounds[0], std::back_inserter(newExpression));
			// Ajoute l'expression la plus int�rieure � la nouvelle.
			newExpression.push_back(std::to_string(solve(deepestExpression)));
			// Ajoute la fin de l'expression
			std::copy(expression.begin() + bounds[1] + 1, expression.end(), std::back_inserter(newExpression));

			expression = newExpression;
		}

		// R�soud l'op�ration des deux premiers membres de l'expression.
		double result = 0;
		if (expression[1] == "+") result = std::stod(expression[0]) + std::stod(expression[2]);
		else if (expression[1] == "*") result = std::stod(expression[0]) * std::stod(expression[2]);
		else if (expression[1] == "/") result = std::stod(expression[0]) / std::stod(expression[2]);
		else if (expression[1] == "^") result = pow(std::stod(expression[0]), std::stod(expression[2]));

		// Ajoute le r�sultat de la premi�re op�ration de l'expression et son reste � la nouvelle expression.
		std::vector<std::string> newExpression{ std::to_string(result) };
		std::copy(expression.begin() + 3, expression.end(), std::back_inserter(newExpression));

		// Fonctionne par r�cursivit�.
		return solve(newExpression);
	}
}