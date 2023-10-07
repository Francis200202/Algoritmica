#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>
#include <vector>

using namespace std;

void opcion1();
void opcion2();
void opcion3();

void backtracking(int n, vector<int>&reinas, vector<vector<int>> &sol, int op);
bool vegas(int n, vector<int>&reinas);

bool lugar(int k, vector<int>&reinas);

#endif