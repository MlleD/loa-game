## TO DO List
Game Creator (gc) : appli de conception de plateaux de jeu
Game Player (gp) : jouer sur un ensemble de plateaux

### Liste des choses à faire
- Lorsqu'une tâche est faite, merci de bien vouloir le notifier dans ce document
- Tenir la liste à jour

#### Création de map
- Créer automatiquement une map
    - Taille du plateau de jeu (aléatoire, fixée à 5 x 5)
    - 1 seul monstre
    - 1 diamant et donc une porte
    - 1 chargeur
- Une map étant sous forme de fichier .board, il s'agit ici de remplir le fichier selon les choix utilisateurs
- Enregistrer les infos sur les nombres de chargeur, monstres, diamants

#### Gameplay
- Déplacement du personnage, à l'aide du clavier
- But du jeu : récupérer un max de trésors
- Automatisation des monstres
- Ajout de l'entité diam
- Ajout de l'entité chargeur
- Déroulement d'un tour de jeu : 
1. joueur : choix de l'action à faire : déplacement sur une autre case, rester sur place, se téléporter
1 bis : Interaction avec l'objet sur la case
2. monstre : choix (aléatoire ?, ia ?) de l'action à faire : déplacement sur une autre case, rester sur place, se téléporter


Création d'un jeu

Edition de map

### FAIT
#### Création de map
- Créer interactivement en ligne de commande une map. Demander les paramètres suivants à l'utilisateur : 
    - hauteur et largeur du plateau
    - nombre de monstres
    - nombre de diamants et donc de portes
    - nombre de chargeurs
- Ajout de l'entité joueur
- Ajout de l'entité monstre
