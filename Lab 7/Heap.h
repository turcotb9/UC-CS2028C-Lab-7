#pragma once
#include <iostream>
#include <vector>


class Heap {
	//Class is a Heap Max
private:
	std::vector<int> vector;

	int bubbleUp(int childIndex);
	int bubbleDown(int rootIndex);

	int getRoot();

	Heap(std::vector<int> inputVector);
public:
	void insert(int val);
	void remove();
	void display();
	void bulidHeapBU(std::vector<int> inputVector);
	void bulidHeapTD(std::vector<int> inputVector);
	void heapSort();


};

