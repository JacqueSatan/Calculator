# Calculatrice

Interpréteur d'expressions algébriques et d'algorithmes. Supporte les lois de distributivité et de priorité de calcul.

Réalisée pour UWP.

# Langage ALG

## 1. Syntaxe

Inspirée par Intel64.

```asm
; Ceci est un commentaire, la ligne commence par ;

; Assigner une valeur à une variable
set nom_de_variable valeur

; Afficher une variable ou le résultat d'une opération
display nom_de_variable_ou_valeur

; Pour déclarer une fonction, il suffit de marquer son nom, sans indentation
nom_de_la_fonction
; Le code exécuté par cette fonction doit être précédé d'une tabulation.
code à exéctuer
; Exemple d'utilisation des arguments
set variableA 45
```

## 2. Structure d'un programme

Un programme ALG doit forcément avoir une fonction nommée `main`.

Aucune instruction ne doit se situer en dehors d'une fonction.

Toutes les variables déclarées sont globales.

Un algorithme ne doit contenir que des caractères anglais.

Une variable ne peut pas avoir de chiffre ni de ponctuation dans son nom.

## 3. Instructions utilisables

| Nom de l'instruction 	| Arguments                      	| Description                                                           	|
|----------------------	|--------------------------------	|-----------------------------------------------------------------------	|
| display              	| `Valeur`                       	| Affiche la valeur donnée.                                             	|
| displaytext           | `Texte à afficher`             | Affiche le texte donné.                                                    |
| set                  	| `Nom de la variable`, `Valeur` 	| Assigne une valeur donnée à une variable donnée.                      |
| compare               | `Première valeur`, `Seconde valeur` | Compare deux valeurs, et stocke le résultat dans l'interpréteur.    |
| jump                 	| `Nom de la fonction`           	| Exécute le code appartenant à la fonction indiquée.                   	|
| jumpeq               	| `Nom de la fonction`           	| Exécute le code appartenant à la fonction indiquée si la dernière comparaison indique que les comparés est == .                   	|
| jumpdi               	| `Nom de la fonction`           	| Exécute le code appartenant à la fonction indiquée si la dernière comparaison indique que les comparés est != .                   	|
| jumpgt               	| `Nom de la fonction`           	| Exécute le code appartenant à la fonction indiquée si la dernière comparaison indique que les comparés est > .                   	|
| jumplt               	| `Nom de la fonction`           	| Exécute le code appartenant à la fonction indiquée si la dernière comparaison indique que les comparés est < .                   	|
| jumpge               	| `Nom de la fonction`           	| Exécute le code appartenant à la fonction indiquée si la dernière comparaison indique que les comparés est >= .                   	|
| jumple               	| `Nom de la fonction`           	| Exécute le code appartenant à la fonction indiquée si la dernière comparaison indique que les comparés est <= .                   	|
| pop                  	| `Variable`                     	| Déplace la valeur située en haut de la pile dans la variable donnée.  	|
| push                 	| `Valeur`                       	| Place la valeur donnée en haut de la pile.                            	|
