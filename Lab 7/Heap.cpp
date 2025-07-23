#include "Heap.h"


int Heap::bubbleUp(int childIndex) {
	if (childIndex == 0) {
		return;
	}
	int parentIndex = (childIndex - 1) / 2;
	if (vector.at(childIndex) > vector.at(parentIndex)) {
		int temp = vector.at(childIndex);
		vector.at(childIndex) = vector.at(parentIndex);
		vector.at(parentIndex) = temp;
		return bubbleUp(parentIndex);
	}
	else {
		return;
	}
}

int Heap::bubbleDown(int parentIndex) {
	int leftIndex = (parentIndex * 2) + 1;
	int rightIndex = (parentIndex * 2) + 2;
	int smallerIndex;

	int vectorEnd = vector.size() - 1;

	bool leftCheck;
	bool rightCheck;
	if (leftIndex > vectorEnd) {
		leftCheck = false;
	}
	if (rightIndex > vectorEnd) {
		rightCheck = false;
	}

	if (rightCheck == false && leftCheck == false) {
		return; //Ends
	}

	if (leftCheck == true || vector.at(leftIndex) <= vector.at(rightIndex)) {
		smallerIndex = leftIndex;
	} else {
		smallerIndex = rightIndex;
	}

	if (vector.at(smallerIndex) > vector.at(parentIndex)) {
		int temp = vector.at(smallerIndex);
		vector.at(smallerIndex) = vector.at(parentIndex);
		vector.at(parentIndex) = temp;
		return bubbleDown(smallerIndex);
	}
	else {
		return;
	}
}

int Heap::getRoot() {
	vector.at(0);
}


Heap::Heap(std::vector<int> inputVector) {
	vector = inputVector;
}

void Heap::insert(int val) {
	vector.push_back(val);
	bubbleUp(vector.back());
}

void Heap::remove() {
	int rootIndex = 0;
	int temp = vector.at(rootIndex);
	//Swap
	vector.at(rootIndex) = vector.at(vector.back());
	vector.at(vector.back()) = temp;
	//Remove last element
	vector.pop_back();
	//Bubble down
	bubbleDown(rootIndex);
}

void Heap::display() {
	std::cout << "Max-Heap: ";
	for (int i = 0; i < vector.size(); i++) {
		std::cout << vector.at(i) << ", ";
	}
	std::cout << std::endl;
}

void Heap::bulidHeapBU(std::vector<int> inputVector) {
	for (int i = 0; i < inputVector.size(); i++) {
		vector.push_back(inputVector.at(i));
	}
	int lastNode = (vector.size() / 2) - 1;
	for (int k = lastNode; k >= 0; k--) {
		bubbleDown(k);
	}
}

void Heap::bulidHeapTD(std::vector<int> inputVector) {
	for (int i = 0; i < inputVector.size(); i++) {
		insert(i);
	}

}

void Heap::heapSort() {
	Heap copyHeap(vector);
	int size = vector.size();
	std::cout << "Heap Sort: ";
	while (size != 0) {
		//Displays the root value, then removes it
		std::cout << copyHeap.getRoot() << ", ";
		copyHeap.remove();
		//Subtract from size
		--size;
	}
	std::cout << std::endl;
}