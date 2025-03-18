#include<iostream>

using namespace std;

void initadjmatrix (int adjMatrix[4][4]){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			adjMatrix[i][j]=0;
		}
	}
}

void addEdge(int adjMatrix[4][4],int n, int m){
	adjMatrix[n][m]=1;
	adjMatrix[m][n]=1;
}

void printMatrix(int adjMatrix [4][4]){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cout<<adjMatrix[i][j]<<" ";
		}
		cout<<endl;
	}
	
}

int main(){
	int adjMatrix [4][4];
	initadjmatrix(adjMatrix );
	addEdge(adjMatrix,0,1);
	addEdge(adjMatrix ,0,2);
	addEdge(adjMatrix ,0,3);
	addEdge(adjMatrix,1,3);
	addEdge(adjMatrix ,1,2);
printMatrix(adjMatrix );
}
