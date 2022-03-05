#include <iostream>
#include <list>

class Graph
{
  int numVertices;
  std::list<int> *adjLists;
  bool *visited;

public:
  Graph(int vertices)
  {
    numVertices = vertices;
    adjLists = new std::list<int>[vertices];
    visited = new bool[vertices];

    for (int i = 0; i < numVertices; i++)
    {
      visited[i] = false;
    }
  }

  void addUniEdge(int src, int dest)
  {
    adjLists[src].push_front(dest);
  }

  void addBiEdge(int src, int dest)
  {
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
  }

  // Referensi: https://www.programiz.com/dsa/graph-dfs
  void DFS(int vertex)
  {
    visited[vertex] = true;
    std::list<int> adjList = adjLists[vertex];

    // cetak vertex yang dikunjungi
    std::cout << vertex << " ";

    for (auto i = adjList.begin(); i != adjList.end(); ++i)
    {
      if (visited[*i])
      {
        continue;
      }

      DFS(*i);
    }
  }

  // Referensi: https://www.programiz.com/dsa/graph-bfs
  void BFS(int startVertex)
  {
    std::list<int> queue;
    visited[startVertex] = true;
    queue.push_back(startVertex);

    while (!queue.empty())
    {
      int currVertex = queue.front();

      // cetak vertex yang dikunjungi
      std::cout << currVertex << " ";
      queue.pop_front();

      for (auto i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i)
      {
        int adjVertex = *i;
        if (visited[adjVertex])
        {
          continue;
        }

        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
};

int main()
{
  Graph graphDfs(4);
  graphDfs.addBiEdge(0, 1);
  graphDfs.addBiEdge(0, 2);
  graphDfs.addBiEdge(1, 2);
  graphDfs.addBiEdge(2, 3);

  std::cout << "Metode DFS" << std::endl;
  graphDfs.DFS(0);

  Graph graphBfs(4);
  graphBfs.addBiEdge(0, 1);
  graphBfs.addBiEdge(0, 2);
  graphBfs.addBiEdge(1, 2);
  graphBfs.addBiEdge(2, 0);
  graphBfs.addBiEdge(2, 3);
  graphBfs.addBiEdge(3, 3);

  std::cout << "\nMetode BFS" << std::endl;
  graphBfs.BFS(0);

  return 0;
}
