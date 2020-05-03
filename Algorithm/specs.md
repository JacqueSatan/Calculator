# Langage ALG

## 1. Syntaxe

Inspir�e par Intel64.

```asm
; Ceci est un commentaire, la ligne commence par ;

; Assigner une valeur � une variable
set nom_de_variable valeur

; Afficher une variable ou le r�sultat d'une op�ration
display nom_de_variable_ou_valeur

; R�cup�rer un nombre depuis la console
get nom_de_variable

; Pour d�clarer une fonction, il suffit de marquer son nom, sans indentation
nom_de_la_fonction
; Le code ex�cut� par cette fonction doit �tre pr�c�d� d'une tabulation.
code � ex�ctuer
jump nom_de_la_fonction
```

## 2. Structure d'un programme

Un programme ALG doit forc�ment avoir une fonction nomm�e `main`.
Aucune instruction ne doit se situer en dehors d'une fonction.
Toutes les variables d�clar�es sont globales.

## 3. Instructions utilisables

| Nom de l'instruction 	| Arguments                      	| Description                                                           	|
|----------------------	|--------------------------------	|-----------------------------------------------------------------------	|
| display              	| `Valeur`                       	| Affiche la valeur donn�e.                                             	|
| displaytext           | `Texte � afficher`              | Affiche le texte donn�.                                                   |
| get                  	| `Nom de la variable`           	| Assigne une valeur r�cup�r�e depuis la console � une variable donn�e. 	|
| jump                 	| `Nom de la fonction`           	| Ex�cute le code appartenant � la fonction indiqu�e.                   	|
| pop                  	| `Variable`                     	| D�place la valeur situ�e en haut de la pile dans la variable donn�e.  	|
| push                 	| `Valeur`                       	| Place la valeur donn�e en haut de la pile.                            	|
| set                  	| `Nom de la variable`, `Valeur` 	| Assigne une valeur donn�e � une variable donn�e.                      	|