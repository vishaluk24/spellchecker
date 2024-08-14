#pragma once
#include <vector>

// Class Declarations
class Trie;
class Node;
class illegal_exception;

/*
==========================
=== Class Definitions ===
==========================
*/
class Trie
{
public:
    Trie();
    ~Trie();
    bool insert(std::string word);
    void searchPrefix(std::string prefix);
    bool erase(std::string word);
    void runPrintWords();
    void printWords(Node *currNode, std::string prefix);
    void spellcheck(std::string word);
    void isEmpty();
    bool clear();
    void size();

private:
    Node *findNode(std::string word);
    void inOrderTraversalForPrefix(Node *currNode);
    void traversalForClear(Node *currNode, std::string prefix);
    Node *root;
    Node *currentNode;
    char currentCharacter;
    int countPrefixInstances;
    int numberOfWords;
    Node **nodesToErase;
    std::vector<std::string> allTheWords;
    std::string tempPrefix;
    std::string firstLetterOfWord;
};

class Node
{
public:
    ~Node();
    Node(char c);
    char getCharacter();
    bool isEndOfWord();
    int getNumberOfChildren();
    void setCharAsEndOfWord(bool lastLetter);
    void incrementNumberOfChildren();
    void decrementNumberOfChildren();
    void setCharacter(char c);

    Node **children;

private:
    char character;
    bool endOfWord;
    int numberOfChildren;
};

class illegal_exception : public std::exception
{
public:
    const char *what() const throw();
};