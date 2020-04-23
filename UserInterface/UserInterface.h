#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace Calculatrice::UI {
	// Enumerateur de toutes les commandes
	enum class Commands
	{
		HELP,
		QUIT,
		SOLVE,
	};

	enum class Colors
	{
		GREEN = 10,
		CYAN = 11,
		RED = 12,
		YELLOW = 14,
		WHITE = 15
	};

	// Strucuture repr�sentant une commande entr�e par l'utilisateur
	struct Command
	{
		Commands command{};
		std::vector<std::string> args;
	};

	// Options de l'interface, pas encore impl�ment�es
	struct UserInterfaceOptions
	{

	};

	// Structure repr�sentant une erreur
	struct Error
	{
		std::string name;
		std::string description;
	};

	// Sert � �crire un texte de couleur
	void writeColor(std::string text, Colors color);

	// Interface utilisateur
	class UserInterface
	{
	public:
		UserInterface(UserInterfaceOptions options);

		// D�marrer l'interface dans une console
		void startConsole();

	private:
		// Execute une commande
		void handleCommand(Command command);
		// Demande � l'utilisateur d'entrer une commande
		Command listenCommand();
		UserInterfaceOptions m_options;
	};
}
