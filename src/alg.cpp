// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::string war;
    BST<std::string> peace;
    std::ifstream file(filename);
    if (file) {
        while (!file.eof()) {
            char words = toolower(file.get());
            if (!alpha(words)) {
                if (!war.empty()) {
                    peace.add(war);
                }
                war.clear();
            } else {
                war += words;
            }
        }
    } else {
        std::cout << "Error file!" << std::endl;
    }
    file.close();
    return peace;
}
