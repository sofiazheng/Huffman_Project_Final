#pragma once
#ifndef _HUFFMAN_TREE_H_
#define _HUFFMAN_TREE_H_

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <stack>
#include <unordered_set>
#include <queue>          
#include <vector>         
#include <functional>
#include <math.h>
using namespace std;

class huffman_tree {

public:
	struct Node {
		int freq;
		char letter;
		Node* left;
		Node* right;

	};
	struct compareFreq {
		bool operator()(Node const* temp1, Node const* temp2)const
		{
			return temp1->freq > temp2->freq;
		}
	};


	Node* makeHuffTree(std::vector<Node*>& treeNodes) const;
	void HuffTreeCodes(Node* root, std::string code, std::unordered_map<char, std::string >& table) const;
	bool isLeaf(Node* root) const;

	Node* root;
	std::unordered_map<char, std::string > encodedMap;

	huffman_tree(const std::string& file_name);

	~huffman_tree();

	std::string get_character_code(char character) const;
	std::string encode(const std::string& file_name) const;
	std::string decode(const std::string& string_to_decode) const;
};

#endif