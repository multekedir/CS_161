
/******************************************************
** Program: adventure.cpp
** Author: Multezem Kedir
** Date: 21 January 2018
** Description: A text adventure game.
** Input: libraries: iostream, string, ctime, cstdlib
** Output:
******************************************************/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Item{
	//an object to keep track of items
	string name;
	bool pickedItem;
}key, apple, pod;

struct Room{
	//an object to keep track of Rooms
	string name;
	string message;
	Item item;
	bool hasItem;
	Room* north; //room adjest in the north
	Room* south; //room adjest in the south
	Room* west;  //room adjest in the west
	Room* east;  // //room adjest in the east
}bedRooom,masterBedRoom, livingRoom,kitchen,dining,laundry,garage,porch,lHall,door,westBHall,eastBHall,wall;


//number of steps take by the user
int numOfStep = 0;

//function prototypes
void creatRooms();
string peek(Room, string);
bool doPodchallenge();
bool get(Item, Room);
Room go(string, Room);
bool isHungery();
bool checkRoomItem(Room);
bool getItems();
bool openDoor(Room);


int main() {


	int input;
	string direction, roomName;
	Room curent = door; //the first room

	creatRooms(); //set up rooms
	srand(time(NULL)); //seed the random number

	cout    << "**************** Welcome to the Adventure Game **********************" << endl
			<< "Your objective for this game is to find the key and leave the house!" << endl
			<< "Make sure you do this before getting hungry, food can be found in the kitchen" <<endl;


	cout   << "Your list of commands are"  << endl << "\t  0  \t go north"
										   << endl << "\t  1  \t go south"
										   << endl << "\t  2  \t go west"
										   << endl << "\t  3  \t go east"
										   << endl << "\t  4  \t to peek next room"
										   << endl << "\t  5  \t check items"
										   << endl << "\t  6  \t open door"
										   << endl << "\t  7  \t quit"<<endl;
	do{

		cout << "Current Location >> " + curent.name << endl;
		cout << "Enter Command >> ";
		cin >> input;

			switch(input){
				case 0:
					curent = go("north", curent);
					checkRoomItem(curent);
					break;
				case 1:
					curent = go("south", curent);
					checkRoomItem(curent);
					break;
				case 2:
					curent = go("west", curent);
					checkRoomItem(curent);
					break;
				case 3:
					curent = go("east", curent);
					checkRoomItem(curent);
					break;
				case 4:
					cout << "Which Direction >> ";
					cin >> direction;
					roomName = peek(curent,direction);
					cout << roomName << endl;
					break;
				case 5:
					getItems();
					break;
				case 6:
					openDoor(curent);
					break;
				case 7:
					go("east", curent);
					break;

			}



	}while((input != 7) && (isHungery() == false));
	cout << "Good by" <<endl;
}


void creatRooms(){

	/*********************************************************************
	** Function: creatRooms()
	** Description: Setup room adjacency(north,south,west,east), and
	** 				add items (key,apple, pod)
	** Parameters: none
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/

	//set up items
	key.name = "key";
	apple.name = "apple";
	pod.name = "pod";

	//	setup wall
	wall.message = "You hit a wall";
	wall.name = "wall";

	//	add rooms adjacent to livingRoom
	livingRoom.name = "Living Room";
	livingRoom.message = "You are in the"+ livingRoom.name;
	livingRoom.north = &porch;
	livingRoom.south = &lHall;
	livingRoom.west = &dining;
	livingRoom.east = &wall;

	//	add rooms adjacent to lHall
	lHall.name = "Hallway";
	lHall.message =  "You are in the Living Room Hallway";
	lHall.north = &livingRoom;
	lHall.south = &door;
	lHall.west = &laundry;
	lHall.east = &wall;

	//	add rooms adjacent to porch
	porch.name = "Porch";
	porch.message =  "You are on the porch";
	porch.south = &livingRoom;
	porch.north = &wall;
	porch.east = &wall;
	porch.west = &wall;
	porch.item = key;
	porch.hasItem = true;

	//	add rooms adjacent to dining Room
	dining.name = "Dining Room";
	dining.message = "You are in the Dining Room";
	dining.south = &kitchen;
	dining.east = &livingRoom;
	dining.north = &wall;
	dining.west = &wall;

	//	add rooms adjacent to kitchen
	kitchen.name = "Kitchen";
	kitchen.message = "You are in the Kitchen";
	kitchen.north = &dining;
	kitchen.south = &wall;
	kitchen.east = &wall;
	kitchen.west = &wall;
	kitchen.item = apple;
	kitchen.hasItem = true;

	//	add rooms adjacent to laundry
	laundry.name = "Laundry";
	laundry.message =  "You are in the Laundry";
	laundry.east = &lHall;
	laundry.west = &wall;
	laundry.south = &wall;
	laundry.north= &wall;
	laundry.item = pod;
	laundry.hasItem = true;

	//	add rooms adjacent to door
	door.name = "Entrance Hallway";
	door.message = "You are by the Entrance";
	door.north = &lHall;
	door.west = &garage;
	door.east = &westBHall;

	//	add rooms adjacent to westBHall
	westBHall.name = "Bed Room Hallway";
	westBHall.message = "You are in the bed room hallway";
	westBHall.north = &bedRooom;
	westBHall.west = &door;
	westBHall.east = &eastBHall;
	westBHall.south = &wall;

	//	add rooms adjacent to eastBHall
	eastBHall.name = "Bed Room Hallway";
	eastBHall.message = "You are in the bed room hallway";
	eastBHall.north = &masterBedRoom;
	eastBHall.west = &westBHall;
	eastBHall.east = &wall;
	eastBHall.south = &wall;

	//	add rooms adjacent to bedRooom
	bedRooom.name = "Bed Room One";
	bedRooom.message = "You are in the bed room 1";
	bedRooom.south = &westBHall;
	bedRooom.north = &wall;
	bedRooom.east= &wall;
	bedRooom.west= &wall;

	//	add rooms adjacent to masterBedRoom
	masterBedRoom.name = "Master Bed Room";
	masterBedRoom.message = "You are in the Master BedRoom";
	masterBedRoom.south = &eastBHall;
	masterBedRoom.north = &wall;
	masterBedRoom.east= &wall;
	masterBedRoom.west= &wall;

	//	add rooms adjacent to garage
	garage.name = "Garage";
	garage.message = "You are in garage";
	garage.east = &door;
	garage.south = &eastBHall;
	garage.north = &wall;
	garage.west= &wall;
}

bool checkRoomItem(Room curent){
	/*********************************************************************
	** Function: checkRoomItem
	** Description: Checks if a room has an item
	** Parameters: current: The current Room
	** Pre-Conditions:
	** Post-Conditions:
	** Retruns: True if Room has Item
	** Calls: get()
	*********************************************************************/
	string input;
	if(curent.hasItem){
		cout << "This room has " + curent.item.name << endl;
		cout << "Do you want to get it? yes(y) / no(n) >> ";
		cin >> input;
		if(input == "yes" || input == "y"){
			get(curent.item, curent);
			return true;
		}
	}
	return false;
}

bool doPodchallenge(){
	/*********************************************************************
		** Function: doPodchallenge
		** Description: Dose the tide pod challenge and
		**  			depending on a random number the
		**  			user might loose,
		** Parameters: none
		** Pre-Conditions:
		** Post-Conditions:
		** Retruns: True if the person is alive
		** Calls:
		*********************************************************************/
	int x;
	x = rand() %2; // get random number range from 0 to 2
	cout << x << endl;
	string input;
	cin >> input;
	if(input == "yes" || input == "y"){
		if(x == 1){
			cout << "Not a smart Choice but you Succeeded" << endl;
			return false;
		}else{
			cout << "You are not so lucky \n You died" << endl;
			exit(0);
			return false;
		}
	}else {
		cout << "Smart Choice" << endl;
		return true;
	}


	return false;
}
bool isHungery(){
	/*********************************************************************
	** Function: isHungery
	** Description: Checks if the person has take to many steps without eating
	** Parameters: none
	** Pre-Conditions:
	** Post-Conditions:
	** Retruns: true if the person is hungery
	** Calls:
	*********************************************************************/
	if((apple.pickedItem == false) && (numOfStep > 5)){
		cout << "You died out of Hunger " <<endl;
		return true;
	}
	return false;
}

bool getItems(){
	/*********************************************************************
	** Function: getItems
	** Description: Prints what item the person has
	** Parameters: none
	** Pre-Conditions:
	** Post-Conditions:
	** Retruns:
	** Calls:
	*********************************************************************/
	if(apple.pickedItem == true){
		cout << "You have eat an apple" <<endl;
	}
	if(pod.pickedItem == true){
		cout << "You have Tide pod" <<endl;
	}
	if(key.pickedItem == true){
		cout << "You have the Key" <<endl;
	}
	return true;
}
bool openDoor(Room curent){
	/*********************************************************************
	** Function: openDoor
	** Description: Checks if the person is in the right room and has the key
	** Parameters: curent: the current room
	** Pre-Conditions:
	** Post-Conditions:
	** Retruns: if the door can be opened and the has key
	** Calls:
	*********************************************************************/
	if(curent.name == door.name && key.pickedItem == true){
		cout << "YOU WON GOOD JOB" << endl;
		exit(0); //quit programm
		return true;
	}else{
		cout << "You don't the key or You are not by the door" << endl;
		return false;
	}
}

string peek(Room curent, string direction){
	/*********************************************************************
	** Function: peek
	** Description: checks the name of the adjecent room
	** Parameters: curent: the current room, direction (north, south, east, west)
	** Pre-Conditions:
	** Post-Conditions:
	** Retruns: name of the nxt room
	** Calls:
	*********************************************************************/
	string name = "Nothing";
	if (direction == "north"){
		name = curent.north->name;
	}else if (direction == "south"){
		name = curent.south->name;
	}else if (direction == "east"){
		name = curent.east->name;
	}else if (direction == "west"){
		name =curent.west->name;
	}
	return name;
}

bool get(Item item, Room curent){
	/*********************************************************************
	** Function: get
	** Description: picks up the the item in the room
	** Parameters: curent: the current room, item(key,apple, pod)
	** Pre-Conditions:
	** Post-Conditions:
	** Retruns: true if the picked up the item
	** Calls:doPodchallenge to start the the pod challenge game
	*********************************************************************/
	string input;
	if(item.name == key.name && curent.name == porch.name){
		cout << "You Picked up Key" << endl;
		key.pickedItem = true;
		return true;
	}else if(item.name == apple.name && curent.name == kitchen.name){
		cout << "You eat Apple" << endl;
		apple.pickedItem = true;
		return true;
	}else if(item.name == pod.name && curent.name == laundry.name){
		cout << "You Picked up Tide Pod" << endl << "Do you want to the Challenge? Yes(y)/ No(n)";
		pod.pickedItem = true;
		doPodchallenge();
		return true;
	}
	return false;
}

Room go(string direction, Room curent){
	/*********************************************************************
	** Function: go
	** Description: moves the user from one room to another
	** Parameters: curent: the current room, direction(north,south,west, east)
	** Pre-Conditions:
	** Post-Conditions:
	** Retruns: Room
	*********************************************************************/
	if ((direction == "north") && (curent.north->name != wall.name)){
		cout << "Going north" << endl;
		numOfStep++;
		return *curent.north;
	}else if ((direction == "south")&& (curent.south->name != wall.name) ){
		cout << "Going south" << endl;
		numOfStep++;
		return *curent.south;
	}else if ((direction == "east") && (curent.east->name != wall.name)){
		cout << "Going north" << endl;
		numOfStep++;
		return *curent.east;
	}else if ((direction == "west") && (curent.west->name != wall.name)){
		numOfStep++;
		return *curent.west;
	}else{
		cout << "There is no Door";
		return curent;
	}


}




