#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
using namespace std;

class IGraph {
public:
    IGraph () {};
    IGraph (const IGraph& _oth) {};
    virtual ~IGraph () {}

    virtual void AddEdge (int from, int to) = 0; // Метод принимает вершины начала и конца ребра и добавляет ребро
    virtual int VerticesCount () const = 0; // Метод должен считать текущее количество вершин
    virtual vector<int> Vertices () const = 0;
    virtual vector<int> GetNextVertices (int vertex) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    virtual vector<int> GetPrevVertices (int vertex) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную

    virtual void printGraph () = 0;
};



class ListGraph : public IGraph {
public:
    ListGraph ();
    ListGraph (const IGraph& oth);
    ~ListGraph () override;

    void AddEdge (int from, int to) override;
    int VerticesCount () const override;
    vector<int> Vertices () const override;
    vector<int> GetNextVertices (int vertex) const override;
    vector<int> GetPrevVertices (int vertex) const override;

    void printGraph () override;

private:
    map<int, vector<int>> verticesOut;
    map<int, vector<int>> verticesIn;

    void checkVertex (int);
    void addLink (map<int, vector<int>>&, int, int);
};

class MatrixGraph : public IGraph {
public:
    MatrixGraph ();
    MatrixGraph (const IGraph& oth);
    ~MatrixGraph () override;

    void AddEdge (int from, int to) override;
    int VerticesCount () const override;
    vector<int> Vertices () const override;
    vector<int> GetNextVertices (int vertex) const override;
    vector<int> GetPrevVertices (int vertex) const override;

    void printGraph () override;

private:
    map<int, int> vertex2index;
    vector <int> verticesQueue;
    vector<vector<bool>> matrix;

    void checkVertex (int);
};

ListGraph::ListGraph() {}


ListGraph::~ListGraph() {}


ListGraph::ListGraph (const IGraph& oth) {
    verticesIn.clear ();
    verticesOut.clear ();

    for (const auto& vertex : oth.Vertices ()) {
        verticesOut.insert(pair<int, vector<int>> (vertex, oth.GetNextVertices (vertex)));
        verticesIn.insert (pair<int, vector<int>> (vertex, oth.GetPrevVertices (vertex)));
    }
}



vector <int> ListGraph::Vertices () const {
    vector<int> vertices;
    for (const auto& el : verticesIn)
        vertices.push_back (el.first);

    return vertices;
}


void ListGraph::checkVertex (int vertex) {
    if (verticesIn.find (vertex) == verticesIn.end ())
        verticesIn.insert (pair<int, vector<int>> (vertex, 0));
    if (verticesOut.find (vertex) == verticesOut.end())
        verticesOut.insert (pair<int, vector<int>> (vertex, 0));
}


void ListGraph::addLink (map<int, vector<int>>& inMap, int to, int from) {
    map<int, vector<int>>::iterator itf = inMap.find (to);
    bool found = false;
    for (int i = 0; !found && (i < itf->second.size ()); ++i)
        if (itf->second[i] == from)
            found = true;
    if (!found)
        itf->second.push_back (from);
}


void ListGraph::AddEdge (int from, int to) {
    checkVertex (from);
    checkVertex (to);

    addLink (verticesIn, to, from);
    addLink (verticesOut, from, to);
}


int ListGraph::VerticesCount () const {
    return verticesIn.size();
}


vector<int> ListGraph::GetNextVertices (int vertex) const {
    return (verticesOut.find(vertex)->second);
}


vector<int> ListGraph::GetPrevVertices (int vertex) const {
    return (verticesIn.find(vertex)->second);
}


void ListGraph::printGraph () {
    for (auto& elem : verticesOut) {
        sort (elem.second.begin(), elem.second.end());
        cout << setw (4) << elem.first << ": ";
        for (const auto& vertices : elem.second)
            cout << setw (4) << vertices;
        cout << "\n";
    }

    cout << "\n";
}

MatrixGraph::MatrixGraph () {}


MatrixGraph::~MatrixGraph () {}


MatrixGraph::MatrixGraph (const IGraph& oth) {
    vertex2index.clear ();
    verticesQueue.clear ();
    matrix.clear ();

    for (const auto& vertex : oth.Vertices ())
        for (const auto& next : oth.GetNextVertices (vertex))
            AddEdge (vertex, next);
}


vector<int> MatrixGraph::Vertices () const {
    return verticesQueue;
}


void MatrixGraph::checkVertex (int vertex) {
    if (vertex2index.find (vertex) == vertex2index.end ()) {
        size_t pos = verticesQueue.size ();
        vertex2index.insert (pair <int, int> (vertex, pos));
        verticesQueue.push_back (vertex);
    }
}


void MatrixGraph::AddEdge (int from, int to) {
    checkVertex (from);
    checkVertex (to);

    size_t verticesCount = verticesQueue.size ();
    if (matrix.size () != verticesCount) {
        matrix.resize (verticesCount);
        for (auto& row : matrix)
            row.resize (verticesCount);
    }

    int indexFrom = vertex2index.find (from)->second;
    int indexTo   = vertex2index.find (to)->second;

    matrix[indexFrom][indexTo] = true;
}


int MatrixGraph::VerticesCount () const {
    return verticesQueue.size();
}


vector<int> MatrixGraph::GetNextVertices (int vertex) const {
    vector<int> nextVertices;
    if (vertex2index.find (vertex) == vertex2index.end ())
        return nextVertices;

    int index = vertex2index.find (vertex)->second;

    for (int col = 0; col < matrix[index].size(); ++col)
        if (matrix[index][col] == 1)
            nextVertices.push_back (verticesQueue[col]);

    return nextVertices;
}


vector<int> MatrixGraph::GetPrevVertices (int vertex) const {
    vector<int> prevVertices;
    if (vertex2index.find (vertex) == vertex2index.end ())
        return prevVertices;

    int index = vertex2index.find (vertex)->second;

    for (int row = 0; row < matrix.size(); ++row)
        if (matrix[row][index] == 1)
            prevVertices.push_back (verticesQueue[row]);

    return prevVertices;
}


void MatrixGraph::printGraph () {
    cout << setw (4) << ' ';
    for (const auto& vertex : verticesQueue)
        cout << setw (4) << vertex;
    cout << "\n";

    for (int i = 0; i < matrix.size(); ++i) {
        cout << setw (4) << verticesQueue[i];
        for (int j = 0; j < matrix[i].size(); ++j)
            cout << setw (4) << matrix[i][j];
        cout << "\n";
    }

    cout << "\n";
}


int main() {
    MatrixGraph m1;
    m1.AddEdge (2, 3);
    m1.AddEdge (3, 1);
    m1.AddEdge (1, 0);
    m1.AddEdge (2, 1);
    m1.AddEdge (0, 0);
    m1.printGraph ();

    ListGraph l1 = m1;
    l1.printGraph ();

    MatrixGraph m2 = l1;
    m2.printGraph ();
}