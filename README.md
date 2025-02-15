# Outil-de-Compression-Run-Length-Encoding-RLE-

Ce projet est une implémentation en langage C de l'algorithme de compression Run Length Encoding (RLE). Il permet de compresser des fichiers binaires en regroupant les séquences répétées pour réduire leur taille.

Fonctionnalités :
- Compression des fichiers binaires à l'aide de l'algorithme RLE.
- Gestion des erreurs : prise en charge des fichiers inexistants ou corrompus.
- Utilisation efficace de la mémoire pour traiter des fichiers de différentes tailles.

Structure du projet :
- main.c : Code principal qui contient les fonctions pour lire un fichier, effectuer la compression et sauvegarder le fichier compressé.
- README.md : Ce fichier, qui documente le projet.

Prérequis :
Pour exécuter le programme, vous aurez besoin d'un compilateur C (comme GCC) et d'un environnement de développement compatible.

Améliorations potentielles :
- Ajout d'une fonctionnalité de décompression pour reconstruire les fichiers originaux.
- Optimisation de l'utilisation de la mémoire pour les fichiers volumineux.
- Ajout d'une interface graphique ou d'une CLI plus conviviale.
- Intégration de tests automatisés pour garantir la fiabilité et la robustesse.

Applications possibles :
- Compression de journaux ou de fichiers texte avec des séquences répétitives.
- Réduction de la taille des fichiers bitmap pour économiser de l'espace.
- Prétraitement des données pour leur stockage ou transmission dans des systèmes embarqués.
- Démonstration éducative d'un algorithme de compression simple et efficace.

Note : 
L'algorithme RLE fonctionne mieux avec des données contenant des séquences répétées. Les fichiers sans répétition significative pourraient ne pas être compressés efficacement.
