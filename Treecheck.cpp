// Treecheck.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

/* TASKS:

  1. Baum einlesen:
  - Integer-Schlüsselwerte einlesen und nach der Reihe binären Suchbaum erstellen
  - Doppelte Schlüsselwerte werden verworfen
  - für jeden Knoten den Balance-Faktor (BF) ausgeben
  - überprüfen ob Baum ein AVL-Baum ist
  - Wenn AVL-Bedingung in einem Knoten verletzt wird (BF > 1 oder < -1)
  - statistische Auswertung (min, max, avg der Schlüsselwerte) -> mittels Traversierung berechnen
  - Aufwandschätzung der Funktionen mittels O-Notation

  Info:
  - Programmaufruf soll so aussehen: treecheck filename
  - ein Key pro Zeile als Integer, beliebig viele Keys

  Balance-Faktor:
  - bal(k) = h(right subtree) - h(left subtree)
  - bei Verletzung der AVL-Bedingung -> bal(k) = x (AVL violation!)

  Ausgabe am Ende:
  AVL: yes/no
  min: x, max: y, avg: z

*/

#include <iostream>
#include <list>
#include <fstream>
#include "Node.h"
#include "Tree.h"

bool readFile(std::string path, Tree &tree);

int main(int argc, char* argv[]) {
	Tree tree;
	Tree subtree;
	if (argc >= 2) {
		if (readFile(argv[1], tree)) {
			if (tree.getSize() == 0) {
				std::cout << "Tree empty!";
				return -1;
			}
		}
		else {
			return -2;
		}
		if (argc == 2) {
			tree.print();
		}
		if (argc == 3) {
			if (readFile(argv[2], subtree)) {
				if (subtree.getSize() == 0) {
					std::cout << "Subtree empty!";
					return -3;
				}
				else {
					tree.search(subtree);
				}
			}
			else {
				return -4;
			}
		}
	}
	else {
		std::cout << "Please enter at least one path to a tree file." << std::endl;
	}
}

bool readFile(std::string path, Tree &tree) {
	std::string line;
	std::ifstream file (path);
	if (file.is_open()) {
		while (std::getline(file, line)) {
			tree.add(std::stoi(line));
		}
		file.close();
		return true;
	}
	else {
		std::cout << path << " not found." << std::endl;
	}
	return false;
}