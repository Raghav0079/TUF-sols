#include <iostream>
using namespace std;

class Robot {
private:
    string name;

public:
    Robot(string name) {
        this->name = name;
    }

    void performAction() {
        cout << name << " is performing an action." << endl;
    }
    class Arm {
        Robot* robot; 
    public:
        Arm(Robot* r) {
            robot = r;
        }

        void pickItem() {
            cout << robot->name << " arm picking an item." << endl;
        }
    };

    class Processor {
    public:
        void process() {
            cout << "Processor analyzing the data." << endl;
        }
    };


    void manageSensors() {
        class Sensor {
            string name;
        public:
            Sensor(string n) : name(n) {}
            void sense() {
                cout << name << " sensor detecting obstacles." << endl;
            }
        };

        Sensor sensor(name);
        sensor.sense();
    }


    void executeTask() {
        auto task = [this]() {
            cout << name << " executing a custom task." << endl;
        };

        task();
    }
};




// Please Do not change anything below, It is only for your reference.
/*

  // Below code demonstrates the Driver code and its working for the class 'Robot'.

  int main() {
      string name;

      // Creating the object of the class Robot
      Robot robot(name);

      // Calling the performAction method of class Robot
      robot.performAction();

      // Using non-static inner class
      // creating the object of the inner class and calling its method pickItem
      Robot::Arm arm(&robot);
      arm.pickItem();

      // Using static nested class
      // creating the object of the nested class and calling its method process
      Robot::Processor processor;
      processor.process();

      // Calling the method manageSensors that implements the local inner class
      // It then calls the sense method inside the manageSensors method to print the corresponding text
      robot.manageSensors();

      // Calling method executeTask that overrides the method execute which is implemented by the interface Task
      robot.executeTask();

      return 0;
  }

*/

/*

cout << name << " is performing an action.";        // -> It is for performAction method
cout << name << " arm picking an item.";            // -> It is for pickItem method
cout << "Processor analyzing the data.";            // -> It is for process method
cout << name << " sensor detecting obstacles.";     // -> It is for sense method
cout << name << " executing a custom task.";        // -> It is for execute method

*/
