#include "Linklist.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Linklist::Linklist(){
	sentinel_ = new Node(-1);
	sentinel_->next_ = sentinel_;
	sentinel_->prev_ = sentinel_;
	sentinel_->shape_ = NULL;
}

//This method reverses the order of a doubly linked node,
//swapping the 'nextLink' and 'prevLink'
void Linklist::reverseOrder(){
	
	Node* current = this->sentinel_;

	do{//we must do the sentinel case first, this necessitates the do-while

		//swap prev and next fields on all Nodes.
		Node temp = *(current);

		current->next_ = temp.prev_;
		current->prev_ = temp.next_;

		//go to the next node, which we just made "previous"
		current = current->prev_;
	}while(current != this->sentinel_);

}

//The first shape that 'getNodeAt' finds should be brought
//to the top of the list.
void Linklist::bringToFront(int x, int y){

	Node* current = getNodeAt(x,y);
	if(current != NULL){
		this->removeNode(current);
		this->insertAfter(current,this->sentinel_);
	}
}

//This method inserts the "new_node" before the "target_node" in the linklist
void Linklist::insertBefore(Node* new_node, Node* target_node){

	new_node->next_ = target_node;
	new_node->prev_ = target_node->prev_;

	target_node->prev_ = new_node;
	(new_node->prev_)->next_ = new_node;

}

//This method inserts the "new_node" after the "target_node" in the linklist
void Linklist::insertAfter(Node* new_node, Node* target_node){

	new_node->next_ = target_node->next_;
	new_node->prev_ = target_node;

	target_node->next_ = new_node;
	(new_node->next_)->prev_ = new_node;

}


//This method removes a Node from our list and returns that Node.
Node* Linklist::removeNode(Node* target_node){

	//point the next Node and the previous Node to each other.

	(target_node->next_)->prev_ = target_node->prev_;
	(target_node->prev_)->next_ = target_node->next_;

	//make the target node's pointers null because it's no longer in a list.
	target_node->prev_ = NULL;
	target_node->next_ = NULL;

	return target_node;
}


void Linklist::draw(){

	Node* current = this->sentinel_->prev_;

	while(current != this->sentinel_){
		(current->shape_)->draw();
		
		current = current->prev_;
	}

}

//This method cycles through the linked list, looking for the first shape
//whose boundaries overlap with the given coordinates.
Node* Linklist::getNodeAt(int x, int y){

	Node* current = this->sentinel_->next_;

	while(current != this->sentinel_){

		//if the point is within the area of the shape return that node
		if((current->shape_)->isPointInArea(x, y))
			return current;

		//otherwise Nothing found, move to the next Node.
		current = current->next_;
	}

	//if no point was found, return null.
	return NULL;
}