#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// Function to display the to-do list
void displayTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty!\n";
        return;
    }

    cout << "\n--- To-Do List ---\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

// Function to add a task to the list
void addTask(vector<string>& tasks) {
    cout << "Enter a new task: ";
    cin.ignore(); // Clear any newline characters in the input buffer
    string task;
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added successfully!\n";
}

// Function to delete a task from the list
void deleteTask(vector<string>& tasks) {
    displayTasks(tasks);
    if (tasks.empty()) return;

    cout << "Enter the number of the task to delete: ";
    int taskNum;
    cin >> taskNum;

    if (taskNum > 0 && taskNum <= tasks.size()) {
        tasks.erase(tasks.begin() + (taskNum - 1));
        cout << "Task deleted successfully!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

// Function to save tasks to a file
void saveTasks(const vector<string>& tasks, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error saving tasks to file.\n";
        return;
    }
    for (const auto& task : tasks) {
        outFile << task << '\n';
    }
    outFile.close();
    cout << "Tasks saved to " << filename << " successfully!\n";
}

// Function to load tasks from a file
void loadTasks(vector<string>& tasks, const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "No saved tasks found.\n";
        return;
    }
    tasks.clear();
    string task;
    while (getline(inFile, task)) {
        tasks.push_back(task);
    }
    inFile.close();
    cout << "Tasks loaded from " << filename << " successfully!\n";
}

int main() {
    vector<string> tasks;
    const string filename = "tasks.txt";

    // Load existing tasks from file
    loadTasks(tasks, filename);

    while (true) {
        cout << "\n--- To-Do List Menu ---\n";
        cout << "1. View Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Delete Task\n";
        cout << "4. Save Tasks\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                displayTasks(tasks);
                break;
            case 2:
                addTask(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                saveTasks(tasks, filename);
                break;
            case 5:
                saveTasks(tasks, filename);
                cout << "Exiting the program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
