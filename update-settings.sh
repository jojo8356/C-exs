#!/bin/sh
# Licensed under the unlicense, see LICENSE file for details.
# Script to update VSCode settings from the repository.
# Must be run from the root of the r101-c repository.
# Usage: wget -qO- https://framagit.org/benabel/r101-c/-/raw/main/update-settings.sh | sh


if [ -d ".vscode" ]; then
    echo "Sauvegarde des réglages de vscode..."
    rm -rf .vscode.bak
    mv .vscode .vscode.bak
    mkdir .vscode
    echo "Mise à jour des réglages de vscode..."
else
    echo "Erreur : Le dossier .vscode n'existe pas. Ce script doit être lancé depuis la racine de votre dossier r101-c."
    exit 1
fi

# Download the settings files from the repository
for f in settings.json extensions.json c_cpp_properties.json tasks.json; do
    wget -qO .vscode/$f https://framagit.org/benabel/r101-c/-/raw/main/.vscode/$f
done

# Fichier .clang-format
wget -qO .clang-format https://framagit.org/benabel/r101-c/-/raw/main/.clang-format

echo "Réglages de vscode mis à jour avec succès."