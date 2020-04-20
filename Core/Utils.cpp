#include <algorithm>
#include <string>
#include <vector>

#include "Utils.h"

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
	//
	//
	//	Exemple d'utilisation :
	//		Pour transformer la valeur string :
	//			"(21+45)*98"
	//		En :
	//			{ "(", "21", "+", "45", ")", "*", "98" }		(Repr�sentation sous forme d'array)
	//
	//		On utilise :
	//			utils::splitString("(21+45)*98", vector<string>({"+", "*", "(", ")"}));
	//
	//
	//	Retourne :
	//		Vector constitu� de strings cr��s � partir d'un valeur string scind� en
	//		fonction de s�parateur(s).
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
		return std::count(vect.begin(), vect.end(), key);
	}

	//	Indique si un certain vecteur inclut un certain �l�ment.
	//
	//
	bool vectorIncludes(std::vector<std::string> vect, std::string key)
	{
		// Si vect contient key, la fonction renvoie true. Sinon, elle renvoie false.
		return std::count(vect.begin(), vect.end(), key);
	}

	int firstIndexInVector(std::vector<std::string> vect, std::string key)
	{
		int index = 0;
		for (auto& character : vect)
		{
			if (character == key)
				break;
			index++;
		}

		return index;
	}

	std::vector<int> indexesInVector(std::vector<std::string> vect, std::string key)
	{
		std::vector<int> result;

		while (Calculatrice::Utils::vectorIncludes(vect, key))
		{
			int index = firstIndexInVector(vect, key);
			result.push_back(index);
			vect[index] = "";
		}

		return result;
	}

	std::vector<int> findDeepestExpression(std::vector<std::string> expression)
	{
		std::vector<int> openParentheses = indexesInVector(expression, "(");
		std::vector<int> closedParentheses = indexesInVector(expression, ")");

		int openParenthese = openParentheses.back();
		int closedParenthese{};

		for (int i = closedParentheses.back(); i >= openParentheses.back() && i >= closedParentheses.front(); i--)
		{
			if (vectorIncludes(closedParentheses, i))
				closedParenthese = i;
		}

		return { openParenthese, closedParenthese };
	}
}