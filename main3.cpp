#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

string alphabets = "abcdefghijklmnopqrstuvwxyz";

struct HashTable{

	std::vector<char> key;
	std::vector<string> value;
	std::vector<string> status;
	
	char getkey(string value);
	int find(HashTable*, int, string);
	void print(HashTable*);

	HashTable* insertion(HashTable*, string);
	HashTable* deletion(HashTable*, string);
};

//function to get key as the last character of the hashvalue
char HashTable::getkey(string value){
    char key = value.at(value.length()-1);
    return key;
}    
//function to print the final table
void HashTable::print(HashTable* hashtable){
	if(hashtable!=NULL){
		for(unsigned int i=0; i<hashtable->key.size();i++){
			if(hashtable->status[i]=="occupied"){
				cout<<hashtable->value[i] << " ";
				
			}
		}
	}
	else{
	    cout<<"Empty";
	}
}    

//function to find the position of a slot
int HashTable::find(HashTable* hashtable, int i,string value){
	if(hashtable->status[i] == "empty"){ // if a slot is empty , return the position of the slot
	    return i;
		
	}
	else if(hashtable->status[i] != "empty" && hashtable->value[i]== value){ // if the slot if not empty, but it has the value already inserted, return -1
		return -1;
		
	}
	else{// check for the next slot , repeat until find en empty slot
		for(unsigned int j=i+1;j<hashtable->key.size();j++){
		    if(hashtable->status[j] == "empty"){ // if it find an empty slot, return the position
			    return j;
		    }
		    else if(hashtable->status[j] != "empty" && hashtable->value[j] == value){// if the value is already inserted ,retuen -1
			    return -1;
			
		    }
	    }
	    for (int j = 0; j < i; j++){
		    if(hashtable->status[j] == "empty" ){// if a slot is empty , return the position of the slot
			    return j;
		    }
		    else if(hashtable->status[j] != "empty" && hashtable->value[j] == value){// if the value is already inserted ,retuen -1
			   return -1;
			    
		    }		
	    }
    	return -1;
	    
	}
	
}
//function to add values from the table
HashTable* HashTable::insertion(HashTable* hashtable, string value){
	int search; 
	
	char key = getkey(value); // call fucntion to get key
	if(hashtable == NULL){ //check if hashtable is empty
		hashtable = new HashTable(); //create new hashtable
		for(unsigned int i=0; i<alphabets.size();i++){
			hashtable->key.push_back(alphabets[i]);
			hashtable->status.push_back("empty");
			hashtable->value.push_back(" ");
		}
	}
	for(unsigned int i=0;i< hashtable->key.size();i++){
	
		if(key == hashtable->key[i]){ //when we find the key , linear prob to insert values
			search = find(hashtable,i,value);
		}
		
	}
	if(search!=-1){ // if the value is already inserted ,change the status to occupied
		hashtable->value[search] = value;
		hashtable->status[search] = "occupied";
	}
	return hashtable;
}

//function to delete values from the table
HashTable* HashTable::deletion(HashTable* hashtable,string value){
    if(hashtable == NULL){ //check if hastable is empty
		return hashtable;
	}
	else{ 
	    for(unsigned int i=0; i<alphabets.size();i++){
		    if(hashtable->value[i]==value){ 
			    hashtable->value[i]=" ";
			    hashtable->status[i]="empty";
		    }
	    }    
	}
	return hashtable;
}




int main3(){
    
	std::vector<string> v;
	string moves;
	string value;
	
	HashTable* hashtable = NULL;

	int option=0;
	string input;                   
	getline(std::cin, input);       
	string word;   


	stringstream ss(input); //convert the input to a string stream
	while(ss>>word){               
	  v.push_back(word); //push into a vector.                    
	              
	}

	
	for(unsigned int i=0;i<v.size();i++){
		moves=v[i];
		value = moves.substr(1, moves.size()-1);
		//check the first character of the modification move to decide if it wants to add or delete
		if(moves[0]== 'A'){
		    option=1;
			
			
		}else if(moves[0]== 'D'){
		    option=2;
			
			
		}
		//switch case to choose between insertion or deletio 
		switch(option){
		    case 1:
		       hashtable = hashtable->insertion(hashtable,value);
		       break;
		    case 2:
		        hashtable = hashtable->deletion(hashtable,value);
		        break;
		}        
		
	}
	hashtable->print(hashtable); //print hastable
	
	
}
