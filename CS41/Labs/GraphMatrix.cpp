#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Graph {
private:
    vector<vector<bool> > matrix;
    vector<string> labels;
    int numVertices;

public:
    Graph(int vertices) : numVertices(vertices) {
        matrix.resize(numVertices, vector<bool>(numVertices, false));
        labels.resize(numVertices);
    }

    void setLabel(int vertex, const string& label) {
        labels[vertex] = label;
    }

    void addEdge(const string& from, const string& to) {
        int fromIndex = findLabelIndex(from);
        int toIndex = findLabelIndex(to);
        if (fromIndex != -1 && toIndex != -1) {
            matrix[fromIndex][toIndex] = true;
            cout << "Added Edge " << from << "->" << to << endl;
        } else {
            cout << "Invalid vertex label(s)" << endl;
        }
    }

    void listEdges() {
        cout << "Your edges are: ";
        bool first = true;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (matrix[i][j]) {
                    if (!first) cout << ", ";
                    cout << labels[i] << labels[j];
                    first = false;
                }
            }
        }
        cout << endl;
    }

private:
    // Helper function to find the index of a label
    int findLabelIndex(const string& label) {
        for (int i = 0; i < numVertices; i++) {
            if (labels[i] == label) return i;
        }
        return -1;
    }
};

int main() {
    // Ask for the number of vertices
    int numVertices;
    cout << "How many vertices? ";
    cin >> numVertices;

    Graph graph(numVertices);

    // Get labels for each vertex
    for (int i = 0; i < numVertices; i++) {
        string label;
        cout << "What is the label for vertex " << (i + 1) << "? ";
        cin >> label;
        graph.setLabel(i, label);
    }

    cout << "\nDefine an edge by listing a pair of vertices, i.e. \"A B\", or -1 to stop." << endl;
    string input;
    while (true) {
        getline(cin, input);
        if (input.empty()) continue;  // Skip empty lines

        if (input == "-1") break;

        // Parse input and add edge
        size_t spacePos = input.find(' ');
        if (spacePos != string::npos) {
            string from = input.substr(0, spacePos);
            string to = input.substr(spacePos + 1);
            graph.addEdge(from, to);
        } else {
            cout << "Invalid input format. Please use 'A B' format." << endl;
        }
    }

    // Display all edges in the graph
    graph.listEdges();

    return 0;
}