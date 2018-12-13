#include<iostream>
#include<fstream>
#include<string>

using namespace std;
#define S 11
#define EBS 0x7FFFFFFF;

void grafOlustur();
void optimalYolBul(int graph[S][S] , int src);
int minDistance(int dist[],bool sptSet[]);
void printSolution(int dist[], int n);
void print(int array[S][S]);
int array[S][S];

int main(){
	grafOlustur();
	//print(array);
	optimalYolBul(array, 0);
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


void optimalYolBul(int graph[S][S] , int src){
	
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
		{
			if(!sptSet[t] && graph[u][t] && dist[u] != __INT_MAX__
				&& dist[u]+graph[u][t]< dist[t] ){
					dist[t] = dist[u] + graph[u][t];
                    cout<<t<<"->"<<dist[t]<<endl;
			}
			//printSolution(dist ,S);
		}
		
	}


}

void printSolution(int dist[], int n){
	cout<<"Dugümlerin ana kaynağa olna uzakığı"<<endl;
	
	for(int i = 0; i < n; i++)
	{
		cout<<" "<<i<<dist[i]<<endl;
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
		}
	}
    return minIndex;
}
