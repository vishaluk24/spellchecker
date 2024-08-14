#include <iostream>
#include <fstream>
#include <string>
#include "SpellChecker.hpp"

/*

ECE 250 - Project 3: Spell-Checking Using Trie ADT

Name:   Azizul Chowdhury
ID:     20893907
Email:  a48chowd@uwaterloo.ca

*/

int main()
{
    std::string command, word, prefix;
    Trie spellchecker;
    std::ifstream fin("corpus.txt");

    while (std::cin >> command)
    {
        if (command == "load")
        {
            while (fin >> word)
            {
                spellchecker.insert(word);
            }
            std::cout << "success\n";
        }

        else if (command == "i") // insert a word
        {
            std::cin >> word;

            try
            {
                if (spellchecker.insert(word))
                {
                    std::cout << "success\n";
                }
                else
                {
                    std::cout << "failure\n";
                }
            }
            catch (illegal_exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }

        else if (command == "c") // search for a prefix
        {
            std::cin >> prefix;

            try
            {
                spellchecker.searchPrefix(prefix);
            }
            catch (illegal_exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }

        else if (command == "e") // erase a word
        {
            std::cin >> word;

            try
            {
                if (spellchecker.erase(word))
                {
                    std::cout << "success\n";
                }
                else
                {
                    std::cout << "failure\n";
                }
            }
            catch (illegal_exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }

        else if (command == "p") // print all the words in the trie, alphabetically
        {
            spellchecker.runPrintWords();
        }

        else if (command == "spellcheck")
        {
            std::cin >> word;

            spellchecker.spellcheck(word);
        }

        else if (command == "empty") // check if trie is empty
        {
            spellchecker.isEmpty();
        }

        else if (command == "clear") // clear the trie
        {
            if (spellchecker.clear())
            {
                std::cout << "success\n";
            }
        }

        else if (command == "size") // prints number of words in trie
        {
            spellchecker.size();
        }

        else if (command == "exit")
        {
            return 0;
        }
    }

    return 0;
}