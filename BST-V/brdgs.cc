#include "/public/read.h"
#include <Bridges.h>
#include <BSTElement.h>
using namespace std;
using namespace bridges;

int main(int argc, char **argv) {
	Bridges bridges (763, "jefary", "1082731491246");

	//set title
	bridges.setTitle("DDP2");
	bridges.setDescription("Yerrr BST bby!");

	string name = read("Enter name: \n");
	if (name.length() < 1) {
		cout << "Error. Retry again!\n";
		exit(1);
	}

	auto *root = new BSTElement<char, char>(name.at(0));
	root->setLabel(to_string(name.at(0)));

	for (int i = 1; i < name.size(); i++) {
		auto *new_guy = new BSTElement<char, char>(name.at(i));
		new_guy->setLabel(to_string(name.at(i)));
		auto *temp = root;
		while (temp) {
			if (new_guy->getKey() == temp->getKey()) {
				delete new_guy;
				break;
			}
			if (new_guy->getKey() < temp->getKey()) {
				if(!temp->getLeft()) {
					temp->setLeft(new_guy);
					break;
				}
				else {
					temp = temp->getLeft();
				}
			}
			else {
				if(!temp->getRight()) {
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
