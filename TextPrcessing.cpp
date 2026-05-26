#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <chrono>

using namespace std;
using namespace chrono;

int main()
{
    // Pornim cronometrul
    auto start = high_resolution_clock::now();

    // Deschidem fisierul text
    ifstream file("text.txt");

    // Verificam daca fisierul exista
    if (!file)
    {
        cout << "Fisierul nu poate fi deschis!";
        return 1;
    }

    map<string, int> frecventa;

    string cuvant;

    // Citim fiecare cuvant
    while (file >> cuvant)
    {
        // Transformam in litere mici
        for (char& c : cuvant)
        {
            c = tolower(c);
        }

        // Crestem frecventa
        frecventa[cuvant]++;
    }

    file.close();

    // Afisam rezultatele
    cout << "Frecventa cuvintelor:\n\n";

    for (auto x : frecventa)
    {
        cout << x.first << " -> " << x.second << endl;
    }

    // Oprim cronometrul
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "\nTimp executie: "
        << duration.count()
        << " ms";

    return 0;
}