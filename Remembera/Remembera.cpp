#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void saveToFile(const vector<string> &todo) {
    ofstream outFile("Remebera.txt");

    if (outFile.is_open()) {
        for (const string &task : todo) {
            outFile << task << endl;
        }
        outFile.close();
        cout << "Your to-do list has been saved!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}

void add(vector<string> &todo) {
    cout << "Add what to do: ";
    string new_task;
    getline(cin, new_task);
    if (!new_task.empty()) {
        todo.push_back(new_task);  // Add new task to the list
        cout << "You have this to do: " << endl;
        for (const string &task : todo) {
            cout << task << endl;
        }
    } else {
        cout << "No task entered." << endl;
    }
}

void loadFromFile(vector<string> &todo) {
    ifstream inFile("todo_list.txt");

    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            todo.push_back(line);  // Add each line as a new task
        }
        inFile.close();
    } else {
        cout << "No previous to-do list found." << endl;
    }
}

int main() {
    vector<string> todo;
    loadFromFile(todo);

    cout << "Remebera by staxhinho" << endl;
    cout << "This is your to-do list" << endl;
    if (todo.empty()) {
        cout << "You have nothing to do." << endl;
    }

    while (todo.empty()) {
        cout << "Add what to do: ";
        string new_task;
        getline(cin, new_task);
        todo.push_back(new_task);  // Add task to the list
    }

    while (!todo.empty()) {
        cout << "You have this to do: " << endl;
        for (const string &task : todo) {
            cout << task << endl;
        }

        string whattodo;
        cout << "Add, remove, clear, or save what to do?" << endl;
        cout << "(add/rem/clear/save)" << endl;
        getline(cin, whattodo);

        if (whattodo == "add") {
            add(todo);   // Call the add function
            continue;  // Exit the inner loop and return to the main loop
        } else if (whattodo == "rem") {
            cout << "Enter task number to remove: ";
            int task_num;
            cin >> task_num;
            cin.ignore();  // Clear the input buffer
            if (task_num > 0 && task_num <= todo.size()) {
                todo.erase(todo.begin() + task_num - 1);  // Remove task
                cout << "Task removed." << endl;
            } else {
                cout << "Invalid task number." << endl;
            }
            continue;  // Exit the inner loop and return to the main loop
        } else if (whattodo == "clear") {
            todo.clear();  // Removes all tasks from the list
            cout << "All tasks have been cleared." << endl;
            saveToFile(todo);
            continue;  // Exit the inner loop and return to the main loop
        } else if (whattodo == "save") {
            saveToFile(todo);  // Save to file
            string closecont;
            cout << "Close or continue?" << endl;
            cout << "close/cont" << endl;
            cin >> closecont;
            cin.ignore();  // Clear the input buffer
            if (closecont == "close") {
                return 0;
            } else if (closecont == "cont") {
                continue;
            } else {
                cout << "Wrong input. Please enter 'close' or 'cont'." << endl;
                break;
            }
        } else {
            cout << "Wrong input. Please enter 'add', 'rem', 'clear', or 'save'." << endl;
        }
    }
}