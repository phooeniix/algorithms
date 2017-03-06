
#include <iostream>
#include <string>

using namespace
int main(){
  int n, nC = 0;
  cin>>n;
  string *vet = new string [n];
  for(int i=0;i<n;i++){
    cin>>vet[i];
    if(strlen(vet[i])>nC){
      nC = strlen(vet[i]);
    }
  }
  char mat[n][nC];
  for(int i=0;i<n;i++)
    for(int j=0;j<nC;j++)
      mat[i][j] = '*';

      for(int i=0;i<n;i++){
        for(int j=0;j<nC;j++){
          mat[i][j] =vet[i] ;
        }
      }
      for(int i=0;i<n;i++){
        for(int j=0;j<nC;j++){
          cout<<mat[i][j];
        }
        cout<<endl;
      }

  return 0;
}
