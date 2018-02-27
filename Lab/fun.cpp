string* reSize(string *param, int oldSize){
	/*********************************************************************
	** Function: reSize
	** Src: http://www.cplusplus.com/forum/general/11111/
	** Description: gets a array and gives it addtion size of 10 by coppying
	** Parameters: string data, vector number operators
	** Pre-Conditions: string not empty
	*********************************************************************/
  Debug("IN reSize");
  Debug("IN reSize *param " << param);
	int newSize = oldSize+10;
	string* newArr = new string[newSize];
	Debug("New Array on Heap");
  Debug("IN reSize *newArr " << newArr);
    for(int i=0; i< newSize; i++)
        newArr[i]= "/0";
	Debug("New Array Created");
	for(int i = 0; i < oldSize; i++)
        newArr[i] = param[i];
  Debug("IN reSize delete param" << param);
	delete[] param;
	Debug("reSize Done");
	return newArr;
}



bool checkSize(string **data, int &size,int count){
    Debug("In checkSize " << size << " " << count );
    Debug("IN checkSize **data " << *data);
	if(size == count){
	    *data = reSize(*data,size);
      Debug("IN checkSize new **data " << *data);
		  size +=10;
      Debug("Arr grown to size "<< size);
		return true;
	}
	return false;
}

string* pars(string data, char token, int &size) {
/*********************************************************************
** Function: pars
** Description: gets a string with  token and turns
**				it to a list of numbers and
** Parameters: string data, vector number operators
** Pre-Conditions: string not empty
*********************************************************************/
  Debug("IN Pars");
	string* parsArr = new string[size];
  Debug("IN Pars parsArr " << parsArr);
	int last = 0;
	int count = 0;
	string noSpace = rmSpace(data); // remove space
  Debug("Removed Space");
	for (int i = 0; i < noSpace.length(); i++) {
		if(noSpace[i] == token){
			checkSize(&parsArr, size, count);
      Debug("IN Pars parsArr " << parsArr);
			parsArr[count] = noSpace.substr(last, (i - last));
			last = i + 1; //rember the last position of delimiter
			count++;
		}

		if(i == noSpace.length()-1){
			parsArr[count] = noSpace.substr(last,(noSpace.length()-1));
		}

	}
	Debug("IN Pars parsArr fainal " << parsArr);
	return parsArr;

}
int main(int argc, char *argv[]) {
  /*
  vector <Player> players;
  string colour[4] = {"Blue", "Red", "Orange", "Yellow"};
  Debug("Creating Players");
  creatPlayers(colour, players,4);
  Debug("Created Players");
  //cout << players.at(3);
  */

  int size = 10;
  string* parsed = new string[size];
  Debug("IN Main parsed " << parsed);
  cout << size << endl;
  parsed = pars("h,g,h,g,h,g,h,g,h,g,h,g,h,g,h,g,h,g,",',', size);
  Debug("IN Main parsed fainal " << parsed);
  /*for (int i = 0; i < 10; i++) {
    cout << i << parsed[i];
  }*/

  Debug("IN Main parsed delete " << parsed);
  delete[] parsed;
	return 0;

}
