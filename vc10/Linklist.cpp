#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Shape.h"
#include "Linklist.h"

using namespace ci;
using namespace ci::app;
using namespace std;

//This method reverses the order of a doubly linked node,
//swapping the 'nextLink' and 'prevLink'
void reverseOrder(Linklist* list){
	
	Linklist::node* current = list->sentinel_->next;

	while(current != list->sentinel_){
	Linklist::node* temp = current->next;
	current->next = current->prev;
	current->prev = current->next;

	//go to the next node, which we just made "previous"
	current = current->prev;
}


}