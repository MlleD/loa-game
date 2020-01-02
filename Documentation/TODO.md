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
- MapLoader pour charger/sauvegarder les fichiers .board
- GameLoader pour charger/sauvegarder les fichiers .game
- MapEditor :   -ouverture des fichier en parametre
                -creation/edition de fichier.game
- Map : modifier la generation de la map afin qu'elle ne mette que des mur sur les bordures de la map
- Renommage de GameStructure en StructureElement
- Gros changements concernant l'utilisation des new et destructeur.
- Optimisation des fuite mémoire
- Game Player (gp) :- ouverture des fichiers en argument
                    - fonction membre pour map : move(x,y,Position)
                    - fonctions membre pour Creature : wich_position(x,y,vector<Position>)
                                                        move_to(Position)
                    - boucle de jeu
- Modifier la structure des fichiers .board, MapLoader, Map afin de dissocier les GameElement en Creature, StuctureElement et InteractiveElement

- Améliorer l'affichage de la map
                    

## TO DO List
- Ajout des classes Teleporter et Diamonds
- Game Creator (gc) : - boucle interactive pour modifier une map
- Game Player (gp) :- créer un ordre pour les tours de jeu
- Améliorer le Makefile
- Player wich_move() :- Implémenter le tour du joueur
- Monster wich_move() : ne pas manger les autres monstres sur son passage
- Ajouter un nouveau type de monstre
- Game : Ajouter un membre string file_path
- Ajouter un membre static const symbole pour le caractère des GameElement
