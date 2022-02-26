// #include <algorithm>
// #include <iostream>
// #include <map>
// #include <vector>



//print board to screen

void board (std::map<std::string, std::string> places);


std::vector<int> update_available(int choice, std::vector<int> available);


bool check_user_win(std::vector<std::string> user, std::vector<std::vector<std::string>> win_combo);


bool check_comp_win(std::vector<std::string> comp, std::vector<std::vector<std::string>> win_combo);


void x_or_o(std::string *user_xo, std::string *comp_xo);


void player_turn( std::string player_xo,
                std::vector<std::string> &player, 
                std::map<std::string, std::string> &places, 
                std::vector<std::string> &available);


void comp_turn( std::string comp_choice,
                std::string comp_xo,
                std::vector<std::string> &comp,
                std::map<std::string, std::string> &places,
                std::vector<std::string> &available);