// Malakai Ponce | October 04, 2025 | COMSC 210
// Lab 18

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
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

    void loadFiles(string filename) {  //used an example to build this
        ifstream inFile(filename);

        if (!inFile) {
            cout << "Could not read" << endl;
            return;
        }
        double rating;
        string comment;

        while (inFile >> rating) {
            inFile.ignore();
            getline(inFile, comment);
            AddToFront(rating, comment);
        }
        cout << "files from: " << filename << endl;
        inFile.close();
    }
};

int main() {
    const int NUM_MOVIES = 4;

    Movie* movies[NUM_MOVIES];
    movies[0] = new Movie("HTTYD");
    movies[1] = new Movie("Batman");
    movies[2] = new Movie("StarWars");
    movies[3] = new Movie("Demon Slayer");


    movies[0]->loadFiles("HTTYD.txt");
    movies[1]->loadFiles("Batman.txt");
    movies[2]->loadFiles("StarWars.txt");
    movies[3]->loadFiles("Demon_Slayer.txt");


    movies[0]->DisplayList();
    movies[1]->DisplayList();
    movies[2]->DisplayList();
    movies[3]->DisplayList();
};