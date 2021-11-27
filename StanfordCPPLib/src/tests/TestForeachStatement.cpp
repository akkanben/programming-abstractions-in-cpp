/*
 * File: TestForeachStatement.cpp
 * ------------------------------
 * This file tests the various forms of the foreach statement.
 */

/*************************************************************************/
/* Stanford Portable Library                                             */
/* Copyright (c) 2014 by Eric Roberts <eroberts@cs.stanford.edu>         */
/*                                                                       */
/* This program is free software: you can redistribute it and/or modify  */
/* it under the terms of the GNU General Public License as published by  */
/* the Free Software Foundation, either version 3 of the License, or     */
/* (at your option) any later version.                                   */
/*                                                                       */
/* This program is distributed in the hope that it will be useful,       */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of        */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         */
/* GNU General Public License for more details.                          */
/*                                                                       */
/* You should have received a copy of the GNU General Public License     */
/* along with this program.  If not, see <http://www.gnu.org/licenses/>. */
/*************************************************************************/

#include <cctype>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "grid.h"
#include "map.h"
#include "set.h"
#include "strlib.h"
#include "unittest.h"
#include "vector.h"
using namespace std;

static void testForeachWithSTLVector();
static void testForeachWithSTLMap();
static void testForeachWithSTLSet();
static void testForeachWithVector();
static void testForeachWithGrid();
static void testForeachWithMap();
static void testForeachWithSet();
static void testForeachWithCString();
static void testForeachWithCPPString();
static void testForeachWithArray();
static int sumCharacterCodes(string str);

void testForeachStatement() {
   testForeachWithSTLVector();
   testForeachWithSTLMap();
   testForeachWithSTLSet();
   testForeachWithVector();
   testForeachWithGrid();
   testForeachWithMap();
   testForeachWithSet();
   testForeachWithCString();
   testForeachWithCPPString();
   testForeachWithArray();
   test(sumCharacterCodes("ABC"), 198);
   reportResult("foreach statement");
}

static void testForeachWithSTLVector() {
   declare(vector<string> stlvec);
   trace(stlvec.push_back("one"));
   trace(stlvec.push_back("two"));
   trace(stlvec.push_back("three"));
   declare(string result = "");
   trace(foreach (string str in stlvec) result += str);
   test(result, "onetwothree");
}

static void testForeachWithSTLMap() {
   reportMessage("map<char,int> roman;");
   map<char,int> roman;
   trace(roman['I'] = 1);
   trace(roman['V'] = 5);
   trace(roman['X'] = 10);
   trace(roman['L'] = 50);
   trace(roman['C'] = 100);
   trace(roman['D'] = 500);
   trace(roman['M'] = 1000);
   declare(string result = "");
   trace(foreach (char key in roman) result += key);
   test(result, "CDILMVX");
}

static void testForeachWithSTLSet() {
   declare(set<int> primes);
   trace(primes.insert(2));
   trace(primes.insert(3));
   trace(primes.insert(5));
   trace(primes.insert(7));
   trace(primes.insert(11));
   trace(primes.insert(13));
   trace(primes.insert(17));
   trace(primes.insert(19));
   declare(string result = "{ ");
   trace(foreach (int n in primes) result += integerToString(n) + " ");
   trace(result += "}");
   test(result, "{ 2 3 5 7 11 13 17 19 }");
}

static void testForeachWithVector() {
   declare(Vector<string> vec);
   trace(vec.push_back("one"));
   trace(vec.push_back("two"));
   trace(vec.push_back("three"));
   declare(string result = "");
   trace(foreach (string str in vec) result += str);
   test(result, "onetwothree");
}

static void testForeachWithGrid() {
   declare(Grid<char> grid(2, 2));
   trace(grid[0][0] = 0);
   trace(grid[0][1] = 1);
   trace(grid[1][0] = 2);
   trace(grid[1][1] = 3);
   declare(string result = "");
   trace(foreach (int value in grid) result += integerToString(value));
   test(result, "0123");
}

static void testForeachWithMap() {
   reportMessage("Map<char,int> roman;");
   Map<char,int> roman;
   trace(roman['I'] = 1);
   trace(roman['V'] = 5);
   trace(roman['X'] = 10);
   trace(roman['L'] = 50);
   trace(roman['C'] = 100);
   trace(roman['D'] = 500);
   trace(roman['M'] = 1000);
   declare(string result = "");
   trace(foreach (char key in roman) result += key);
   test(result, "CDILMVX");
}

static void testForeachWithSet() {
   declare(Set<int> primes);
   trace(primes.add(2));
   trace(primes.add(3));
   trace(primes.add(5));
   trace(primes.add(7));
   trace(primes.add(11));
   trace(primes.add(13));
   trace(primes.add(17));
   trace(primes.add(19));
   declare(string result = "{ ");
   trace(foreach (int n in primes) result += integerToString(n) + " ");
   trace(result += "}");
   test(result, "{ 2 3 5 7 11 13 17 19 }");
}

static void testForeachWithCString() {
   declare(string result = "");
   trace(foreach (char ch in "abcde") result += toupper(ch));
   test(result, "ABCDE");
}

static void testForeachWithCPPString() {
   declare(string result = "");
   trace(foreach (char ch in string("abcde")) result += toupper(ch));
   test(result, "ABCDE");
}

static void testForeachWithArray() {
   reportMessage("int array[] = { 1, 2, 3 };");
   int array[] = { 1, 2, 3 };
   declare(int result = 0);
   trace(foreach (int digit in array) result = 10 * result + digit);
   test(result, 123);
   reportMessage("const string BOOLEAN_NAMES[] = { \"FALSE\", \"TRUE\" };");
   const string BOOLEAN_NAMES[] = { "FALSE", "TRUE" };
   declare(string names = "");
   trace(foreach (string str in BOOLEAN_NAMES) names += str);
   test(names, "FALSETRUE");
}

static int sumCharacterCodes(string str) {
   int sum = 0;
   foreach (char ch in str) {
      sum += ch;
   }
   return sum;
}
