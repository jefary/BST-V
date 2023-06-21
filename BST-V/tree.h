class Node {
	public:
	char key;
	Node* left;
	Node* right;

	Node(char nKey) {
		key = nKey;
		left = nullptr;
		right = nullptr;
	}

	void set_key(char new_key) {
		key = new_key;
	}

	char get_key() const {
		return key;
	}

	void set_left(Node* new_left) {
		left = new_left;
	}

	Node *get_left() const {
		return left;
	}

	void set_right(Node* new_right) {
		right = new_right;
	}

	Node *get_right() const {
		return right;
	}

};

class BST {
	private:
		Node* root;
		int size;

	public:
		BST() {
			root = nullptr;
			size = 0;
		}

		void set_root(Node* new_root) {
			root = new_root;
		}

		Node* get_root() const {
			return root; 
		}

		void Insert(Node* node) {
			if (root == nullptr) {
				root = node;
			}
			else {
				Node* curr = root;
				while (curr) {
					if (node->key < curr->key) {
						if (curr->left == nullptr) {
							curr->left = node;
							curr = nullptr;
						}
						else {
							curr = curr->left;
						}
					}
					else {
						if (curr->right == nullptr) {
							curr->right = node;
							curr = nullptr;
						}
						else {
							curr = curr->right;
						}
					}
				}
			}
		}

		Node* Search(char nKey) {
			Node* curr = root;
			while (curr) {
				if (curr->key == nKey) {
					std::cout << "Found " << nKey << ". Retrace your steps to the entrance.\n";
					return curr;
				}
				else if (nKey < curr->key) {
					std::cout << "Take the left door at the " << curr->key << ".\n";
					curr = curr->left;
				}
				else {
					std::cout << "Take the right door at the " << curr->key << ".\n";
					curr = curr->right;
				}
			}
			return nullptr;
		}

		Node* Solvable_Search(char nKey) {
			Node* curr = root;
			while (curr) {
				if(curr->key == nKey) {
					return curr;
				}
				else if (nKey < curr->key) {
					curr = curr->left;
				}
				else {
					curr = curr->right;
				}
			}
			std::cout << "NOT SOLVABLE\n";
			exit(EXIT_FAILURE);
			return 0;
		}
};
