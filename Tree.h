#pragma once
#include <iostream>


namespace  Reality
{
	template<typename T>
	class Tree
	{
	private:

		template<typename T>
		class Node
		{
		public:
			Node* _left;
			Node* _right;
			T _data;

			Node(T _data = T()) : _data(_data), _left(nullptr), _right(nullptr)
			{

			}

		};

		Node<T>* root;

	public:

		Tree();
		~Tree();

		void push_back(T _data);
		void push_back(T _data, Node<T>*  root);

		T Max();
		T Min();
		 

		T find(T target);
		T find(T target, Node<T>*  root);




	};

	template<typename T>
	Tree<T>::Tree() : root(nullptr)
	{

	}

	template<typename T>
	Tree<T>::~Tree()
	{

	}

	template<typename T>
	void Tree<T>::push_back(T _data)
	{
		if (root == nullptr) {

			root = new Node<T>(_data);
		}
		else {
			Node<T>* current = this->root;
			this->push_back(_data, current);
		}
	}




	template<typename T>
	void Tree<T>::push_back(T _data, Node<T>* current)
	{


		if (_data > current->_data) {
			if (current->_right != nullptr)
			{
				current = current->_right;

				this->push_back(_data, current);
			}
			current->_right = new Node<T>(_data);

		}
		else {
			if (current->_left != nullptr)
			{
				current = current->_left;

				this->push_back(_data, current);
			}
			current->_left = new Node<T>(_data);

		}

	}



	template<typename T>
	T Tree<T>::Max()
	{
		Node<T>* current = this->root;


		while (current->_right != nullptr) {
			current = current->_right;
		}
		return current->_data;
	}



	template<typename T>
	T Tree<T>::Min()
	{
		Node<T>* current = this->root;

		while (current->_left != nullptr) {
			current = current->_left;
		}
		return current->_data;
	}

	 

	template<typename T>
	T Tree<T>::find(T target)
	{
		Node<T>* current = this->root;

		if (target == current->_data) {

			return  T(current->_data);
		}
		else {
			if (target > current->_data) {
				if (current->_right != nullptr) {

					current = current->_right;
					this->find(target, current);
				}
				else {
					return NULL;
				}
			}
			else {
				if (current->_left != nullptr) {

					current = current->_left;
					this->find(target, current);
				}
				else {
					return NULL;
				}
			}
		}
	}

	template<typename T>
	T Tree<T>::find(T target, Node<T>*  current)
	{

		if (target == current->_data) {
			return T(current->_data);
		}
		else {
			if (target > current->_data) {
				if (current->_right != nullptr) {

					current = current->_right;
					this->find(target, current);
				}
				else {
					return NULL;
				}
			}
			else {
				if (current->_left != nullptr) {

					current = current->_left;
					this->find(target, current);
				}
				else {
					return NULL;
				}
			}
		}
	}


}