#include <algorithm>
#include <string>
#include <vector>

#include "Utils.h"

namespace Calculatrice::Utils
{
	std::vector<std::string> splitString(std::string text, std::vector<std::string> delimiters)
	{
		//d�finition des objets utilis�s par la fonction
		std::vector<std::string> final;   //Variable retourn�e
		std::string intermediaire;   //<variable permettant de stocker plusieurs caract�res, comme un
								//nombre par exemple.

	 // Boucle �xecut�e pour chacun des caract�res du texte � scinder
		for (size_t i = 0; i < text.length(); i++)
		{
			// D�finition de variables utilis�es par la fonction
			char token(text[i]);		// Caract�re indiqu� par la boucle
			bool isDelimiter(false);	// Indique si le caract�re actuel est un d�limiteur

			// Execute le code suivant si le caract�re actuel n'a pas encore �t� d�fini comme
			// d�limiteur
			if (!isDelimiter)
			{// Boucle �x�cut�e pour chacun des d�limiteurs
				for (size_t o = 0; o < delimiters.size(); o++)
				{
					// D�finition du d�limiteur actuel
					std::string delimiter = delimiters[o];

					// Si le caract�re actuel fait partie des d�limiteurs, alors il est d�fini
					// comme tel.
					if (Calculatrice::Utils::vectorIncludes(delimiters, std::string(1, token)))
						isDelimiter = true;
				}
			}

			// Ajoute le caract�re actuel � la variable interm�diaire si il n'a pas �t� d�fini
			// comme un d�limiteur dans la boucle pr�c�dente
			if (!isDelimiter)
				intermediaire += token;
			// Sinon, la variable interm�diaire est transf�r�e � la fin de la variable finale,
			// tout comme le d�limiteur
			else
			{
				final.push_back(intermediaire);
				final.push_back(std::string(1, token));
				intermediaire = "";
			}
		}

		// La derni�re valeur interm�diaire est ajout�e la variable finale
		final.push_back(intermediaire);

		//Retourne le r�sultat final
		return final;
	}

	bool vectorIncludes(std::vector<int> vect, int key)
	{
		// Si le vector contient au moins une fois key, alors la fonction retournera true.
		return std::count(vect.begin(), vect.end(), key);
	}

	bool vectorIncludes(std::vector<std::string> vect, std::string key)
	{
		return std::count(vect.begin(), vect.end(), key);
	}

	int firstIndexInVector(std::vector<std::string> vect, std::string key)
	{
		// Index par d�faut.
		int index = 0;
		// S'ex�cute sur chaque �l�ment du vector.
		for (auto& character : vect)
		{
			// Si la cl� est correspondante au caract�re actuel, alors on sort de la boucle.
			if (character == key)
				break;
			// Sinon, index est incr�ment�.
			index++;
		}

		return index;
	}

	std::vector<int> indexesInVector(std::vector<std::string> vect, std::string key)
	{
		// Vector contenant tous les index.
		std::vector<int> result;

		// S'ex�cute tant que le vector contient la cl�
		while (Calculatrice::Utils::vectorIncludes(vect, key))
		{
			// Ajoute le premier index � la liste
			int index = firstIndexInVector(vect, key);
			result.push_back(index);
			// Puis le supprime du vector
			vect[index] = "";
		}

		return result;
	}

	std::vector<std::string> frameAlignedOperations(std::vector<std::string> expression, std::string operation)
	{
		// Contient tous les index de l'op�rateur en question
		std::vector<int> indexes = indexesInVector(expression, operation);
		
		// S'ex�cute pour chaque op�rateur
		for (int i = 0; i < indexes.size(); i++)
		{
			indexes = indexesInVector(expression, operation);
			int index = indexes[i];
			// Si c'est le premier op�rateur
			if (i == 0)
				expression.insert(expression.begin() + index - 1, "(");
			// Si celui le pr�c�dant �tait diff�rent
			else if (expression[static_cast<size_t>(index) - 2] != operation)
				expression.insert(expression.begin() + index - 1, "(");

			// Mise � jour des index, car ils peuvent avoir �t� modifi�s juste au dessus.
			indexes = indexesInVector(expression, operation);
			index = indexes[i];
			// Si c'est le dernier op�rateur
			if (i == indexes.size() - 1)
				expression.insert(expression.begin() + index + 2, ")");
			// Si le suivant est diff�rent
			else if (expression[static_cast<size_t>(index) + 2] != operation)
					expression.insert(expression.begin() + index + 2, ")");
		}

		return expression;
	}

	std::vector<int> findDeepestExpression(std::vector<std::string> expression)
	{
		std::vector<int> openParentheses = indexesInVector(expression, "(");
		std::vector<int> closedParentheses = indexesInVector(expression, ")");

		// La derni�re parenth�se ouverte est forc�ment la plus int�rieure.
		int openParenthese = openParentheses.back();
		int closedParenthese{};

		// S'ex�cute sur tous les caract�res de l'expression en partant de la gauche, jusqu'� la derni�re parenth�se ouverte.
		for (int i = closedParentheses.back(); i >= openParenthese && i >= closedParentheses.front(); i--)
		{
			// Si le le caract�re est une parenth�se fermante, alors closedParenthese est assign� � son index.
			if (vectorIncludes(closedParentheses, i))
				closedParenthese = i;
		}

		return { openParenthese, closedParenthese };
	}
}