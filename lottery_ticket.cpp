#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readLuckNum(string lotteryTickets[], int size){
    
    ifstream File;
    File.open("Lucky.txt");

    for(int i = 0; i < size; i++)
        File >> lotteryTickets[i];

    File.close();
}

bool numValidation(string winningNum){

    if(!(winningNum.length() == 5)){
        cout << "Please enter a 5-digit number" << endl;
        return false;
    }
    else
        return true;
}

void thisWeeksNum(string &winningNum){

    while(!(numValidation(winningNum))){
        cin >> winningNum;
    }

}


int binarySearch(string lotteryTickets[], string winningNum, int listSize){

    
    int low = 0;
    int high = listSize - 1;

    while (high >= low){
        int mid = (low + high) / 2;
        if (winningNum < lotteryTickets[mid])
            high = mid - 1;
        else if (winningNum == lotteryTickets[mid])
            return mid;
        else
            low = mid + 1;
    }

    return -low - 1;
}


int main(){

    
    string lotteryTickets[10];
    string winningNum;
    string& winningNumRef = winningNum;

    readLuckNum(lotteryTickets, 10);


    cout << "Please enter this week's 5-digit winning number: " << endl;
    cin >> winningNumRef;
    thisWeeksNum(winningNumRef);

    int key = binarySearch(lotteryTickets, winningNumRef, 10);

    if((binarySearch(lotteryTickets, winningNumRef, 10)) < 0)
        cout << "No winners!" << endl;
    else
        cout << "Lottery ticket " << lotteryTickets[key] << " is a winner!" << endl;

    return 0;

}
