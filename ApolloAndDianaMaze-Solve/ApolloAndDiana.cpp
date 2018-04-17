/* Analysis of Algorithms
 * Spring 2018
 * Project #3
 * Student: Patricia Wilthew
 */
using namespace std;
#include <vector>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <bits/stdc++.h>
#include <list>
#define MAX_NODES 100

/* Mapping of directions to integers */
enum direction{None, N, NE, E, SE, S, SW, W, NW};

/* Mapping of colors to integers */
enum color{Final, Blue, Red};

/* Node definition */
struct Node {
  int color;
  int dir; 
  int x;
  int y;
  string text;
  int visited;
  struct Node* parent;
  vector<Node*> neighbors;
};

/* Given a dash-delimited string with color and direction,
   return the color */
int getColor(string s) {
  size_t pos = s.find("-");
  string s_color = s.substr(0, 1);

  if (s_color == "B")
    return Blue;
  if (s_color == "R") 
    return Red;
  return Final;
}

/* Given a dash-delimited string with color and direction,
   return the direction */
int getDir(string s) {
  size_t pos = s.find("-");
  string s_dir = s.substr(pos + 1);
  
  if (s_dir == "NE") 
    return NE;
  if (s_dir == "SE") 
    return SE;
  if (s_dir == "NW") 
    return NW;
  if (s_dir == "SW") 
    return SW;
  if (s_dir == "N") 
    return N;
  if (s_dir == "E") 
    return E;
  if (s_dir == "S") 
    return S;
  if (s_dir == "W") 
    return W;
  return None;
}

/* Inverse of getDir() */
string getDirString(int e) {
  if (e == NE)
    return "NE";
  if (e == SE)
    return "SE";
  if (e == NW)
    return "NW";
  if (e == SW)
    return "SW";
  if (e == N)
    return "N";
  if (e == E)
    return "E";
  if (e == S)
    return "S";
  if (e == W)
   return "W";
  if (e == None)
   return "";
}

/* Given a matrix of nodes, create the directed edges between
   the nodes by adding the neighbors of each.
   This is done by looking at the direction of a node N and
   choosing those nodes that are being pointed by N that are
   not of the same color */
void createEdges(struct Node graph[MAX_NODES][MAX_NODES], int rows, int columns) {
  int dir, color, i, j;

  for (int row=0; row < rows; row++) {
    for (int column=0; column < columns; column++) {

      dir = graph[row][column].dir;
      color = graph[row][column].color;

      if (dir == None) {
        break;
      }

      else if (dir == N) {
        for (i=0; i < row; i++) {
          if (graph[i][column].color != color) {
            graph[row][column].neighbors.push_back(&graph[i][column]);
          }
        }
      }

      else if (dir == S) {
        for (i=row; i < rows; i++) {
          if (graph[i][column].color != color) {
            graph[row][column].neighbors.push_back(&graph[i][column]);
          }
        }
      }

      else if (dir == W) {
        for (j=0; j < column; j++) {
          if (graph[row][j].color != color) {
            graph[row][column].neighbors.push_back(&graph[row][j]);
          }
        }
      }

      else if (dir == E) {
        for (j=column; j < columns; j++) {
          if (graph[row][j].color != color) {
            graph[row][column].neighbors.push_back(&graph[row][j]);
          }
        }
      }

      else if (dir == NE) {
        i = row;
        j = column;
        while ((i >= 0) && j < (columns)) {
          if (graph[i][j].color != color) {
            graph[row][column].neighbors.push_back(&graph[i][j]);
          }
          i--;
          j++;
        }
      }

      else if (dir == SE) {
        i = row;
        j = column;
        while ((i < rows) && (j < columns)) {
          if (graph[i][j].color != color) {
            graph[row][column].neighbors.push_back(&graph[i][j]);
          }
          i++;
          j++;
        }
      }

      else if (dir == SW) {
        i = row;
        j = column;
        while ((i < rows) && (j >= 0)) {
          if (graph[i][j].color != color) {
            graph[row][column].neighbors.push_back(&graph[i][j]);
          }
          i++;
          j--;
        }
      }

      else if (dir == NW) {
        i = row;
        j = column;
        while ((i >= 0) && (j >= 0)) {
          if (graph[i][j].color != color) {
            graph[row][column].neighbors.push_back(&graph[i][j]);
          }
          i--;
          j--;
        }
      }
    }
  }
}

/* Given an initial node, return a list containing the path
   from that node to the final node, "O" */
list <Node*> DFS(struct Node *node) {
  list<Node*> list;
  stack<Node*> stack;
  stack.push(node);

  while (!stack.empty()) {
    node = stack.top();
    stack.pop();

    if (node->text == "O")
      break;

    if (!(node->visited)) {
      node->visited = 1;
    }

    vector<Node*> neigh = node->neighbors;
    vector<Node*>::iterator iter;
    for (iter = neigh.begin(); iter != neigh.end(); ++iter) {
      if (!(*iter)->visited) {
        (*iter)->parent = node;
        stack.push(*iter);
      } 
    }
  }
  // Get path in a list by reversing the traversing
  while (node != NULL) {
    list.push_front(node);
    node = node->parent;
  }
  return list;
}

/* Given two nodes, return the maze distance between them*/
int getDistance(struct Node *node1, struct Node *node2) {
  int dir = node1->dir;
  if (dir == W || dir == E)
    return abs(node1->y - node2->y);
  else
    return abs(node1->x - node2->x);
}

/* Write to output.txt the moves that need to be taken to traverse
   the maze from the top left position to the right bottom position.
   Each move is represented by the number of spaces to move and
   the direction, with no space in between. The direction is 
   represented using N, E, S, W, NE, SE, SW, and NW, as in the 
   input*/
int main(int argc, char* argv[]) {
  int rows, columns;
  string next;
  ifstream infile;
  ofstream outfile;
  int dir_int, dist;
  string dir_string;
  Node *node1, *node2;
  list <Node*> list;

  // Check the number of parameters
  if (argc < 2) {
    // Tell the user how to run the program
    cerr << "Usage: " << argv[0] << " <input_file>" << endl;
    return 1;
  }

  // Open file
  string name_of_file = argv[1]; 
  infile.open(name_of_file);

  // Create a graph with file content
  if (infile.is_open()) { 
    infile >> rows;
    infile >> columns;

    // Matrix of nodes
    struct Node graph[MAX_NODES][MAX_NODES];

    // Populate nodes in the matrix with color and direction info
    for (int i=0; i < rows; i++) {
      for (int j=0; j < columns; j++) {
        struct Node* n = (struct Node*)malloc(sizeof(struct Node));
        infile >> next;
        n->color = getColor(next);
        n->dir = getDir(next);
        n->text = next;
        n->x = i;
        n->y = j;
        n->visited = 0;
	n->parent = NULL;
        graph[i][j] = *n;
      }
    }
    
    // Populate neighbors of each node
    createEdges(graph, rows, columns);

    // Get DFS path in a list
    list = DFS(&graph[0][0]);

    // Write output to a file
    outfile.open("output.txt");
    for (std::list<Node*>::iterator it = list.begin(); it != list.end();) {
      // Get next node of path
      node1 = (*it);
      
      // Get its direction in integer and string forms
      dir_int = node1->dir;
      dir_string = getDirString(dir_int);
      
      // Increment iterator
      ++it;

      // If iterator finished, exit loop
      if (it == list.end()) {
        break;
      }
      // Else, get node pointed by iterator
      node2 = (*it);

      // Calculate distance between node1 and node2
      dist = getDistance(node1, node2);
      cout << dist << dir_string << " ";
      outfile << dist << dir_string << " ";
    }
    outfile.close();
  }
  else {
    cout << "Error opening file" << endl;
    exit(1);
  }
  infile.close();
  return 0;
}
