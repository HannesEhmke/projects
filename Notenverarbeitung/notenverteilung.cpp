#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <fstream>
#include <sstream>


void begruessung() {
    std::cout<< "Hallo, in diesem Programm werden die Noten aus einer txt Datei ausgelesen und verarbeitet.\n";
}

/* alter code - für tastaturinput
std::vector<double> input(){
    std::vector<double> noten;
    double in = 1.0;
    do{
        
        std::cin>> in;
        if (in !=0.0){
        noten.push_back(in);
        }
        
    } while(in!=0.0);
   return noten;
}
   */

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

std::vector<double> input_from_file(const std::string& dateipfad) {
    std::vector<double> noten;
    std::ifstream datei(dateipfad);

    if (!datei.is_open()) {
        std::cerr << "Fehler: Die Datei '" << dateipfad << "' konnte nicht geoeffnet werden!\n";
        return noten;
    }

    std::string zeile;

    while (std::getline(datei, zeile)) {
        std::stringstream ss(zeile);
        std::string wort;

        
        while (ss >> wort) {
            try {
                double wert = std::stod(wort);

                if (wert >= 1.0 && wert <= 5.0) {
                    noten.push_back(wert);
                }
            } catch (...) {
            }
        }
    }

    datei.close();
    return noten;
}


std::vector<int> anzahlnoten(const std::vector<double>& noten) {
    
    static const std::unordered_map<int, int> noten_zu_index = {
        {10, 0}, {13, 1}, {17, 2}, {20, 3}, {23, 4},
        {27, 5}, {30, 6}, {33, 7}, {37, 8}, {40, 9}, {50, 10}
    };

    std::vector<int> ergebnis(11, 0);

    for (double note : noten) {
        int key = static_cast<int>(std::round(note * 10.0));
        auto it = noten_zu_index.find(key);
        if (it != noten_zu_index.end()) {
            ergebnis[it->second]++;
        }
    }

    return ergebnis;
}

std::vector<double> filternachbestanden(std::vector<double>& noten){
    std::vector<double> bestandenenoten;
    for (int i=0;i<noten.size();i++){
        if (noten[i] <= 4.0 && noten[i] > 0.0){
                bestandenenoten.push_back(noten[i]);
        }
    }
    return bestandenenoten;
}

double calcaverage(std::vector<double>& noten){
    double sum = 0.0;
    for (int i=0;i<noten.size();i++){
        sum += noten[i];
    }
    return sum / noten.size();
}

void printnumber(int x){
    for (int i=0;i < x;i++){
        std::cout << "X";
    }
}

void outputvisuals(const std::vector<int>& anzahlnoten) {
    const std::vector<std::string> beschriftung = {
        "1.0", "1.3", "1.7", "2.0", "2.3", "2.7", "3.0", "3.3", "3.7", "4.0", "5.0"
    };

    std::cout << "\n";
    for (size_t i = 0; i < anzahlnoten.size() && i < beschriftung.size(); ++i) {
        std::cout << beschriftung[i] << ": ";
        
        for (int j = 0; j < anzahlnoten[i]; ++j) {
            std::cout << "X";
        }
        std::cout << "\n";
    }
}



int main(){
    begruessung();
    std::vector<double> noten= input_from_file("noten.txt");
    if (noten.empty()){
        std::cout << "Es wurden keine gueltigen Noten eingelesen \n";
        return 1;
    }
    std::cout << "Es wurden " << noten.size() << " Noten eingelesen.\n";

    std::vector<double> bestandenenoten = filternachbestanden(noten);
    
    std::vector<int> notenanzahl = anzahlnoten(noten);

    std::cout << "Der Durchschnitt ist: " << calcaverage(noten) << " \n";
    if (bestandenenoten.empty()){
        std::cout << "Es gibt keine bestandenen Klausuren.\n";
    } else {
    std::cout << "Der Durchschnitt der bestandenen Noten ist: " << calcaverage(bestandenenoten) << " \n";
    }
    std::cout << "-------Visualisierung--------- \n";
    outputvisuals(notenanzahl);
    return 0;


}