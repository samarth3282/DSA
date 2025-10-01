// 2353. Design a Food Rating System
#include <bits/stdc++.h>
using namespace std;

class FoodRatings
{
public:
    // vector<int>forCuisine(cuisines.size());
    map<string, set<pair<int, string>>> cuisine_food_rating;
    map<string, string> food_cuisine;
    map<string, int> food_rating;
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        for (int i = 0; i < foods.size(); i++)
        {
            food_rating[foods[i]] = ratings[i];
            food_cuisine[foods[i]] = cuisines[i];
            cuisine_food_rating[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating)
    {
        int prevRating = food_rating[food];
        food_rating[food] = newRating;
        string cuisine = food_cuisine[food];
        cuisine_food_rating[cuisine].erase({-prevRating, food});
        cuisine_food_rating[cuisine].insert({-newRating, food});
    }

    string highestRated(string cuisine)
    {
        return cuisine_food_rating[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */