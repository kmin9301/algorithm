/*********************************************
Project#01: Insertion Sort
Description: Given a file contains a list of English words, your tasks is to
construct a linked list (in ascending order) for the words.
Author: Kyeongmin Ha
Professor: Dr. Phillips		T.A: Joe Golden
*********************************************/
#include <iostream>
#include <fstream>

std::ifstream inFile;
std::ofstream outFile1;
std::ofstream outFile2;

class ListNode{
	friend class LinkedList;

	private:
		std::string data;
		ListNode *next;

	public:
		//default constructor
		ListNode(){};

		//constructor with @param data
		ListNode(std::string data){
			this->data = data;
		};

		//constructor with @param data, next
		ListNode(std::string data, ListNode *next){
			this->data = data;
			this->next = next;
		};
};

class LinkedList{
	private:
		ListNode *listHead;
		int index ;

	public:
		//constructor
		LinkedList(){
			listHead = new ListNode("DUMMY", NULL);
			index = 0;
		};

		/*****
		Method Name: listInsert(ListNode *spot, ListNode *node)
		Description: Let the @param node to be set next of @param spot
		ex) 1. spot -> spot.next
		2. node -> spot.next (= node.next)
		3. spot -> node
		result : spot -> node -> node.next
		*****/
		void listInsert(std::string data){
			ListNode *spot = listHead;

			if(!isEmpty()){
				while(spot->next != NULL && spot->next->data <= data){
					spot = spot->next;
				}
			}

			ListNode *newNode = new ListNode(data);
			newNode->next = spot->next;
			spot->next = newNode;
		};

		/*****
		Method Name: isEmpty()
		Description: Checks if the liked list has no node or not
		 returns true if there is no node
		 returns false if there is more than one node
		*****/
		bool isEmpty(){
			bool result = false;

			ListNode *spot = listHead;
			if(spot->next == NULL)result = true;

			return result;
		}


		/*****
		Method Name: printList()
		Description: Print the linked list on outFile2 with format followed by given instruction
		included small modification with brackets
		ex) dummy -> ... -> ( current->data : current->next->data ) -> ... ->NULL
		*****/
		void printList(){
			ListNode *spot = listHead;

			if(spot->next == NULL){
				outFile1 << "(" <<spot->data << " : NULL) -> NULL" ;
			}else{
				index ++;
				outFile1 << index << "|\t| (" << spot->data << " : " << spot->next->data << ") -> ";
			}

			while(spot->next->next != NULL){
				spot = spot -> next;
				outFile1 << "(" << spot->data << " : " << spot->next->data << ") --> ";
			}

			outFile1 << "(" << spot->next->data << " : NULL) -> (NULL) \n";
		};

		/*****
		Method Name: outFileTitle()
		Description: Write description of the outputFile in the beggining of the file
		*****/
		void outFileTitle(){
			outFile1 << "----------------------------------------------------\n<<PROJECT01 - Insertion Sort - OUTPUT2>>\n";
			outFile1 <<	"\tAUTHOR: KYEONGMIN HA \n\tDescription:\n\t print the linked list of sorted strings in\n\t ascending order";
			outFile1 << "\n----------------------------------------------------\n";
		}
};


int main(int argc, char** argv){
	inFile.open(argv[1]);
	outFile1.open(argv[2]);

	LinkedList * ll = new LinkedList();
	ll->outFileTitle();

	std::string data; //for getting input data

	while(inFile >> data){
		outFile1 << "INSERT:"<< data << "\n";
		ll->listInsert(data);		// insert the node in the corresponding spot
		ll->printList();		// print the list on the outFile2
	}

	inFile.close();
	outFile1.close();
}
