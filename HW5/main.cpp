

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "book.h"
using namespace std;

void readFile(vector <Book> &books){
    ifstream infile;
    infile.open("books.csv");
    if(infile.fail()){
        cout << "Error opening file" << endl;
        exit(1);
    }

    else{

        string Syear;
        string title;
        string authorLast;
        string authorFirst;
        string genre;
        string srating;

        // While loop that uses getline to read in the file with a delemator of a comma then appends the data to the vector

        while (getline (infile, Syear, ',')){
            getline (infile, title, ',');
            getline (infile, authorLast, ',');
            getline (infile, authorFirst, ',');
            getline (infile, genre, ',');
            getline (infile, srating, '\n');

            // Converts the string to an int and float

            int year = stoi(Syear);
            float rating = stof(srating);

            // Creates a new book object and appends it to the vector

            Book book(year, title, authorLast, authorFirst, genre, rating);
            books.push_back(book);

        }

        infile.close();






    }
}



void writeFile(vector <Book> &books, string filename){
    ofstream outfile;
    outfile.open(filename);
    if(outfile.fail()){
        cout << "Error opening file" << endl;
        exit(1);
    }
    else{
        for(int i = 0; i < int(books.size()); i++){
            outfile << books[i].getYear() << ", ";
            outfile << books[i].getTitle() << ", ";
            outfile << books[i].getAuthorLast() << ", ";
            outfile << books[i].getAuthorFirst() << ", ";
            outfile << books[i].getGenre() << ", ";
            outfile << books[i].getRating() << endl;

        }

    }

    outfile.close();
}


// Insertion function that sorting based off year then calls the writeFile to write the vector into a file called insertion.csv
// It sorts based off get year

void insertionSort(vector <Book> &books, int low, int high){

    for(int i = low + 1; i < high; i++){  // Start a loop from low+1 to high-1
        Book temp = books[i];         // Store the i-th element in a temporary variable
        int j = i - 1;                // Set j as the previous element to i
        while((j >= 0) && (books[j].getYear() > temp.getYear())){  // Loop until j is greater than or equal to 0 and previous year is greater than current year
            books[j + 1] = books[j];  // Shift the element to the right
            j--;                      // Decrement j
        }
        books[j + 1] = temp;          // Insert the current element at correct position
    }

    writeFile(books, "insertion.csv"); // Write the sorted array to a file
    cout << "Insertion sort complete" << endl; // Print a message indicating that the sort is complete


}

//Selection sort function that sorts based off the first name of the author then calls the writeFile to write the vector into a file called selection.csv

void selectionSort(vector <Book> &books, int low, int high){
    for(int i = low; i < high; i++){    // Start a loop from low to high-1
        int min = i;                // Set the minimum element as the current index i
        for(int j = i + 1; j < high; j++){  // Start a nested loop from i+1 to high-1
            if(books[j].getAuthorFirst() < books[min].getAuthorFirst()){  // If author of j-th book comes before author of current minimum book
                min = j;            // Update the index of minimum element
            }
        }
        Book temp = books[i];       // Swap the current index i with minimum index
        books[i] = books[min];
        books[min] = temp;
    }

   
}


// Quick sort function that sorts based off the last name of the author then calls the writeFile to write the vector into a file called quick.csv



int partition(vector <Book> &books, int low, int high){
    // Choose the pivot element
    Book pivot = books[high];
    // Initialize the partition index
    int i = low - 1;
    // Iterate through the array from low to high
    for(int j = low; j < high; j++){
        // If the current element is less than pivot,
        // increment the partition index and swap the current element
        // with the element at the partition index
        if(books[j].getAuthorLast() < pivot.getAuthorLast()){
            i++;
            Book temp = books[i];
            books[i] = books[j];
            books[j] = temp;
        }
    }
    // Finally, swap the pivot element with the element at the partition index
    Book temp = books[i + 1];
    books[i + 1] = books[high];
    books[high] = temp;
    // Return the partition index
    return i + 1;
}

void quickSort(vector <Book> &books, int low, int high){
    // Base case: If low is greater than or equal to high, the array is already sorted
    if(low < high){
        // Find the pivot index by partitioning the array
        int pivot = partition(books, low, high);
        // Recursively sort the left and right sub-arrays
        quickSort(books, low, pivot - 1);
        quickSort(books, pivot + 1, high);
    }
}


    
 
//Merge sort function that sorts based off the title of the book then calls the writeFile to write the vector into a file called merge.csv

void merge(vector<Book> &books, int left, int right){
    // Find the number of elements to be sorted
    int count = right - left + 1;
    // If there is more than one element, continue sorting
    if (count > 1){
        // Divide the array in half and recursively sort each half
        int mid = (left + right) / 2;
        merge(books, left, mid);
        merge(books, mid + 1, right);
        
        // Create a temporary array to hold the sorted values
        Book* copy = new Book[count];

        // Merge the two sorted halves into the temporary array
        int i = left;
        int i2 = mid + 1;
        int k = 0;
        while (i <= mid && i2 <= right){
            if (books[i].getTitle() < books[i2].getTitle()){
                copy[k++] = books[i++];
            }
            else{
                copy[k++] = books[i2++];
            }
        }
        // Copy any remaining elements from the first half
        while (i <= mid){
            copy[k++] = books[i++];
        }
        // Copy any remaining elements from the second half
        while (i2 <= right){
            copy[k++] = books[i2++];
        }

        // Copy the sorted values back into the original array
        for (int i = 0; i < count; i++){
            books[left + i] = copy[i];
        }
        
        // Clean up the temporary array
        delete[] copy;
    }
}

int main(){
vector <Book> books;





readFile(books);
clock_t time1=clock();

insertionSort(books, 0, books.size() - 1);

clock_t time2=clock();
double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
   cout << "Run time of insertionSort: " << run_time << " seconds\n";

    

clock_t time3 = clock();
selectionSort(books, 0, books.size() - 1);
 writeFile(books, "selection.csv");
clock_t time4 = clock();
double run_time2 = (time4 - time3) / (double)CLOCKS_PER_SEC;
cout << "Run time of selectionSort: " << run_time2 << " seconds\n";

;


clock_t time5 = clock();
quickSort(books, 0, books.size() - 1);
writeFile(books, "quick.csv");

clock_t time6 = clock();
double run_time3 = (time6 - time5) / (double)CLOCKS_PER_SEC;
cout << "Run time of quickSort: " << run_time3 << " seconds\n";



clock_t time7 = clock();
merge(books, 0, books.size() - 1);
writeFile(books, "merge.csv");
    
clock_t time8 = clock();
double run_time4 = (time8 - time7) / (double)CLOCKS_PER_SEC;
cout << "Run time of mergeSort: " << run_time4 << " seconds\n";

    
    



}














