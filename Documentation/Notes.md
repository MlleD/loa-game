## Notes et remarques sur le projet

Version 2
Date : 01/12/2019
Auteur : Dorothée Huynh

### 1. Jeu

### 2. Extensions du jeu

### 3. Architecture du code 

D'une manière générale, pour augmenter la robustesse du code face aux changements,
des "interfaces" sont utilisées.

#### Design Patterns, potentiellement utilisés 
- #### Adaptateur
But : encapsuler l'implémentation de certains types de données et la séparer de son utilisation
De cette manière, si on change d'implémentation, tout le code du programme qui utilise cette
implémentation ne sera pas à modifier également.

Exemples:

1. "Symbol" pour désigner le symbole de l'entité sur la case au lieu de char ou string

2. "Container" (ou un autre nom) pour encapsuler le conteneur des cases du plateau
Exemple d'utilisation : utiliser la classe vector de la bibliothèque standard de C++ dans un premier temps,
puis changer d'implémentation et utiliser à la place un type conteneur (le Container) qui serait codé à la main.

- #### Factory


### 4. Forme du code

- Snake case
- Indentation de 4 espaces