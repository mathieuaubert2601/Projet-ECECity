# Projet-ECECity

**Projet-ECECity** est un jeu de gestion et de simulation urbaine développé en langage C. Le joueur est invité à construire et gérer une ville, en assurant le développement de ses infrastructures, la gestion de ses ressources, et le bien-être de ses habitants. Ce projet met en œuvre des concepts avancés de programmation et d'organisation logicielle (modularité, gestion de ressources, interface graphique).

## Objectifs

- Développer un moteur de simulation urbaine en C
- Concevoir une interface utilisateur interactive
- Gérer les différentes composantes d’une ville : eau, électricité, bâtiments, population
- Mettre en œuvre des algorithmes de sauvegarde, de cycle de jeu et de progression

## Structure du projet

```
├── .idea/                  # Fichiers de configuration IDE
├── cmake-build-debug/      # Fichiers de build CMake
├── CMakeLists.txt          # Configuration du projet pour CMake
├── main.c                  # Point d'entrée du programme
├── header.h                # Définitions et prototypes communs
├── case.c                  # Gestion des cases et parcelles de la ville
├── construction.c          # Logique de construction des bâtiments
├── gestionEau.c            # Gestion de la ressource eau
├── gestionElec.c           # Gestion de la ressource électricité
├── gestionBouton.c         # Gestion de l'interface des boutons
├── gestion_cycles.c        # Gestion des cycles de jeu
├── interface.c             # Interface graphique et interaction utilisateur
├── map.c                   # Génération et gestion de la carte
├── niveau.c                # Système de niveaux et progression
├── sauvegarde.c            # Système de sauvegarde du jeu
├── MenuJeu.c               # Menu principal et navigation
├── init_allegro.c          # Initialisation de la librairie graphique Allegro
├── modificationTemps.c     # Gestion du temps et des événements
├── compterHabEauElec.c     # Compteur d’habitants, eau et électricité
├── pompier.c               # Gestion des interventions (ex : pompiers)
```

## Prérequis & Installation

- **CMake** (pour la compilation)
- **Compilateur C** (GCC recommandé)
- **Librairie Allegro** (pour l’interface graphique)

Pour compiler le projet :
```bash
mkdir build && cd build
cmake ..
make
```

## Utilisation

- Lancez l’exécutable généré après compilation.
- Suivez les instructions à l’écran pour débuter une partie, construire et gérer votre ville.
- Explorez les différentes fonctionnalités : ajout de bâtiments, gestion des ressources, sauvegarde de partie, etc.

---
