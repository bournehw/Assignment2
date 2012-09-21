#include "Linklist.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Linklist::Linklist(){
	node* sentinel_;
	sentinel_->next = sentinel_;
	sentinel_->prev = sentinel_;
	sentinel_->shape = NULL;
}

//This method reverses the order of a doubly linked node,
//swapping the 'nextLink' and 'prevLink'
void Linklist::reverseOrder(){
	
	Linklist::node* current = this->sentinel_->next;

	while(current != this->sentinel_){
		//swap prev and next fields on all nodes.
		Linklist::node* temp = current;
		current->next = temp->prev;
		current->prev = temp->next;

		//go to the next node, which we just made "previous"
		current = current->prev;
	}

}

//This method cycles through the linked list, looking for a shape
//whose boundaries overlap with the given coordinates.
//The first shape that matches these parameters should be brought
//to the top of the list.
void Linklist::bringToFront(int x, int y){

	Linklist::node* current = this->sentinel_->next;

	while(current != this->sentinel_){

		//store the shape of the current node for ease of access
		MyShape* shape = current->shape;

		//if the point is within the area of the shape, bring it
		//to the front of the list and stop searching.
		if(shape->isPointInArea(x, y)){
			this->removeNode(current);
			this->insertAfter(current,this->sentinel_);
			break;
		}

		//Nothing found, move to the next node.
		current = current->next;

	}

}

//This method inserts the "new_link" before the "target_link" in the linklist
void Linklist::insertBefore(Linklist::node* new_link, Linklist::node* target_link){

	new_link->next = target_link;
	new_link->prev = target_link->prev;

	target_link->prev = new_link;
	(new_link->prev)->next = new_link;

}

//This method inserts the "new_link" after the "target_link" in the linklist
void Linklist::insertAfter(Linklist::node* new_link, Linklist::node* target_link){

	new_link->next = target_link->next;
	new_link->prev = target_link;

	target_link->next = new_link;
	(new_link->next)->prev = new_link;

}


//This method removes a node from our list and returns that node.
Linklist::node* Linklist::removeNode(Linklist::node* target_node){

	//point the next node and the previous node to each other.
	(target_node->next)->prev = target_node->prev;
	(target_node->prev)->next = target_node->next;

	//make the target node's pointers null because it's no longer in a list.
	target_node->prev = NULL;
	target_node->next = NULL;

	return target_node;
}


void Linklist::draw(){

	Linklist::node* current = this->sentinel_->next;

	while(current != this->sentinel_){
		(current->shape)->draw(); //NOTE: this line might be fucked up.
		
		current = current->next;
	}

}

