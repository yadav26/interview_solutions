// uniquestr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
// C++ program to find total area of two
// overlapping Rectangles

using namespace std;

struct CartesianPoint
{
    int x, y;
};

struct Points
{
    CartesianPoint l1;
    CartesianPoint r1;
    CartesianPoint l2;
    CartesianPoint r2;
};


int overlappingTimesA1(CartesianPoint l1, CartesianPoint r1,
    CartesianPoint l2, CartesianPoint r2)
{
    // Area of 1st Rectangle
    int a1 = abs(l1.x - r1.x);
    int a2 = abs(l1.y - r1.y);

    int area1 = abs(l1.x - r1.x)
        * abs(l1.y - r1.y);
    cout << "A1 = " << area1 <<endl;
    // Area of 2nd Rectangle
    int area2 = abs(l2.x - r2.x)
        * abs(l2.y - r2.y);
    cout << "A2 = " << area2 << endl;
    // Length of intersecting part i.e
    // start from max(l1.x, l2.x) of
    // x-coordinate and end at min(r1.x,
    // r2.x) x-coordinate by subtracting
    // start from end we get required
    // lengths

    auto rxmin = min(r1.x, r2.x);
    auto lxmax = max(l1.x, l2.x);
    int x_dist = ( rxmin - lxmax );
    auto rymin = min(r1.y, r2.y);
    auto lymax = max(l1.y, l2.y);


    int y_dist = ( rymin - lymax );
    int oa = 0;
    if (x_dist > 0 && y_dist > 0)
    {
        oa = x_dist * y_dist;
        cout << "Times of A1/A = " << area1 / oa << endl;
    }
    cout << "Overlap (area1/areaI)= " << area1 / oa << endl;
    

    return (area1 / oa);
}
int getLeastX(vector<int> v)
{
    auto min = 1000000000000000;
    for (int i = 0; i < v.size(); i=i+2)
    {
        if (min > v[i]) min = v[i];
    }
    return min;
}
int getLeastY(vector<int> v)
{
    auto min = 1000000000000000;
    for (int i = 1; i < v.size(); i = i + 2)
    {
        if (min > v[i]) min = v[i];
    }
    return min;
}
void resetXaxis(vector<int>& v)
{
    int shift = abs(getLeastX(v));
    for (int i = 0; i < v.size(); i = i + 2)
    {
        v[i] = v[i] + shift;
    }
}
void resetYaxis(vector<int>& v)
{
    int shift = abs(getLeastY(v));
    for (int i = 1; i < v.size(); i = i + 2)
    {
        v[i] = v[i] + shift;
    }
}
int find_min_x1(vector<int>& v) {
    auto min = 1000000000000000;
    for (int i = 0; i <8; i = i + 2)
    {
        if(min>v[i])min=v[i];
    }
    return min;
}
int find_max_x1(vector<int>& v) {
    auto m = -9999999999999999;
    for (int i = 0; i < 8; i = i + 2)
    {
        if (m < v[i])m = v[i];
    }
    return m;
}
int find_min_y1(vector<int>& v) {
    auto min = 1000000000000000;
    for (int i = 1; i < 8; i = i + 2)
    {
        if (min > v[i])min = v[i];
    }
    return min;
}
int find_max_y1(vector<int>& v) {
    auto m = -9999999999999999;
    for (int i = 1; i < 8; i = i + 2)
    {
        if (m < v[i])m = v[i];
    }
    return m;
}
int find_min_x2(vector<int>& v) {
    auto min = 1000000000000000;
    for (int i = 8; i <= 15; i = i + 2)
    {
        if (min > v[i])min = v[i];
    }
    return min;
}
int find_max_x2(vector<int>& v) {
    auto m = -9999999999999999;
    for (int i = 8; i <=15; i = i + 2)
    {
        if (m < v[i])m = v[i];
    }
    return m;
}
int find_min_y2(vector<int>& v) {
    auto min = 1000000000000000;
    for (int i = 9; i <= 15; i = i + 2)
    {
        if (min > v[i])min = v[i];
    }
    return min;
}
int find_max_y2(vector<int>& v) {
    auto m = -9999999999999999;
    for (int i = 9; i <= 15; i = i + 2)
    {
        if (m < v[i])m = v[i];
    }
    return m;
}
Points ParseInputIntoCartesian(string strArr[])
{
    std::vector<string> pos;

    istringstream f(strArr[0]);
    string str;
    while (getline(f, str, ')')) {
        str.erase(str.begin(), str.begin() + str.find_first_of("(") + 1);
        pos.push_back(str);
    }

    std::vector<CartesianPoint> points;
    std::vector<int> xy;
    for (auto v : pos)
    {
        istringstream f(v);
        string str;
        CartesianPoint  c;
        while (getline(f, str, ',')) {
            xy.push_back(stoi(str));
        }
    }

    auto xyorg = xy;
    resetXaxis(xy);
    resetYaxis(xy);
    for (int i = 0; i < xy.size(); ++i)
    {
        cout  << xy[i] << ",";
    }
    
    CartesianPoint l1{ find_min_x1(xy), find_min_y1(xy) };
    CartesianPoint r1{ find_max_x1(xy), find_max_y1(xy) };
    CartesianPoint l2{ find_min_x2(xy), find_min_y2(xy) };
    CartesianPoint r2{ find_max_x2(xy), find_max_y2(xy) };

    return Points{ l1,r1,l2,r2 };
}

// Driver Code
int main()
{

    //CartesianPoint l1 = { 2, 2 }, r1 = { 5, 7 };
    //CartesianPoint l2 = { 3, 4 }, r2 = { 6, 9 };
    //string arr[] = { "(0,0),(2,2),(2,0),(0,2),(1,0),(1,2),(6,0),(6,2)" };
    //string arr[] = { "(0,0),(0,-2),(3,0),(3,-2),(2,-1),(3,-1),(2,3),(3,3)" };
    string arr[] = { "(0,0),(5,0),(0,2),(5,2),(2,1),(5,1),(2,-1),(5,-1)" };

    cout << arr[0] << endl;
    auto p = ParseInputIntoCartesian(arr);
    // Function Call
    cout << overlappingTimesA1(p.l1, p.r1, p.l2, p.r2);
    return 0;
}
