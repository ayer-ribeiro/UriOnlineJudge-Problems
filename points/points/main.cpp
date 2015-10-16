//
//  main.cpp
//  points
//
//  Created by Bruno Smarsaro Bazelato on 10/15/15.
//  Copyright © 2015 Bruno Smarsaro Bazelato. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int is_colinear(vector<int> p1, vector<int> p2, vector<int> p3){
    return (p1[0]*(p2[1] - p3[1]) + p2[0]*(p3[1] - p1[1]) + p3[0]*(p1[1] - p2[1]));
}

vector<float> compute_centre(vector<int> p1, vector<int> p2, vector<int> p3){
    float h, k; // h = X and k = Y ---> no reason for this notation!
    float nume, deno;
    // Calculating h
    nume = ((pow(p1[0],2)) + pow(p1[1],2))*(p2[1]) + ((p1[1])*((pow(p3[0], 2)) + pow(p3[1],2))) + ((pow(p2[0],2)) + pow(p2[1],2))*(p3[1]) - (p2[1])*((pow(p3[0],2)) + (pow(p3[1],2))) - (p1[1])*((pow(p2[0],2)) + pow(p2[1],2)) - ((pow(p1[0],2)) + (pow(p1[1],2)))*(p3[1]);
    
    deno = 2*(p1[0]*p2[1] + p1[1]*p3[0] + p2[0]*p3[1] - p2[1]*p3[0] - p1[1]*p2[0] - p1[0]*p3[1]);
    
    h = nume/deno;
    // Calculating k
    nume = ((pow(p2[0],2)) + pow(p2[1],2))*p1[0] +((pow(p1[0],2)) + pow(p1[1],2))*p3[0] + ((pow(p3[0], 2)) + pow(p3[1],2))*p2[0] - ((pow(p2[0],2)) + pow(p2[1],2))*p3[0] - ((pow(p1[0],2)) + pow(p1[1],2))*p2[0] - ((pow(p3[0], 2)) + pow(p3[1],2))*p1[0];
    
    k = nume/deno;
    
    vector<float> point = {h,k};
    return point;
}

bool is_equal(vector<float> p1, vector<float> p2){
    if (p1[0] == p2[0] && p1[1] == p2[1]) return true;
    else return false;
}

int number_points (vector<vector<float>> centre){
    int max = - 1;
    int equals;
    for (int i = 0; i < centre.size(); i++){
        equals = 0;
        for (int j = i+ 1; j < centre.size(); j++){
            if (is_equal(centre[i], centre[j])){
                equals++;
            }else break;
            
        }
        if (max < equals) max = equals;
    }
    
    return max;
}

int main(int argc, const char * argv[]) {
    
    
    int n_points = 1;
    while (n_points != 0) {
        cin >> n_points;
        vector<vector <int>> points;
        points.resize(n_points);
        
        vector<vector<float>> centre;
        
        
        for (int i = 0; i<n_points; i++){
            points[i].resize(2);
            cin >> points[i][0] >> points [i][1]; // [i][0] = x and [i][1] = y
        }
        
        
        for(int i = 0; i<n_points; i++){
            for(int j = i + 1; j < n_points; j++){
                for(int k = j + 1; k < n_points; k++){
                    // verify whether they form a circunference or not
                    // if so, calculates the centre and store it
                    // otherwise checks next point!
                    if (is_colinear(points[i], points[j], points[k])) {
                        continue;
                    } else{
                        vector<float> centre_pos = compute_centre(points[i], points[j], points[k]);
                        centre.push_back(centre_pos);
                    }
                }
            }
        }
        cout << number_points(centre) << "\n";
    }
    
    cout << n_points << "\n";
    return 0;
}