/* Author: Patricia Wilthew.
 * Description: Allows the user to enter movie information which is then
 *  stored in a vector. When the user has indicated that he or she
 *  is done entering movie data, the program outputs the information
 *  stored in the vector.
 */
using namespace std;
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

/*
 * Definition of a Movie type
 */
struct Movie {
    string title;
    string director;
    int year;
    int minutes;
};


void create_movie(struct Movie &m);
void print_movies(vector <Movie> &movies, int size);

/*
 * Main program
 */
int main() {

    vector <Movie> movies;
    bool run = true;
    string ans;

    while (run) {
    
        struct Movie m;
        create_movie(m);
        movies.push_back(m);

        cout << endl << "Do you have more movies info to enter?\n";
        cout << "Enter y for yes or n for no: ";

        cin.ignore();
        getline(cin, ans);
        cout << endl;

        if (ans == "n" || ans == "N")
            run = false;
    }

    cout << "Here is the info that you entered:\n";

    print_movies(movies, movies.size());

    return 1;
}

/*
 * Obtains the data necessary to instantiate a Movie
 */
void create_movie(struct Movie &m) {

    cout << endl << "Enter the title of the movie: ";
    getline(cin, m.title);

    cout << "Enter the director's name: ";
    getline(cin, m.director);

    cout << "Enter the year the movie was created: ";
    cin >> m.year;

    cout << "Enter the movie length (in minutes): ";
    cin >> m.minutes;

}

/*
 * Prints a vector of Movie type elements through standard output
 */
void print_movies(vector <Movie> &movies , int size) {

    for (struct Movie n: movies) {
        cout << "Movie Title: " << n.title << endl;
        cout << "Movie Director: " << n.director << endl;
        cout << "Movie Year: " << n.year << endl;
        cout << "Movie Length: " << n.minutes << endl;
        cout << endl;
    }

}
