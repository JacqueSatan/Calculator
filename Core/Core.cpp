#include "Core.h"
#include "Operations.h"
#include "Utils.h"

namespace Calculatrice::Core {
	std::vector<std::string> parse(std::string rawExpression)
	{
		// G�n�re une liste des nombres de 0 � 9, et l'alphabet
		std::vector<std::string> numbers, alphabet{};
		for (int i = 48; i < 58; i++)
			numbers.push_back(std::string(1, i));
		for (int i = 65; i < 123; i++)
			alphabet.push_back(std::string(1, i));
		numbers.push_back(".");

		std::vector<std::string> expression;
		std::string intermediaire;

		// Pour chaque caract�re de l'expression
		for (size_t i = 0; i < rawExpression.size(); i++)
		{
			// Caract�re actuel
			std::string currentChar = std::string(1, rawExpression[i]);
			// Si c'est le premier, ou si la valeur interm�diaire est vide
			if (i == 0 || intermediaire == "")
			{
				intermediaire += currentChar;
			}
			else {
				// Si le caract�re actuel est un d�limiteur
				bool isDelimiter = Calculatrice::Utils::vectorIncludes(Calculatrice::Utils::Constants::delimiters, currentChar);
				if (isDelimiter)
				{
					// On ajoute la valeur interm�diaire
					expression.push_back(intermediaire);
					// Et le d�limiteur actuel
					expression.push_back(currentChar);
					// Puis on vide la valeur interm�diaire
					intermediaire = "";
				}
				// Si le caract�re actuel ne fait pas partie des d�limiteurs
				else
				{
					// Si le caract�re actuel est une lettre
					bool isLetter = Calculatrice::Utils::vectorIncludes(alphabet, currentChar);
					if (isLetter)
					{
						// Si le caract�re pr�c�dent �tait aussi une lettre, on l'ajoute � la suite
						if (Calculatrice::Utils::vectorIncludes(alphabet, std::string(1, intermediaire.back())))
							intermediaire += currentChar;
						// Sinon, la valeur interm�diaire est ajout�e � l'expression
						else
						{
							expression.push_back(intermediaire);
							intermediaire = currentChar;
						}
					}
					// Idem si le caract�re actuel est un chiffre
					else
					{
						if (Calculatrice::Utils::vectorIncludes(numbers, std::string(1, intermediaire.back())))
							intermediaire += currentChar;
						else
						{
							expression.push_back(intermediaire);
							intermediaire = currentChar;
						}
					}
				}
			}
		}

		if (intermediaire != "")
			expression.push_back(intermediaire);

		return expression;
	}

	std::vector<std::string> serialize(std::string rawExpression)
	{
		// S�pare les nombres des symboles
		std::vector<std::string> expression = parse(rawExpression);
		// Supprime les �l�ments vides de l'expression
		while (Calculatrice::Utils::vectorIncludes(expression, ""))
			expression.erase(expression.begin() + Calculatrice::Utils::firstIndexInVector(expression, ""));

		// Remplacer la constante d'Euler (de la fonction exponentielle) par sa valeur
		while (Calculatrice::Utils::vectorIncludes(expression, "e"))
			expression[Calculatrice::Utils::firstIndexInVector(expression, "e")] = std::to_string(Calculatrice::Utils::Constants::euler);

		std::vector<std::string> numbers{"."};
		for (int i = 48; i < 58; i++)
			numbers.push_back(std::string(1, i));

		// Sert � respecter les lois de distributivit�.
		// Remplace toutes les soustractions par des additions du nombre oppos�.
		while (Calculatrice::Utils::vectorIncludes(expression, "-"))
		{
			int index = Calculatrice::Utils::firstIndexInVector(expression, "-");
			expression[index] = "+";
			
			// static_cast<size_t>(index) sert � considerer index comme une variable sur 8 octets plutot que 4.
			// Cela permet d'�viter des erreurs sur les tr�s (tr�s) grandes op�rations, et le compilateur
			//		consid�re �a comme une erreur.

			// Si - est devant une parenth�se
			if (expression[static_cast<size_t>(index) + 1] == "(")
			{
				// Si - est le premier caract�re de l'expression
				if (index == 0)
					expression.erase(expression.begin()); // Supprime le + ajout�
				expression.insert(expression.begin() + (index == 0 ? index : index + 1), { "-1", "*" });
			}
			// Si - est le premier caract�re de l'expression
			else if (index == 0)
			{
				expression.erase(expression.begin());
				expression[0] = "-" + expression[0];
			}
			// Si - est derri�re un signe
			else if (Calculatrice::Utils::vectorIncludes(Calculatrice::Utils::Constants::delimiters, expression[static_cast<size_t>(index) - 1]))
			{
				expression.erase(expression.begin() + index);
				expression[static_cast<size_t>(index)] = "-" + expression[static_cast<size_t>(index)];
			}
		}

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

			// Sert � respecter les lois de priorit�s de calcul.
			// Encadre de parenth�ses les op�rations qui se suivent.
			// Ces instructions ne sont pas situ�es dans la fonction de s�rialisation,
			// car les parenth�ses provoqueraient des bugs.
			deepestExpression = Calculatrice::Utils::frameAlignedOperations(deepestExpression, "^");
			deepestExpression = Calculatrice::Utils::frameAlignedOperations(deepestExpression, "rcn");
			deepestExpression = Calculatrice::Utils::frameAlignedOperations(deepestExpression, "*");
			deepestExpression = Calculatrice::Utils::frameAlignedOperations(deepestExpression, "/");

			// Supprime toutes les parenth�ses de l'expression la plus int�rieure
			for (auto& i : { "(", ")" })
				while (Calculatrice::Utils::vectorIncludes(deepestExpression, i))
					deepestExpression.erase(deepestExpression.begin() + Calculatrice::Utils::firstIndexInVector(deepestExpression, i));

			// Ajoute la premi�re partie de l'expression au vector de la nouvelle expression.
			std::copy(expression.begin(), expression.begin() + bounds[0], std::back_inserter(newExpression));
			// Ajoute l'expression la plus int�rieure � la nouvelle.
			newExpression.push_back(std::to_string(solve(deepestExpression)));
			// Ajoute la fin de l'expression
			std::copy(expression.begin() + bounds[1] + 1, expression.end(), std::back_inserter(newExpression));

			expression = newExpression;
		}

		if (expression.size() == 1) return std::stod(expression[0]);

		// R�soud l'op�ration des deux premiers membres de l'expression.
		double result = 0;
		if (expression[1] == "+") result = std::stod(expression[0]) + std::stod(expression[2]);
		else if (expression[1] == "*") result = std::stod(expression[0]) * std::stod(expression[2]);
		else if (expression[1] == "/") result = Calculatrice::Operations::division(std::stod(expression[0]), std::stod(expression[2]), 10);
		else if (expression[1] == "^") result = Calculatrice::Operations::exponentiation(std::stod(expression[0]), std::stod(expression[2]));
		else if (expression[1] == "rcn") result = Calculatrice::Operations::root(std::stod(expression[0]), std::stod(expression[2]));

		// Ajoute le r�sultat de la premi�re op�ration de l'expression et son reste � la nouvelle expression.
		std::vector<std::string> newExpression{ std::to_string(result) };
		std::copy(expression.begin() + 3, expression.end(), std::back_inserter(newExpression));

		// Fonctionne par r�cursivit�.
		return solve(newExpression);
	}
}