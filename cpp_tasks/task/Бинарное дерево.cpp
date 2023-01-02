#include <iostream>
/*
Должны быть реализованы методы:
добавления элементов в дерево,
удаления элементов из дерева,
вывод дерева на экран.
*/

using namespace std;


template <class T>
class Tree 
{
private:
	struct Node
	{
		T data;
		Node* left;
		Node* right;
	};
	Node* root;

	bool CheckNode(Node* root, T data_, bool & flag)
	{
		if (root->left != nullptr)
		{
			CheckNode(root->left, data_, flag);
		}

		if (root->data == data_)
		{
			flag = true;
		}

		if (root->right != nullptr)
		{
			CheckNode(root->right, data_, flag);
		}
		return flag;
	}

	void PrintNode(Node* root)
	{

		if (root != nullptr)
		{
			if (root->left != nullptr)
			{
				PrintNode(root->left);
			}
			cout << root->data << "  ";
			if (root->left != nullptr)
			{
				PrintNode(root->right);
			}
		}
	}

	Node* CreateNode(const T key)
	{
		Node* node = new Node;
		node->left = nullptr;
		node->right = nullptr;
		node->data = key;
		return node;
	}

	void InsertNode(Node* &root, const T key)
	{
		if (root == nullptr)
		{
			root = CreateNode(key);
			return;
		} 
		else
		{
			if (key < root->data) {
				InsertNode(root->left, key);
			}
			else if (key > root->data) {
				InsertNode(root->right, key);
			}
		}
	}

	void Destroy_tree(Node* root)
	{
		if (root != nullptr)
		{
			Destroy_tree(root->left);
			Destroy_tree(root->right);
			delete root;
		}
	}

	Node* RemoveElem(Node* root, T key)
	{
		if (root == nullptr) return root;
		if (root->data == key)
		{
			Node* tmp;
			if (root->right == nullptr)
				tmp = root->left;
			else {
				Node* ptr = root->right;
				if (ptr->left == nullptr) {
					ptr->left = root->left;
					tmp = ptr;
				}
				else {
					Node* pmin = ptr->left;
					while (pmin->left != nullptr) {
						ptr = pmin;
						pmin = ptr->left;
					}
					ptr->left = pmin->right;
					pmin->left = root->left;
					pmin->right = root->right;
					tmp = pmin;
				}
			}
			delete root;
			return tmp;
		}
		else if (key < root->data)
			root->left = RemoveElem(root->left, key);
		else
			root->right = RemoveElem(root->right, key);
		return root;
	}
public:
	Tree()
	{
		this->root = nullptr;
	}
	void Insert(const T key)
	{
		InsertNode(this->root, key);
	}
	void Print()
	{
		PrintNode(this->root);
		cout << endl;
	}

	void Check(const T key)
	{
		bool flag = false;
		if (CheckNode(this->root, key, flag)) cout << "Yeap!" << endl;
		else cout << "Nope!" << endl;
	}

	void Destroy()
	{
		Destroy_tree(this->root);
		this->root = nullptr;
	}

	void Delete(const T key)
	{
		this->root = RemoveElem(this->root, key);
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	Tree <int> b;
	cout << "Вставка элементов... " << endl;
	b.Insert(0);
	b.Insert(-2);
	b.Insert(4);
	b.Insert(-5);
	b.Insert(54);
	b.Insert(-45);
	b.Insert(1);
	cout << "Дерево: ";
	b.Print();
	cout << "Удаление -2 из дерева.." << endl;
	b.Delete(-2);
	cout << "Дерево: ";
	b.Print();
	cout << "Проверка на нахождение элемента в дереве.. " << endl << "0 : ";
	b.Check(0);
	cout << "-2 : ";
	b.Check(-2);

	return 0;
}
