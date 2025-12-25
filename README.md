# Get Next Line

*Ce projet a été créé dans le cadre du cursus 42 par abnassir.*

## Description

**Get Next Line** est une fonction en C qui permet de lire un fichier ligne par ligne. À chaque appel de la fonction `get_next_line()`, elle retourne la prochaine ligne du fichier, y compris le caractère de nouvelle ligne `\n` s'il existe.

L'objectif principal de ce projet est de :
- Comprendre la gestion de la mémoire dynamique en C
- Apprendre à manipuler les file descriptors
- Gérer un buffer statique pour conserver les données entre les appels
- Optimiser la lecture de fichiers avec un buffer de taille variable

## Instructions

### Compilation

Pour compiler le projet avec votre programme de test :

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

**Note :** Vous pouvez changer la valeur de `BUFFER_SIZE` (ex: 1, 42, 1000, etc.)

### Utilisation

```c
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;
    
    fd = open("fichier.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### Fichiers du projet

- `get_next_line.c` : Fonction principale
- `get_next_line_utils.c` : Fonctions utilitaires (ft_strlen, ft_strchr, ft_strjoin, etc.)
- `get_next_line.h` : Header avec les prototypes et includes

## Algorithme

### Choix de l'algorithme

J'ai choisi un algorithme basé sur **l'accumulation progressive avec buffer statique**. Voici pourquoi :

**Principe :**
1. **Lecture et accumulation** : Lire le fichier par blocs de taille `BUFFER_SIZE` et accumuler dans une variable statique `tmp`
2. **Détection de fin de ligne** : Continuer à lire jusqu'à trouver un `\n` ou atteindre la fin du fichier
3. **Extraction** : Extraire la ligne jusqu'au `\n` inclus
4. **Sauvegarde du reste** : Garder le reste dans `tmp` pour le prochain appel

**Justification :**

✅ **Efficacité mémoire** : On ne lit que ce dont on a besoin, sans charger tout le fichier en mémoire

✅ **Flexibilité** : Fonctionne avec n'importe quelle taille de `BUFFER_SIZE`

✅ **Gestion de l'état** : La variable statique `tmp` permet de conserver les données entre les appels sans perdre d'informations

✅ **Robustesse** : Gère correctement les cas limites (EOF, lignes sans `\n`, fichiers vides, erreurs de lecture)

### Schéma de fonctionnement

```
Fichier: "Hello\nWorld\n"
BUFFER_SIZE = 3

Appel 1:
  Lecture: "Hel" → tmp = "Hel"
  Lecture: "lo\n" → tmp = "Hello\n"
  → Retourne "Hello\n", tmp = ""

Appel 2:
  Lecture: "Wor" → tmp = "Wor"
  Lecture: "ld\n" → tmp = "World\n"
  → Retourne "World\n", tmp = ""

Appel 3:
  Rien à lire (EOF)
  → Retourne NULL
```

### Gestion des cas particuliers

- **Fin de fichier sans `\n`** : Retourne la dernière ligne même sans `\n`
- **Lignes vides** : Retourne `\n` correctement
- **Erreurs de lecture** : Libère la mémoire et retourne NULL
- **File descriptor invalide** : Retourne NULL immédiatement

## Resources

### Documentation
- [man read](https://man7.org/linux/man-pages/man2/read.2.html) - Documentation de la fonction read()
- [man open](https://man7.org/linux/man-pages/man2/open.2.html) - Documentation des file descriptors
- [Static variables in C](https://www.geeksforgeeks.org/static-variables-in-c/)

### Tutoriels
- [42 Docs - Get Next Line](https://harm-smits.github.io/42docs/projects/get_next_line)
- [Understanding File I/O in C](https://www.tutorialspoint.com/cprogramming/c_file_io.htm)

### Utilisation de l'IA

L'IA (Claude) a été utilisée pour :
- **Debugging** : Identifier et corriger les erreurs de logique (segfault, memory leaks)
- **Compréhension** : Expliquer le fonctionnement des variables statiques et de la gestion mémoire
- **Optimisation** : Conseils sur la structure du code et l'organisation des fonctions
- **Documentation** : Aide à la rédaction de ce README

**Parties du code écrites par l'étudiant :**
- La logique principale de l'algorithme
- Les fonctions utilitaires (ft_strlen, ft_strchr, ft_strjoin, etc.)
- La structure générale du projet

**Parties assistées par l'IA :**
- Corrections des bugs (gestion de NULL, memory leaks)
- Amélioration de la gestion des cas limites
- Suggestions d'optimisation

---