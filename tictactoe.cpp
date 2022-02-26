#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include "tictactoe.hpp"


void board (std::map<std::string, std::string> places)
{
std::cout << "   |   |   \n";
std::cout << " " << places["7"] << " | " << places["8"] << " | " << places["9"] << " \n";
std::cout << "___|___|___\n";
std::cout << "   |   |   \n";
std::cout << " " << places["4"] << " | " << places["5"] << " | " << places["6"] << " \n";
std::cout << "___|___|___\n";
std::cout << "   |   |   \n";
std::cout << " " << places["1"] << " | " << places["2"] << " | " << places["3"] << " \n";
std::cout << "   |   |   \n";
}


std::vector<int> update_available(int choice, std::vector<int> available){
    if (std::find(available.begin(), available.end(), choice) != available.end()){
        std::remove(available.begin(), available.end(), choice);
        return available;
    } else {
        std::cout << "Move unavailable. Pick a numbered spot.";
        return available;
    }
}


bool check_user_win(std::vector<std::string> user, std::vector<std::vector<std::string>> win_combo){
    for (int i=0; i<8; i++){
        if (find(user.begin(), user.end(), win_combo.at(i).at(0)) != user.end() &&
            find(user.begin(), user.end(), win_combo.at(i).at(1)) != user.end() &&
            find(user.begin(), user.end(), win_combo.at(i).at(2)) != user.end()){
                return true;
            } 
        }
    
    return false;
}


bool check_comp_win(std::vector<std::string> comp, std::vector<std::vector<std::string>> win_combo){
    for (int i=0; i<8; i++){
        if (find(comp.begin(), comp.end(), win_combo.at(i).at(0)) != comp.end() &&
            find(comp.begin(), comp.end(), win_combo.at(i).at(1)) != comp.end() &&
            find(comp.begin(), comp.end(), win_combo.at(i).at(2)) != comp.end()){
                return true;
            } 
        }
    
    return false;
}


void x_or_o(std::string *user_xo, std::string *comp_xo){
    std::cout << "x or o?\n";
    std::cin >> *user_xo;

    if (*user_xo == "x"){
        *user_xo = "X";
        *comp_xo = "O";
    } else if (*user_xo == "o"){
        *user_xo = "O";
        *comp_xo = "X";
    } else {
        std::cout << "Please choose either x or o (lowercase).\n";
        x_or_o(user_xo, comp_xo);
    }
    
}


void player_turn( std::string player_xo,
                std::vector<std::string> &player, 
                std::map<std::string, std::string> &places, 
                std::vector<std::string> &available){

    std::string choice;
    std::cout << "Pick your place: ";
    std::cin >> choice;
    if (std::find(available.begin(), available.end(), choice) != available.end()){
        available.erase(std::remove(available.begin(), available.end(), choice)), available.end();
        player.push_back(choice);
        places[choice] = player_xo;
    } else {
        std::cout << "Please pick an available numbered spot./n";
        player_turn( player_xo, player, places, available);
    }
}


void comp_turn( std::string comp_choice,
                std::string comp_xo,
                std::vector<std::string> &comp,
                std::map<std::string, std::string> &places,
                std::vector<std::string> &available){

    comp.push_back(comp_choice);
    places[comp_choice] = comp_xo;
    available.erase(std::remove(available.begin(), available.end(), comp_choice)), available.end();
                }
