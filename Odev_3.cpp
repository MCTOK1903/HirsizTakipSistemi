#include<iostream>
#include<fstream>
#include <queue>
#include<string>
#include <algorithm>
#include "q.h"

using namespace std;
#define S 11
#define EBS 0x7FFFFFFF;

void grafOlustur();
void optimalYol(int graph[S][S] , int src);
void optimalYolBul();
int minDistance(int dist[],bool sptSet[]);
int knapSack(int W, int wt[], int val[], int n);
void printSolution(int dist[], int n, int src);
void hirsizGuzergah();
void print(int array[S][S]);
int array[S][S];
int arrayVal[8];
int arrayWt[8];
string arrayHirsiz[8][4];
Queue<string> hirsizQ;
Queue<string> polisQ;

int main(){
	grafOlustur();
	//print(array);
	optimalYolBul();
	hirsizGuzergah();
	return 0;
}


void grafOlustur(){
	int x=0,y=0;
 	fstream file;
	string input="";
	file.open("YolBilgisi.txt");
	while(file){
		
		getline(file,input,',');
			if(x<11){
				//cout<<"x'in değeri"<<x<<endl;
				//cout<<"y'nin değeri"<<y<<endl;
				//cout<<input<<endl;
				array[x][y]=stoi(input);
					y++;
				if(y%11==0){
					x++;
					y=0;
				}
			}		
	}

	/*for(int j=0;j<=10;j++){
		for(int k=0;k<=10;k++){
			cout<<array[j][k]<<",";
		}*/
	
	file.close();
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


void optimalYol(int graph[S][S] , int src){

    int dist[S];
	bool sptSet[S];
	for (int i=0 ; i<S;i++){
		dist[i] = __INT_MAX__;
		sptSet[i]=false;
	}
		dist[src]=0;

		for(int count=0;count<S;count++){
			int u = minDistance(dist,sptSet);
			sptSet[u]=true;
        
		
			for(int t = 0; t < S; t++)
		    	if(!sptSet[t] && graph[u][t] && dist[u] != __INT_MAX__
					&& dist[u]+graph[u][t] < dist[t] )
						dist[t] = dist[u] + graph[u][t];
                    //cout<<"dist"<<"["<<u<<"]"<<dist[u]<<endl;
                    //cout<<"graph"<<"["<<u<<"]"<<"["<<t<<"]"<<graph[u][t]<<endl;
                    //cout<<t<<"->"<<dist[t]<<endl;
	
	    }

		
   //printSolution(dist ,S, src);
    
}

void printSolution(int dist[], int n, int src){
	cout<<"Dugümlerin "<<src<<" kaynağına olan uzakığı"<<endl;
	
	for(int i = 0; i < n; i++)
	{
		cout<<i<<".Düğüm"<<dist[i]<<endl;
	}


	
}

int minDistance(int dist[],bool sptSet[]) {

	int min = __INT_MAX__ ;
    int minIndex;
    
	for(int i = 0; i < 11; i++)
	{
		if(sptSet[i]==false && dist[i] <= min){
			min=dist[i];
            
			minIndex=i;
            //cout<<minIndex<<endl;	
		}
	}
    return minIndex;
}

void hirsizGuzergah(){

	fstream file2;
	string input2;
	file2.open("EsyaBilgileri.txt");
	int x=0,y=0;
	while(file2){

		getline(file2,input2,',');
		if(x<8){
				//cout<<"x'in değeri"<<x<<endl;
				//cout<<"y'nin değeri"<<y<<endl;
				//cout<<input2<<endl;
			arrayHirsiz[x][y]=input2;
			y++;
			if(y%4==0){
				y=0;
				x++;
			}
		}

	}

	for(int i =0 ; i<8 ; i++){
		arrayVal[i]=stoi(arrayHirsiz[i][3]);
		//cout<<arrayVal[i]<<endl;
	}

	for(int j=0 ; j<8; j++){
		arrayWt[j]=stoi(arrayHirsiz[j][2]);
		//cout<<arrayWt[j]<<endl;
	}
	file2.close();
	knapSack(200,arrayWt,arrayVal,8);
}	


int knapSack(int W, int wt[], int val[], int n) { 
   int i=0, w=0;
   int hacim=0;
   int deger=0;
   int counttt=0;
   int a=0;
   int K[n+1][W+1]; 
   int Keep[n+1][W+1];
   double index[n];

	for(int i=0;i<8;i++){
		index[i]=val[i]/wt[i];
		//cout<<index[i]<<endl;
	}

	for(int i = 0; i<8; i++)
	{
		hacim+=+wt[i];
		deger+=val[i];
		counttt++;
		 if(hacim>W){
			hacim-=wt[i];
			deger-=val[i];
			counttt--;
			break;

		 }   
	}

	cout<<" Mağazalar"<<endl;
	for(int i =0 ;i<counttt;i++){
		hirsizQ.enqueue(arrayHirsiz[i][0]);
		//cout<<arrayHirsiz[i][0]<<endl;
	}

	cout<<"maxiımum deger ->"<<deger;
	return deger; 
	} 





