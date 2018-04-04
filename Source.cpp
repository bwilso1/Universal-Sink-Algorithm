/*	Name:	Brian Wilson
	Date:	4/3/18
	Class:	CS 441
	Purpose:
		My trial of code to help with HW problem #3.  Code was not required, but I prefer actual code to pseudo code.

	Problem:
		Most graph algorithms that take an adjacency-matrix representation as input require
		time Om(V^2) but there are some exceptions. Show how to determine whether
		a directed graph G contains a universal sink—a vertex with in-degree |V| - 1 and
		out-degree 0, in time O(V), given an adjacency matrix for G.

	Def:
		A universal sink exists in an adjacency matrix at Vertex  C if  row C is all 0's and col C is all 1's except for graph[c][c].

		graph
		  |1  2  C  4
		1 |-  -  1  -
		2 |-  -  1  -
		C |0  0  0  0
		4 |-  -  1  -

	Supplemental Files:
		1-7.txt are sample files to test algorithm below.  Results should be
		1.txt	True
		2.txt	True
		3.txt	True
		4.txt	True
		5.txt	False
		6.txt	False
		7.txt	False
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int const verts = 4;
int graph[verts][verts];
void readFromFile(std::string input);
void printGraph();

int main() {

	memset(graph, 0, sizeof(graph));


	std::string filename;
	std::string list[] = { "1.txt", "2.txt", "3.txt", "4.txt", "5.txt", "6.txt", "7.txt" };

	
	int i = 0;
	int j = 0;
	int count = 0;
	bool sinkExists = false;
	for (int file = 0; file < 7; file++){
		i = 0;
		j = 0;
		count = 0;
		sinkExists = false;
		readFromFile(list[file]);
		std::cout << "\n---------------------\n\nFile: " << list[file] << "\n";
		printGraph();
		while (i != verts && j != verts){
			if (graph[i][j] == 0){
				j++; //go right
			}
			else if (graph[i][j] == 1){
				i++; //go down
			}
			count++;
		}//end while

		//now 'i' should be index of universal sink, lets test
		
		//row check
		sinkExists = true;
		for (int x = 0; x < verts; x++){
			if (graph[i][x] == 1){
				sinkExists = false;
			}
			count++;
		}

		//col check
		if (sinkExists){
			for (int x = 0; x < verts; x++){
				if (x != i){
					if (graph[x][i] == 0)
						sinkExists = false;
				}
			}
			count++;
		}


		//Print results to screen
		std::cout << "Universal Sink exists in '" << list[file] << "'  ";
		if (sinkExists){
			printf("true");
		}
		else{
			printf("false");
		}
		printf("\nRun Time was %d\n", count);
	}//end file loop
	
	printf("\n");
	return 0;
}

void readFromFile(std::string input){
	std::ifstream instream(input);
	std::string tempLine;
	int x = 0;
	int i = 0;
	if (instream.is_open()){
		while (getline(instream, tempLine)){
			std::stringstream lineSplitter(tempLine);
			tempLine.clear();
			for (int k = 0; lineSplitter.good(); k++){
				lineSplitter >> tempLine;
				x = std::stoi(tempLine);
				graph[i][k] = x;

			}
			i++;  //increment i;

		}//end while
		instream.close();
	}
	else{
		std::cout << "couldn't load " << input << "\n";
	}
}

void printGraph(){
	for (int i = 0; i < 4; i++){
		for (int k = 0; k < 4; k++){
			printf("%d ", graph[i][k]);
		}
		printf("\n");
	}
	printf("\n");


}