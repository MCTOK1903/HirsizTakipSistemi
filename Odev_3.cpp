#include<iostream>
#include<fstream>
#include<string>

using namespace std;
#define S 11
#define EBS 0x7FFFFFFF;

void grafOlustur();
void optimalYol(int graph[S][S] , int src);
void optimalYolBul();
int minDistance(int dist[],bool sptSet[]);
void printSolution(int dist[], int n, int src);
void hirsizGuzergah();
void print(int array[S][S]);
int array[S][S];

int main(){
	grafOlustur();
	//print(array);
	optimalYolBul();
	hirsizGuzergah();
	return 0;
}


}

void print(int array[11][11]){
		for(int j=0;j<=10;j++){
			for(int k=0;k<=10;k++){
				cout<<array[j][k]<<",";
		}
	}
		
}

void optimalYolBul(){
	for(int h=0;h<S;h++){
		optimalYol(array,h);
	}
}



void hirsizGuzergah(){

	fstream file2;
	string input2;
	file2.open("EsyaBilgileri.txt");
	int c=0;
	while(file2){

		getline(file2,input2,',');
		c++;
		cout<<c<<"index->"<<input2<<endl;	
		
	}
}
