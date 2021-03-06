#pragma once
#include <vector>
#include "types.h"
#include "object.h"
// #include "objects.h"
using namespace std;

class Agent {
private:
    string name;
    object_list inventory;
    int sleep_remaining;
    int calories_remaining;

    // constants
    static const int MAX_SLEEP = 18;
    static const int MIN_SLEEP = 0;
    static const int MAX_CALORIES = 2000;
    static const int MIN_CALORIES = 0;

    // the operation currently being completed
    operation_type current_operation;
    vector< int > current_operation_arguments;
    int turns_remaining_for_current_operation;


public:
    Agent(
        string name,
        object_list intial_inventory,
        int initial_sleep,
        int initial_calories
    );

    string get_name();
    int get_sleep_state();
    int get_calories_state();
    object_list get_inventory_state();
    void print_state();

    operation_type get_current_operation();
    vector< int > get_current_operation_arguments();

    void change_sleep_state_by(int amount_to_change);
    void change_calories_state_by(int amount_to_change);
    void set_inventory_state(object_list new_inventory);

    bool is_busy();
    int get_turns_remaining_for_current_operation();
    void decrement_turn_counter();

    void set_next_operation(
        operation_type, 
        vector< int > arguments = {},
        int turns_required = 0
    );
};