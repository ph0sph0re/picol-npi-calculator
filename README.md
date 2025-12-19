Voici une proposition de fichier `README.md` complet et professionnel pour ton projet C++.

---

# Évaluateur d'Expressions Arithmétiques (Infixe vers NPI)

Ce projet est une implémentation en **C++** d'un algorithme permettant de convertir une expression mathématique standard (notation infixée) en **Notation Polonaise Inverse (NPI)** (notation postfixée), puis d'en calculer le résultat.

## 🚀 Fonctionnalités

- **Conversion Infixe ⮕ NPI** : Utilise l'algorithme de la gare de triage (*Shunting-yard algorithm*).
- **Gestion des priorités** : Respecte l'ordre des opérations (multiplication/division avant addition/soustraction).
- **Gestion des parenthèses** : Supporte les expressions complexes avec parenthèses imbriquées.
- **Calculateur NPI** : Évalue le résultat final de l'expression convertie.
- **Nombres entiers** : Gère les nombres à plusieurs chiffres (ex: `10+200`).

## 🛠️ Fonctionnement technique

Le code est divisé en deux parties principales :

1.  **`infixeVersNPI`** :
    *   Parcourt l'expression caractère par caractère.
    *   Utilise une pile (`std::stack`) pour stocker temporairement les opérateurs et les parenthèses.
    *   Produit une chaîne de caractères où les opérateurs suivent leurs opérandes.

2.  **`calculNPI`** :
    *   Parcourt la chaîne NPI.
    *   Empile les nombres.
    *   Dès qu'un opérateur est rencontré, il dépile les deux derniers nombres, effectue l'opération, et réempile le résultat.

## 💻 Prérequis

- Un compilateur C++ (GCC, Clang, MSVC).
- Standard C++11 ou supérieur.

## 🔨 Compilation et Exécution

Pour compiler le programme, utilise la commande suivante dans ton terminal :

```bash
g++ -o evaluateur main.cpp
```

Pour lancer le programme :

```bash
./evaluateur
```

## 📝 Exemple d'utilisation

**Entrée :**
```text
Entrez une expression : 3 + (4 * 2) - 5
```

**Sortie :**
```text
Expression en NPI : 3 4 2 * + 5 - 
Resultat : 6
```

## ⚠️ Limitations actuelles

- Ne gère que les nombres entiers (`int`).
- Ne gère pas les nombres négatifs saisis directement (ex: `-5 + 2`).
- Ne gère pas les nombres à virgule (flottants).
- L'expression ne doit pas contenir de caractères spéciaux autres que `+ - * / ( )` et des chiffres.

---
*Projet réalisé à des fins pédagogiques sur les structures de données (Piles).*
