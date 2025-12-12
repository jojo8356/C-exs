# R101 Initiation au développement en C

> Dépôt de fichiers utiles pour la ressource R101 de l'IUT informatique de Nice.

## Mise en place de l'éditeur de code `VSCode`

Après avoir téléchargé le dépôt, ouvrir le dossier avec `VSCode` et installer les
extensions recommandées pour le
[développement C/C++](https://code.visualstudio.com/docs/languages/cpp).

## Organisation du travail

Pour chaque TD, créer un dossier (par ex. `td01`) et organiser votre code en
utilisant au minimum un fichier par exercice (par ex. `ex1.c`).

## Librairies incluses

Vous pouvez utiliser la touche `F5` pour compiler et exécuter les fichiers `c`.

Le fichier `tasks.json` crée les liens symboliques lors de la compilation vers
les librairies `ncurses` et `math` ainsi que toutes les librairies
utilisateurs du dossier `lib/`.

## Mises à jour des réglages

Si en cours de semestre vous avez besoin de remettre à jour les réglages de
`VSCode`, utilisez le script `update-settings.sh` depuis la racine du dépôt.

    wget -qO- https://framagit.org/benabel/r101-c/-/raw/main/update-settings.sh | sh

## Licences

Ce projet utilise deux licences libres pour son contenu.

* Le contenu écrit est sous licence
  [CC-BY-SA](https://creativecommons.org/licenses/by-sa/4.0/), voir le fichier
  [LICENCE-CONTENT](./LICENCE-CONTENT).
* Les programmes et exemples de code sont sous licence
  [unlicence](https://unlicense.org), voir le fichier
  [LICENCE](./LICENCE).
