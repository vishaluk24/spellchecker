# Spell-Checker Using Trie

## Overview
This project implements a spell-checker using a trie data structure. Users can supply words into the trie by loading a text file, or by manually inserting individual words. A given word can be "spell-checked" by comparing it with the words that are already in the trie. The program suggests similar words from the trie when the given word doesn't match any word in the trie.

This project was completed as part of the Winter 2023 offering of ECE 250: Algorithms and Data Structures at the University of Waterloo. 

## Getting Started
1. Clone this repository.
2. In the root directory, run `make` on a terminal to compile the program.
3. In the root directory, run `./a.out` to start the program.

## Usage
| Command | Parameters | Description |
| --- | --- | --- |
| load | | Loads all the words from `corpus.txt` into the trie. Duplicate words are not inserted. |
| i | word | Insert a new word into the trie. |
| c | prefix | Prints the number of words in the trie that have the given prefix. |
| e | word | Erase a word from the trie. |
| p | | Prints all words in the trie in alphabetical order on a single line (using depth-first traversal). |
| spellcheck | word | Spell-checks the word or offers suggestions if the word is not spelled correctly. As an example, if the trie had the words `DOUBT, DOUGH, DOUBLE` in it and you were to run `spellcheck DOG`, all the words in the trie starting with `DO` would be printed in alphabetical order. |
| empty | | Used to check whether the trie is empty. |
| clear | | Used to delete all the words in the trie. |
| size | | Outputs the number of words that are in the trie. |
| exit | | Terminates the program. |
