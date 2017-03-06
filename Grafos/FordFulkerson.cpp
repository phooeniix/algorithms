/**
  * @author Alexandre Carvalho
  * @author James Yuri
  * @version 1.06
  * Algoritmo de encontrar o Fluxo em rede

*/
#include <iostream>
#include <queue>
using namespace std;

// NÚMERO DE VERTICES DO GRAFO
#define V 10

/* Esta função retorna verdadeiro se existir um caminho de s até t, no grafo
        residual;
      Também preenche o parent[] para armazenar o caminho
*/
bool bfs(int grafoResidual[V][V], int s, int t, int parent[])
{
    /*
    Aqui eu crio um vetor de vértices visitados e marco todos os vértices
      como visitados
    */
    bool visited[V];
    //MARCANDO TODOS OS VÉRTICES COMO VISITADO
    for(int i =0;i<sizeof(visited);i++){
      visited[i] = false;
    }

    // Crio uma pilha, desempilho o primeiro vértice, e o marco como visitado
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // LOOP PADRÃO
    //enquanto a pilha estiver vazia
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v=0; v<V; v++)
        {
            if (visited[v]==false && grafoResidual[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // Se chegar no destino marca como true se não é false
    return (visited[t] == true);
}

// FUNÇÃO PARA RETORNAR O FLUXO MÁXIMO DO VERTICE S PARA T NOA grafo dado
int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;

    /*    CRIANDO UM GRAFO RESIDUAL E PREENCHE ELE COM O
              RESULTADO DA CAPACIDADE ORIGINAL DO GRAFO
              DE RESIDUAL DO GRAFO

    */
    int grafoResidual[V][V];
    /* GRAFO RESIDUAL ONDE grafoResidual[i][j] INDICA
     A CAPACIDADE RESIDUAL DE I ATÉ J
     (SE ENCONTRAR UMA BORDA, SE  grafoResidual[i][j] é igual a 0 então não existe
   */
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             grafoResidual[u][v] = graph[u][v];

    int parent[V];  // vetor preenchido com a BFS onde será armazenado o caminho

    int max_flow = 0;  //AQUI É O FLUXO MÁXIMO INICIADO COM 0

    // AUMENTE O FLUXO ENQUANTO EXISTIR CAMINHO DE S PARA T
    while (bfs(grafoResidual, s, t, parent))
    {
        /*
          ENCONTRE A MENOR CAPACIDADE RESIDUAL PARA A BORDA AO LONGO
              DO CAMINHO PREENCHIDO PELA BFS. OU PODE-SE DIZER QUE ENCONTROU O
              CAMINHO MÁXIMO ATRAVÉS DO CAMINHO ENCONTRADO
        */
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, grafoResidual[u][v]);
        }

        /*
            ATUALIZE A CAPACIDADE RESIDUAL BORDA A BORDA AO
                AO LONGO DO CAMINHO

        */
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            grafoResidual[u][v] -= path_flow;
            grafoResidual[v][u] += path_flow;
        }

        // ADICIONANDO UM FLUXO DE CAMINHO AO FLUXO GERAL
        max_flow += path_flow;
    }

    // RETORNAR O FLUXO MÁXIMO
    return max_flow;
}

int main()
{
  //CRIANDO O GRAFO DO PROBLEMA COM 10 VÉRTICES

  /*
    S - VERTICE ORIGEM, INICIO
    A - BOLSA DE SANGUE TIPO A
    B - BOLSA DE SANGUE TIPO B
    AB - BOLSA DE SANGUE TIPO AB
    O - BOLSA DE SANGUE TIPO O
    P1 - PACIENTE DO TIPO A
    P2 - PACIENTE DO TIPO B
    P3 - PACIENTE DO TIPO AB
    P4 - PACIENTE DO TIPO O
    T - VERTICE FIM

  */
    int graph[V][V] = { {0, 25, 5, 7, 20, 0,0,0,0,0},
                        {0,0,0,0,0,INT_MAX,0,INT_MAX,0,0},
                        {0,0,0,0,0,0,INT_MAX,INT_MAX,0,0},
                        {0,0,0,0,0,0,0,INT_MAX,0,0},
                        {0,0,0,0,0,INT_MAX,INT_MAX,INT_MAX,INT_MAX,0},
                        {0,0,0,0,0,0,0,0,0,10},
                        {0,0,0,0,0,0,0,0,0,15},
                        {0,0,0,0,0,0,0,0,0,15},
                        {0,0,0,0,0,0,0,0,0,15},
                        {0,0,0,0,0,0,0,0,0,0}
                      };

                      //ALTERANDO A DEMANDA DE AB de 7 PARA 10 mantém o mesmo valor do fluxo

    cout << "FLUXO MÁXIMO " << fordFulkerson(graph, 0, 9)<<endl;


    return 0;
}
