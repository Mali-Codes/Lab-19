// Malakai Ponce | October 04, 2025 | COMSC 210
// Lab 18

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct ReviewNode {
    double rating;
    string comment;
    ReviewNode* next;
};


class Movie {
private:

    string title;
    ReviewNode* head;
    ReviewNode* tail;

public:

    Movie(string movieTitle) {
    title = movieTitle;
    head = nullptr;
    tail = nullptr;
    }

    //adds to front
    void AddToFront (double rating, string comment) {

        ReviewNode* newNode = new ReviewNode;

        newNode->rating = rating;
        newNode->comment = comment;
        newNode->next = head;
        
        head = newNode;

        if (tail == nullptr) {
            tail = newNode;
        }
    };
    //adds to back - not really needed for this lab
    void addToBack (double rating, string comment) {

        ReviewNode* newNode = new ReviewNode;

        newNode->rating = rating;
        newNode->comment = comment;
        newNode->next = nullptr;            

        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;

        if (head == nullptr) {
            head = newNode;
        }
    };
    //displays list
    void DisplayList () {
        if (head == nullptr) {
            cout << "Somin ain't right\n";
            return;
        }

        int count = 0;
        double sum = 0.0;
        ReviewNode* current = head;

        while (current != nullptr) {
            count++;
            sum += current->rating;
        
            cout << "   > Review #" << count << ": " << current->rating 
                << ": " << current->comment << endl;

            current = current->next;
            
        }

        double average = sum / count;
        cout << "Average: " << average << "\n";
    }
    //loads the files
    void loadFiles(string filename) {  //used an example to build this
        ifstream inFile(filename);

        if (!inFile) {
            cout << "Could not read" << endl;
            return;
        }
        double rating;
        string comment;
        int count = 0;

        while (getline(inFile, comment)) {
            double rating = (rand() % 41 + 10) / 10.0;  // Generates 1.0, 1.1, 1.2, ... 5.0
            
            AddToFront(rating, comment);
            count++;
        }
        cout << "files from: " << filename << endl;
        inFile.close();
    }

};
//main function to run it
int main() {
    srand(time(0));

    const int NUM_MOVIES = 4;

    Movie* movies[NUM_MOVIES];
    movies[0] = new Movie("HTTYD");
    movies[1] = new Movie("Batman");
    movies[2] = new Movie("StarWars");
    movies[3] = new Movie("Demon Slayer");


    movies[0]->loadFiles("HTTYD.txt");
    movies[0]->DisplayList();

    movies[1]->loadFiles("Batman.txt");
    movies[1]->DisplayList();

    movies[2]->loadFiles("StarWars.txt");
    movies[2]->DisplayList();

    movies[3]->loadFiles("Demon_Slayer.txt");
    movies[3]->DisplayList();

    //memory cleaning
    for (int i = 0; i < NUM_MOVIES; i++) {  
        delete movies[i];
    }

    return 0;
};