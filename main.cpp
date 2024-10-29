#include <iostream>  // For input and output operations
#include <fstream>   // For file operations (ifstream, ofstream)
#include <string>    // For using string data type
using namespace std;
//a function for the feedback
void feedback(double avg)
{
    if (avg>=75)
    {
        cout<<"Congratulation you got a Distinction!!"<<endl;
    }else if(avg >=50)
    {
        cout<<" Well done you Passed"<<endl;
    }
    else
    {
        cout<<"Unfortunately you failed"<<endl;
    }

}
int main()
{
    // Open the 'GradeBook.txt' file in append mode to add data at the end without overwriting existing content
    ofstream flOutput("GradeBook.txt", ios::app);

    // Check if the file opened successfully; if not, display an error message and exit the program
    if (!flOutput) {
        cerr << "Error opening file!" << endl;  // Output error message to standard error stream
        return 1;  // Exit the program with an error code
    }

    int numStudent;  // Variable to store the number of students
    cout << "Enter the number of students: ";
    cin >> numStudent;  // Get the number of students from the user

    // Loop to collect details for each student
    for (int i = 0; i < numStudent; i++)
        {
        string stdName;  // Variable to store the student's name
        cout << "Enter the name for student " << i + 1 << ": ";
        cin >> stdName;  // Get the student's name from input
        flOutput << "Student Name: " << stdName << endl;  // Write the name to the file

        float stdID;  // Variable to store the student's ID
        cout << "Enter the ID for student " << i + 1 << ": ";
        cin >> stdID;  // Get the student's ID from input
        flOutput << "Student ID: " << stdID << endl;  // Write the ID to the file

        int numSubjects;  // Variable to store the number of subjects the student has
        cout << "How many subjects does this student have? ";
        cin >> numSubjects;  // Get the number of subjects from input
        flOutput << "Number of Subjects: " << numSubjects << endl;  // Write the subject count to the file

        int totGrade = 0;  // Initialize total grade to 0
        double stdAverage;  // Variable to store the student's average grade

        // Loop to collect and record grades for each subject
        for (int s = 0; s < numSubjects; s++) {
            int grade;  // Variable to store the grade for the current subject
            cout << "Enter grade for subject " << s + 1 << ": ";
            cin >> grade;  // Get the grade from input
            flOutput << "Grade " << s + 1 << " : " << grade << endl;  // Write the grade to the file
            totGrade += grade;  // Add the grade to the total
        }

        // Calculate the student's average grade by dividing the total grades by the number of subjects
        stdAverage = static_cast<double>(totGrade) / numSubjects;  // Use static_cast to ensure floating-point division

        // Display the student's average grade on the console
        cout << "Student's average: " << stdAverage << endl;
        feedback(stdAverage);

        // Write the average grade to the file
        flOutput << "Average Grade: " << stdAverage << endl;
        cout<<endl;


        // Write a separator to the file for readability between student entries
        flOutput << "---------------------------" << endl;
    }

    // Close the file to ensure data is saved properly
    flOutput.close();

    // Inform the user that the data was successfully saved to the file
    cout << "Student details saved to 'GradeBook.txt'." << endl;

    return 0;  // Indicate that the program ended successfully
}
