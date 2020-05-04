#pragma once

#include <string>
#include <vector>

#include "Manager.hpp"

namespace Calculatrice::Algorithm {
	// Enum�re toutes les instructions du langage
	enum class InstructionType
	{
		DISPLAY,
		DISPLAYTEXT,
		GET,
		JUMP,
		POP,
		PUSH,
		SET
	};

	// Est utilisable avec des op�rations sur les bits pour r�cup�rer facilement le r�sultat d'une comparaison
	enum ComparisonResult
	{
		EQUAL				= 0x1,
		DIFFERENT			= 0x2,
		GREATER				= 0x4,
		SMALLER				= 0x8,
	};

	// D�finition pour les classes Variable, Instruction et Function.
	class Algorithm;

	// Repr�sente une variable
	class Variable
	{
	public:
		inline Variable(std::string name, std::string value) : m_name(name), m_value(value) {}

		// Retourne le nom de la variable
		inline std::string name() { return m_name; }
		// Retourne la valeur de la variable
		inline std::string value() { return m_value; }
		// Modifie la valeur de la variable
		inline Variable* setValue(std::string newValue) { m_value = newValue; return this; }
		// Retourne le nom de la variable, sert au manager.
		std::string id() { return m_name; }
	private:
		std::string m_name;
		std::string m_value;
	};
	
	// Repr�sente une instruction
	class Instruction
	{
	public:
		Instruction(Algorithm& algorithm, InstructionType type, std::vector<std::string> args) : m_algorithm(algorithm), m_type(type), m_args(args) {}
		void execute();

		inline std::string id() { return ""; }
	private:
		// R�f�rence vers l'algorithme parent, permet d'acc�der au manager de variables.
		Algorithm& m_algorithm;
		InstructionType m_type;
		std::vector<std::string> m_args;
	};

	// Repr�sente une fonction
	class Function
	{
	public:
		inline Function(std::string name) : instructionManager(new Manager::Manager<Instruction>), m_name(name) {}
		Manager::Manager<Instruction>* instructionManager;
		void execute();

		std::string id() { return m_name; }
	private:
		std::string m_name;
	};
	
	class Algorithm
	{
	public:
		inline Algorithm() : variableManager(new Manager::Manager<Variable>), functionManager(new Manager::Manager<Function>), currentFunction(nullptr) {}

		void execute();

		Manager::Manager<Variable>* variableManager;
		Manager::Manager<Function>* functionManager;
		Function* currentFunction;

		std::string pop();
		Algorithm* push(std::string value);

		int compare(double first, double second);
	private:
		std::vector<std::string> m_stack;
		int lastComparison{};
	};


	Algorithm parseAlgorithm(std::string rawAlgorithm);
}