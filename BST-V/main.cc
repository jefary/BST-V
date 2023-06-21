#include "/public/read.h"
#include <iostream>
#include <Bridges.h>
#include <BSTElement.h>
#include "tree.h"
using namespace bridges;
using namespace std;
/*
bool solvable(const string& nInput, const string& nKey) {
	unordered_set<char> inputChar;
	unordered_set<char> keyChar;

	for (char c : nInput) {
		inputChar.insert(c);
	}

	for (char c : nKey) {
		keyChar.insert(c);
	}

	if (inputChar == keyChar) {
		return true;
	}
	else {
		return false;
	}
}
*/

void make_bridges(string name) {

	Bridges bridges (732, "jefary", "1082731491246");

	bridges.setTitle("Dungeon Delve Part II");
	
	auto *root = new BSTElement<char, char>(name.at(0));
	root->setLabel(to_string(name.at(0)));

	for(int i = 1; i < name.size(); i++) {
		auto *new_guy = new BSTElement<char, char>(name.at(i));
		new_guy->setLabel(to_string(name.at(i)));
		auto *temp = root;
		while (temp) {
			if (new_guy->getKey() == temp->getKey()) {
				delete new_guy;
				break;
			}
			if (new_guy->getKey() < temp->getKey()) {
				if (!temp->getLeft()) {
					temp->setLeft(new_guy);
					break;
				}
				else { 
					temp = temp->getLeft();
				}
			}
			else {
				if (!temp->getRight()) {
					temp->setRight(new_guy);
					break;
				}
				else {
					temp = temp->getRight();
				}
			}
		}
	}

	
	
	bridges.setDataStructure(root);
	bridges.visualize();
	delete root;

}
int main() {
	BST tree;
	string input = read();
	//tree.Insert(new Node(c), input);
	//auto *root = new BSTElement<char, char>(input.at(0));
	///root->setLabel(to_string(input.at(0)));


	for (char c : input) {
		if (isalpha(c)) {
			//i++;
			//auto *new_guy = new BSTElement<char, char>(c);
			//new_guy->setLabel(to_string(c));
			tree.Insert(new Node(c));
		}
	}

	string key = read();

	for (char c : key) {
		if (isalpha(c)) {
			Node* temp = tree.Solvable_Search(c);
		}
	}
	
	for (char c : key) {
		if(isalpha(c)) {
			Node* temp = tree.Search(c);
		}
	}

	cout << "Exit the dungeon!\n";
	
	make_bridges(key);
//	bridges.setDataStructure(BSTtemp);
//	bridges.visualize();
//	delete root;	

	return 0;

}
