#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

// Class for managing the To-Do List
class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& taskDesc) {
        tasks.emplace_back(taskDesc);
        cout << "Task added: " << taskDesc << endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "Your to-do list is empty!\n";
            return;
        }

        cout << "\nTo-Do List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
        }
    }

    void markTaskCompleted(int taskNumber) {
        if (taskNumber < 1 || taskNumber > tasks.size()) {
            cout << "Invalid task number!\n";
            return;
        }

        tasks[taskNumber - 1].completed = true;
        cout << "Task " << taskNumber << " marked as completed.\n";
    }

    void removeTask(int taskNumber) {
        if (taskNumber < 1 || taskNumber > tasks.size()) {
            cout << "Invalid task number!\n";
            return;
        }

        cout << "Task \"" << tasks[taskNumber - 1].description << "\" removed from the list.\n";
        tasks.erase(tasks.begin() + taskNumber - 1);
    }
};

// Function to display the menu
void displayMenu() {
    cout << "\nTo-Do List Menu:\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "0. Exit\n";
}

int main() {
    ToDoList todoList;
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore();  // Clear the newline from the buffer
                string taskDesc;
                cout << "Enter task description: ";
                getline(cin, taskDesc);
                todoList.addTask(taskDesc);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                int taskNumber;
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                todoList.markTaskCompleted(taskNumber);
                break;
            }
            case 4: {
                int taskNumber;
                cout << "Enter task number to remove: ";
                cin >> taskNumber;
                todoList.removeTask(taskNumber);
                break;
            }
            case 0:
                cout << "Exiting the to-do list. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
